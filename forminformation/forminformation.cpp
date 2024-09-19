#include "forminformation.h"
#include "ui_forminformation.h"

#include "settings.h"
#include "FigureViewButton.h"

#include <QMessageBox>

FormInformation::FormInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInformation)
{
    ui->setupUi(this);

    tInfo = new TableInfo(this);
    tInfo->loadFigureTable();
    tInfo->setStyleSheet("::item:hover { color:rgb(0,0,255) }");
    tInfo->setRowCount(1);
    ui->verticalLayout_2->addWidget(tInfo);


    //connect(tInfo, &TableInfo::setLightFigure, this, &FormInformation::setLightFigure)
    connect(tInfo, &TableInfo::setLightFigure, this, &FormInformation::setLightFigure);
    //connect(tInfo->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), key, SLOT(cell_position(QModelIndex)));
}


void FormInformation::cell_position(QModelIndex)
{


}


FormInformation::~FormInformation()
{
    delete ui;
}

void FormInformation::setLightFigure(int row, int col)
{
    qDebug()<<"void FormInformation::setLightFigure(int row, int col)";
    Q_UNUSED(col);
    FigureViewButton* pb = qobject_cast<FigureViewButton*>(tInfo->cellWidget(row,5));
    if(pb==nullptr)return;
    emit setColotFigure(pb->finfo.Id);

}


QIcon FormInformation::getIcon(QString name)
{
    if(name == Settings::View)
    {
             QIcon myIcon(Settings::IconView);
             return myIcon;
    }
    else if(name == Settings::Hide)
    {
             QIcon myIcon(Settings::IconDelete);
             return myIcon;

    }
}

void FormInformation::ViewHideFigure(figureInfo f)
{
      //tInfo->removeRow(f.row);
    qDebug()<<"visible: "<<f.Id;
    FigureViewButton* pb = qobject_cast<FigureViewButton*>(tInfo->cellWidget(f.row,4));
    if(pb==nullptr)return;
    pb->finfo.visible=!pb->finfo.visible;
    pb->setLabel();

    //QMessageBox::information(nullptr,"","Показать фигуру");
    emit hideFigure(f.Id);

}

void FormInformation::DeleteFigure(figureInfo f)
{
    qDebug()<<"old Id: "<<f.Id<<"; "<<f.row;
    //QMessageBox::information(nullptr,"","Показать фигуру");
    tInfo->removeRow(f.row);
    tInfo->update();
    if(tInfo->rowCount()==0)return;
    FigureViewButton* pb = qobject_cast<FigureViewButton*>(tInfo->cellWidget(f.row,5));
    if(pb==nullptr)return;
    //pb->finfo.Id;
    qDebug()<<"action: "<<pb->getAction()<<"Id: "<<pb->finfo.Id<<"; "<<pb->finfo.row;
    emit hideFigure(f.Id);
}

void FormInformation::setRowTableRow(int Id, QString type, qreal x, qreal y, qreal width, qreal height)
{
    int rowCounter=tInfo->rowCount()-1;
    tInfo->setRowCount(tInfo->rowCount()+1);
    QTableWidgetItem * tItem;

    // кнопка видимости фигуры в таблице
    FigureViewButton * figureViewButton = new FigureViewButton(Settings::View, tInfo);//getFigureButton();//tInfo);
    figureViewButton->setDataFigure(rowCounter,Id,type,x,y,width,height);
    connect(figureViewButton, SIGNAL(ViewHide(figureInfo)),
            this, SLOT(ViewHideFigure(figureInfo)));
    //tInfo->setCellWidget(rowCounter, figureTableHeaders.indexOf(Settings::View), figureViewButton);
    tInfo->setCellWidget(rowCounter, 4, figureViewButton);

    // кнопка удаления в таблице
    FigureViewButton * figureHideButton = new FigureViewButton(Settings::Hide, tInfo);//getFigureButton();//tInfo);
    figureHideButton->setDataFigure(rowCounter,Id,type,x,y,width,height);
    connect(figureHideButton, SIGNAL(DeleteFig(figureInfo)),
            this, SLOT(DeleteFigure(figureInfo)));
    //tInfo->setCellWidget(rowCounter, figureTableHeaders.indexOf(Settings::Hide), figureHideButton);
    tInfo->setCellWidget(rowCounter, 5, figureHideButton);

    // position
    tItem = new QTableWidgetItem(figureHideButton->getPosition());
    //tInfo->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Position), tItem);
    tInfo->setItem(rowCounter, 3, tItem);


    //region
    tItem = new QTableWidgetItem(figureHideButton->getRegion());
    //tInfo->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Region), tItem);
    tInfo->setItem(rowCounter, 2, tItem);

    //type
    tItem = new QTableWidgetItem(figureHideButton->getType());
    //tInfo->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Type), tItem);
    tInfo->setItem(rowCounter, 1, tItem);

    //Id
    tItem = new QTableWidgetItem(figureHideButton->getId());
    //tInfo->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Id), tItem);
    tInfo->setItem(rowCounter, 0, tItem);


}



