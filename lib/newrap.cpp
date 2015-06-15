#include "newrap.h"

using intervalarth::interval;
intervalarth::IntervalArithmetic IA;
//f1
long double f1(long double x) {
    long double z = x*x;
    return z*(z-5)+4;
}

long double df1(long double x) {
    return 4*x*(x*x-2.5);
}

long double d2f1(long double x) {
    return 12*x*x-10;
}

interval if1(interval x) {
    interval z = IA.IMul(x, x);
    return IA.IAdd( IA.IntRead("4.0"), IA.IMul( z, IA.ISub(z, IA.IntRead("5.0") )) );
}

interval dif1(interval x) {
    return IA.IMul( IA.IMul( IA.ISub(IA.IMul(x, x), IA.IntRead("2.5")), x), IA.IntRead("4.0") );
}

interval d2if1(interval x) {
    return IA.ISub( IA.IMul(IA.IMul(x, x), IA.IntRead("12.0")) , IA.IntRead("10.0") );
}


//f2
long double f2(long double x) {
    long double s = sin(x);
    return s * (s + 0.5) - 0.5;
}

long double df2(long double x) {
    return sin(2*x)+0.5*cos(x);
}

long double d2f2(long double x) {
    return 2*cos(2*x)-0.5*sin(x);
}

interval if2(interval x) {
    int st;
    interval s = IA.ISin(x, st);
    return IA.ISub( IA.IMul(s, IA.IAdd(s, IA.IntRead("0.5"))), IA.IntRead("0.5") );
}

interval dif2(interval x) {
    int st;
    return IA.IAdd( IA.ISin( IA.IMul(IA.IntRead("2,0"), x), st ), IA.IMul( IA.IntRead("2.0"), IA.ICos(x, st)));
}

interval d2if2(interval x) {
    int st;
    return IA.ISub( IA.IMul(IA.IntRead("2.0"), IA.ICos(IA.IMul(IA.IntRead("2.0"), x), st)),
                            IA.IMul(IA.IntRead("0.5"), IA.ISin(x, st)) );
}

//f3
long double f3(long double x) {
    return x*x-2;
}

long double df3(long double x) {
    return 2*x;
}

long double d2f3(long double x) {
    return 2;
}
