#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene;
    Nodo1 = new QGraphicsItemGroup();
    ui->setupUi(this);
    currentScale = 1;
    scaleFactor = 1.1;
    scaleMin = .1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QGraphicsEllipseItem *ellipse2;
    QGraphicsTextItem *texto;

    QBrush redBrush(Qt::red);
    //QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    ellipse1 = scene->addEllipse(0, 10, 100, 100, blackPen, redBrush);
    ellipse2 = scene->addEllipse(500, 10, 100, 100, blackPen, redBrush);
    ellipse1->setAcceptDrops(true);
    ellipse2->setAcceptDrops(true);
    ellipse1->setFlag(QGraphicsItem::ItemIsMovable, true);

    texto = new QGraphicsTextItem();
    texto->setPos(0,50);
    texto->setPlainText("Nodo X");
    Nodo1->addToGroup(ellipse1);
    Nodo1->addToGroup(texto);
    Nodo1->setAcceptDrops(true);
    Nodo1->setFlag(QGraphicsItem::ItemIsMovable, true);

    scene->addItem(Nodo1);
    ui->painter->setAcceptDrops(true);
    ui->painter->setScene(scene);
    ui->painter->scale(currentScale,currentScale);
}

void MainWindow::on_pushButton_2_clicked()//+
{
    currentScale*=scaleFactor;
    ui->painter->scale(scaleFactor,scaleFactor);
}

void MainWindow::on_pushButton_3_clicked()//-
{
    if(currentScale>scaleMin){
        currentScale/=scaleFactor;
        ui->painter->scale(1/scaleFactor,1/scaleFactor);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    cout<<Nodo1->pos().x()<<" , "<<Nodo1->pos().y()<<endl;
}
