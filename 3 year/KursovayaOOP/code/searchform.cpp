#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Тема", "Получатель", "Содержание", "Дата"});
}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::on_searchButton_clicked()
{
    QString subject = ui->subjectLineEdit->text();
    QList<QStringList> searchResults = userManager.searchMessagesBySubject(userManager.getCurrentUserEmail(), subject);

    for (const auto &message : searchResults)
    {
        int rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);

        for (int i = 0; i < message.size(); ++i)
        {
            QTableWidgetItem *item = new QTableWidgetItem(message.at(i));
            ui->tableWidget->setItem(rowPosition, i, item);
        }
    }
}


void SearchForm::on_pushButton_2_clicked()
{
    UserMainForm *userMainForm = new UserMainForm();
    userMainForm->show();
    this->close();
}


void SearchForm::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString text = ui->tableWidget->item(row, 2)->text();
    QMessageBox::information(this, "Message Text", text);
}

