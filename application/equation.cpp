#include "equation.h"

Equation::Equation() : mit(1000) {
}

Equation::Equation(int &mit, double esp, int &it, int &st) :
    mit(mit), esp(esp), it(it), st(st) {
}
