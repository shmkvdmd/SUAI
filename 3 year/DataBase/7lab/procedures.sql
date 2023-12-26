-- Хранимая процедура с добавлением нового тестировщика.
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
-- Вызов процедуры
CALL InsertTester('Иван', 'Иванов','Иванович');

DELIMITER //
CREATE PROCEDURE InsertWithLookup(
    IN p_bug_name VARCHAR(50),
    IN p_is_fixed BOOLEAN,
    IN p_started DATE,
    IN p_ended DATE,
    IN p_tester_name VARCHAR(30),
    IN p_crit_name VARCHAR(50)
)
BEGIN
    DECLARE v_tester_id INT;
    DECLARE v_crit_id INT;

    -- Проверяем и добавляем данные в таблицу tester
    INSERT INTO tester (t_first_name, t_surname, t_lastname)
    VALUES (SUBSTRING_INDEX(p_tester_name, ' ', 1), 
            SUBSTRING_INDEX(SUBSTRING_INDEX(p_tester_name, ' ', -2), ' ', 1), 
            SUBSTRING_INDEX(p_tester_name, ' ', -1))
    ON DUPLICATE KEY UPDATE id_tester = LAST_INSERT_ID(id_tester);

    -- Получаем или добавляем данные в таблицу CritLevel
    SELECT id_crit INTO v_crit_id FROM CritLevel WHERE crit_name = p_crit_name;
    IF v_crit_id IS NULL THEN
        INSERT INTO CritLevel (crit_name) VALUES (p_crit_name);
        SET v_crit_id = LAST_INSERT_ID();
    END IF;

    -- Вставляем данные в таблицу bug
    INSERT INTO bug (bug_name, is_fixed, started, ended, id_tester, id_crit)
    VALUES (p_bug_name, p_is_fixed, p_started, p_ended, LAST_INSERT_ID(), v_crit_id);
END //
DELIMITER ;

-- Процедура с очисткой справочников
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

-- Вызов процедуры
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
