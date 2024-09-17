#include "ellipse.h"

void Ellipse::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    //setBrush(QBrush(Qt::red, Qt::SolidPattern));
    setBrush(QBrush(clr, Qt::SolidPattern));
    QGraphicsEllipseItem::mouseReleaseEvent(event);
}

void Ellipse::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsEllipseItem::mouseMoveEvent(event);
}

void Ellipse::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setBrush(QBrush(Qt::green, Qt::SolidPattern));
    to_front();
    QGraphicsEllipseItem::mousePressEvent(event);
}

void Ellipse::to_front() {
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
