#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->objectSetEdit,SIGNAL(returnPressed()),this,SLOT(on_conBt_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_conBt_clicked()
{
    int TIMEOUT=(ui->timeSetEdit->text().toInt())*1000;
    myTimerId=this->startTimer(TIMEOUT);

}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId()!=myTimerId)
        return;
    handleTimeOut();
}

void MainWindow::handleTimeOut()
{
    QString program=ui->objectSetEdit->text();
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
    this->killTimer(myTimerId);
}

void MainWindow::on_canBt_clicked()
{
    this->close();
}

