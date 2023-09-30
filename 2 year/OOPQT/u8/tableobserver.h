#ifndef TABLEOBSERVER_H
#define TABLEOBSERVER_H

#include <QObject>
#include <QModelIndex>
#include <QVariant>

class TableObserver : public QObject
{
    Q_OBJECT
public:
    explicit TableObserver(QObject *parent = nullptr);

signals:
    void dataDeleted(const QModelIndex& index, const QVariant& deletedData);

public slots:
    void observeDataDeletion(const QModelIndex& index, const QVariant& deletedData);
};

#endif // TABLEOBSERVER_H
