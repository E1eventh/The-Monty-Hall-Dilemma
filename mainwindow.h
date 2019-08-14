#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    int getIterator();

    int getAllGames();

    int getYesWin();

    int getNoWin();

    int numbOfExp();

    int randomBetween(int low, int high);

    void setIterator(int value);

    void setAllGames(int value);

    void setYesWin(int values);

    void setNoWin(int value);

    void setDoors(int *prizeDoor, int *startDoor, int *foolDoor, int *finalDoor);

    void on_paradocs_clicked();

private:
    Ui::MainWindow *ui;

    int it = 1;

    int allGames = 0;

    int yesWin = 0;

    int noWin = 0;
};

#endif // MAINWINDOW_H
