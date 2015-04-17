#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int dupa(int a) {
    std::cout<<"a: "<<a<<"\n";
}

int main(int argc, char *argv[])
{
    typedef int (*fun)(int);
    fun f;
    f = dupa;
    f(5);
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
}
