#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <iostream>
using namespace std;
//#include "QGraphicNodo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    double currentScale, scaleMin, scaleFactor;
    QGraphicsScene *scene;
    QGraphicsItemGroup* Nodo1;
    QGraphicsEllipseItem *ellipse1;
};

#endif // MAINWINDOW_H
