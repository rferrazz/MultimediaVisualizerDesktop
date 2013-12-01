#ifndef IMAGESERVER_H
#define IMAGESERVER_H

#include <QTcpServer>
#include <QImage>
#include <QTcpSocket>

class ImageServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ImageServer(QObject *parent = 0);

signals:
    void imageRecived(QImage image);
    void startReciving();
    void receptionFailed();

private slots:
    void readData();

protected:
    void incomingConnection(int handle);

private:
    QTcpSocket *_activeConnection;
    int _blockSize;

};

#endif // IMAGESERVER_H
