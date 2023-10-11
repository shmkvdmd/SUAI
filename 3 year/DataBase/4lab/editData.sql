-- Обновление всех по параметру
UPDATE tester
SET t_first_name = 'Vasya'
WHERE t_first_name = 'Ivan';

-- Обновление одного
UPDATE tester
SET t_first_name = 'Vasya'
WHERE ('id_tester' = '2');

-- Удаление одного
DELETE FROM tester 
WHERE (`id_tester` = '3');

-- Удаление всех по параметру
DELETE FROM tester 
WHERE t_surname = 'Ivanov';