#ifndef MYITEM_H
#define MYITEM_H

#include <QAbstractGraphicsShapeItem>

//enum { Type = UserType + 1 };
enum DiagramType { Box, Triangle, Line, Ellipse };

class MyItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyItem(DiagramType diagramType, QGraphicsItem *item = nullptr){}

    DiagramType diagramType() const
    {
        return Box; //;polygon() == boxPolygon ? Box : Triangle;
    }
    int type() const override { return Type; }


};

#endif // MYITEM_H
