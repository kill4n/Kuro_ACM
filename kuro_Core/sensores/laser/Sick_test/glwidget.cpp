#include "glwidget.h"

GlWidget::GlWidget(QWidget *parent):
    QGLWidget(parent)
{
    Laser=NULL;
    ang = new double[271];
    for (int i = 0; i < 271; i++) {
        ang[i]=(double)(((i-45)*M_PI)/180.0);
    }
}

void GlWidget::initializeGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);

}

void GlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();                       // Reset The View
    glPointSize(20.0);
    glTranslatef(0.0f,0.0f,-15.0f);
    glColor3f(0.0,0.0,1.0);
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex3f( 0.0f, 0.0f, 0.0f);
    glEnd();
    glPointSize(3.0);
    glColor3f(1.0,1.0,1.0);

    if(Laser!=NULL)
    {
        glBegin(GL_POINTS);
        for (int jk = 0; jk < 271; ++jk) {
            double l=Laser[jk];
            glVertex3f((l*cos(ang[jk])),
                       (l*sin(ang[jk])),0.0);
        }
        glEnd();
    }

    glFlush();
}

void GlWidget::resizeGL(int w, int h)
{
    glViewport( 0, 0, (GLint)w, (GLint)h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double wld=5500.0;
    glOrtho(-wld, wld, -wld, wld, 5.0, 15.0 );
    glMatrixMode( GL_MODELVIEW );
}

void GlWidget::setData(int *datos)
{
    Laser = datos;
    update();
}

GlWidget::~GlWidget()
{

}

