#ifndef INVENTORYOBJECT_H
#define INVENTORYOBJECT_H

#include <QTableWidget>

class InventoryObject : public QTableWidget
{
public:
    InventoryObject(QString, QIcon);
    ~InventoryObject();

private:
    QString _typeObject;
    QIcon _iconObject;
    QTableWidgetItem *_itemApple;
};

#endif // INVENTORYOBJECT_H
