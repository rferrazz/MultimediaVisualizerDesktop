#include "imagereciver.h"

ImageReciver::ImageReciver(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    setFlag(ItemHasNoContents, false);
    server = new ImageServer(this);
    server->listen(QHostAddress::Any, 6017);
    serviceRegister = new BonjourServiceRegister(this);
    serviceRegister->registerService(BonjourRecord("ImageSharingServer", "_imageserver._tcp", QString()),
                                      server->serverPort());
    connect(server, SIGNAL(startReciving()), this, SIGNAL(startReciving()));
    connect(server, SIGNAL(imageRecived(QImage)), this, SLOT(parseImage(QImage)));
}

ImageReciver::~ImageReciver(){

}

void ImageReciver::parseImage(QImage image){
    lastImage = image;
    emit imageReady();
    update();
}

void ImageReciver::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QSize imageSize = lastImage.size();
    imageSize.scale(boundingRect().width(), boundingRect().height(), Qt::KeepAspectRatio);
    QRect ImgBoundingRect((boundingRect().width()/2)-(imageSize.width()/2),
                          (boundingRect().height()/2)-(imageSize.height()/2), imageSize.width(), imageSize.height());
    painter->drawImage(ImgBoundingRect, lastImage, lastImage.rect());
}
