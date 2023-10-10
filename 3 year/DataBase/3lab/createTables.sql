CREATE TABLE tester
(
	id_tester INT PRIMARY KEY AUTO_INCREMENT,
    t_first_name VARCHAR(30),
    t_surname VARCHAR(30),
    t_lastname VARCHAR(30)
);

CREATE TABLE project
(
	id_project INT PRIMARY KEY AUTO_INCREMENT,
    project_name VARCHAR(50)
);

CREATE TABLE developer
(
	id_developer INT PRIMARY KEY AUTO_INCREMENT,
    d_first_name VARCHAR(30),
    d_surname VARCHAR(30),
    d_lastname VARCHAR(30)
);

CREATE TABLE CritLevel
(
	id_crit INT PRIMARY KEY AUTO_INCREMENT,
    crit_name VARCHAR(50)
);

CREATE TABLE bug
(
	id_bug INT PRIMARY KEY AUTO_INCREMENT,
	bug_name VARCHAR(50) NOT NULL,
    is_fixed BOOLEAN NOT NULL,
    started DATE NOT NULL,
    ended DATE,
    id_tester INT,
    id_crit INT,
    FOREIGN KEY(id_tester) REFERENCES tester(id_tester) ON DELETE RESTRICT ON UPDATE CASCADE,
    FOREIGN KEY(id_crit) REFERENCES CritLevel(id_crit) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE bug_developer
(
	id_bug INT NOT NULL,
    id_developer INT NOT NULL,
    PRIMARY KEY (id_bug, id_developer),
    FOREIGN KEY (id_bug) REFERENCES bug(id_bug) ON DELETE RESTRICT ON UPDATE CASCADE,
    FOREIGN KEY (id_developer) REFERENCES developer(id_developer) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_bug
(
	id_project INT NOT NULL,
    id_bug INT NOT NULL,
    PRIMARY KEY (id_project, id_bug),
    FOREIGN KEY(id_project) REFERENCES project(id_project) ON DELETE RESTRICT ON UPDATE CASCADE,
    FOREIGN KEY(id_bug) REFERENCES bug(id_bug) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_tester
(
	id_project INT NOT NULL,
    id_tester INT NOT NULL,
    PRIMARY KEY (id_project, id_tester),
    FOREIGN KEY(id_project) REFERENCES project(id_project) ON DELETE RESTRICT ON UPDATE CASCADE,
    FOREIGN KEY(id_tester) REFERENCES tester(id_tester) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_developer
(
	id_project INT NOT NULL,
    id_developer INT NOT NULL,
    PRIMARY KEY (id_project, id_developer),
    FOREIGN KEY(id_project) REFERENCES project(id_project) ON DELETE RESTRICT ON UPDATE CASCADE,
    FOREIGN KEY(id_developer) REFERENCES developer(id_developer) ON DELETE RESTRICT ON UPDATE CASCADE
);