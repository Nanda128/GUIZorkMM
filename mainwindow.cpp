#include "gameexception.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zorkul.h"
#include <algorithm>

template <typename T>
void addItem(vector<T> v, T t)
{
    v.push_back(t);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->staminaDisplay->setTextColor(QColor("green"));
    gameStatus.EndGame=0;
    gameStatus.OnGoing=1;
    ui->selectSuspect1->setEnabled(false);
    ui->selectSuspect2->setEnabled(false);
    ui->mainConsole->append(QString::fromStdString(zork->printWelcome() + "\n"));
    printCharacterStats();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_southButton_clicked()
{
    goRoom("south");
}

void MainWindow::on_westButton_clicked()
{
    goRoom("west");
}

void MainWindow::on_northButton_clicked()
{
    goRoom("north");
}

void MainWindow::on_eastButton_clicked()
{
    goRoom("east");
}

void MainWindow::on_teleportButton_clicked()
{//Teleport
    goRoom("teleport");
}

void MainWindow::on_viewCharInfo_clicked()
{//View Character Info
    ui->mainConsole->append(QString::fromStdString(character.longDescription()));
}

void MainWindow::on_help_clicked()
{//Help
    ui->mainConsole->append(QString::fromStdString(zork->printHelp()));
}

void MainWindow::on_viewMap_clicked()
{   ui->mainConsole->append(QString::fromStdString(zork->map() + "\n"));
}

void MainWindow::on_viewRoomItems_clicked()
{//View items in the room
    putInInventory = true;
    vector<Item> items = zork->getCurrentRoom().viewItems();
    listItems(items, "room");
}

void MainWindow::on_viewCharItems_clicked()
{//View items held by character
    putInInventory = false;
    vector<Item> items = character.viewItems();
    listItems(items, "character");
}

void MainWindow::on_selectSuspect1_clicked(){
    //User clicked Suspect 1 Button and lost
    if(gameStatus.EndGame)
    {
        endGameState("selected the wrong suspect", "lost");
    }
}

void MainWindow::on_selectSuspect2_clicked(){
    //User clicked Suspect 2 Button and won
    if(gameStatus.EndGame)
    {
        endGameState("selected the correct suspect", "won");
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem*item)
{
    string description = item->text().toStdString();
    Item i = *new Item(description);
    ui->listWidget->takeItem(ui->listWidget->row(item));
    //delete item;

    if (putInInventory)
    {
        Room r = zork->getCurrentRoom();
        Item m = r.findItem(i);
        //character.itemsInCharacter.push_back(m);
        addItem(character.itemsInCharacter, m);
        character.addItem(&m);
        r.removeItem(m);
        ui->mainConsole->append(QString::fromStdString(description + " has been added to your inventory.\n"));
        overencumberedTest();
    }
    else
    {
        Item m = character.findItem(i);
        Room r = zork->getCurrentRoom();
        addItem(r.itemsInRoom, m);
        character.removeItem(m);
        ui->mainConsole->append(QString::fromStdString(description + " has been removed from your inventory.\n"));
    }
}

void MainWindow::addItemsToListWidget(vector<Item> items)
{
    ui->listWidget->clear();

    if (putInInventory)
    {
        if (!zork->getCurrentRoom().allItemsCollected())
        {
            for (unsigned int i = 0; (unsigned int)i < (unsigned int)zork->getCurrentRoom().numberOfItems(); i++)
            {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else {
            ui->mainConsole->append(QString::fromStdString("There are no items in the room."));
        }
    }
    else
    {
        if (!character.itemsInCharacter.empty())
        {
            for (unsigned int i = 0; i < character.itemsInCharacter.size(); i++)
            {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else
        {
            ui->mainConsole->append(QString::fromStdString("There are no items in " + character.shortDescription() + "'s inventory.\n"));
        }
    }
}

void MainWindow::endGameState(string message1, string message2)
{
    ui->southButton->setEnabled(false);
    ui->westButton->setEnabled(false);
    ui->northButton->setEnabled(false);
    ui->eastButton->setEnabled(false);
    ui->teleportButton->setEnabled(false);
    ui->viewCharInfo->setEnabled(false);
    ui->help->setEnabled(false);
    ui->viewMap->setEnabled(false);
    ui->viewRoomItems->setEnabled(false);
    ui->viewCharItems->setEnabled(false);
    ui->listWidget->setEnabled(false);
    ui->selectSuspect1->setEnabled(false);
    ui->selectSuspect2->setEnabled(false);
    ui->mainConsole->setText(QString::fromStdString(character.description + " has " + message1 + ". You have " + message2 + " the game.\n"));

    if(message2=="won")
    {throw gameException(character.description + " has " + message1 + ". You have won the game.\n");
    }
    else if(message2=="lost")
    {throw gameException(character.description + " has " + message1 + ". You have lost the game.\n");
    }

    character.stamina = 0;
    ui->staminaDisplay->setText(QString::fromStdString(displayStamina()));
}

void MainWindow::overencumberedTest()
{
    if (character.isOverencumbered(10.0))
    {
        endGameState("been overencumberd", "lost");
    }
}

void MainWindow::goRoom(string direction)
{
    if (character.stamina >= 0)
    {
        character.decrementStamina();
        printCharacterStats();

        if (direction == "teleport")
        {
            ui->mainConsole->append(QString::fromStdString(zork->teleport() + "\n"));
        }
        else
        {
            ui->mainConsole->append(QString::fromStdString(zork->go(direction) + "\n"));

            if (zork->getCurrentRoom().description == "SubmissionRoom")
            {   gameStatus.EndGame = true;
                gameStatus.OnGoing = false;//Making sure the user doesn't activate the buttons if they're not in SubmissionRoom
                ui->selectSuspect1->setEnabled(true);
                ui->selectSuspect2->setEnabled(true);
                ui->mainConsole->setText(QString::fromStdString("So, who do you think it is? Hit the button on the bottom left if its Suspect 1, or the button in bottom right if its Suspect 2."));
            }
        }
    }
    else
    {
        endGameState("ran out of stamina", "lost");
    }
}

void MainWindow::listItems(vector<Item> items, QString description)
{
    if (!items.empty())
    {
        addItemsToListWidget(items);
    }
    else
    {
        ui->mainConsole->append("No " + description + " items could be found.\n");
    }
}

string MainWindow::displayStamina()
{
    string output = "Stamina:\n";

    for (int i = 0; i < character.stamina; i++)
    {
        output += "[] ";
    }

    return output;
}

void MainWindow::printCharacterStats()
{
    if (!(character.stamina > 0 && gameStatus.OnGoing))
    {
        endGameState("run out of stamina", "lost");
    }
    else
    {
        ui->staminaDisplay->setText(QString::fromStdString(displayStamina()));
    }
}
