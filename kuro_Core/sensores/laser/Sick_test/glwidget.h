#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "stdio.h"
#include <iostream>
#include "math.h"

using namespace std;

class GlWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GlWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void setData(int* datos);
    void SickTriggered(int* x);
    ~GlWidget();
private:
    int*Laser;
    double*ang;
};

#endif // GLWIDGET_H
