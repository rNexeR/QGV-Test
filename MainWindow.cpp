#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsTextItem *texto;

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    scene->addEllipse(0, 10, 100, 100, blackPen, redBrush);
    scene->addEllipse(500, 10, 100, 100, blackPen, redBrush);
    texto = new QGraphicsTextItem();
    texto->setPos(100,100);
    texto->setPlainText("Nodo X");
    scene->addItem(texto);
    ui->painter->setScene(scene);
}
