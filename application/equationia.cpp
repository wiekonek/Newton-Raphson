#include "equationia.h"

using intervalarth::interval;
using intervalarth::IntervalArithmetic;

EquationIA::EquationIA() : st(0), it(0) {

    IA = new IntervalArithmetic();
    ix = IA->IntRead("0.0");
    ifatx = IA->IntRead("0.0");

}

EquationIA::EquationIA(QString ix, void * handle, QString iFunctionName, QString mit, QString eps) throw(string) {
    if(ix == "" || iFunctionName == "" || mit == "" || eps == "") {
        std::string except = "Blad danych. Sprawdz czy wprowadziles wszystkie dane.";
        throw except;
    }

    this->mit = mit.replace(",", ".").toInt();
    this->eps = eps.replace(",", ".").toDouble();

    IA = new IntervalArithmetic();

    this->ifatx = IA->IntRead("0.0");
    this->ix = IA->IntRead(ix.replace(",", ".").toStdString());

    char * error;
    iFunctionName = "i" + iFunctionName;
    std::string iname = iFunctionName.toStdString() ;

    iif = (ifunct)dlsym(handle, iname.c_str());
    if ((error = dlerror()) != NULL)  {
        iname = "Funkcja: \"" + iname + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw iname;
    }

    idf = (ifunct)dlsym(handle, ("d" + iname).c_str());
    if ((error = dlerror()) != NULL)  {
        iname = "Funkcja: \"" + iname + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw iname;
    }

    id2f = (ifunct)dlsym(handle, ("d2" + iname).c_str());
    if ((error = dlerror()) != NULL)  {
        iname = "Funkcja: \"" + iname + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw iname;
    }

}

EquationIA::EquationIA(QString ix_a, QString ix_b, void *handle, QString iFunctionName, QString mit, QString eps) {
    if(ix_a == "" || ix_b == "" || iFunctionName == "" || mit == "" || eps == "") {
        std::string except = "Blad danych. Sprawdz czy wprowadziles wszystkie dane.";
        throw except;
    }

    this->mit = mit.replace(",", ".").toInt();
    this->eps = eps.replace(",", ".").toDouble();

    IA = new IntervalArithmetic();

    this->ifatx = IA->IntRead("0.0");
    ix.a = IA->LeftRead(ix_a.replace(",", ".").toStdString());
    ix.b = IA->RightRead(ix_b.replace(",", ".").toStdString());

    if(ix.a > ix.b) {
        std::string except = "Blad danych. Lewa strona przedziału musi być mniejsza od prawej.";
        throw except;
    }

    char * error;
    iFunctionName = "i" + iFunctionName;
    std::string iname = iFunctionName.toStdString() ;

    iif = (ifunct)dlsym(handle, iname.c_str());
    if ((error = dlerror()) != NULL)  {
        iname = "Funkcja: \"" + iname + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw iname;
    }

    idf = (ifunct)dlsym(handle, ("d" + iname).c_str());
    if ((error = dlerror()) != NULL)  {
        iname = "Funkcja: \"" + iname + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw iname;
    }

    id2f = (ifunct)dlsym(handle, ("d2" + iname).c_str());
    if ((error = dlerror()) != NULL)  {
        iname = "Funkcja: \"" + iname + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw iname;
    }

}

EquationIA::~EquationIA() {
    delete IA;
}

interval EquationIA::iabs(interval x) {
    long double a = x.a;
    long double b = x.b;
    interval ret;
    if(a > 0.0 && b > 0.0) {
        ret = x;
    } else if(a < 0.0 && b < 0.0) {
        ret = IA->Opposite(x);
    } else {
        ret.a = IA->LeftRead("0.0");
        a = abs(a);
        b = abs(b);
        if(a > b)
            ret.b = a;
        else
            ret.b = b;
    }
    return ret;
}

double EquationIA::mid(interval x) {
    return (x.a+x.b)/2;
}

interval EquationIA::solve_ia() {
    interval idfatx, id2fatx, ip, iv, iw, ixh, ix1, ix2, test01, test02;
    interval i2 = IA->IntRead("2.0");
    interval i0 = IA->IntRead("0.0");
    test01 = i0;
    test02 = i0;
    if(mit < 1)
        st = 1;
    else {
        st = 3;
        it = 0;
        do {
            it++;
            ifatx = iif(ix);
            idfatx = idf(ix);
            id2fatx = id2f(ix);
            ip = IA->ISub( IA->IMul(idfatx, idfatx), IA->IMul(i2, IA->IMul(ifatx, id2fatx)) );
            if(ip.a < 0)
                st = 4;
            else {
                ixh = ix;
                iw = iabs(ixh);
                ip.a = sqrt(ip.a);
                ip.b = sqrt(ip.b);
                ix1 = IA->ISub( ix,  IA->IDiv(IA->ISub(idfatx, ip), id2fatx) );
                ix2 = IA->ISub( ix,  IA->IDiv(IA->IAdd(idfatx, ip), id2fatx) );
                test01 = iabs(IA->ISub(ix2, ixh));
                test02 = iabs(IA->ISub(ix1, ixh));
                mid( test01 ) > mid( test02 ) ? ix = ix1 : ix = ix2;
                iv = iabs(ix);
                if (iv.b < iw.a)
                    iv = iw;
                if(iv.a <= 0 && iv.b >= 0)
                    st = 0;
                //(abs(x-xh)/v <= eps)
                //else if ( IA->IDiv(iabs( IA->ISub(ix, ixh) ), iv ).b <= eps )
                else if (abs(ix.a-ixh.a) <= eps && abs(ix.b-ixh.b) <= eps  )
                    st = 0;
            }
        } while( it != mit && st == 3);
    }
    if(st==0 || st==3)
        return ix;
    return i0;
}
