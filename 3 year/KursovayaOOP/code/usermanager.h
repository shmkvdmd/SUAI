#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "user.h"
#include "databasemanager.h"
#include "Includes.h"

class UserManager
{
public:
    static UserManager& instance() {
            static UserManager instance;
            return instance;
        }
    bool createUser(const QString& name, const QString& email, const QString& password);
    bool loginUser(const QString& email, const QString& password);
    QList<QStringList> getMessagesForUser(const QString &email);
    QList<QStringList> searchMessagesBySubject(const QString &email,const QString &subject);
    bool deleteMessage(const QString &email, const QString &subject);
    QString getCurrentUserEmail();

private:
    DatabaseManager databaseManager;
    UserManager() {}
    QString hashPassword(const QString& password);
    QString currentUserEmail;
};

#endif // USERMANAGER_H
