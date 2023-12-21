-- г. Критический баг, который добавили первым
-- 1) С использованием агрегатных функций
SELECT id_bug, bug_name FROM bug
JOIN critlevel ON critlevel.id_crit = bug.id_crit
	WHERE crit_name = 'Критический'
AND started = (
    SELECT MIN(started) FROM bug
    JOIN critlevel ON critlevel.id_crit = bug.id_crit
	WHERE crit_name = 'Критический'
);


-- 2) С использованием ALL
SELECT id_bug, bug_name FROM bug
JOIN critlevel ON critlevel.id_crit = bug.id_crit
	WHERE crit_name = 'Критический'
AND started <= ALL (
    SELECT (started) FROM bug
    JOIN critlevel ON critlevel.id_crit = bug.id_crit
	WHERE crit_name = 'Критический'
);
-- д. Тестировщик, с самым большим количеством добавленных багов
SELECT id_tester, t_first_name, t_surname, t_lastname
FROM tester
WHERE id_tester = (
    SELECT id_tester
    FROM bug
    GROUP BY id_tester
    ORDER BY COUNT(id_bug) DESC
    LIMIT 1
);

SELECT t.id_tester, t.t_first_name, t.t_surname, t.t_lastname FROM tester t
WHERE NOT EXISTS (
    SELECT 1 FROM bug b1
    WHERE b1.id_tester = t.id_tester
) OR NOT EXISTS (
    SELECT 1 FROM bug b2
    WHERE b2.id_tester = t.id_tester
    GROUP BY b2.id_tester
    HAVING COUNT(b2.id_bug) < (
        SELECT COUNT(b3.id_bug) FROM bug b3
        WHERE b3.id_tester = t.id_tester
    )
)
LIMIT 1;


-- е. Разработчик, у которого нет неисправленных багов

SELECT d.* FROM developer d
WHERE d.id_developer NOT IN (
    SELECT bd.id_developer FROM bug_developer bd
    JOIN bug b ON bd.id_bug = b.id_bug
    WHERE b.is_fixed = FALSE
);


SELECT d.* FROM developer d
EXCEPT
SELECT d.* FROM developer d
JOIN bug_developer bd ON d.id_developer = bd.id_developer
JOIN bug b ON bd.id_bug = b.id_bug
WHERE b.is_fixed = FALSE;


SELECT d.* FROM developer d
LEFT JOIN (
    SELECT bd.id_developer FROM bug_developer bd
    JOIN bug b ON bd.id_bug = b.id_bug
    WHERE b.is_fixed = FALSE
) unresolved_bugs ON d.id_developer = unresolved_bugs.id_developer
WHERE unresolved_bugs.id_developer IS NULL;


-- ж. Тестировщик, работавший со всеми проектами
SELECT t.* FROM tester t
WHERE NOT EXISTS (
    SELECT 1 FROM project p
    WHERE NOT EXISTS (
        SELECT 1 FROM project_tester pt
        WHERE pt.id_project = p.id_project
        AND pt.id_tester = t.id_tester
    )
);


SELECT t.id_tester, t.t_first_name, t.t_surname, t.t_lastname FROM tester t
JOIN project_tester pt ON t.id_tester = pt.id_tester
GROUP BY t.id_tester
HAVING COUNT(DISTINCT pt.id_project) = (SELECT COUNT(*) FROM project);