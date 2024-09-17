#ifndef FIGUREINFO_H
#define FIGUREINFO_H

#include <QString>

#include <QColor>

struct figureInfo
{
    QString type;
    //QString clr; // color
    QColor clr;
    QString hexColor;
    uint8_t r,g,b;
    bool visible=true;
    qreal x1,y1,x2,y2,x3,y3,x4,y4,width,height; // dots trinangle (1-3) line(1-2) rectangle (1-4)
    qreal r1,r2,x,y; // radius coordinate ellipse
    qreal posx,posy;
    int Id;
    int row,col; // number row column in table data information

};

struct figureData
{
    QString type;
    //QString clr; // color
    QColor clr;
    bool visible=true;
    qreal x1,y1,x2,y2,x3,y3,x4,y4,width,height; // dots trinangle (1-3) line(1-2) rectangle (1-4)
    qreal r1,r2; // radius ellipse
    int Id;

};


#endif // FIGUREINFO_H
