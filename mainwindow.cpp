#include "mainwindow.h"
#include <QDeclarativeContext>

MainWindow::MainWindow(QUrl source, QWidget *parent) :
    QMainWindow(parent)
{
    ui = new QDeclarativeView(this);
    ui->rootContext()->setContextProperty("mainWindow", this);
    ui->setSource(source);
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}
