#ifndef NEWRAP_H
#define NEWRAP_H

#include "../application/IntervalArithmetic.h"
using intervalarth::interval;


extern "C" {

long double f1(long double);
long double df1(long double);
long double d2f1(long double);

long double example1(long double);
long double dexample1(long double);
long double d2example1(long double);

interval if1(interval);
interval dif1(interval);
interval d2if1(interval);

}

#endif // NEWRAP_H
