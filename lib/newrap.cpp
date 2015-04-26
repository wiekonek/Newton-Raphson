#include "newrap.h"
#include "../application/IntervalArithmetic.h"

using intervalarth::interval;
intervalarth::IntervalArithmetic IA;

long double f(long double x) {
    return 2*x*x + 3*x + 5;
}

long double df(long double x) {
    return 4*x + 3;
}

long double d2f(long double x) {
    return 4;
}

interval iif(interval x) {
    return IA.DIAdd( IA.DIAdd( IA.DIMul( IA.DIMul( IA.IntRead("2.0"), x), x), IA.DIMul(IA.IntRead("3.0"), x)), IA.IntRead("5.0") );
}

interval idf(interval x) {
    return IA.DIAdd( IA.DIMul(IA.IntRead("4.0"), x), IA.IntRead("3.0") );
}

interval id2f(interval x) {
    return IA.IntRead("4.0");
}
