#include "newrap.h"

using intervalarth::interval;


long double f1(long double x) {
    return 2*x*x + 3*x + 5;
}

long double df1(long double x) {
    return 4*x + 3;
}

long double d2f1(long double x) {
    return 4;
}

long double example1(long double x) {
    long double z = x*x;
    return z*(z-5)+4;
}

long double dexample1(long double x) {
    return 4*x*(x*x-2.5);
}

long double d2example1(long double x) {
    return 12*x*x-10;
}

interval if1(interval x) {
    intervalarth::IntervalArithmetic IA;
    return IA.DIAdd( IA.DIAdd( IA.DIMul( IA.DIMul( IA.IntRead("2.0"), x), x), IA.DIMul(IA.IntRead("3.0"), x)), IA.IntRead("5.0") );
}

interval dif1(interval x) {
    intervalarth::IntervalArithmetic IA;
    return IA.DIAdd( IA.DIMul(IA.IntRead("4.0"), x), IA.IntRead("3.0") );
}

interval d2if1(interval x) {
    intervalarth::IntervalArithmetic IA;
    return IA.IntRead("4.0");
}
