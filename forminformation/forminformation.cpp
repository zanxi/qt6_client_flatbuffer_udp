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

    ui->tableWidget->setRowCount(1);
    loadFigureTable();

    //connect(this,&FigureViewButton::ViewHide,this,SLOT(FormInformation::ViewHideFigure(QString)));
    //ui->tableWidget->ro
    //setRowTableRow();
}

FormInformation::~FormInformation()
{
    delete ui;
}

void FormInformation::loadFigureTable()
{
//    QSettings settings(SETTINGSFILE, QSettings::IniFormat);

//    tableActive = false;
//    Packet tempPacket;


//    QList<Packet> packetsSavedFiltered;
//    packetsSavedFiltered.clear();

    //QString filterString = ui->searchLineEdit->text().toLower().trimmed();


//    foreach (tempPacket, packetsSaved) {

//        if (tempPacket.name.toLower().contains(filterString) ||
//            tempPacket.hexToASCII(tempPacket.hexString).toLower().contains(filterString) ||
//            tempPacket.toIP.toLower().contains(filterString) ||
//            QString::number(tempPacket.port).contains(filterString)
//            ) {
//            packetsSavedFiltered.append(tempPacket);
//            continue;
//        }
//    }

    //QDEBUGVAR(packetsSavedFiltered.size());



    figureTableHeaders  = Settings::defaultPacketTableHeader();
    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(figureTableHeaders.size());

    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->horizontalHeader()->show();
    ui->tableWidget->setHorizontalHeaderLabels(figureTableHeaders);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

}

FigureViewButton* FormInformation::getFigureButton(QTableWidget * parent)
{

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
      //ui->tableWidget->removeRow(f.row);
    qDebug()<<"visible: "<<f.Id;
    FigureViewButton* pb = qobject_cast<FigureViewButton*>(ui->tableWidget->cellWidget(f.row,4));
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
    ui->tableWidget->removeRow(f.row);
    ui->tableWidget->update();
    if(ui->tableWidget->rowCount()==0)return;
    FigureViewButton* pb = qobject_cast<FigureViewButton*>(ui->tableWidget->cellWidget(f.row,5));
    if(pb==nullptr)return;
    //pb->finfo.Id;
    qDebug()<<"action: "<<pb->getAction()<<"Id: "<<pb->finfo.Id<<"; "<<pb->finfo.row;
    emit hideFigure(f.Id);
}

void FormInformation::setRowTableRow(int Id, QString type, qreal x, qreal y, qreal width, qreal height)
{
    int rowCounter=ui->tableWidget->rowCount()-1;
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);


    QTableWidgetItem * tItem;
    //ui->tableWidget->setr



    // кнопка видимости фигуры в таблице
    FigureViewButton * figureViewButton = new FigureViewButton(Settings::View, ui->tableWidget);//getFigureButton();//ui->tableWidget);
    figureViewButton->setDataFigure(rowCounter,Id,type,x,y,width,height);
    connect(figureViewButton, SIGNAL(ViewHide(figureInfo)),
            this, SLOT(ViewHideFigure(figureInfo)));
    ui->tableWidget->setCellWidget(rowCounter, figureTableHeaders.indexOf(Settings::View), figureViewButton);

    // кнопка удаления в таблице
    FigureViewButton * figureHideButton = new FigureViewButton(Settings::Hide, ui->tableWidget);//getFigureButton();//ui->tableWidget);
    figureHideButton->setDataFigure(rowCounter,Id,type,x,y,width,height);
    connect(figureHideButton, SIGNAL(DeleteFig(figureInfo)),
            this, SLOT(DeleteFigure(figureInfo)));
    ui->tableWidget->setCellWidget(rowCounter, figureTableHeaders.indexOf(Settings::Hide), figureHideButton);

    // position
    tItem = new QTableWidgetItem(figureHideButton->getPosition());
    ui->tableWidget->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Position), tItem);


    //region
    tItem = new QTableWidgetItem(figureHideButton->getRegion());
    ui->tableWidget->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Region), tItem);

    //type
    tItem = new QTableWidgetItem(figureHideButton->getType());
    ui->tableWidget->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Type), tItem);

    //Id
    tItem = new QTableWidgetItem(figureHideButton->getId());
    ui->tableWidget->setItem(rowCounter, figureTableHeaders.indexOf(Settings::Id), tItem);


}



