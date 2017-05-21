#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>

#include "inventoryobject.h"
#include "inventorytable.h"
#include "databaseinventory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initializeUi(this);
    connect(_exitBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(_mainMenuBtn, SIGNAL(clicked()), this, SLOT(mainMenuBtnClicked()));
    connect(_newGameBtn, SIGNAL(clicked()), this, SLOT(newGameBtnClicked()));
}

MainWindow::~MainWindow()
{

}

/*
 * инициализируем графику
*/
void MainWindow::initializeUi(QMainWindow *mainWindow)
{
    QWidget *mainWdg = new QWidget(mainWindow);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainWdg->setLayout(mainLayout);
    setCentralWidget(mainWdg);
    _topMenuWdg = new QWidget();
    QHBoxLayout *topMenuLayout = new QHBoxLayout();
    mainLayout->addWidget(_topMenuWdg);
    _topMenuWdg->setLayout(topMenuLayout);
    _newGameBtn = new QPushButton(tr("Новая игра"));
    _exitBtn = new QPushButton(tr("Выход"));
    topMenuLayout->addWidget(_newGameBtn);
    topMenuLayout->addWidget(_exitBtn);
    QVBoxLayout *rightAreaLayout = new QVBoxLayout();

    InventoryObject *objectApple = new InventoryObject("apple", QIcon(QPixmap(":/images/apple.png")));
    objectApple->setMaximumWidth(100);
    objectApple->setMaximumHeight(100);
    objectApple->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    objectApple->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    objectApple->verticalHeader()->hide();
    objectApple->horizontalHeader()->hide();
    objectApple->setDragEnabled(true);
    objectApple->setColumnWidth(0, 100);
    objectApple->setRowHeight(0, 100);
    objectApple->setIconSize(QSize(92, 92));
    objectApple->setDragDropOverwriteMode(true);
    objectApple->setDropIndicatorShown(true);

    DataBaseInventory inventoryDb;
    inventoryDb.addObjectInventory("apple");

    _mainMenuBtn = new QPushButton(tr("Главное меню"));
    rightAreaLayout->addWidget(objectApple);
    rightAreaLayout->addWidget(_mainMenuBtn);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    rightAreaLayout->layout()->setSizeConstraint(QLayout::SetFixedSize);

    _inventoryTable = new InventoryTable(3, 3);
    _inventoryTable->setMinimumWidth(300);
    _inventoryTable->setMinimumHeight(300);
    _inventoryTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _inventoryTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _inventoryTable->verticalHeader()->hide();
    _inventoryTable->horizontalHeader()->hide();
    _inventoryTable->setDragDropMode(QAbstractItemView::DragDrop);
    _inventoryTable->setColumnWidth(0, 100);
    _inventoryTable->setColumnWidth(1, 100);
    _inventoryTable->setColumnWidth(2, 100);
    _inventoryTable->setRowHeight(0, 100);
    _inventoryTable->setRowHeight(1, 100);
    _inventoryTable->setRowHeight(2, 100);
    _inventoryTable->setIconSize(QSize(92, 92));
    _inventoryTable->setDragDropOverwriteMode(true);
    _inventoryTable->setDropIndicatorShown(true);

    QHBoxLayout *centralLayout = new QHBoxLayout();
    centralLayout->addWidget(_inventoryTable);
    centralLayout->addLayout(rightAreaLayout);
    _centralWdg = new QWidget();
    _centralWdg->setLayout(centralLayout);
    mainLayout->addWidget(_centralWdg);
    _centralWdg->setDisabled(true);
}

/*
 * переходим в главное меню
*/
void MainWindow::mainMenuBtnClicked()
{
    _topMenuWdg->show();
    _centralWdg->setDisabled(true);
}

/*
 * начинаем новую игру
*/
void MainWindow::newGameBtnClicked()
{
    _centralWdg->setEnabled(true);
    _topMenuWdg->hide();
    _inventoryTable->clear();
}
