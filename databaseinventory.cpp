#include "databaseinventory.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DataBaseInventory::DataBaseInventory()
{
    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("database_inventory.sqlite");
    if(!_database.open())
    {
        qDebug() << _database.lastError().text();
    }
}

/*
 * добавляем в базу данных предмет(яблоко)
*/
void DataBaseInventory::addObjectInventory(QString type)
{
    QSqlQuery checkObject;
    checkObject.prepare("SELECT type FROM object");
    checkObject.exec();
    if(checkObject.value(0).toString() != "apple")
    {
        QSqlQuery addObject;
        addObject.prepare("INSERT INTO object (type) VALUES(:type);");
        addObject.bindValue(":type", type);
        addObject.exec();
    }
}
