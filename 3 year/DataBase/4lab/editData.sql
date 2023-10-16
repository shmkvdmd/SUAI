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
MERGE INTO target_table AS T
USING source_table AS S
ON T.id = S.id
WHEN MATCHED THEN
  UPDATE SET T.column1 = S.column1, T.column2 = S.column2
WHEN NOT MATCHED THEN
  INSERT (id, column1, column2) VALUES (S.id, S.column1, S.column2)
WHEN NOT MATCHED BY SOURCE THEN
  DELETE;
