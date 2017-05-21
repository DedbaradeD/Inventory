#include "inventorytable.h"

#include <QTableWidget>
#include <QDragEnterEvent>

InventoryTable::InventoryTable(int rows, int columns)
    :QTableWidget(rows, columns)
{
    _tableRows = rows;
    _tableColumns = columns;
}


void InventoryTable::dragEnterEvent(QDragEnterEvent *event)
{
    QTableWidget::dragEnterEvent(event);
}

void InventoryTable::dragMoveEvent(QDragMoveEvent *event)
{
    QTableWidget::dragMoveEvent(event);
}

void InventoryTable::dragLeaveEvent(QDragLeaveEvent *event)
{
    QTableWidget::dragLeaveEvent(event);
}

void InventoryTable::dropEvent(QDropEvent *event)
{
   QTableWidget::dropEvent(event);
}
