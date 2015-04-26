#ifndef EQUATIONPA_H
#define EQUATIONPA_H

#include "equationia.h"

using intervalarth::interval;

class EquationPA : public EquationIA {
private:
    long double x, fatx;
public:
    EquationPA(QString, funct, funct, funct, int, long double, QString, int, int);
    EquationPA(long double, funct, funct, funct, int, long double, long double, int, int);
    long double solve_pa();
};

#endif // EQUATIONPA_H
