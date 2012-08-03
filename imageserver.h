#ifndef IMAGESERVER_H
#define IMAGESERVER_H

#include <QTcpServer>
#include <QImage>
#include "serverthread.h"

class ImageServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ImageServer(QObject *parent = 0);

signals:
    void imageRecived(QImage image);
    void startReciving();

public slots:
    void reciveImage(QByteArray image);

protected:
    void incomingConnection(int handle);

};

#endif // IMAGESERVER_H
