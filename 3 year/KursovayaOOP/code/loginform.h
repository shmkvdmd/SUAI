#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include "usermanager.h"
#include "usermainform.h"
namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_toRegisterButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::LoginForm *ui;
    UserManager& userManager = UserManager::instance();
};

#endif // LOGINFORM_H
