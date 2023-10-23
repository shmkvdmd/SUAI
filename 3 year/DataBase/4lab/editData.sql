-- Обновление всех по параметру
UPDATE tester
SET t_first_name = 'Василий'
WHERE t_first_name = 'Иван';

-- Обновление одного
UPDATE tester
SET t_first_name = 'Евгений'
WHERE id_tester = '2';

-- Удаление одного
DELETE FROM tester Ц
WHERE id_tester = '3';

-- Удаление всех по параметру
DELETE FROM tester 
WHERE t_surname = 'Петров';

-- Пример использования MERGE
MERGE INTO developer AS dev
USING tester AS test
ON dev.id_developer = test.id_tester
WHEN MATCHED THEN
  UPDATE SET dev.d_first_name = test.t_first_name, dev.d_surname = test.t_surname,dev.d_lastname = test.t_lastname
WHEN NOT MATCHED THEN
  INSERT (id_developer, d_first_name, d_surname, d_lastname) VALUES (test.id_tester, test.t_first_name, test.t_surname,test.t_lastname)
WHEN NOT MATCHED BY SOURCE THEN
  DELETE;
