#include "settings.h"


const QString Settings::TIME_STR = "Time";

const QString Settings::Id = "ID";
const QString Settings::Type = "Type";
const QString Settings::Position = "Position(X, Y)";
const QString Settings::Region = "Region(Width, Height)";
const QString Settings::View = "view/hide";
const QString Settings::Hide = "Delete Figure";

const QString Settings::IconView = ":/icons/res/view.png";
const QString Settings::IconHide = ":/icons/res/view_none.png";
const QString Settings::IconDelete = ":/icons/res/rem.png";

const QString Settings::TypeRectangle = "Rectangle";
const QString Settings::TypeLine = "Line";
const QString Settings::TypeEllipse = "Ellipse";
const QString Settings::TypeTriangle = "Triangle";



Settings::Settings()
{

}

QStringList Settings::defaultPacketTableHeader()
{
    QStringList list;
    list.clear();
    //list << Settings::SEND_STR << Settings::NAME_STR << Settings::RESEND_STR << Settings::TOADDRESS_STR << Settings::TOPORT_STR << Settings::METHOD_STR << Settings::ASCII_STR << Settings::HEX_STR;
    list << Settings::Id << Settings::Type << Settings::Position << Settings::Region << Settings::View << Settings::Hide;

    return list;

}

int Settings::randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}


