#ifndef USERMAINFORM_H
#define USERMAINFORM_H

#include <QWidget>
#include "Includes.h"
#include "usermanager.h"
#include "messageform.h"
namespace Ui {
class UserMainForm;
}

class UserMainForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserMainForm(QWidget *parent = nullptr);
    ~UserMainForm();
    void displayMessages();

private slots:
    void on_logoutButton_clicked();
    void on_messagesTable_cellDoubleClicked(int row, int column);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_deleteButton_clicked();

private:
    Ui::UserMainForm *ui;
    UserManager& userManager = UserManager::instance();
    QString currentUserEmail;
};

#endif // USERMAINFORM_H
