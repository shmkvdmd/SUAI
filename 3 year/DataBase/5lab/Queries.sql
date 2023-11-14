-- а) Баги, в названии которых содержится слово «индекс», но оно не последнее
SELECT bug_name FROM bug
WHERE bug_name LIKE '%индекс%_';

-- б) Баги, найденные в одном проекте , но разными теститировщиками
SELECT DISTINCT b1.id_bug, b2.id_bug, pb1.id_project, pb2.id_project, b1.id_tester, b2.id_tester
FROM 
project_bug AS pb1 
JOIN project_bug AS pb2 ON pb1.id_project = pb2.id_project
JOIN bug AS b1 ON b1.id_bug = pb1.id_bug
JOIN bug AS b2 ON b2.id_bug = pb2.id_bug
WHERE b1.id_bug < b2.id_bug
  AND b1.id_tester <> b2.id_tester;

-- в) Проект без багов
SELECT p.id_project, p.project_name
FROM project AS p
LEFT JOIN project_bug AS pb ON p.id_project = pb.id_project
WHERE pb.id_project IS NULL;

