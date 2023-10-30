-- г) Критический баг, который добавили первым
SELECT b.id_bug AS critical_bug_id, b.bug_name AS critical_bug_name
FROM bug AS b
WHERE b.id_bug = (
    SELECT MIN(id_bug)
    FROM bug
    WHERE id_crit = (SELECT id_crit FROM CritLevel WHERE crit_name = 'Критический')
);

-- д) Тестировщик, с самым большим количеством добавленных багов:
SELECT t.id_tester, t.t_first_name, t.t_surname, t.t_lastname, COUNT(b.id_bug) AS bug_count
FROM tester AS t
JOIN bug b ON t.id_tester = b.id_tester
GROUP BY t.id_tester
ORDER BY bug_count DESC
LIMIT 1;

-- е) Разработчик, у которого нет неисправленных багов:
SELECT d.id_developer, d.d_first_name, d.d_surname, d.d_lastname
FROM developer d
LEFT JOIN bug_developer bd ON d.id_developer = bd.id_developer
LEFT JOIN bug b ON bd.id_bug = b.id_bug
GROUP BY d.id_developer
HAVING SUM(CASE WHEN b.is_fixed = FALSE THEN 1 ELSE 0 END) = 0;

-- ж) Тестировщик, работавший со всеми проектами:
SELECT t.id_tester, t.t_first_name, t.t_surname, t.t_lastname
FROM tester t
WHERE t.id_tester IN (
    SELECT pt.id_tester
    FROM project_tester pt
    GROUP BY pt.id_tester
    HAVING COUNT(DISTINCT pt.id_project) = (SELECT COUNT(*) FROM project)
);
