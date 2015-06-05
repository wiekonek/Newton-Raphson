#include "equationpa.h"

EquationPA::EquationPA(QString x, funct f, funct df, funct d2f, int mit, long double eps, QString fatx, int it, int st) :
    EquationIA(x, f, df, d2f, mit, eps, fatx, it, st), x(x.toDouble()), fatx(fatx.toDouble()) {
}

EquationPA::EquationPA(long double x, funct f, funct df, funct d2f, int mit, long double eps, long double fatx, int it, int st) :
    EquationIA(x, f, df, d2f, mit, eps, fatx, it, st), x(x), fatx(fatx) {
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
            std::cout<<"p: "<<p<<"\n";
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
        } while( it != mit || st == 3);
    }
    //std::cout<<"x: "<<x<<" fatx: "<<fatx<<" it: "<<it<<"\n";
    if (st == 0 || st == 3)
        return x;
    return 0;
}
/*
begin
  if mit<1
    then st:=1
    else begin
           st:=3;
           it:=0;
           repeat
             it:=it+1;
             fatx:=f(x);
             dfatx:=df(x);
             d2fatx:=d2f(x);
             p:=dfatx*dfatx-2*fatx*d2fatx;
             if p<0
               then st:=4
               else if d2fatx=0
                      then st:=2
                      else begin
                             xh:=x;
                             w:=abs(xh);
                             p:=sqrt(p);
                             x1:=x-(dfatx-p)/d2fatx;
                             x2:=x-(dfatx+p)/d2fatx;
                             if abs(x2-xh)>abs(x1-xh)
                               then x:=x1
                               else x:=x2;
                             v:=abs(x);
                             if v<w
                               then v:=w;
                             if v=0
                               then st:=0
                               else if abs(x-xh)/v<=eps
                                      then st:=0
                           end
           until (it=mit) or (st<>3)
         end;
  if (st=0) or (st=3)
    then begin
           NewtonRaphson:=x;
           fatx:=f(x)
         end
end;
*/
