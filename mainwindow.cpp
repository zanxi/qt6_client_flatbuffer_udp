#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>


#include <QDesktopServices>

#include "figureinfo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRect r = QGuiApplication::primaryScreen()->geometry();
    //this->resize(r.width(), r.height());
    setGeometry(QRect(50, 50, (r.width()-100), (r.height()-100)));

    connect(ui->action, &QAction::triggered, this, [](){
        qDebug()<<"Drawing";
        QMessageBox::information(nullptr,"", "Отрисовка");

        });

    connect(ui->action_2, &QAction::triggered, this, [](){
        qDebug()<<"Information";
        QMessageBox::information(nullptr,"","Информация");
    });

    draw = new FormDrawing;
    infotab = new FormInformation;

    //inputSpreadSheet *is = new inputSpreadSheet;

    //connect(draw, SIGNAL(FormDrawing::signal_to_info()), this, SLOT(MainWindow::slot_to_Figure fnfo()));
    connect(draw, &FormDrawing::signal_to_info, this, &MainWindow::slot_to_FigureInfo);
    connect(infotab, &FormInformation::deleteFig, this, &MainWindow::slot_to_FigureDraw_delete);
    connect(infotab, &FormInformation::hideFigure, this, &MainWindow::slot_to_FigureDraw_Visible);
    connect(infotab, &FormInformation::setColotFigure,this, &MainWindow::setColotFigure);

    //connect(infotab, &FormInformation::signal_to_draw_visiblebledelete, this, &MainWindow::slot_to_FigureDraw_Visible);

    //Form * form = new Form;

    //ui->verticalLayout_figure->addWidget(form);
    ui->verticalLayout_figure->addWidget(draw);
    ui->verticalLayout_table->addWidget(infotab);
    //ui->verticalLayout_table->addWidget(is);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::onTimerUpdate);
    timer->start(100);


}

void MainWindow::slot_to_FigureInfo(figureInfo f)
{
    qDebug()<<" - ------------- Figure №: "<<f.Id;


    if(f.type == Settings::TypeEllipse)
    {
    infotab->setRowTableRow(f.Id,f.type,f.posx,f.posy,f.r1,f.r2);
    }
    else if(f.type == Settings::TypeLine)
    {
    infotab->setRowTableRow(f.Id,f.type,f.posx,f.posy,0,0);
    }
    else if(f.type == Settings::TypeRectangle)
    {
    infotab->setRowTableRow(f.Id,f.type,f.posx,f.posy,f.x2-f.x1,f.y2-f.y1);
    }
    else if(f.type == Settings::TypeTriangle)
    {
    infotab->setRowTableRow(f.Id,f.type,f.posx,f.posy,f.x2-f.x1,f.y2-f.y1);
    }

    //infotab->setRowTableRow(draw->getCountFigure(),draw->ty);
    //infotab->setRowTableRow(draw->countFigure,Settings::TypeLine,rand()%300,rand()%200,rand()%200,rand()%200);
    //infotab->
    //infotab->seti;
    //QMessageBox::information(this,"Спасибо","Информация о фигуре получена");
}

void MainWindow::setColotFigure(int Id)
{
    draw->setColorFigure(Id);

}

void MainWindow::slot_to_FigureDraw_Visible(int Id)
{

    qDebug()<<"void MainWindow::slot_to_FigureDraw_Visible(int Id)";
    draw->ViewHide(Id);
}

void MainWindow::slot_to_FigureDraw_delete(int Id)
{
    draw->DeleteFigure(Id);

}

int count =0;

void MainWindow::onTimerUpdate()
{
    count++;

    //for(int i=0;i<0;i++)
    {
        switch(rand()%5)
        {
                    case 0:
            draw->addFigure(Settings::TypeEllipse);
                        break;
                    case 1:
                        draw->addFigure(Settings::TypeLine);
                        break;
                    case 2:
                        draw->addFigure(Settings::TypeRectangle);
                        break;
        case 3:
            draw->addFigure(Settings::TypeTriangle);
            break;
        default:
            draw->addFigure(Settings::TypeLine);
            break;
        }
    }

    if(count>12)timer->stop();


   // qDebug()<<"Figure №: "<<draw->getCountFigure();

    //draw->update();

    //if(draw->countFigure>8)timer->stop();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (keyEvent->key() == Qt::Key_Enter) {
        qDebug() << ("keyPressEvent: Enter received");
    }
    else if (keyEvent->key() == Qt::Key_A)
    {
        qDebug() << ("keyPressEvent: A received");
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (keyEvent->key() == Qt::Key_Enter) {
        qDebug() << ("keyReleaseEvent: Enter received");
    }
    else if (keyEvent->key() == Qt::Key_A)
    {
        qDebug() << ("keyReleaseEvent: A received");
    }
    else if (keyEvent->key() == Qt::Key_Escape)
    {
        qDebug() << ("keyReleaseEvent: Escape received");
        QMessageBox::information(this,"Спасибо","Вы вышли из программы");
        QApplication::closeAllWindows();
        QApplication::quit();
    }
}


