#include "loginform.h"
#include "ui_loginform.h"
#include "registrationform.h"
#include "usermanager.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_toRegisterButton_clicked()
{
    registrationform *registerForm = new registrationform();
    registerForm->show();
    this->close();
}


void LoginForm::on_loginButton_clicked()
{
    QString email = ui->emailLineEdit->text();
        QString password = ui->passwordLineEdit->text();

        if (userManager.loginUser(email, password)) {
            qDebug() << "Login successful.";
            UserMainForm *userMainForm = new UserMainForm();
            userMainForm->show();
            userMainForm->displayMessages();
            this->close();
        } else {
            QMessageBox::warning(this, "Ошибка входа", "Неудачная попытка входа. \nПроверьте адрес и пароль.");
        }
}

