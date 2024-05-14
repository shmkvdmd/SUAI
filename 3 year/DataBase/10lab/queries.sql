SELECT * FROM worker WHERE first_name LIKE 'А%'

SELECT * FROM developer WHERE surname LIKE 'М%'


CREATE FUNCTION case_text_equal(text, text) RETURNS boolean AS $$
    SELECT LOWER($1) = LOWER($2);
$$ LANGUAGE SQL IMMUTABLE;

CREATE OPERATOR ==* (
    PROCEDURE = case_text_equal,
    LEFTARG = text,
    RIGHTARG = text,
    COMMUTATOR = '==*',
    NEGATOR = '!=*'
);


CREATE FUNCTION count_bugs(state bigint, bug_crit bug_crit) RETURNS bigint
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
    STYPE = bigint,
    INITCOND = '0'
);

SELECT crit_level AS "Критичность", bug_count(crit_level) AS "Количество багов" FROM bugs
GROUP BY crit_level;
