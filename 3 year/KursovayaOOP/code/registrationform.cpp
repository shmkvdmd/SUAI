#include "registrationform.h"
#include "ui_registrationform.h"
#include "usermanager.h"

registrationform::registrationform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registrationform)
{
    ui->setupUi(this);
}

registrationform::~registrationform()
{
    delete ui;
}

void registrationform::on_registerButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
        UserManager& userManager = UserManager::instance();
        if (!name.isEmpty() && !email.isEmpty() && !password.isEmpty())
        {
            if (userManager.createUser(name, email, password)) {
                QMessageBox::information(this, "Регистрация", "Пользователь успешно зарегистрирован.");
                LoginForm *loginForm = new LoginForm();
                loginForm->show();
                this->close();
            } else {
                QMessageBox::warning(this, "Ошибка регистрации", "Неудачная попытка регистрации.\nПопробуйте еще раз");
            }
        }
        else
        {
            QMessageBox::warning(this, "Ошибка регистрации", "Необходимо заполнить все поля");
        }
}


void registrationform::on_pushButton_clicked()
{
    LoginForm *loginForm = new LoginForm();
    loginForm->show();
    this->close();
}

