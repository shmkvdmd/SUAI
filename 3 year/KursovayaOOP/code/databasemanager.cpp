#include "databasemanager.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QDateTime>

DatabaseManager::DatabaseManager(const QString &dbName,
                                 const QString &dbType,
                                 const QString &hostName,
                                 int port,
                                 const QString &userName,
                                 const QString &password)
{
    m_database = QSqlDatabase::addDatabase(dbType);
            m_database.setDatabaseName(dbName);
            m_database.setHostName(hostName);
            m_database.setPort(port);
            m_database.setUserName(userName);
            m_database.setPassword(password);
            if (!m_database.open()) {
                        qDebug() << "Cannot open database:" << m_database.lastError().text();
                    } else {
                        qDebug() << "Database opened successfully.";
                        createUserTable();
                    }
}

bool DatabaseManager::openDatabase()
{
    if (!m_database.open()) {
                qDebug() << "Ошибка подключения к базе данных:" << m_database.lastError().text();
                return false;
            }

            qDebug() << "Успешное подключение к базе данных";
            createUserTable();
            return true;
}

bool DatabaseManager::createUserTable()
{
    QSqlQuery query;
    return query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT, password TEXT)");
}
void DatabaseManager::closeDatabase()
{
    m_database.close();
}

bool DatabaseManager::createUser(const User& user)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (name, email, password) VALUES (:name, :email, :password)");
    query.bindValue(":name", user.getName());
    query.bindValue(":email", user.getEmail());
    query.bindValue(":password", user.getPassword());

    if (!query.exec()) {
        return false;
    }

    return true;
}
