#include "equationpa.h"

#include "equation.h"

EquationPA::EquationPA(long double x, funct f, funct df, funct d2f, int mit, long double esp, long double fatx, int it, int st)
    : Equation(mit, f, df, d2f, esp, it, st), x(x), fatx(fatx) {
}




long double EquationPA::solve_pa() {
    long double dfatx, d2fatx, p, v, w, xh, x1, x2;
    if(mit < 1)
        st = 1;
    else {
        st = 3;
        it = 0;
        do {
            it++;
            fatx = (*f)(x);
            dfatx = (*df)(x);
            d2fatx = (*d2f)(x);
            p = dfatx*dfatx-2*fatx*d2fatx;
            if (p < 0)
                st = 4;
            else {
                xh = x;
                w = abs(xh);
                p = sqrt(p);
                x1 = x-(dfatx-p)/d2fatx;
                x2 = x-(dfatx+p)/d2fatx;
                abs(x2-xh) > abs(x1-xh) ? x = x1 : x = x2;
                v = abs(x);
                if (v < w)
                    v = w;
                if (v == 0)
                    st = 0;
                else if (abs(x-xh)/v <= eps)
                    st = 0;
            }
        } while( it != mit || st == 3);
    }
    if (st == 0 || st == 3)
        return x;
    return 0;
}
