#include "tableinfo.h"

#include <QDragEnterEvent>
#include <QMimeData>
#include <QHeaderView>

#include "../settings.h"


void TableInfo::dragEnterEvent(QDragEnterEvent *event) {
    if (event->source() == this) {
        qDebug() << "Internal";
        setDragDropMode(QAbstractItemView::InternalMove);
    } else {
        qDebug() << "External";
        setDragDropMode(QAbstractItemView::DropOnly);
    }
    if (event->mimeData()->hasFormat("templateItemDrag")) {
        qDebug() << "111" << event << "\n3213213" << event->proposedAction() << event->possibleActions() << event->dropAction();
        event->acceptProposedAction();
    }
    //QAbstractItemView::dragEnterEvent(event);
}
void TableInfo::dragMoveEvent(QDragMoveEvent *event) {
    event->accept();
    filterDropIndator(event);
    //QAbstractItemView::dragMoveEvent(event);
}
void TableInfo::dragLeaveEvent(QDragLeaveEvent *event) {
    QAbstractItemView::dragLeaveEvent(event);
}
void TableInfo::dropEvent(QDropEvent *event) {
    qDebug() << "yay ?v3whyg345hg3w";
    if (event->mimeData()->hasFormat("templateItemDrag")) {
        qDebug() << "2132145215215";
        event->acceptProposedAction();
        return;
    }
    QTableWidget::dropEvent(event);
}
TableInfo::TableInfo(QWidget *parentPtr) : QTableWidget(parentPtr) {
    setAcceptDrops(true);
    setDragEnabled(true);
    //viewport()->setAcceptDrops(true);
    //setDragDropOverwriteMode(false);
    //setDropIndatorShown(true);
    setDropIndicatorShown(true);
    setDefaultDropAction(Qt::MoveAction);
    setColumnCount(10);
    setRowCount(1);
    connect(this, &TableInfo::cellEntered, this, &TableInfo::newMousePos);
}

TableInfo::~TableInfo() {

}

void TableInfo::loadFigureTable()
{
    QStringList figureTableHeaders;
    figureTableHeaders  = Settings::defaultPacketTableHeader();
    clear();

    setColumnCount(figureTableHeaders.size());

    verticalHeader()->show();
    horizontalHeader()->show();
    setHorizontalHeaderLabels(figureTableHeaders);
    resizeColumnsToContents();
    resizeRowsToContents();
    horizontalHeader()->setStretchLastSection(true);


}

void TableInfo::filterDropIndator(QDragMoveEvent *event) {
    auto *w = itemAt(event->pos());
    if (w) {

    } else {
        qDebug() << "Row pos/col = " <<  mRow << mColumn;
    }
    qDebug() << "filtering indator :" << w;

}
void TableInfo::newMousePos(int row, int column) {
    qDebug()<<" ---------- x: "<<row<<"; col: "<<column;
    mRow = row;
    mColumn = column;
    emit setLightFigure(row,column);
}
