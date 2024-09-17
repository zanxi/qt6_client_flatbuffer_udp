#ifndef SETTINGS_H
#define SETTINGS_H

#include <QList>

class Settings
{
public:
    Settings();

    static QStringList defaultPacketTableHeader();

    static const QString TIME_STR;

    static const QString Id;
    static const QString Type;
    static const QString Position;
    static const QString Region;
    static const QString View;
    static const QString Hide;

    static const QString TypeRectangle;
    static const QString TypeLine;
    static const QString TypeEllipse;
    static const QString TypeTriangle;

    static const QString IconView;
    static const QString IconHide;
    static const QString IconDelete;

    static int randomBetween(int low, int high);


private:
    QStringList figureTableHeaders;
    QStringList packetSavedTableHeaders;

};

#endif // SETTINGS_H
