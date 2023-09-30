#include "observer.h"
#include <QDebug>

Observer::Observer(QObject *parent) : QObject(parent)
{
}

void Observer::observeDataDeletion(const QModelIndex& index, const QVariant& deletedData)
{
    emit dataDeleted(index, deletedData);
}

