#include "serverthread.h"

#include <QDataStream>

ServerThread::ServerThread(int id, QObject *parent) :
    QThread(parent)
{
    socketDescriptor = id;
    blockSize = 0;
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void ServerThread::run(){
#ifdef QT_DEBUG
    qDebug("started thread");
#endif
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(socketDescriptor)){
        qDebug("error");
        emit error(socket->error());
        return;
    }
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);
    exec();
}

void ServerThread::readData(){
    QDataStream out(socket);

    if(blockSize == 0){
        emit startReciving();
        if(socket->bytesAvailable()< sizeof(qint64))
            return;

        out >> blockSize;
#ifdef QT_DEBUG
    qDebug()<<"size: "<< blockSize;
#endif
    }

    if (socket->bytesAvailable() < blockSize){
        return;
    }

    QByteArray data;
    out >> data;
    emit recivedSomething(data);
}

void ServerThread::disconnected(){
    socket->deleteLater();
    exit(0);
}
