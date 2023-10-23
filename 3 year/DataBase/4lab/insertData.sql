INSERT tester(t_first_name, t_surname, t_lastname) 
VALUES 
('Андрей', 'Петров', 'Иванович'),
('Елена', 'Смирнова', 'Александровна'),
('Денис', 'Козлов', 'Сергеевич'),
('Ольга', 'Иванова', 'Андреевна');


INSERT project(project_name)
VALUES
('Проект1'),
('Проект2'),
('Проект3'),
('Проект4');


INSERT developer(d_first_name,d_surname,d_lastname)
VALUES
('Игорь', 'Смирнов', 'Александрович'),
('Елена', 'Коваленко', 'Игоревна'),
('Алексей', 'Петров', 'Сергеевич'),
('Анна', 'Иванова', 'Дмитриевна');


INSERT critlevel(crit_name)
VALUES
('Блокирующий'),
('Критический'),
('Значительный'),
('Незначительный'),
('Тривиальный');

INSERT bug(bug_name,is_fixed,started,ended,id_tester,id_crit)
VALUES
('Отсутствующий индекс',TRUE,'2023-10-10','2023-10-17', 1,2),
('Индекс с неправильным типом данных',FALSE,'2023-05-13',null,2,3),
('Индекс с недействительными ссылками', TRUE, '2023-07-11', '2023-07-15', 4, 2),
('Ошибка в алгоритме сортировки', FALSE, '2023-09-15', null, 1, 2),
('Проблемы с многозадачностью', TRUE, '2023-07-25', '2023-08-05', 4, 1),
('Потеря данных при перезагрузке', FALSE, '2023-06-10', null, 3, 3);

INSERT bug_developer(id_bug,id_developer)
VALUES
(1,1),
(2,1),
(3,1),
(4,2),
(5,3),
(6,4);


INSERT project_developer(id_project,id_developer)
VALUES
(1, 1),
(2,2),
(3,3),
(4,4);


INSERT project_tester(id_project,id_tester)
VALUES
(1,1),
(2,1),
(3,1),
(4,1),
(2,2),
(3,3),
(4,4);

INSERT project_bug (id_project, id_bug)
VALUES 
(1,1),
(1,2),
(2,1),
(2,4),
(3,3),
(3,5),
(3,6);