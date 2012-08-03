#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#ifdef QT_DEBUG
#include <QDebug>
#endif
#include <QThread>
#include <QTcpSocket>

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(int id, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError error);
    void recivedSomething(QByteArray recived);
    void startReciving();

public slots:
    void readData();
    void disconnected();

private:
    QTcpSocket *socket;
    int socketDescriptor;
    qint64 blockSize;

};

#endif // SERVERTHREAD_H
