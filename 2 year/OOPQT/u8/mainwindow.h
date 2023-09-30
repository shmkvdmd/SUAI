#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <tablesnapshot.h>
#include <QFile>
#include <observer.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void on_tableView_2_clicked(const QModelIndex &index);

    void setupTable();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void updateDateTime();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_Send_clicked();

    void on_tableView_3_doubleClicked(const QModelIndex &index);
    void onDataDeleted(const QModelIndex& index, const QVariant& deletedData);

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QModelIndex selectedCellIndex;
    QStandardItemModel* model2;
    QStandardItemModel* model3;
    QString selectedSender;
    QString selectedRecipient;
    Observer *observer;
    QFile deletedDataFile;
};
#endif // MAINWINDOW_H
