#include "user.h"

User::User(const QString& name, const QString& email, const QString& password)
    : m_name(name), m_email(email), m_password(password)
{
}

QString User::getName() const
{
    return m_name;
}

QString User::getEmail() const
{
    return m_email;
}

QString User::getPassword() const
{
    return m_password;
}
