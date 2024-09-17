#ifndef FIGUREVIEWBUTTON_H
#define FIGUREVIEWBUTTON_H

#include <QPushButton>
#include "settings.h"

//#include <QGraphicsItem>
#include "figureinfo.h"

class FigureViewButton : public QPushButton
{
    Q_OBJECT
public:
    FigureViewButton(QString action, QWidget *parent = 0);
    void setDataFigure(int row, int Id, QString type, qreal x, qreal y, qreal width, qreal height);
    QString getPosition();
    QString getRegion();
    QString  getType();
    QString  getId();
    QString  getAction();

    void setLabel();

    figureInfo finfo;

signals:
    void ViewHide(figureInfo);
    void DeleteFig(figureInfo);

public slots:
    void ViewHideFigure();
    void DeleteFigure();

private:
    QString action = Settings::View;

    void init();



    QIcon getIcon(QString name);



};

#endif // FIGUREVIEWBUTTON_H
