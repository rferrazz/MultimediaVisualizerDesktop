#include "imageserver.h"

ImageServer::ImageServer(QObject *parent) :
    QTcpServer(parent)
{
}

void ImageServer::incomingConnection(int handle){
    ServerThread *thread = new ServerThread(handle);
    connect(thread, SIGNAL(startReciving()), this, SIGNAL(startReciving()));
    connect(thread, SIGNAL(recivedSomething(QByteArray)), this, SLOT(reciveImage(QByteArray)));
    thread->start();
}

void ImageServer::reciveImage(QByteArray image){
    QImage img;
    img.loadFromData(image, "JPG");
    emit imageRecived(img);
}
