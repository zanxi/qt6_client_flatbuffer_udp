#include "rectangle.h"

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    setBrush(QBrush(clr, Qt::SolidPattern));
    qDebug()<<clr;
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsRectItem::mouseMoveEvent(event);
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setBrush(QBrush(Qt::green, Qt::SolidPattern));
    to_front();
    QGraphicsRectItem::mousePressEvent(event);
}

void Rectangle::to_front() {
    if (figures->isEmpty()) return;

    QAbstractGraphicsShapeItem *zmax = (*figures)[0];
    for (auto &c : *figures) {
        if (c->zValue() > zmax->zValue())
            zmax = c;
    }
    this->setZValue(zmax->zValue() + 1);
    for (auto &c : *figures) {
        c->setZValue(c->zValue() - 1);
    }
}
