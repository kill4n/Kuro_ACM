#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sick_test.h"
#include "glwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void SickTriggered(int* x);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

private:    
    Ui::MainWindow *ui;
    sick_test<MainWindow> *sickTim351;
    int*d;    
};

#endif // MAINWINDOW_H
