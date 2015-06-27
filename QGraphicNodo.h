#ifndef QGRAPHICNODO
#define QGRAPHICNODO
#include <QGraphicsItem>
#include <QtGui>

class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;

class QGraphicNodo : public QGraphicsObject{
public:
    QGraphicNodo(QGraphicsItem *parent = 0): QGraphicsObject(parent), color(Qt::lightGray), dragOver(false)
    {
        setAcceptDrops(true);
    }

    void dragEnterEvent(QGraphicsSceneDragDropEvent *event){
        if (event->mimeData()->hasColor()) {
            event->setAccepted(true);
            dragOver = true;
            update();
        } else {
            event->setAccepted(false);
        }
    }

    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
        Q_UNUSED(event);
        dragOver = false;
        update();
    }

    void dropEvent(QGraphicsSceneDragDropEvent *event){
        dragOver = false;
        if (event->mimeData()->hasColor())
            color = qvariant_cast<QColor>(event->mimeData()->colorData());
        update();
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0){
        Q_UNUSED(option);
           Q_UNUSED(widget);
               painter->setBrush(dragOver ? color.light(130) : color);
               painter->drawRoundedRect(-10, -30, 20, 30, 25, 25, Qt::RelativeSize);
               painter->setBrush(Qt::white);
               painter->drawEllipse(-7, -3 - 20, 7, 7);
               painter->drawEllipse(0, -3 - 20, 7, 7);
               painter->setBrush(Qt::black);
               painter->drawEllipse(-5, -1 - 20, 2, 2);
               painter->drawEllipse(2, -1 - 20, 2, 2);
               painter->setPen(QPen(Qt::black, 2));
               painter->setBrush(Qt::NoBrush);
               painter->drawArc(-6, -2 - 20, 12, 15, 190 * 16, 160 * 16);
    }

    QColor color;
    QRectF boundingRect() const{
        return QRectF(-15, -50, 30, 50);
    }
    bool dragOver;
};

#endif // QGRAPHICNODO

