-- Логирование
DELIMITER //
CREATE TRIGGER log_bug_changes_on_update
AFTER UPDATE ON bug
FOR EACH ROW
BEGIN
    -- Запись изменений в лог-таблицу
    INSERT INTO bug_log (bug_id, action, timestamp)
    VALUES (NEW.id_bug, CONCAT('Action: UPDATE'), NOW());
END;
//
DELIMITER ;

DELIMITER //
CREATE TRIGGER log_bug_changes
AFTER INSERT ON bug
FOR EACH ROW
BEGIN
    -- Запись изменений в лог-таблицу
    INSERT INTO bug_log (bug_id, action, timestamp)
    VALUES (NEW.id_bug, CONCAT('Action: INSERT'), NOW());
END;
//
DELIMITER ;

DELIMITER //
CREATE TRIGGER log_bug_changes_on_delete
AFTER DELETE ON bug
FOR EACH ROW
BEGIN
    -- Запись изменений в лог-таблицу
    INSERT INTO bug_log (bug_id, action, timestamp)
    VALUES (OLD.id_bug, CONCAT('Action: DELETE'), NOW());
END;
//
DELIMITER ;

CREATE TABLE bug_log
(
    log_id INT PRIMARY KEY AUTO_INCREMENT,
    bug_id INT,
    action VARCHAR(255),
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (bug_id) REFERENCES bug(id_bug) ON DELETE CASCADE ON UPDATE CASCADE
);
-- Обеспечение безопасности данных
DELIMITER //
CREATE TRIGGER ensure_data_security
BEFORE INSERT ON tester
FOR EACH ROW
BEGIN
    -- Предотвращение вставки данных с определенными условиями
    IF NEW.t_first_name = 'запрещенное_имя' THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Запрещенное имя тестировщика';
    END IF;
END;
//
DELIMITER ;

--Триггеры для обеспечения ссылочной целостности
DELIMITER //
CREATE TRIGGER enforce_foreign_key_before_delete
BEFORE DELETE ON tester
FOR EACH ROW
BEGIN
    IF (SELECT COUNT(*) FROM bug WHERE id_tester = OLD.id_tester) > 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Нельзя удалить тестировщика';
    END IF;
END;
//
DELIMITER ;

DELIMITER //
CREATE TRIGGER enforce_foreign_key_project_tester
BEFORE INSERT ON project_tester
FOR EACH ROW
BEGIN
    IF NOT EXISTS (SELECT 1 FROM project WHERE id_project = NEW.id_project) OR
       NOT EXISTS (SELECT 1 FROM tester WHERE id_tester = NEW.id_tester) THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Не существует проекта или тестировщика';
    END IF;
END;
//
DELIMITER ;

DELIMITER //
CREATE TRIGGER update_foreign_key_project_tester
BEFORE UPDATE ON project_tester
FOR EACH ROW
BEGIN
    IF NOT EXISTS (SELECT 1 FROM project WHERE id_project = NEW.id_project) OR
       NOT EXISTS (SELECT 1 FROM tester WHERE id_tester = NEW.id_tester) THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Не существует проекта или тестировщика';
    END IF;
END;
//
DELIMITER ;