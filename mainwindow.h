#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "zorkul.h"
#include "character.h"

namespace Ui { //Namespaces!
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    friend class Character;
    friend class Room;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void overencumberedTest();
    void allRoomItemsCollectedTest();
    void disableAllButtons();
    void addItemsToListWidget(vector<Item> item);
    string displayStamina();
    struct GameStatus { //Bit Structures!
        bool EndGame : 1;
        bool OnGoing : 1;
    } gameStatus;
    void printCharacterStats();
    void endGameState(string message1, string message2);

private:
    Ui::MainWindow *ui;
    ZorkUL *zork = new ZorkUL();
    Character character = *new Character("The detective");
    bool putInInventory;
    void goRoom(string direction);
    void listItems(vector<Item> items, QString description);

private slots:
    void on_southButton_clicked();
    void on_westButton_clicked();
    void on_northButton_clicked();
    void on_eastButton_clicked();
    void on_teleportButton_clicked();
    void on_viewCharInfo_clicked();
    void on_help_clicked();
    void on_viewMap_clicked();
    void on_viewRoomItems_clicked();
    void on_viewCharItems_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_selectSuspect1_clicked();
    void on_selectSuspect2_clicked();
};

#endif
