#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "./formdrawing/formdrawing.h"
#include "./forminformation/forminformation.h"

#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);



public slots:
    void slot_to_FigureInfo(figureInfo f);
    void onTimerUpdate();

    void slot_to_FigureDraw_Visible(int Id);
    void slot_to_FigureDraw_delete(int Id);
    void setColotFigure(int);

private:
    Ui::MainWindow *ui;

    FormDrawing *draw;
    FormInformation *infotab;

    QTimer *timer;
};
#endif // MAINWINDOW_H
