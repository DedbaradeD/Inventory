#ifndef DATABASEINVENTORY_H
#define DATABASEINVENTORY_H

#include <QtSql/QSqlDatabase>

class DataBaseInventory
{
public:
    DataBaseInventory();

    void addObjectInventory(QString);

private:
    QSqlDatabase _database;
};

#endif // DATABASEINVENTORY_H
