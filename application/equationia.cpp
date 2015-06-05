#include "equationia.h"

using intervalarth::interval;
using intervalarth::IntervalArithmetic;

EquationIA::EquationIA() : st(0), it(0) {

    IA = new IntervalArithmetic();
    ix = IA->IntRead("0");
    ifatx = IA->IntRead("0");

}

EquationIA::EquationIA(QString ix, void * handle, QString iFunctionName, int mit, double eps) :
    mit(mit), eps(eps) {
    EquationIA();
    this->ix = IA->IntRead(ix.toStdString());

    char * error;

    std::string iname = iFunctionName.toStdString() ;

    iif = (ifunct)dlsym(handle, iname.c_str());
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    idf = (ifunct)dlsym(handle, ("d" + iname).c_str());
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    id2f = (ifunct)dlsym(handle, ("d2" + iname).c_str());
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

}

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
            it++; /*
            ifatx.a = f(ix.a);
            ifatx.b = f(ix.b);
            idfatx.a = df(ix.a);
            idfatx.b = df(ix.b);
            id2fatx.a = d2f(ix.a);
            id2fatx.b = d2f(ix.b); */
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
