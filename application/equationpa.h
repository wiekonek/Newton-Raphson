#ifndef EQUATIONPA_H
#define EQUATIONPA_H

#include "equation.h"

using intervalarth::interval;

class EquationPA : public Equation
{
private:
    long double x, fatx;
public:
    EquationPA(long double, funct, funct, funct, int, long double, long double, int, int);
    interval solve_ia() {}
    long double solve_pa();
};

#endif // EQUATIONPA_H
