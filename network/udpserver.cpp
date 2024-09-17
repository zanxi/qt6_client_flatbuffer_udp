#include "udpserver.h"

#include <QDebug>
#include <QFile>
#include <fstream>
#include <iostream>

#include <QDataStream>
#include <QNetworkDatagram>

#include "flatbuffers/flatbuffers.h"

//#include "Client_generated.h"
#include "api_generated.h"


UDPserver::UDPserver(QObject *parent)
	: QUdpSocket(parent)
{

}

//::flatbuffers::GetRoot<TriangleData>(buffer.data());
inline const TriangleData *GetTriangleResult(const void *buf) {
    return ::flatbuffers::GetRoot<TriangleData>(buf);
}
inline const LineData *GetLineResult(const void *buf) {
    return ::flatbuffers::GetRoot<LineData>(buf);
}
inline const RectData *GetRectResult(const void *buf) {
    return ::flatbuffers::GetRoot<RectData>(buf);
}
inline const EllipseData *GetEllipseResult(const void *buf) {
    return ::flatbuffers::GetRoot<EllipseData>(buf);
}

UDPserver::~UDPserver()
{
	socket->close();
	delete socket;
}

void UDPserver::openConnection()
{
	socket = new QUdpSocket;
    if(!socket->bind(QHostAddress::Any,10002))//8065))
	{
		qDebug() << "Could not start server.";
		
	}
	else
    {
        qDebug() << "Listening on port 10002"; //8065.";
		connect(socket,SIGNAL(readyRead()),this,SLOT(handleReadyRead()));
	}
}

void UDPserver::handleReadyRead()
{

    QNetworkDatagram datagram;
    //QNetworkDatagram buffer;
    //QByteArray buffer;
    while (socket->hasPendingDatagrams())
    {
        datagram = socket->receiveDatagram();

//        qint64 dataSize_ = socket->pendingDatagramSize();
//        buffer.resize(dataSize_);
//        socket->readDatagram(buffer.data(), buffer.size());
        //auto shape = m_impl->parse_data(std::move(datagram));
    }

    QByteArray buffer = datagram.data();


//    QString fn = "api.bin";
//    QFile file(fn);
//    //file.resize(file_size);
//    while(socket->hasPendingDatagrams()) {
//        QByteArray datagram;
//        qint64 dataSize_ = socket->pendingDatagramSize();
//        datagram.resize(dataSize_);

//        socket->readDatagram(datagram.data(), datagram.size());
//        qDebug()<<"dartasize: "<<dataSize_;

//        // Сохраняем данные, учитывая смещение.
//        if(file.open(QFile::WriteOnly)) {
//            file.write(datagram);
//            qDebug()<<"size file new: "<<file.size();
//            file.close();
//        }
//    }


//    qDebug()<<"EXCELLENT READ FlatBuffers Data API !!!!!!!!!! \n";
//    //return;

//    {
//        std::ifstream input_file(fn.toStdString(), std::ios::binary | std::ios::ate);
//        //input_file.


//        if (!input_file.is_open()) {
//            std::cerr << "Error: Unable to open file for reading." << std::endl;
//            return;
//        }

//        qDebug()<<"EXCELLENT FlatBuffers Data API !!!!!!!!!!!!!!!!!!!!! \n";

//        //return;

//        std::ifstream::pos_type file_size = input_file.tellg();

//        std::vector<char> buffer(file_size);
//        input_file.seekg(0, std::ios::beg);
//        input_file.read(buffer.data(), file_size);
//        input_file.close();


        //****************************************************

        //::flatbuffers::

        //auto f = ::flatbuffers::GetRoot<Figure>(reinterpret_cast<const uint8_t*>(buffer.data()));
        auto f = ::flatbuffers::GetRoot<Figure>((buffer.data()));


        flatbuffers::Verifier verifier(reinterpret_cast<const uint8_t*>(buffer.data()), buffer.size());
        if (!f->Verify(verifier)) {
            std::cerr << "Error: Invalid FIGURE buffer." << std::endl;
            return;
        }


        if(f->type()==FigureType::FigureType_Triangle)
        {
            qDebug()<<"Triangle";
            auto triag = reinterpret_cast<const TriangleData *>(GetTriangleResult(reinterpret_cast<const uint8_t*>(buffer.data())));
            //auto triag = GetTriangleResult((buffer.data()));

//            if (!triag->Verify(verifier)) {
//                std::cerr << "Error: Invalid TriangleData." << std::endl;
//                return;
//            }

            qDebug()<<"x1 = "<<(int)triag->x1()<<"; y1 = "<<(int)triag->x2()<<"; x2 = "<<(int)triag->x2()<<"; y2 = "<<triag->y2();
            //f->

        }
        else if(f->type()==FigureType::FigureType_Line)
        {
            qDebug()<<"Line";
            //auto line = GetLineResult(reinterpret_cast<const uint8_t*>(buffer.data()));
            auto line = GetLineResult((buffer.data()));

            if (!line->Verify(verifier)) {
                std::cerr << "Error: Invalid LineData." << std::endl;
                return;
            }
            qDebug()<<"x1 = "<<line->x1()<<"; y1 = "<<line->x2()<<"; x2 = "<<line->x2()<<"; y2 = "<<line->y2();

        }
        else if(f->type()==FigureType::FigureType_Rect)
        {
            qDebug()<<"Rectangle";
            //auto rect = GetRectResult(reinterpret_cast<const uint8_t*>(buffer.data()));
            auto rect = GetRectResult((buffer.data()));

            if (!rect->Verify(verifier)) {
                std::cerr << "Error: Invalid RectData." << std::endl;
                return;
            }

            qDebug()<<"x = "<<static_cast<int>(rect->x())<<"; y = "<<static_cast<int>(rect->y())<<"; width = "<<static_cast<int>(rect->width())<<"; height = "<<static_cast<int>(rect->height());
        }
        else if(f->type()==FigureType::FigureType_Ellipse)
        {
            qDebug()<<"Ellipse";
            //auto elli = GetEllipseResult(reinterpret_cast<const uint8_t*>(buffer.data()));
            auto elli = GetEllipseResult((buffer.data()));

            if (!elli->Verify(verifier)) {
                std::cerr << "Error: Invalid EllipseData." << std::endl;
                return;
            }

            qDebug()<<"x = "<<elli->x()<<"; y = "<<elli->y()<<"; r1 = "<<elli->r1()<<"; r2 = "<<elli->r2();
        }
        else
        {
            qDebug()<<"Unknown Figure";
        }


        //flatbuffers::Verifier verifier_(reinterpret_cast<const uint8_t*>(buffer.data()), file_size);
        //if(!triag->Verify(verifier_))
        {
            //qDebug()<<"ERROR figure TRIANGLE";
            //return;
        }
        //qDebug()<<"x1 = "<<triag->x1()<<"; y1 = "<<triag->x2()<<"; x2 = "<<triag->x2()<<"y2 = "<<triag->y2();


//        ::flatbuffers::FlatBufferBuilder fbb(2000);
//        uint_8 *buf = fbb.GetBufferPointer();
//        int size = fbb.GetSize();

        //fbb.Finish(::flatbuffers::c);


        //::flatbuffers::GetRoot<::TriangleDataBuilder>(buffer);

        //TriangleData(::TriangleDataBuilder(buffer));

        //TriangleDataBuilder t(::flatbuffers::FlatBufferBuilder(buffer));

        //CreateTriangleData(::TriangleDataBuilder(buffer));






//        flatbuffers::Parser parser;
//        const char *include_directories[] = { "samples", nullptr };
//        ok = parser.Parse(schemafile.c_str(), include_directories) &&
//             parser.Parse(jsonfile.c_str(), include_directories);
//        assert(ok);

        //auto figureRect = RectData();
        // Deserialize the data

        //flatbuffers::Verifier verifier_(reinterpret_cast<const uint8_t*>(buffer.data()), file_size);
        //verifier_.

        //TriangleDataBuilder t(buffer);
        //auto f = FigureBuilder(verifier_);

        //flatbuffers::FlatBufferBuilder builder(buffer);


        //::flatbuffers::GetRoot<ClientNamespace::Root>(buf);



        std::cout<<"EXCELLENT !!!!!!!!!! \n";





    return;
    //****************************


}

