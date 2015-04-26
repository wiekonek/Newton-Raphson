#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "equationpa.h"

long double f(long double x) {
    return x*x-144;
}

long double df(long double x) {
    return 2*x;
}

long double d2f(long double x) {
    return 2;
}

int main(int argc, char *argv[]) {
//    typedef long double (*funct)(long double);
//    EquationPA *epa = new EquationPA(0, f, df, d2f, 10, 0.0000001, 0, 0, 0);
//    epa->solve_pa();
//    delete epa;
//
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
