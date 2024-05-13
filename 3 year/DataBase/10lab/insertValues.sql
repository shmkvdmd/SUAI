INSERT INTO tester (worker_id, first_name, surname, patronym) VALUES 
	(1, 'Иван', 'Иванов', 'Иванович'), 
	(2, 'Петр', 'Петров', 'Петрович'), 
	(3, 'Мария', 'Сидорова', 'Ивановна');

INSERT INTO developer (worker_id, first_name, surname, patronym) VALUES 
	(4, 'Алексей', 'Козлов', 'Алексеевич'), 
	(5, 'Елена', 'Михайлова', 'Петровна'), 
	(6, 'Сергей', 'Николаев', 'Сергеевич'); 

INSERT INTO project (project_name) VALUES 
	('Первый проект'),
	('Второй проект'),
	('Третий проект');

INSERT INTO features (feature_data, feature_name) VALUES 
	((TRUE, '2024-05-10', '2024-05-13'), 'Функция 1'),
	((FALSE, '2024-05-07', NULL), 'Функция 2'),
	((TRUE, '2024-04-18', '2024-04-30'), 'Функция 3');

INSERT INTO bugs (bug_name, bug_data, tester_id, crit_level) VALUES 
	('Проблема с загрузкой страницы', (TRUE, '2024-04-15', '2024-04-17'), 1, 'Критичный'),
	('Ошибка валидации формы', (FALSE, '2024-04-20', NULL), 2, 'Некритичный'),
	('Вылет приложения при нажатии на кнопку', (TRUE, '2024-04-18', '2024-04-20'), 3, 'Очень критичный');

INSERT INTO project_bug (project_id, bug_id) VALUES 
	(1, 1),
	(1, 2), 
	(2, 3); 

INSERT INTO bug_developer (bug_id, developer_id) VALUES 
	(1, 4),
	(2, 5),
	(3, 6);

INSERT INTO project_developer (project_id, developer_id) VALUES 
	(1, 4),
	(1, 5), 
	(2, 6);

INSERT INTO project_features (project_id, feature_id) VALUES 
	(1, 1),
	(1, 2), 
	(2, 3); 

INSERT INTO developer_features (developer_id, feature_id) VALUES 
	(4, 1), 
	(5, 2), 
	(6, 3); 

