#include "funct.h"

Funct::Funct() : Funct(0, 0, 0) {
}

Funct::Funct(double a) : Funct(0, 0, a) {
}

Funct::Funct(double a, double b) : Funct(0, a, b) {
}

Funct::Funct(double a, double b, double c) : a(a), b(b), c(c) {
}

double Funct::operator() (double x){
    return a*x*x + b*x + c;
}

Funct* Funct::derivative() const{
    double _a, _b;
    _a = a*2;
    _b = b ;
    return new Funct(0, _a, _b);
}
