#ifndef INVENTORYTABLE_H
#define INVENTORYTABLE_H

#include <QTableWidget>

class QString;

class InventoryTable : public QTableWidget
{
public:
    InventoryTable(int, int);

private:
    int _tableRows;
    int _tableColumns;
    int _objectCount;
    QString _objectType;

private slots:
    void dragEnterEvent(QDragEnterEvent*);
    void dropEvent(QDropEvent*);
    void dragMoveEvent(QDragMoveEvent*);
    void dragLeaveEvent(QDragLeaveEvent*);
};

#endif // INVENTORYTABLE_H
