#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QBrush>

#include "figureinfo.h"
#include "../settings.h"

class Ellipse : public QObject, public QGraphicsEllipseItem, public figureInfo
{
    Q_OBJECT
    QVector<QAbstractGraphicsShapeItem*> *figures;
public:
    Ellipse(qreal x, qreal y, qreal w, qreal h, QVector<QAbstractGraphicsShapeItem*> *figs,
            QGraphicsItem *parent = nullptr) :
        QGraphicsEllipseItem(x, y, w, h, parent)
    {
        r = Settings::randomBetween(50,200);
        g = Settings::randomBetween(50,200);
        b = Settings::randomBetween(50,200);

        clr = QColor(r,g,b);
        figures = figs;
        setBrush(QBrush(clr));
    }

    void setColor(QString clr){ hexColor = clr;};
    void setColor(uint8_t r, uint8_t g, uint8_t b){this->r = r; this->g = g; this->b=b; };
    void setColor(QColor clr){ this->clr = clr; };

    figureInfo f;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    void to_front();
};

#endif // ELLIPSE_H
