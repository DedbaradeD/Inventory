#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QTableWidget;
class InventoryTable;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *_exitBtn;
    QPushButton *_mainMenuBtn;
    QPushButton *_newGameBtn;
    InventoryTable *_inventoryTable;
    QWidget *_topMenuWdg;
    QWidget *_centralWdg;

    void initializeUi(QMainWindow*);

private slots:
    void mainMenuBtnClicked();
    void newGameBtnClicked();
};

#endif // MAINWINDOW_H
