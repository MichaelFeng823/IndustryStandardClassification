#include "mainwindow.h"
#include <QApplication>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QApplication::style()->standardIcon(QStyle::SP_TitleBarMenuButton));
    w.setWindowTitle("GJB元器件分类-V 0.1.0");
    w.setWindowIcon(QApplication::style()->standardIcon(QStyle::SP_TitleBarMenuButton));
    w.setFixedSize(1058,693);
    w.show();
    return a.exec();
}
