#include "usermainform.h"
#include "ui_usermainform.h"
#include "loginform.h"
#include "messageform.h"
#include "searchform.h"

UserMainForm::UserMainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserMainForm)
{
    ui->setupUi(this);
    ui->messagesTable->setColumnCount(4);
    ui->messagesTable->setHorizontalHeaderLabels({"Тема письма", "Получатель", "Содержание", "Дата"});
    displayMessages();
    ui->mail_label->setText(userManager.getCurrentUserEmail());
}

UserMainForm::~UserMainForm()
{
    delete ui;
}

void UserMainForm::on_logoutButton_clicked()
{
    this->close();
    LoginForm *loginForm = new LoginForm();
    loginForm->show();
}

void UserMainForm::on_messagesTable_cellDoubleClicked(int row, int column)
{
    QString text = ui->messagesTable->item(row, 2)->text();
    QMessageBox::information(this, "Message Text", text);
}

void UserMainForm::on_pushButton_clicked()
{
    this->close();
    MessageForm *messageForm = new MessageForm();
    messageForm->show();
}

void UserMainForm::displayMessages()
{
    ui->messagesTable->clearContents();
    ui->messagesTable->setRowCount(0);

    QList<QStringList> messages = userManager.getMessagesForUser(userManager.getCurrentUserEmail());

    for (const auto &message : messages)
    {
        int rowPosition = ui->messagesTable->rowCount();
        ui->messagesTable->insertRow(rowPosition);

        for (int i = 0; i < message.size(); ++i)
        {
            QTableWidgetItem *item = new QTableWidgetItem(message.at(i));
            ui->messagesTable->setItem(rowPosition, i, item);
        }
    }
}

void UserMainForm::on_pushButton_2_clicked()
{
    this->close();
    SearchForm *searchForm = new SearchForm();
    searchForm->show();
}


void UserMainForm::on_deleteButton_clicked()
{
    int selectedRow = ui->messagesTable->currentRow();
        if (selectedRow >= 0)
        {
            QString subject = ui->messagesTable->item(selectedRow, 0)->text();
            userManager.deleteMessage(userManager.getCurrentUserEmail(), subject);
            displayMessages();
        }
}

