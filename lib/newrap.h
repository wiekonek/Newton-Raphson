#ifndef NEWRAP_H
#define NEWRAP_H

#include "IntervalArithmetic.h"
using intervalarth::interval;


extern "C" {

long double f1(long double);
long double df1(long double);
long double d2f1(long double);

interval if1(interval);
interval dif1(interval);
interval d2if1(interval);


long double f2(long double);
long double df2(long double);
long double d2f2(long double);

interval if2(interval);
interval dif2(interval);
interval d2if2(interval);

long double f3(long double);
long double df3(long double);
long double d2f3(long double);

interval if3(interval);
interval dif3(interval);
interval d2if3(interval);

}

#endif // NEWRAP_H
