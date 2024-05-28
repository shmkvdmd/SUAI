CREATE TABLE worker (
    worker_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    surname VARCHAR(50) NOT NULL,
    patronym VARCHAR(50) NOT NULL
);

CREATE TYPE date_task AS (
	is_fixed BOOL,
	started TIMESTAMP,
	ended TIMESTAMP
);

CREATE TABLE tester (
	PRIMARY KEY (worker_id)
) INHERITS (worker);

CREATE TABLE developer (
	PRIMARY KEY (worker_id)
) INHERITS (worker);

CREATE TABLE project (
	project_id SERIAL PRIMARY KEY,
	project_name VARCHAR(100) NOT NULL
);

CREATE TABLE features (
	feature_id SERIAL PRIMARY KEY,
	feature_data date_task,
	feature_name VARCHAR(100) NOT NULL
);
CREATE TYPE bug_crit AS ENUM ('Некритичный', 'Критичный', 'Очень критичный');

CREATE TABLE bugs (
	bug_id SERIAL PRIMARY KEY,
	bug_name VARCHAR(100) NOT NULL,
	bug_data date_task,
	tester_id INT NOT NULL,
	crit_level bug_crit NOT NULL,
	FOREIGN KEY (tester_id) REFERENCES tester(worker_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_bug (
	project_id INT,
	bug_id INT,
	PRIMARY KEY (project_id, bug_id),
	FOREIGN KEY (project_id) REFERENCES project(project_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (bug_id) REFERENCES bugs(bug_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE bug_developer (
	bug_id INT,
	developer_id INT,
	PRIMARY KEY (bug_id, developer_id),
	FOREIGN KEY (developer_id) REFERENCES developer(worker_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (bug_id) REFERENCES bugs(bug_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_developer (
	project_id INT,
	developer_id INT,
	PRIMARY KEY (project_id, developer_id),
	FOREIGN KEY (project_id) REFERENCES project(project_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (developer_id) REFERENCES developer(worker_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_features (
	project_id INT,
	feature_id INT,
	PRIMARY KEY (project_id,feature_id),
	FOREIGN KEY (project_id) REFERENCES project(project_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (feature_id) REFERENCES features(feature_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE developer_features (
	developer_id INT,
	feature_id INT,
	PRIMARY KEY (developer_id, feature_id),
	FOREIGN KEY (developer_id) REFERENCES developer(worker_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (feature_id) REFERENCES features(feature_id) ON DELETE RESTRICT ON UPDATE CASCADE
);