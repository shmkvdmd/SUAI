#include "tableobserver.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TableObserver::TableObserver(QObject *parent) : QObject(parent)
{
}
void TableObserver::observeDataDeletion(const QModelIndex& index, const QVariant& deletedData)
{

}
