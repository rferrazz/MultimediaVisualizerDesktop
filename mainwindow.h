#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDeclarativeView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QUrl source, QWidget *parent = 0);
    ~MainWindow();
    
private:
    QDeclarativeView *ui;
};

#endif // MAINWINDOW_H
