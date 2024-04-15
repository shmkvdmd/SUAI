CREATE TABLE tester (
	tester_id SERIAL PRIMARY KEY,
	t_first_name VARCHAR(50) NOT NULL,
	t_surname VARCHAR(50) NOT NULL,
	t_patronym VARCHAR(50) NOT NULL
);

CREATE TABLE developer (
	developer_id SERIAL PRIMARY KEY,
	d_first_name VARCHAR(50) NOT NULL,
	d_surname VARCHAR(50) NOT NULL,
	d_patronym VARCHAR(50) NOT NULL
);

CREATE TABLE crit_level (
	crit_id SERIAL PRIMARY KEY,
	crit_name VARCHAR(50) NOT NULL
);

CREATE TABLE project (
	project_id SERIAL PRIMARY KEY,
	project_name VARCHAR(100) NOT NULL
);

CREATE TABLE features (
	feature_id SERIAL PRIMARY KEY,
	feature_name VARCHAR(100) NOT NULL
);

CREATE TABLE bugs (
	bug_id SERIAL PRIMARY KEY,
	bug_name VARCHAR(100) NOT NULL,
	is_fixed BOOL NOT NULL,
	started DATE, NOT NULL,
	ended DATE,
	tester_id INT NOT NULL,
	crit_id INT NOT NULL,
	FOREIGN KEY (tester_id) REFERENCES tester(tester_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (crit_id) REFERENCES crit_level(crit_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_bug (
	project_id SERIAL PRIMARY KEY,
	bug_id SERIAL PRIMARY KEY,
	FOREIGN KEY (project_id) REFERENCES project(project_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (bug_id) REFERENCES bugs(bug_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE bug_developer (
	bug_id SERIAL PRIMARY KEY,
	developer_id SERIAL PRIMARY KEY,
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (bug_id) REFERENCES bugs(bug_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_developer (
	project_id SERIAL PRIMARY KEY,
	developer_id SERIAL PRIMARY KEY,
	FOREIGN KEY (project_id) REFERENCES project(project_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE project_features (
	project_id SERIAL PRIMARY KEY,
	features_id SERIAL PRIMARY KEY,
	FOREIGN KEY (project_id) REFERENCES project(project_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (feature_id) REFERENCES features(feature_id) ON DELETE RESTRICT ON UPDATE CASCADE
);

CREATE TABLE developer_features (
	developer_id SERIAL PRIMARY KEY,
	features_id SERIAL PRIMARY KEY,
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	FOREIGN KEY (feature_id) REFERENCES features(feature_id) ON DELETE RESTRICT ON UPDATE CASCADE
);