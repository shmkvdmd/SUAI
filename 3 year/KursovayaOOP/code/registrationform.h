#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include "user.h"
#include "databasemanager.h"
#include "loginform.h"
namespace Ui {
class registrationform;
}

class registrationform : public QWidget
{
    Q_OBJECT

public:
    explicit registrationform(QWidget *parent = nullptr);
    ~registrationform();

private slots:
    void on_registerButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::registrationform *ui;
};

#endif // REGISTRATIONFORM_H
