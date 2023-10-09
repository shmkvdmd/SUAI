/*ALTER TABLE название_таблицы 
{ ADD название_столбца тип_данных_столбца [атрибуты_столбца] | 
  DROP COLUMN название_столбца |
  MODIFY COLUMN название_столбца тип_данных_столбца [атрибуты_столбца] |
  ALTER COLUMN название_столбца SET DEFAULT значение_по_умолчанию |
  ADD [CONSTRAINT] определение_ограничения |
  DROP [CONSTRAINT] имя_ограничения}*/
  
  -- Добавление столбца
  ALTER TABLE critlevel
  ADD critDescrption VARCHAR(255);
  
    -- Изменение типа столбца
  ALTER TABLE critlevel
  MODIFY COLUMN critDescription CHAR(100);
  
  -- Удаление столбца
  ALTER TABLE critlevel
  DROP COLUMN critDescription;