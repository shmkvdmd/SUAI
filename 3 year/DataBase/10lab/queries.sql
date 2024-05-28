SELECT * FROM worker WHERE first_name LIKE 'А%'

SELECT * FROM developer WHERE surname LIKE 'М%'


CREATE FUNCTION case_text_equal(text, text) RETURNS boolean AS $$
    SELECT LOWER($1) = LOWER($2);
$$ LANGUAGE SQL IMMUTABLE;

CREATE OPERATOR ==* (
    PROCEDURE = case_text_equal,
    LEFTARG = text,
    RIGHTARG = text,
    COMMUTATOR = '==*'
);


CREATE FUNCTION count_bugs(state bigint, bug_crit bug_crit) RETURNS int
AS $$
BEGIN
    IF bug_crit IS NOT NULL THEN
        RETURN state + 1;
    ELSE
        RETURN state;
    END IF;
END;
$$ LANGUAGE plpgsql;

CREATE AGGREGATE bug_count(bug_crit) (
    SFUNC = count_bugs,
    STYPE = int,
    INITCOND = '0'
);

SELECT crit_level AS "Критичность", bug_count(crit_level) AS "Количество багов" FROM bugs
GROUP BY crit_level;



CREATE TYPE average_state AS (accum INTERVAL, qty numeric);


CREATE OR REPLACE FUNCTION fix_avg_time(stat average_state, ac1 date_task)
    RETURNS average_state LANGUAGE plpgsql
AS $$
BEGIN 
    IF (ac1.started IS NULL) OR (ac1.ended IS NULL) THEN
        RETURN stat;
    ELSE
        RETURN ROW(stat.accum + (ac1.ended - ac1.started), stat.qty+1)::average_state;
    END IF;
END;
$$ IMMUTABLE;

CREATE OR REPLACE FUNCTION average_time_final(state average_state)
    RETURNS interval AS $$
BEGIN
    RETURN CASE WHEN state.qty > 0 THEN state.accum/state.qty
END;
END; $$ LANGUAGE plpgsql;

CREATE AGGREGATE bug_avg(date_task) (
    SFUNC = fix_avg_time,
    STYPE = average_state,
	FINALFUNC = average_time_final,
    INITCOND = '(0,0)'
);

SELECT bug_avg(bug_data) FROM bugs;

