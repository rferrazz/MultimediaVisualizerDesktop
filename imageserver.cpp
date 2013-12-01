#include "imageserver.h"

ImageServer::ImageServer(QObject *parent) :
    QTcpServer(parent)
{
    _activeConnection = 0;
    _blockSize = 0;
}

void ImageServer::incomingConnection(int handle){
    if (_activeConnection != 0){
        delete _activeConnection;
    }
    _activeConnection = nextPendingConnection();
    connect(_activeConnection, SIGNAL(readyRead()), this, SLOT(readData()));
}

void ImageServer::readData()
{
    emit startReciving();

    QDataStream out(_activeConnection);
    out.setVersion(QDataStream::Qt_4_7);

    if(_blockSize == 0){
        emit startReciving();
        if(_activeConnection->bytesAvailable()< sizeof(qint64))
            return;

        out >> _blockSize;
#ifdef QT_DEBUG
    qDebug()<<"size: "<< _blockSize;
#endif
    }

    if (_activeConnection->bytesAvailable() < _blockSize){
        emit receptionFailed();
        return;
    }

    QByteArray data;
    out >> data;
    QImage image;
    image.loadFromData(data, "JPG");
    emit imageRecived(image);
    _blockSize = 0;
}
