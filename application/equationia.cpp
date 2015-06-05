#include "equationia.h"

using intervalarth::interval;
using intervalarth::IntervalArithmetic;

EquationIA::EquationIA(interval ix, funct f, funct df, funct d2f, int mit, long double eps, interval ifatx, int it, int st) :
    ix(ix), f(f), df(df), d2f(d2f), mit(mit), eps(eps), ifatx(ifatx), it(it), st(st) {
    IA = new IntervalArithmetic();
}

EquationIA::EquationIA(double x, funct f, funct df, funct d2f, int mit, long double eps, double fatx, int it, int st) :
    EquationIA(QString::number(x), f, df, d2f, mit, eps, QString::number(fatx), it, st) {}

EquationIA::EquationIA(long double x, funct f, funct df, funct d2f, int mit, long double eps, long double fatx, int it, int st) :
    EquationIA(QString::number((double)x), f, df, d2f, mit, eps, QString::number((double)fatx), it, st) {
}

EquationIA::EquationIA(QString _x, funct f, funct df, funct d2f, int mit, long double eps, QString _fatx, int it, int st) :
    f(f), df(df), d2f(d2f), mit(mit), eps(eps), it(it), st(st) {
    IA = new IntervalArithmetic();
    ix = IA->IntRead(_x.toStdString());
    ifatx = IA->IntRead(_fatx.toStdString());
}
/*
EquationIA::EquationIA(QString _x, QString library, int mit, long double eps) {

}
*/
EquationIA::~EquationIA() {
    delete IA;
}

intervalarth::interval EquationIA::solve_ia() {
    interval idfatx, id2fatx, ip, iv, iw, ixh, ix1, ix2;
    interval i2 = IA->IntRead("2.0");
    interval i0 = IA->IntRead("0.0");
    if(mit < 1)
        st = 1;
    else {
        st = 3;
        it = 0;
        do {
            it++;
            ifatx.a = f(ix.a);
            ifatx.b = f(ix.b);
            idfatx.a = df(ix.a);
            idfatx.b = df(ix.b);
            id2fatx.a = d2f(ix.a);
            id2fatx.b = d2f(ix.b);
            ip = IA->DISub( IA->DIMul(idfatx, idfatx), IA->DIMul(i2, IA->DIMul(ifatx, id2fatx)) );
            if(ip.a < 0)
                st = 4;
            ixh = ix;
            iw.a = abs(ixh.a);
            iw.b = abs(ixh.b);
            ix1 = IA->DISub( ix,  IA->DIDiv(IA->DISub(idfatx, ip), id2fatx) );
            ix2 = IA->DISub( ix,  IA->DIDiv(IA->DIAdd(idfatx, ip), id2fatx) );
            abs(ix2.a - ixh.b) > abs(ix1.b - ixh.a) ? ix = ix1 : ix = ix2;
            iv.a = abs(ix.a);
            iv.b = abs(ix.b);
            if (iv.b < iw.a)
                iv = iw;
            if(iv.a <= 0 && iv.b >= 0)
                st =0;
            else if (abs(ix.b-ixh.a)/iv.a <= eps)
                st = 0;
        } while( it != mit || st == 3);
    }
    if(st==0 || st==3)
        return ix;
    return i0;
}
