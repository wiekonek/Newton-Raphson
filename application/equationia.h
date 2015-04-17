#ifndef EQUATIONIA_H
#define EQUATIONIA_H

#include "equation.h"

using intervalarth::interval;

class EquationIA : public Equation
{
private:
    interval x, fatx;
public:
    EquationIA(interval, funct, funct, funct, int, long double, interval, int, int);
    interval solve_ia() {}
};

#endif // EQUATIONIA_H
