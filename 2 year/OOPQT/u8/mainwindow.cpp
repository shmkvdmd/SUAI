#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndexList>
#include <QMessageBox>
#include <tablesnapshot.h>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <observer.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupTable();
    observer = new Observer(this);
    connect(observer, &Observer::dataDeleted, this, &MainWindow::onDataDeleted);
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[а-яА-ЯёЁ]+"), this);
    QRegularExpressionValidator *validatorn = new QRegularExpressionValidator(QRegularExpression("[0-9]*"), this);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_3->setMaxLength(11);
    ui->lineEdit_7->setMaxLength(11);
    ui->lineEdit_3->setValidator(validatorn);
    ui->lineEdit_7->setValidator(validatorn);
}

MainWindow::~MainWindow()
{
    delete ui;
    deletedDataFile.close();
}



void MainWindow::onDataDeleted(const QModelIndex& index, const QVariant& deletedData)
{
    QString message = "Запись удалена";
    QMessageBox::information(this, "Удаление записи", message);
}
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_7_clicked()
{
    QString name = ui->lineEdit->text();
        QString address = ui->lineEdit_2->text();
        QString phone = ui->lineEdit_3->text();

        // Проверка заполнения всех полей
        if (name.isEmpty() || address.isEmpty() || phone.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля.");
            return;
        }

        QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
        if (model)
        {
            int rowCount = model->rowCount();
            model->insertRow(rowCount);

            QModelIndex indexName = model->index(rowCount, 0);
            model->setData(indexName, name);

            QModelIndex indexAddress = model->index(rowCount, 1);
            model->setData(indexAddress, address);

            QModelIndex indexPhone = model->index(rowCount, 2);
            model->setData(indexPhone, phone);
        }

        // Очистка полей после добавления данных
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->comboBox->clear(); // Очищаем комбобокс
        QAbstractItemModel* senderModel = ui->tableView->model();
        if (senderModel) {
            QStringList senderList;
            int rowCount = senderModel->rowCount();
            for (int row = 0; row < rowCount; ++row) {
                QModelIndex indexName = senderModel->index(row, 0);
                QVariant dataName = senderModel->data(indexName);

                QModelIndex indexPhone = senderModel->index(row, 2);
                QVariant dataPhone = senderModel->data(indexPhone);

                QString senderData = QString("%1, %2").arg(dataName.toString(), dataPhone.toString());
                senderList << senderData;
            }
            ui->comboBox->addItems(senderList);
        }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    selectedCellIndex = index;  // Обновление выбранного индекса ячейки
    QAbstractItemModel* model = ui->tableView->model();
    if (model) {
        QVariant data = model->data(index);
        ui->lineEdit_4->setText(data.toString());

        // Обновление выбранного отправителя в комбобоксе
        int senderRow = index.row();
        if (senderRow >= 0 && senderRow < ui->comboBox->count()) {
            ui->comboBox->setCurrentIndex(senderRow);
        }
    }
}


void MainWindow::setupTable()
{
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList() << "Имя" << "Адрес" << "Телефон");
    ui->tableView->setModel(model);

    QStandardItemModel* model2 = new QStandardItemModel(this);
    model2->setHorizontalHeaderLabels(QStringList() << "Имя" << "Адрес" << "Телефон");
    ui->tableView_2->setModel(model2);
    ui->safeModeCheckBox->setChecked(false);
    // Создание QTimer
    QTimer* timer = new QTimer(this);

    // Подключение слота обновления времени к сигналу QTimer::timeout()
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDateTime);

    // Установка интервала обновления времени (например, каждую секунду)
    int updateInterval = 1000; // 1 секунда
    timer->start(updateInterval);
    QStandardItemModel* model3 = new QStandardItemModel(this);
    model3->setColumnCount(4);
    model3->setHorizontalHeaderLabels(QStringList() << "Отправил" << "Получил" << "Тема" << "Текст");
    ui->tableView_3->setModel(model3);

    QAbstractItemModel* senderModel = ui->tableView->model();
        if (senderModel) {
            QStringList senderList;
            int rowCount = senderModel->rowCount();
            for (int row = 0; row < rowCount; ++row) {
                QModelIndex indexName = senderModel->index(row, 0);
                QVariant dataName = senderModel->data(indexName);

                QModelIndex indexPhone = senderModel->index(row, 2);
                QVariant dataPhone = senderModel->data(indexPhone);

                QString senderData = QString("%1, %2").arg(dataName.toString(), dataPhone.toString());
                senderList << senderData;
            }
            ui->comboBox->addItems(senderList);
        }

        // Заполнение comboBox_2 данными из таблицы получателей
        QAbstractItemModel* receiverModel = ui->tableView_2->model();
        if (receiverModel) {
            QStringList receiverList;
            int rowCount = receiverModel->rowCount();
            for (int row = 0; row < rowCount; ++row) {
                QModelIndex indexName = receiverModel->index(row, 0);
                QVariant dataName = receiverModel->data(indexName);

                QModelIndex indexPhone = receiverModel->index(row, 2);
                QVariant dataPhone = receiverModel->data(indexPhone);

                QString receiverData = QString("%1, %2").arg(dataName.toString(), dataPhone.toString());
                receiverList << receiverData;
            }
            ui->comboBox_2->addItems(receiverList);
        }


}



void MainWindow::updateDateTime()
{
    // Получение текущей даты и времени
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Форматирование даты и времени (вы можете настроить формат согласно вашим требованиям)
    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

    // Установка отформатированной даты и времени в QLabel
    ui->dateTimeLabel->setText(formattedDateTime);
}


void MainWindow::on_pushButton_8_clicked()
{
    QString newValue = ui->lineEdit_4->text();
    QAbstractItemModel* model = ui->tableView->model();
    if (model && selectedCellIndex.isValid()) {

        model->setData(selectedCellIndex, newValue);
        ui->lineEdit_4->clear();
    }
}




void MainWindow::on_pushButton_9_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (currentIndex.isValid()) {
        QAbstractItemModel* model = ui->tableView->model();
        if (model) {
            if (ui->safeModeCheckBox->isChecked()) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Подтвердите действие", "Вы действительно хотите удалить выбранную строку?",
                                              QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) {
                    return;
                }
            }
            observer->observeDataDeletion(currentIndex, model->data(currentIndex));

            model->removeRow(currentIndex.row());

            ui->comboBox->clear();
            QAbstractItemModel* senderModel = ui->tableView->model();
            if (senderModel) {
                QStringList senderList;
                int rowCount = senderModel->rowCount();
                for (int row = 0; row < rowCount; ++row) {
                    QModelIndex indexName = senderModel->index(row, 0);
                    QVariant dataName = senderModel->data(indexName);

                    QModelIndex indexPhone = senderModel->index(row, 2);
                    QVariant dataPhone = senderModel->data(indexPhone);

                    QString senderData = QString("%1, %2").arg(dataName.toString(), dataPhone.toString());
                    senderList << senderData;
                }
                ui->comboBox->addItems(senderList);
            }
        }
    }
}



void MainWindow::on_pushButton_12_clicked()
{
    QString name = ui->lineEdit_5->text();
        QString address = ui->lineEdit_6->text();
        QString phone = ui->lineEdit_7->text();

        // Проверка заполнения всех полей
        if (name.isEmpty() || address.isEmpty() || phone.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля.");
            return;
        }

        QStandardItemModel* model2 = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());
        if (model2)
        {
            int rowCount = model2->rowCount();
            model2->insertRow(rowCount);

            QModelIndex indexName = model2->index(rowCount, 0);
            model2->setData(indexName, name);

            QModelIndex indexAddress = model2->index(rowCount, 1);
            model2->setData(indexAddress, address);

            QModelIndex indexPhone = model2->index(rowCount, 2);
            model2->setData(indexPhone, phone);
        }

        // Очистка полей после добавления данных
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->comboBox_2->clear(); // Очищаем комбобокс
        QAbstractItemModel* receiverModel = ui->tableView_2->model();
        if (receiverModel) {
            QStringList receiverList;
            int rowCount = receiverModel->rowCount();
            for (int row = 0; row < rowCount; ++row) {
                QModelIndex indexName = receiverModel->index(row, 0);
                QVariant dataName = receiverModel->data(indexName);

                QModelIndex indexPhone = receiverModel->index(row, 2);
                QVariant dataPhone = receiverModel->data(indexPhone);

                QString receiverData = QString("%1, %2").arg(dataName.toString(), dataPhone.toString());
                receiverList << receiverData;
            }
            ui->comboBox_2->addItems(receiverList);
        }
}


void MainWindow::on_pushButton_10_clicked()
{
    QString newValue = ui->lineEdit_8->text();
    QAbstractItemModel* model2 = ui->tableView_2->model();
    if (model2 && selectedCellIndex.isValid()) {

        model2->setData(selectedCellIndex, newValue);
        ui->lineEdit_8->clear();
    }
}
void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    selectedCellIndex = index;  // Обновление выбранного индекса ячейки
    QAbstractItemModel* model2 = ui->tableView_2->model();
    if (model2) {
        QVariant data = model2->data(index);
        ui->lineEdit_8->setText(data.toString());

        // Обновление выбранного получателя в комбобоксе
        int receiverRow = index.row();
        if (receiverRow >= 0 && receiverRow < ui->comboBox_2->count()) {
            ui->comboBox_2->setCurrentIndex(receiverRow);
        }
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    // Получение индекса выбранной строки
        QModelIndex currentIndex = ui->tableView_2->currentIndex();
        if (currentIndex.isValid()) {
            // Получение модели данных таблицы
            QAbstractItemModel* model2 = ui->tableView_2->model();
            if (model2) {
                // Проверка состояния безопасного режима
                if (ui->safeModeCheckBox->isChecked()) {
                    // Отображение диалогового окна для подтверждения действия
                    QMessageBox::StandardButton reply;
                    reply = QMessageBox::question(this, "Подтвердите действие", "Вы действительно хотите удалить выбранную строку?",
                                                  QMessageBox::Yes | QMessageBox::No);
                    if (reply == QMessageBox::No) {
                        return; // Отмена удаления
                    }
                }
                observer->observeDataDeletion(currentIndex, model2->data(currentIndex));
                // Удаление выбранной строки
                model2->removeRow(currentIndex.row());
                ui->comboBox_2->clear();

                            // Заполнение комбобокса данными из модели таблицы
                            QAbstractItemModel* receiverModel = ui->tableView_2->model();
                            if (receiverModel) {
                                QStringList receiverList;
                                int rowCount = receiverModel->rowCount();
                                for (int row = 0; row < rowCount; ++row) {
                                    QModelIndex indexName = receiverModel->index(row, 0);
                                    QVariant dataName = receiverModel->data(indexName);

                                    QModelIndex indexPhone = receiverModel->index(row, 2);
                                    QVariant dataPhone = receiverModel->data(indexPhone);

                                    QString receiverData = QString("%1, %2").arg(dataName.toString(), dataPhone.toString());
                                    receiverList << receiverData;
                                }
                                ui->comboBox_2->addItems(receiverList);
                            }
            }
        }
}


void MainWindow::on_pushButton_Send_clicked()
{
    QString sender = ui->comboBox->currentText();
        QString receiver = ui->comboBox_2->currentText();
        QString subject = ui->lineEdit_Subject->text();
        QString message = ui->textEdit_Message->toPlainText();

        // Проверка заполнения всех полей
        if (sender.isEmpty() || receiver.isEmpty() || subject.isEmpty() || message.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля.");
            return;
        }

        QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_3->model());
        if (model)
        {
            int rowCount = model->rowCount();
            model->insertRow(rowCount);

            QModelIndex indexSender = model->index(rowCount, 0);
            model->setData(indexSender, sender);

            QModelIndex indexReceiver = model->index(rowCount, 1);
            model->setData(indexReceiver, receiver);

            QModelIndex indexSubject = model->index(rowCount, 2);
            model->setData(indexSubject, subject);

            QModelIndex indexMessage = model->index(rowCount, 3);
            model->setData(indexMessage, message);
        }

        // Очистка полей после отправки письма
        ui->comboBox->setCurrentIndex(0);
        ui->comboBox_2->setCurrentIndex(0);
        ui->lineEdit_Subject->clear();
        ui->textEdit_Message->clear();
}


void MainWindow::on_tableView_3_doubleClicked(const QModelIndex &index)
{
    // Проверка столбца "Текст"
        if (index.column() == 3)
        {
            // Получение модели данных таблицы
            QAbstractItemModel* model = ui->tableView_3->model();
            if (model)
            {
                QVariant data = model->data(index);

                // Отображение окна с текстом письма
                QMessageBox::information(this, "Текст письма", data.toString());
            }
        }
}

