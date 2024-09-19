#ifndef FORMDRAWING_H
#define FORMDRAWING_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QAbstractGraphicsShapeItem>
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "line.h"

#include "../figureinfo.h"

namespace Ui {
class FormDrawing;
}

class FormDrawing : public QWidget
{
    Q_OBJECT

    QGridLayout *main_grid;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *add_fig;
    QPushButton *del_fig;

    int countFigure = 0;

    QVector<QAbstractGraphicsShapeItem*> figs;

public:
    explicit FormDrawing(QWidget *parent = nullptr);
    ~FormDrawing();

    void ViewHide(int);
    void DeleteFigure(int Id);
    void setColorFigure(int Id);

public slots:
    void addFigure(QString type);
    void del_fig_clicked();

signals:
    void signal_to_info(figureInfo);
    void deleteItem();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


private:
    Ui::FormDrawing *ui;
};

#endif // FORMDRAWING_H
