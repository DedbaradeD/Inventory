#include "inventoryobject.h"

InventoryObject::InventoryObject(QString typeObject, QIcon iconObject)
    :QTableWidget(1, 1)
{
    _typeObject = typeObject;
    _iconObject = iconObject;
    _itemApple = new QTableWidgetItem();
    _itemApple->setIcon(_iconObject);
    setItem(0, 0, _itemApple);
}

InventoryObject::~InventoryObject()
{
    delete _itemApple;
}
