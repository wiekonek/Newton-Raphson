#ifndef EQUATIONPA_H
#define EQUATIONPA_H

#include "equationia.h"

using intervalarth::interval;

class EquationPA : public EquationIA {

//    int mit;
//    long double eps;
//    int it, st;

private:
    typedef long double (*funct)(long double);
    long double x, fatx;
    funct f, df, d2f;
public:
    EquationPA();
    EquationPA(QString x, funct f, funct df, funct d2f, QString mit, QString eps);
    EquationPA(QString x, void * handle, QString functionName, QString mit, QString eps);
    long double solve_pa();

    long double get_x() {return x;}
    long double get_fatx() {return fatx;}
};

#endif // EQUATIONPA_H
