#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->yesChange->setReadOnly(true);
    ui->noChange->setReadOnly(true);
    ui->yesStatistic->setReadOnly(true);
    ui->noStatistic->setReadOnly(true);
    ui->plusOne->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_paradocs_clicked()
{
    QString experiment;
    QString statistic;

    int countExperiments = numbOfExp();
    int temp = getIterator();
    int prizeDoor = 0, startDoor = 0, foolDoor = 0, finalDoor = 0, i = 0;

    for(i = temp; i < countExperiments + temp; i++)
    {
        prizeDoor = 0;
        startDoor = 0;
        foolDoor = 0;
        finalDoor = 0;
        setDoors(&prizeDoor, &startDoor, &foolDoor, &finalDoor);

        experiment = QString::number(i) + ". Приз за " + QString::number(prizeDoor + 1) +
                " дверью. Учатсник наугад выбирает " + QString::number(startDoor + 1) +
                " дверь. Судья открывает " + QString::number(foolDoor + 1) + " дверь. За ней пусто. " +
                "Судья предлагает перевыбрать дверь. Игрок соглашается и выбирает " +
                QString::number(finalDoor + 1) + " дверь.";

        ui->yesChange->appendPlainText(experiment);

        if(finalDoor == prizeDoor)
        {
            experiment = "Судья открывает " + QString::number(finalDoor + 1) +
                    " дверь. За ней лежит приз. Игрок выйграл!";
            ui->yesChange->appendPlainText(experiment);
            setYesWin(1);
        }

        else
        {
            experiment = "Судья открывает " + QString::number(finalDoor + 1) +
                    " дверь. За ней пусто. Игрок проиграл.";
            ui->yesChange->appendPlainText(experiment);
        }
        experiment = "------------------------------------------------";
        ui->yesChange->appendPlainText(experiment);


        prizeDoor = 0;
        startDoor = 0;
        foolDoor = 0;
        finalDoor = 0;
        setDoors(&prizeDoor, &startDoor, &foolDoor, &finalDoor);

        experiment = QString::number(i) + ". Приз за " + QString::number(prizeDoor + 1) +
                " дверью. Учатсник наугад выбирает " + QString::number(startDoor + 1) +
                " дверь. Судья открывает " + QString::number(foolDoor + 1) + " дверь. За ней пусто. " +
                "Судья предлагает перевыбрать дверь. Игрок не соглашается.";

        ui->noChange->appendPlainText(experiment);

        if(startDoor == prizeDoor)
        {
            experiment = "Судья открывает " + QString::number(startDoor + 1) +
                    " дверь. За ней лежит приз. Игрок выйграл!";
            ui->noChange->appendPlainText(experiment);
            setNoWin(1);
        }

        else
        {
            experiment = "Судья открывает " + QString::number(startDoor + 1) +
                    " дверь. За ней пусто. Игрок проиграл.";
            ui->noChange->appendPlainText(experiment);
        }
        experiment = "------------------------------------------------";
        ui->noChange->appendPlainText(experiment);
    }

    setIterator(i);
    setAllGames(countExperiments);

    int allGames = getAllGames();
    int yesWin = getYesWin();
    int noWin = getNoWin();
    double wins;

    wins = ((double) yesWin / (double) allGames) * 100;
    statistic = "Было проведено " + QString::number(allGames) + " экспериментов. " +
            "Из них игрок выйграл в " + QString::number(yesWin) + " (" +
            QString::number(wins) + "%) случаях. Игрок менял дверь.";
    ui->yesStatistic->setPlainText(statistic);

    wins = 0;
    wins = ((double) noWin / (double) allGames) * 100;
    statistic = "Было проведено " + QString::number(getAllGames()) + " экспериментов. " +
            "Из них игрок выйграл в " + QString::number(noWin) + " (" +
            QString::number(wins) + "%) случаях. Игрок не менял дверь.";
    ui->noStatistic->setPlainText(statistic);
}

int MainWindow::numbOfExp()
{
    if(ui->plusOne->isChecked())
        return 1;

    else
    {
        if(ui->plusFive->isChecked())
            return 5;

        else
        {
            if(ui->plusTen->isChecked())
                return 10;

            else
            {
                if(ui->plusFifty->isChecked())
                    return 50;

                else
                    return 240000;
            }
        }
    }
}

void MainWindow::setDoors(int *prizeDoor, int *startDoor, int *foolDoor, int *finalDoor)
{
    *prizeDoor = randomBetween(0, 2);
    *startDoor = randomBetween(0, 2);

    int tempPrize = *prizeDoor;
    int tempStart = *startDoor;
    int tempFool = *foolDoor;
    int tempFinal = *finalDoor;

    while(tempFool == tempPrize || tempFool == tempStart)
    {
        *foolDoor = tempFool + 1;
        tempFool = *foolDoor;
    }

    while(tempFinal == tempFool || tempFinal == tempStart)
    {
        *finalDoor = tempFinal + 1;;
        tempFinal = *finalDoor;
    }
}

int MainWindow::randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

int MainWindow::getIterator()
{
    return it;
}

void MainWindow::setIterator(int value)
{
    it = value;
}

int MainWindow::getAllGames()
{
    return allGames;
}

void MainWindow::setAllGames(int value)
{
    allGames += value;
}

int MainWindow::getYesWin()
{
    return yesWin;
}

void MainWindow::setYesWin(int value)
{
    yesWin += value;
}

int MainWindow::getNoWin()
{
    return noWin;
}

void MainWindow::setNoWin(int value)
{
    noWin += value;
}
