-- а) Баги, в названии которых содержится слово «индекс», но оно не последнее
SELECT bug_name FROM bug
WHERE bug_name LIKE 'индекс%';

-- б) Баги, найденные в одном проекте , но разными теститировщиками
SELECT DISTINCT b1.id_bug, b2.id_bug
FROM bug AS b1
JOIN bug AS b2 ON b1.id_bug < b2.id_bug AND b1.id_tester <> b2.id_tester
JOIN project_bug AS pb1 ON b1.id_bug = pb1.id_bug
JOIN project_bug AS pb2 ON b2.id_bug = pb2.id_bug
WHERE pb1.id_project = pb2.id_project;

-- в) Проект без багов
SELECT p.id_project, p.project_name
FROM project AS p
LEFT JOIN project_bug AS pb ON p.id_project = pb.id_project
WHERE pb.id_project IS NULL;
