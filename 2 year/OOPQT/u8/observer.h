#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>
#include <QModelIndex>
#include <QVariant>

class Observer : public QObject
{
    Q_OBJECT
public:
    explicit Observer(QObject *parent = nullptr);

signals:
    void dataDeleted(const QModelIndex& index, const QVariant& deletedData);

public slots:
    void observeDataDeletion(const QModelIndex& index,const QVariant& deletedData);
};

#endif // OBSERVER_H
