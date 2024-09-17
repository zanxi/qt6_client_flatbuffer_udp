#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include <QObject>
#include <QBrush>

#include "../figureinfo.h"
#include "../settings.h"

class Line : public QObject, public QGraphicsPolygonItem, public figureInfo
{
    Q_OBJECT
    QVector<QAbstractGraphicsShapeItem*> *figures;
public:
    Line(const QPolygonF &polygon, QVector<QAbstractGraphicsShapeItem*> *figs,
             QGraphicsItem *parent = nullptr) :
        QGraphicsPolygonItem(polygon, parent)
    {
        figures = figs;

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

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    void to_front();
};

#endif // LINE_H
