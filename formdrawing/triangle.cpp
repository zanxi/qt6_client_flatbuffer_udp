#include "triangle.h"

void Triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    setBrush(QBrush(clr, Qt::SolidPattern));
    qDebug()<<clr;
    QGraphicsPolygonItem::mouseReleaseEvent(event);
}

void Triangle::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsPolygonItem::mouseMoveEvent(event);
}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setBrush(QBrush(Qt::green, Qt::SolidPattern));
    to_front();
    QGraphicsPolygonItem::mousePressEvent(event);
}

void Triangle::to_front() {
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
