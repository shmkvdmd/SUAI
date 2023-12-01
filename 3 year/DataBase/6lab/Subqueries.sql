--г. Критический баг, который добавили первым
--1) С использованием агрегатных функций
SELECT id_bug, bug_name
FROM bug
WHERE started = (
    SELECT MIN(started)
    FROM bug
    WHERE id_crit = (SELECT id_crit FROM CritLevel WHERE crit_name = 'Критический')
);
--д. Тестировщик, с самым большим количеством добавленных багов
--С 2 not exists
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


 -- С использованием агрегатных функций
SELECT id_tester, t_first_name, t_surname, t_lastname
FROM tester
WHERE id_tester = (
    SELECT id_tester
    FROM bug
    GROUP BY id_tester
    ORDER BY COUNT(id_bug) DESC
    LIMIT 1
);

-- е. Разработчик, у которого нет неисправленных багов
-- С использованием not in 
SELECT d.* FROM developer d
WHERE d.id_developer NOT IN (
    SELECT bd.id_developer
    FROM bug_developer bd
    JOIN bug b ON bd.id_bug = b.id_bug
    WHERE b.is_fixed = FALSE
);
-- С использованием except
SELECT d.* FROM developer d
EXCEPT SELECT d.* FROM developer d
JOIN bug_developer bd ON d.id_developer = bd.id_developer
JOIN bug b ON bd.id_bug = b.id_bug
WHERE b.is_fixed = FALSE;

-- Левое соединение 
SELECT d.*
FROM developer d
LEFT JOIN (
    SELECT bd.id_developer
    FROM bug_developer bd
    JOIN bug b ON bd.id_bug = b.id_bug
    WHERE b.is_fixed = FALSE
) unresolved_bugs ON d.id_developer = unresolved_bugs.id_developer
WHERE unresolved_bugs.id_developer IS NULL;

-- ж. Тестировщик, работавший со всеми проектами
SELECT t.*
FROM tester t
WHERE t.id_tester NOT IN (
    SELECT pt.id_tester
    FROM project_tester pt
    GROUP BY pt.id_tester
    HAVING COUNT(DISTINCT pt.id_project) < (
        SELECT COUNT(*) FROM project
    )
);
-- С except 

SELECT id_tester, t_first_name, t_surname, t_lastname FROM tester
EXCEPT
SELECT t.id_tester, t.t_first_name, t.t_surname, t.t_lastname
FROM tester t
JOIN project_tester pt ON t.id_tester = pt.id_tester
GROUP BY t.id_tester
HAVING COUNT(DISTINCT pt.id_project) < (SELECT COUNT(*) FROM project);

-- С левым соединением
SELECT t.* FROM tester t
LEFT JOIN project_tester pt ON t.id_tester = pt.id_tester
GROUP BY t.id_tester
HAVING COUNT(DISTINCT pt.id_project) >= (SELECT COUNT(*) FROM project);
