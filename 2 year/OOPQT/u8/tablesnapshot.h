#ifndef TABLESNAPSHOT_H
#define TABLESNAPSHOT_H

#include <QStandardItemModel>
#include <stack>

class TableSnapshot
{
public:
    TableSnapshot(QStandardItemModel* model);
    ~TableSnapshot();

    void takeSnapshot();
    void restoreModel(QStandardItemModel* model);
    void clearSnapshots();

private:
    void cloneModel(QStandardItemModel* sourceModel, QStandardItemModel* targetModel);

    QStandardItemModel* model;
    std::stack<QStandardItemModel*> snapshots;
};

#endif // TABLESNAPSHOT_H
