#ifndef IMAGERECIVER_H
#define IMAGERECIVER_H

#include <QDeclarativeItem>
#include <QPainter>
#include "imageserver.h"
#include "QBonjourServer/bonjourserviceregister.h"

class ImageReciver : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ImageReciver)
public:
    explicit ImageReciver(QDeclarativeItem *parent = 0);
    ~ImageReciver();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    
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
QML_DECLARE_TYPE(ImageReciver)

#endif // IMAGERECIVER_H
