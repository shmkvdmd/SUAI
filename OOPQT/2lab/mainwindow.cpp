#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int price = 850000, discount, all = 0,detail1 = 15000, detail2 = 10000,detail3 = 50000, car = 850000;
    int count = 0;
    QString strcar, strdetails, strall, strdiscount;
    if (ui -> checkBox -> isChecked())
    {
        price += detail1;
        all += detail1;
        ui->label_5->setVisible(true);
    }
    if (ui -> checkBox_2 -> isChecked())
    {
        price += detail2;
        all += detail2;
        ui->label_6->setVisible(true);
    }
    if (ui -> checkBox_3 -> isChecked())
    {
        price += detail3;
        all += detail3;
        ui->label_7->setVisible(true);
    }
    if (ui -> checkBox->isChecked() && ui -> checkBox_2 -> isChecked() && ui -> checkBox_3 -> isChecked())
    {
        strcar.setNum(car);
        strdetails.setNum(all);
        discount = price*0.1;
        price = price - (price*0.1);
        strdiscount.setNum(discount);
        strall.setNum(price);
        ui -> label_4 -> setText("Стоимость машины "+strcar+"\nСтоимость деталей " + strdetails + "\nИтоговая стоимость " + strall + "\nПрименена скидка 10% " + strdiscount);
    }
    else
        {
            strcar.setNum(car);
            strdetails.setNum(all);
            strall.setNum(price);
            ui -> label_4 -> setText("Стоимость машины "+strcar+"\nСтоимость деталей " + strdetails + "\nИтоговая стоимость " + strall);
         }
}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    ui -> label_4 -> clear();
    ui->label_6->setVisible(false);
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    ui -> label_4 -> clear();
    ui->label_5->setVisible(false);
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    ui -> label_4 -> clear();
    ui->label_7->setVisible(false);
}

