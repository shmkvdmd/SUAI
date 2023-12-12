#include "messageform.h"
#include "ui_messageform.h"
#include "usermainform.h"
MessageForm::MessageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageForm)
{
    ui->setupUi(this);
}

MessageForm::~MessageForm()
{
    delete ui;
}

void MessageForm::on_pushButton_clicked()
{
    UserMainForm *userMainForm = new UserMainForm();
    userMainForm->show();
    this->close();
}


void MessageForm::on_sendButton_clicked()
{
    QString recipient = ui->recipientLineEdit->text();
    QString subject = ui->subjectLineEdit->text();
    QString text = ui->textEdit->toPlainText();
    if (recipient.isEmpty() || subject.isEmpty() || text.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля перед отправкой сообщения.");
            return;
        }
    DatabaseManager databaseManager;
    if (databaseManager.createMessage(subject, recipient, text))
        {
            QMessageBox::information(this, "Успех", "Сообщение успешно отправлено.");
            this->close();
            UserMainForm *userMainForm = new UserMainForm();
            userMainForm->show();
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось отправить сообщение. Пожалуйста, попробуйте еще раз.");
        }
}

