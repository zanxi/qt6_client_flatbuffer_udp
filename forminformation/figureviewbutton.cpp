#include "figureviewbutton.h"
#include <QDebug>
#include "../settings.h"

void themeTheButton(QPushButton * button);

FigureViewButton::FigureViewButton(QString action, QWidget *parent):
    QPushButton(parent)
{
    this->action = action;

    QString styleButton=QString(
        "QAbstractButton {"
        "background: rgba(255,255,255,100);"
        "}");
    setStyleSheet(styleButton);
    init();
    //setStyleSheet(styleButton);
    setIcon(getIcon(action));

}

void FigureViewButton::setLabel()
{
   setIcon(getIcon(action));
}


void FigureViewButton::setDataFigure(int row, int Id, QString type, qreal x, qreal y, qreal width, qreal height)
{
    this->finfo.row = row;
    this->finfo.Id = Id;
    this->finfo.type = type;
    this->finfo.posx = x;
    this->finfo.posy = y;
    this->finfo.width = width;
    this->finfo.height = height;
}

void FigureViewButton::init()
{
    connect(this,SIGNAL(clicked()),this,SLOT(ViewHideFigure()));
    connect(this,SIGNAL(clicked()),this,SLOT(DeleteFigure()));
}

QIcon FigureViewButton::getIcon(QString name)
{
    if(name == Settings::View)
    {
        if(finfo.visible) return  QIcon(Settings::IconView);
        if(!finfo.visible) return  QIcon(Settings::IconHide);
    }
    else if(name == Settings::Hide)
    {
        QIcon myIcon(Settings::IconDelete);
        return myIcon;

    }
}

QString FigureViewButton::getPosition()
{
    return QString::number(finfo.posx)+"px, " +
        QString::number(finfo.posy)+"px";

}

QString FigureViewButton::getRegion()
{
    return QString::number(finfo.width)+"px, " +
           QString::number(finfo.height)+"px";

}

QString FigureViewButton::getId()
{
    return QString::number(finfo.Id);
}

QString FigureViewButton::getAction()
{
    return action;
}


QString FigureViewButton::getType()
{
    return finfo.type;
}


void FigureViewButton::ViewHideFigure()
{

    qDebug() << " Emit clicked: " << finfo.type;

    emit ViewHide(finfo);

}

void FigureViewButton::DeleteFigure()
{

    qDebug() << " Emit clicked: " << finfo.type;

    emit DeleteFig(finfo);

}


void themeTheButton(QPushButton * button)
{
    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, QColor("#F5F5F5"));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->setStyleSheet("QPushButton { color: white; } QPushButton::hover { color: #BC810C; } ");
    button->setFlat(true);
    button->setCursor(Qt::PointingHandCursor);
    button->update();


}

