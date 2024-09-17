#include "line.h"

#include <QPen>

void Line::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    setBrush(QBrush(clr, Qt::SolidPattern));
    qDebug()<<clr;
    QGraphicsPolygonItem::mouseReleaseEvent(event);
}

void Line::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsPolygonItem::mouseMoveEvent(event);
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setBrush(QBrush(Qt::green, Qt::SolidPattern));
    to_front();
    QGraphicsPolygonItem::mousePressEvent(event);
}

void Line::to_front() {
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
