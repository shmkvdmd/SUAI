#include "usermanager.h"
#include <QCryptographicHash>

bool UserManager::createUser(const QString& name, const QString& email, const QString& password) {
    QString hashedPassword = hashPassword(password);
    User newUser(name, email, hashedPassword);
    return databaseManager.createUser(newUser, hashedPassword);
}

bool UserManager::loginUser(const QString& email, const QString& password) {
    QString hashedPassword = hashPassword(password);
    if (databaseManager.doesUserExist(email, hashedPassword))
        {
            currentUserEmail = email;
            return true;
        }
        return false;
}

QString UserManager::hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

QList<QStringList> UserManager::getMessagesForUser(const QString &email)
{
    qDebug() << "Getting messages for user:" << email;
    QList<QStringList> messages = databaseManager.getMessagesForUser(email);
    return messages;
}

QList<QStringList> UserManager::searchMessagesBySubject(const QString &email,const QString &subject)
{
    QList<QStringList> messages = databaseManager.searchMessagesBySubject(email,subject);
    return messages;
}
bool UserManager::deleteMessage(const QString &email, const QString &subject)
{
    return databaseManager.deleteMessage(email,subject);
}
QString UserManager::getCurrentUserEmail()
{
    return currentUserEmail;
}
