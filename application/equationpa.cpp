#include "equationpa.h"

EquationPA::EquationPA() :
    x(0), fatx(0) {
    it = 0;
    st = 0;
}

EquationPA::EquationPA(QString x, funct f, funct df, funct d2f, QString mit, QString eps) :
    x(x.toDouble()), f(f), df(df), d2f(d2f) {

    EquationPA();
    this->mit = mit.replace(",", ".").toInt();
    this->eps = eps.replace(",", ".").toDouble();

}

EquationPA::EquationPA(QString x, void *handle, QString functionName, QString mit, QString eps) throw (string) {
    if(x == "" || functionName == "" || mit == "" || eps == "") {
        string except = "Blad danych! Sprawdz czy wypelniles wszystkie niezbedne pola.";
        throw except;
    }

    this->x = x.replace(",", ".").toDouble();

    EquationPA();
    this->mit = mit.replace(",", ".").toInt();
    this->eps = eps.replace(",", ".").toDouble();

    char * error;


    std::string name = functionName.toStdString() ;

    f = (funct)dlsym(handle, name.c_str());
    if ((error = dlerror()) != NULL)  {
        name = "Funkcja: \"" + name + "\" nie istnieje. Podaj inna nazwe funkcji.";
        throw name;
        fputs(error, stderr);
        exit(1);
    }

    df = (funct)dlsym(handle, ("d" + name).c_str());
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    d2f = (funct)dlsym(handle, ("d2" + name).c_str());
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }


}

long double EquationPA::solve_pa() {
    long double dfatx, d2fatx, p, v, w, xh, x1, x2;

    if(mit < 1)
        st = 1;
    else {
        st = 3;
        it = 0;
        do {
            it++;
            fatx = f(x);
            dfatx = df(x);
            d2fatx = d2f(x);
            p = dfatx*dfatx-2*fatx*d2fatx;
            if (p < 0)
                st = 4;
            else {
                xh = x;
                w = abs(xh);
                p = sqrt(p);
                x1 = x-(dfatx-p)/d2fatx;
                x2 = x-(dfatx+p)/d2fatx;
                abs(x2-xh) > abs(x1-xh) ? x = x1 : x = x2;
                v = abs(x);
                if (v < w)
                    v = w;
                if (v == 0)
                    st = 0;
                else if (abs(x-xh)/v <= eps)
                    st = 0;
            }
        } while( it != mit && st == 3);
    }

    if (st == 0 || st == 3)
        return x;

    return 0;
}
