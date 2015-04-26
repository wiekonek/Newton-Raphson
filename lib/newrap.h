#ifndef NEWRAP_H
#define NEWRAP_H

#include "../application/IntervalArithmetic.h"
using intervalarth::interval;


extern "C" {

long double f(long double);
long double df(long double);
long double d2f(long double);
interval iif(interval);
interval idf(interval);
interval id2f(interval);

}

#endif // NEWRAP_H
