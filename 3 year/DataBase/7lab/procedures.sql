--Хранимая процедура с добавлением нового тестировщика.
DELIMITER //

CREATE PROCEDURE InsertTester(
    IN first_name VARCHAR(30),
    IN surname VARCHAR(30),
    IN lastname VARCHAR(30)
)
BEGIN
    INSERT INTO tester (t_first_name, t_surname, t_lastname)
    VALUES (first_name, surname, lastname);
END //

DELIMITER ;
--Вызов процедуры
CALL InsertTester('Иван', 'Иванов','Иванович');


--Процедура с очисткой справочников
DELIMITER //

CREATE PROCEDURE DeleteProjectBugWithCleanup(IN projectID INT, IN bugID INT)
BEGIN
    -- Удаляем запись из таблицы project_bug
    DELETE FROM project_bug WHERE id_project = projectID AND id_bug = bugID;

    -- Если нет зависимых данных в bug_developer, удаляем запись из таблицы bug
    IF NOT EXISTS (SELECT 1 FROM bug_developer WHERE id_bug = bugID) THEN
        DELETE FROM bug WHERE id_bug = bugID;
    END IF;
END //

DELIMITER ;

CALL DeleteProhectBugWithCleanup(1,1);

--Хранимая процедура удаления тестировщика
DELIMITER //

CREATE PROCEDURE DeleteTester(
    IN tester_id INT
)
BEGIN
    DELETE FROM project_tester WHERE id_tester = tester_id;
    DELETE FROM bug WHERE id_tester = tester_id;
    DELETE FROM tester WHERE id_tester = tester_id;
END //

DELIMITER ;

--Вызов процедуры
CALL DeleteTester(5);
--Хранимая процедура с возвратом значения
DELIMITER //

CREATE PROCEDURE TotalBugsForTester(IN tester_id INT, OUT total_bugs INT)
BEGIN
	DECLARE bug_count INT;
    SELECT COUNT(*) INTO bug_count
    FROM bug
    WHERE id_tester = tester_id;
    SET total_bugs = bug_count;
END // 
DELIMITER ;

--Вызов процедуры
CALL TotalBugsForTester(1,@cnt);
SELECT @cnt AS bug_count;
 
--Процедура формирования статистики во временной таблице
DELIMITER //
CREATE PROCEDURE GenerateStatistics()
BEGIN
    CREATE TEMPORARY TABLE temp_statistics (
        tester_id INT,
        total_bugs INT
    );
    INSERT INTO temp_statistics (tester_id, total_bugs)
    SELECT id_tester, COUNT(*) AS total_bugs
    FROM bug
    GROUP BY id_tester;
    SELECT * FROM temp_statistics;
    DROP TEMPORARY TABLE IF EXISTS temp_statistics;
END //
DELIMITER ;

--Вызов процедуры
CALL GenerateStatistics();
