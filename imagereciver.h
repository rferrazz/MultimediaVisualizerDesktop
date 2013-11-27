#ifndef IMAGERECIVER_H
#define IMAGERECIVER_H

#include <QQuickPaintedItem>
#include <QPainter>
#include "imageserver.h"
#include "QBonjourServer/bonjourserviceregister.h"

class ImageReciver : public QQuickPaintedItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ImageReciver)
public:
    explicit ImageReciver(QQuickPaintedItem *parent = 0);
    ~ImageReciver();

    void paint(QPainter *painter);

signals:
    void startReciving();
    void imageReady();

public slots:
    void parseImage(QImage image);

private:
    ImageServer *server;
    BonjourServiceRegister *serviceRegister;
    QImage lastImage;
    
};

#endif // IMAGERECIVER_H
