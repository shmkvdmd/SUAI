#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(const QString& name, const QString& email, const QString& password);

    QString getName() const;
    QString getEmail() const;
    QString getPassword() const;

private:
    QString m_name;
    QString m_email;
    QString m_password;
};

#endif // USER_H
