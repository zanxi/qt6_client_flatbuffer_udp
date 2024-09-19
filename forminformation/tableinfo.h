#ifndef TABLEINFO_H
#define TABLEINFO_H

#include <QTableWidget>

class TableInfo : public QTableWidget
{
    Q_OBJECT
public:

    TableInfo(QWidget *parentPtr);
    ~TableInfo();

    void loadFigureTable();

    void dragEnterEvent(QDragEnterEvent *event)override;
    void dragMoveEvent(QDragMoveEvent *event)override;
    void dragLeaveEvent(QDragLeaveEvent *event)override;
    void dropEvent(QDropEvent *event)override;

    void filterDropIndator(QDragMoveEvent *event);

signals:
    void setLightFigure(int row, int col);
public slots:
    void newMousePos(int row, int column);

private:
    int  mRow, mColumn;
};

#endif // TABLEINFO_H
