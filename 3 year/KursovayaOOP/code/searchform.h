#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>
#include "Includes.h"
#include "usermainform.h"
#include "usermanager.h"
namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = nullptr);
    ~SearchForm();

private slots:
    void on_searchButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::SearchForm *ui;
    UserManager& userManager = UserManager::instance();
};

#endif // SEARCHFORM_H
