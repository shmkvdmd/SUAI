#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator* valid = new QIntValidator(-100, 100, this);
    valid ->setLocale(QLocale::English);
    ui->lineEdit->setValidator(valid);
    ui->lineEdit_2->setValidator(valid);
    ui->lineEdit_3->setValidator(valid);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int dlina = ui->lineEdit->text().toInt();
    int shirina = ui->lineEdit_2->text().toInt();
    int price = ui->lineEdit_3->text().toInt();
    int newprice;
    QString dlin,shirin,money;
    newprice = price*dlina;
    if((ui->comboBox->currentIndex() == 1))
    {
        dlin.setNum(dlina);
        shirin.setNum(shirina);
        money.setNum(newprice);
        ui->label_5 -> setText(dlin + " метров ткани " + shirin + " в ширину, материал Шерсть\nОбойдется вам в " + money + " рублей");
    }
    if((ui->comboBox->currentIndex() == 2))
    {
        dlin.setNum(dlina);
        shirin.setNum(shirina);
        money.setNum(newprice);
        ui->label_5 -> setText(dlin + " метров ткани " + shirin + " в ширину, материал Ситец \nОбойдется вам в " + money + " рублей");
    }
    if((ui->comboBox->currentIndex() == 3))
    {
        dlin.setNum(dlina);
        shirin.setNum(shirina);
        money.setNum(newprice);
        ui->label_5 -> setText(dlin + " метров ткани " + shirin + " в ширину, материал Шелк \nОбойдется вам в " + money + " рублей");
    }
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->label_5->clear();
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->label_5->clear();
}


void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->label_5->clear();
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->label_5->clear();
}

