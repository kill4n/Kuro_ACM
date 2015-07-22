#include "mainwindow.h"
#include "ui_mainwindow.h"

void sick_callbak_func(int *datos);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sickTim351 = new sick_test<MainWindow>("192.168.0.180", 2111);

    //this->sickTim351->setReadDataFunc(metod, this);
    //this->sickTim351->setReadDataFunc(sick_callbak_func);
    //this->sickTim351->setCallback(&GlWidget::SickTriggered, *(this->ui->widget));
    this->sickTim351->setCallback(&MainWindow::SickTriggered, *this);
    this->sickTim351->conectar();

    this->sickTim351->StartRead(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SickTriggered(int *x)
{
    ui->widget->setData(x);
}

void MainWindow::on_pushButton_2_clicked()
{

}
