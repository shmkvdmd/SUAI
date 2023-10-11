INSERT tester(t_first_name, t_surname, t_lastname) 
VALUES 
('Demid', 'Shumkov', 'Vadimovich'),
('Ivan','Ivanov','Ivanovich'),
('Peter', 'Petrov', 'Petrovich');


-- Обновление всех 
UPDATE tester
SET t_first_name = 'Vasya'
WHERE t_first_name = 'Ivan';

-- Обновление одного
UPDATE tester
SET t_first_name = 'Vasya'
WHERE ('id_tester' = '2');