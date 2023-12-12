#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include"includes.h"
class DatabaseManager
{
public:
    DatabaseManager(const QString &dbName = "oopdatabaseMail.db",
                    const QString &dbType = "QSQLITE",
                    const QString &hostName = "localhost",
                    int port = 5432,
                    const QString &userName = "",
                    const QString &password = "") {

        // Инициализация базы данных
        db = QSqlDatabase::addDatabase(dbType);
        db.setDatabaseName(dbName);
        db.setHostName(hostName);
        db.setPort(port);
        db.setUserName(userName);
        db.setPassword(password);

        // Подключение к базе данных
        if (!db.open()) {
            qDebug() << "Cannot open database:" << db.lastError().text();
        } else {
            qDebug() << "Database opened successfully.";
           createTable();
        }
    }
    void createTable() {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT, password TEXT)");
        query.exec("CREATE TABLE IF NOT EXISTS messages (id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER, subject TEXT, recipient TEXT, text TEXT, date TEXT)");
    }
    bool createMessage(const QString &subject, const QString &recipient, const QString &text)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO messages (subject, recipient, text, date) VALUES (:subject, :recipient, :text, CURRENT_TIMESTAMP)");
        query.bindValue(":subject", subject);
        query.bindValue(":recipient", recipient);
        query.bindValue(":text", text);

        return query.exec();
    }


    ~DatabaseManager() {
        db.close();
    }
    void closeDatabase()
    {
        db.close();
    }

    bool isDatabaseOpen() const {
        return db.isOpen();
    }
    bool createUser(const User& user, const QString& hashedPassword) {
        QSqlQuery query;
        query.prepare("INSERT INTO users (name, email, password) VALUES (:name, :email, :password)");
        query.bindValue(":name", user.getName());
        query.bindValue(":email", user.getEmail());
        query.bindValue(":password", hashedPassword);

        if (query.exec()) {
            qDebug() << "User added successfully.";
            return true;
        } else {
            qDebug() << "Error adding user:" << query.lastError().text();
            return false;
        }
    }
    QSqlDatabase getDB(){
        return db;
    }
    bool doesUserExist(const QString &email, const QString &hashedPassword)
    {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM users WHERE email = :email AND password = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", hashedPassword);

        if (query.exec() && query.next())
        {
            return query.value(0).toInt() > 0;
        }
        else
        {
            qDebug() << "Error checking user existence:" << query.lastError().text();
            return false;
        }
    }

    User getUserByEmail(const QString &email)
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE email = :email");
        query.bindValue(":email", email);

        if (query.exec() && query.next())
        {
            QString name = query.value("name").toString();
            QString password = query.value("password").toString();
            return User(name, email, password);
        }
        else
        {
            qDebug() << "Error getting user by email:" << query.lastError().text();
            return User("", "", "");
        }
    }
    QList<QStringList> getMessagesForUser(const QString &email)
    {
        QList<QStringList> messages;

        QSqlQuery query;
        query.prepare("SELECT * FROM messages WHERE recipient = :recipient");
        query.bindValue(":recipient", email);

        if (query.exec())
        {
            while (query.next())
            {
                QStringList message;
                message << query.value("subject").toString()
                        << query.value("recipient").toString()
                        << query.value("text").toString()
                        << query.value("date").toString();

                messages.append(message);
            }
        }
        else
        {
            qDebug() << "Error getting messages for user:" << query.lastError().text();
        }
        return messages;
    }

    QList<QStringList> searchMessagesBySubject(const QString &email, const QString &subject)
    {
        QList<QStringList> messages;

        QSqlQuery query;
        query.prepare("SELECT * FROM messages WHERE recipient = :recipient AND subject LIKE :subject");
        query.bindValue(":recipient", email);
        query.bindValue(":subject", "%" + subject + "%");  // Используйте LIKE для частичного совпадения темы

        if (query.exec())
        {
            while (query.next())
            {
                QStringList message;
                message << query.value("subject").toString()
                        << query.value("recipient").toString()
                        << query.value("text").toString()
                        << query.value("date").toString();

                messages.append(message);
            }
        }
        else
        {
            qDebug() << "Error searching messages by subject:" << query.lastError().text();
        }

        return messages;
    }
    bool deleteMessage(const QString &email, const QString &subject)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM messages WHERE recipient = :recipient AND subject = :subject");
        query.bindValue(":recipient", email);
        query.bindValue(":subject", subject);

        return query.exec();
    }


private:

    QSqlDatabase db;
};
#endif // DATABASEMANAGER_H
