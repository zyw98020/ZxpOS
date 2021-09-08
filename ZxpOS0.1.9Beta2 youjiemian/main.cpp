#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QtTest>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //===静态程序启动画面===
     QPixmap pix("../image/ZxpOS.png");
     QSplashScreen splash(pix);
     qDebug() << "启动中...";
     splash.show();
     a.processEvents();
     MainWindow w;
     w.setWindowTitle("ZxpOS0.1.9Beta1");
     w.show();
     splash.finish(&w);//程序启动画面结束
     return a.exec();
}
