#include "equationia.h"

EquationIA::EquationIA(interval x, funct f, funct df, funct d2f, int mit, long double esp, interval fatx, int it, int st) :
    Equation(mit, f, df, d2f, esp, it, st), x(x), fatx(fatx) {
}
