#ifndef FORMINFORMATION_H
#define FORMINFORMATION_H

#include <QWidget>
#include <QTableWidget>
#include <QGraphicsItem>

#include "figureviewbutton.h"


namespace Ui {
class FormInformation;
}

class FormInformation : public QWidget
{
    Q_OBJECT

public:
    explicit FormInformation(QWidget *parent = nullptr);
    ~FormInformation();

    void setRowTableRow(int Id=0, QString type="unknown", qreal x=0, qreal y=0, qreal width=0, qreal height=0);


signals:
    void ViewHide(QString name);
    void signal_to_draw_delete();
    void signal_to_draw_visiblebledelete(int);
    void hideFigure(int);
    void deleteFig(int);

public slots:

    void ViewHideFigure(figureInfo); // показать скрыть фигуру
    void DeleteFigure(figureInfo); // удалить фигуру

private:
    Ui::FormInformation *ui;

    QStringList figureTableHeaders;
    void loadFigureTable();
    FigureViewButton *getFigureButton(QTableWidget * parent);
    QIcon getIcon(QString name);

};

#endif // FORMINFORMATION_H
