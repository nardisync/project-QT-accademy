#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,   ui(new Ui::MainWindow),
        worker()
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

EnumsType::PossibleApproch MainWindow::getApproch()
{

    if(ui->comboBoxApproch->currentText() == "Sorting Algorithm")
    {
        return EnumsType::PossibleApproch::Sorting;
    }
    else if(ui->comboBoxApproch->currentText() == "Merging Algorithm")
    {
        return EnumsType::PossibleApproch::Merging;
    }
    else if(ui->comboBoxApproch->currentText() == "Problem with Algorithm")
    {
        return EnumsType::PossibleApproch::Problem;
    }

    return EnumsType::PossibleApproch::None;
}

EnumsType::PossibleType MainWindow::getType()
{
    if(ui->comboBoxType->currentText() == "BubbleSort")
    {
        return EnumsType::PossibleType::BubbleSort;
    }
    else if(ui->comboBoxType->currentText() == "QuickSort")
    {
        return EnumsType::PossibleType::QuickSort;
    }
    else if(ui->comboBoxType->currentText() == "MergeSort")
    {
        return EnumsType::PossibleType::MergeSort;
    }

    else if(ui->comboBoxType->currentText() == "NormalMerging")
    {
        return EnumsType::PossibleType::NormalMerging;
    }

    else if(ui->comboBoxType->currentText() == "NormalProblem")
    {
        return EnumsType::PossibleType::NormalProblem;
    }

    return EnumsType::PossibleType::None;
}

EnumsType::Difficulty MainWindow::getDifficulty()
{
    if(ui->radioButtonEasy->isChecked())
    {
        return EnumsType::Difficulty::Easy;
    }
    else if(ui->radioButtonMedium->isChecked())
    {
        return EnumsType::Difficulty::Medium;
    }
    else if(ui->radioButtonHard->isChecked())
    {
        return EnumsType::Difficulty::Hard;
    }

    return EnumsType::Difficulty::None;
}


void MainWindow::on_pushButtonApply_clicked()
{
    EnumsType::PossibleApproch approch = this->getApproch();
    EnumsType::PossibleType type = this->getType();
    EnumsType::Difficulty diff = this-> getDifficulty();

    this->worker->handleMessage(approch, type, diff);

    // TO-DO: Vogliamo lasciarlo pubblico? o implementiamo
    // un altro sistema?
    // Cosi crashiamo, ma ci permette di fare l'append
    //this->worker->sendSignalCalculate();
}



void MainWindow::on_pushButtonAppendThread_clicked()
{
    qDebug() << "on_pushButtonAppendThread_clicked -> START";

    EnumsType::PossibleApproch approch = this->getApproch();
    EnumsType::PossibleType type = this->getType();
    EnumsType::Difficulty diff = this-> getDifficulty();

    this->worker->handleMessage(approch, type, diff);

    qDebug() << "on_pushButtonAppendThread_clicked -> STOP";
}


void MainWindow::on_pushButtonAppendThreadStart_clicked()
{
    qDebug() << "on_pushButtonAppendThreadStart_clicked -> START";
    this->worker->sendSignalCalculate();
    qDebug() << "on_pushButtonAppendThreadStart_clicked -> STOP";
}

