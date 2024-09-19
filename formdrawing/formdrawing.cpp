#include "formdrawing.h"
#include "ui_formdrawing.h"

#include "settings.h"

#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>

FormDrawing::FormDrawing(QWidget *parent) :
    QWidget(parent)
    //,ui(new Ui::FormDrawing)
{
    //ui->setupUi(this);

    figs.resize(0);

    this->resize(600, 500);

    main_grid = new QGridLayout(this);

    //add_fig = new QPushButton("Добавить фигуру");
    //QObject::connect(add_fig, SIGNAL(clicked(bool)), this, SLOT(addFigure()));
    //main_grid->addWidget(add_fig, 0, 0);

    //del_fig = new QPushButton("Удалить фигуру");
    //QObject::connect(this, &deleteItem, this, &del_fig_clicked);
    //main_grid->addWidget(del_fig, 1, 0);

    view = new QGraphicsView();
    scene = new QGraphicsScene();
    //scene->mousePressEvent(mousePressEvent);
    view->setScene(scene);
    main_grid->addWidget(view, 0, 0);
}

void FormDrawing::setColorFigure(int Id)
{
    qDebug()<<"setColor: ";
    QList<QGraphicsItem*> all = scene->items();
    for(int i=0;i<all.size();i++)
    {
        if(dynamic_cast<figureInfo*>(all[i])->Id==Id)
        {
            dynamic_cast<QAbstractGraphicsShapeItem*>(all[i])->setBrush(QColor(0,0,0));
        }
        else
        {
            uint8_t r = dynamic_cast<figureInfo*>(all[i])->r;
            uint8_t g = dynamic_cast<figureInfo*>(all[i])->g;
            uint8_t b = dynamic_cast<figureInfo*>(all[i])->b;
            dynamic_cast<QAbstractGraphicsShapeItem*>(all[i])->setBrush(QColor(r,g,b));
        };
    };
    scene->update();

}

void FormDrawing::DeleteFigure(int Id)
{
    //QMessageBox::information(nullptr,""," ---------- ");

    QList<QGraphicsItem*> all = scene->items();
    for(int i=0;i<all.size();i++)
    {
        if(dynamic_cast<figureInfo*>(all[i])->Id==Id){
            scene->removeItem(all[i]);
        }
        //scene->removeItem(all[i]);
    }
    scene->update();


    return;



}

void FormDrawing::ViewHide(int Id)
{
    //QMessageBox::information(nullptr,""," ---------- ");

    QList<QGraphicsItem*> all = scene->items();
    for(int i=0;i<all.size();i++)
    {
        if(dynamic_cast<figureInfo*>(all[i])->Id==Id){
            if(dynamic_cast<figureInfo*>(all[i])->visible==true)all[i]->hide();
            else all[i]->show();
            dynamic_cast<figureInfo*>(all[i])->visible=!(dynamic_cast<figureInfo*>(all[i])->visible);
            //allpi]`
        }
        //scene->removeItem(all[i]);
    }


    return;



}

void FormDrawing::addFigure(QString type) {

    countFigure++;

    figureInfo f;
    f.Id = countFigure;
    QAbstractGraphicsShapeItem* abstr_fig = nullptr;
    switch (rand() % 4) {
    case 70:
    {
        f.type = Settings::TypeEllipse;
        f.x = rand() % 200;
        f.y = rand() % 200;
        f.r1 = 30+rand() % 280; f.r2=30+rand() % 180;
        abstr_fig = new Ellipse(f.x, f.y, f.r1, f.r2, &figs);
        uint8_t r = Settings::randomBetween(50,200);
        uint8_t g = Settings::randomBetween(50,200);
        uint8_t b = Settings::randomBetween(50,200);
        //(dynamic_cast<Ellipse*>(abstr_fig))->setColor(r,g,b)
        (qgraphicsitem_cast<Ellipse*>(abstr_fig))->setColor(r,g,b);
        f.r=r;
        f.g=g;
        f.b=b;

        f.posx = rand() % 200;
        f.posy = rand() % 200;

        abstr_fig->setPos(f.posx,f.posy);

        break;
    }
    case 1:
    {
        f.type = Settings::TypeRectangle;
        f.x1=rand() % 200;
        f.y1=rand() % 200;
        f.x2=rand() % 300;
        f.y2=rand() % 400;
        abstr_fig = new Rectangle(f.x1,f.y1,f.x2,f.y2, &figs);
        uint8_t r = Settings::randomBetween(50,200);
        uint8_t g = Settings::randomBetween(50,200);
        uint8_t b = Settings::randomBetween(50,200);
        //(dynamic_cast<Ellipse*>(abstr_fig))->setColor(r,g,b)
        (qgraphicsitem_cast<Rectangle*>(abstr_fig))->setColor(r,g,b);
        f.r=r;
        f.g=g;
        f.b=b;

        f.posx = rand() % 200;
        f.posy = rand() % 200;

        abstr_fig->setPos(f.posx,f.posy);

        break;
    }
    case 2:
    {
        //abstr_fig = new Line(rand() % 200, rand() % 200, rand() % 200, rand() % 200, &figs);
        f.type = Settings::TypeLine;
        f.x1=rand() % 200;
        f.y1=rand() % 200;
        f.x2=rand() % 300;
        f.y2=rand() % 400;

        QPolygonF pol;
        QPointF first(f.x1,f.y1);
        QPointF second(f.x2, f.y2);
        QPointF first2(f.x2+4,f.y2+4);
        QPointF second2(f.x1+4, f.y1+4);
        pol << first << second << first2 << second2 ;
        abstr_fig = new Line(pol, &figs);
        uint8_t r = Settings::randomBetween(50,200);
        uint8_t g = Settings::randomBetween(50,200);
        uint8_t b = Settings::randomBetween(50,200);
        //(dynamic_cast<Ellipse*>(abstr_fig))->setColor(r,g,b)
        (qgraphicsitem_cast<Line*>(abstr_fig))->setColor(r,g,b);
        f.r=r;
        f.g=g;
        f.b=b;

        f.posx = rand() % 200;
        f.posy = rand() % 200;

        abstr_fig->setPos(f.posx,f.posy);


        break;
    }
    case 33:
    {
        f.type = Settings::TypeTriangle;
        f.x1=rand() % 200;
        f.y1=rand() % 200;
        f.x2=rand() % 300;
        f.y2=rand() % 400;

        f.x3=rand() % 300;
        f.y3=rand() % 400;

        f.posx = rand() % 200;
        f.posy = rand() % 200;

        QPolygonF pol;
        QPointF first(f.x1,f.y1);
        QPointF second(f.x2,f.y2);
        QPointF third(f.x3,f.y3);
        pol << first << second << third << first;
        abstr_fig = new Triangle(pol, &figs);
        uint8_t r = Settings::randomBetween(50,200);
        uint8_t g = Settings::randomBetween(50,200);
        uint8_t b = Settings::randomBetween(50,200);
        //(dynamic_cast<Ellipse*>(abstr_fig))->setColor(r,g,b)
        (qgraphicsitem_cast<Triangle*>(abstr_fig))->setColor(r,g,b);
        f.r=r;
        f.g=g;
        f.b=b;

        abstr_fig->setPos(f.posx, f.posy);
        break;
    }
    }
    if(abstr_fig==nullptr)return;
    //if(is_null_pointer_v<abstr_fig>::value)return;
    //abstr_fig->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    abstr_fig->setFlag(QGraphicsItem::ItemIsMovable, true);
    abstr_fig->setFlag(QGraphicsItem::ItemIsSelectable, true);

    (dynamic_cast<figureInfo*>(abstr_fig))->Id = countFigure;

    figs.push_back(abstr_fig);
    scene->addItem(abstr_fig);


    emit signal_to_info(f);
}

void FormDrawing::del_fig_clicked() {
    if (figs.isEmpty()) return;
    for (auto c: scene->selectedItems()) {
        scene->removeItem(c);
        for (int i = 0; i < figs.size(); i++) {
            if (figs[i] == c) {
                figs.removeAt(i);
                break;
            }
        }
    }
}

void FormDrawing::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(Qt::RightButton==event->button())
    {
        emit deleteItem();

        //clearSelection();
        //QGraphicsScene::mousePressEvent(event);

    }
}


FormDrawing::~FormDrawing()
{
    delete main_grid;
    delete scene;
    delete view;
    delete add_fig;
    delete del_fig;
}

