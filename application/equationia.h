#ifndef EQUATIONIA_H
#define EQUATIONIA_H

#include <qstring.h>
#include <dlfcn.h>

#include "IntervalArithmetic.h"

using intervalarth::interval;
using intervalarth::IntervalArithmetic;
using std::string;

class EquationIA {
protected:
    typedef interval (*ifunct)(interval);
    interval ix, ifatx;
    IntervalArithmetic *IA;
    ifunct iif, idf, id2f;

    int mit;
    long double eps;
    int it, st;

public:
    EquationIA();
    EquationIA(QString ix, void * handle, QString iFunctionName, int mit, double eps);
    ~EquationIA();

    interval solve_ia();

    long double get_ix_a() {return ix.a;}
    long double get_ix_b() {return ix.b;}
    long double get_ifatx_a() {return ifatx.a;}
    long double get_ifatx_b() {return ifatx.b;}
    int get_it() {return it;}
    int get_st() {return st;}
};

#endif // EQUATIONIA_H

/*
function NewtonRaphson (var x     : Extended;
                        f,df,d2f  : fx;
                        mit       : Integer;
                        eps       : Extended;
                        var fatx  : Extended;
                        var it,st : Integer) : Extended;
{---------------------------------------------------------------------------}
{                                                                           }
{  The function NewtonRaphson finds an approximate value of the root of     }
{  the equation f(x)=0 by the Newton-Raphson second order method.           }
{  Data:                                                                    }
{    x   - initial approximation to the root (changed on exit),             }
{    f   - a Turbo Pascal function which for the given value x evaluates    }
{          f(x),                                                            }
{    df  - a Turbo Pascal function which for the given value x evaluates    }
{          df(x)/dx,                                                        }
{    d2f - a Turbo Pascal function which evaluates the second derivative of }
{          f(x) with respect to x at the given point x,                     }
{    mit - maximum number of iterations in the method,                      }
{    eps - relative accuracy of the solution.                               }
{  Results:                                                                 }
{    NewtonRaphson(x,f,df,d2f,mit,eps,fatx,it,st) - approximate value of    }
{                                                    the root,              }
{    fatx                                          - the value of the       }
{                                                    function f(x) at the   }
{                                                    approximate root,      }
{    it                                            - number of iterations.  }
{  Other parameters:                                                        }
{    st - a variable which within the function NewtonRaphson is assigned    }
{         the value of:                                                     }
{           1, if mit<1,                                                    }
{           2, if during the calculations the second derivative of f with   }
{              respect to x at a point x is equal to zero,                  }
{           3, if the given accuracy eps is not achieved in mit iteration   }
{              steps,                                                       }
{           4, if during the calculations sqr(df(x))-2*f(x)*d2f(x)<0 at a   }
{              point x,                                                     }
{           0, otherwise.                                                   }
{         Note: If st=1,2 or 4, then                                        }
{               NewtonRaphson(x,f,df,d2f,mit,eps,fatx,st) is not            }
{               calculated, and if st=3, then                               }
{               NewtonRaphson(x,f,df,d2f,mit,eps,fatx,st) yields the last   }
{               approximation to the root.                                  }
{  Unlocal identifier:                                                      }
{    fx - a procedural-type identifier defined as follows                   }
{           type fx = function (x : Extended) : Extended;                   }
{  Note: Any function passed as a parameter should be declared with a far   }
{        directive or compiled in the $F+ state.                            }
{                                                                           }
{---------------------------------------------------------------------------}

var dfatx,d2fatx,p,v,w,xh,x1,x2 : Extended;
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

/*
 * Dokumentacja (tylko do funkcji liczącej w arytmetyce przedziałowej)
 * 
 * 1. Zastosowanie (jedno zdanie)
 * 2. Opis metody
 * 3. Wywołanie funkcji (to znaczy nagłówek)
 * 4. Dane ( n -liczba równań, x - coś tam)
 * 5. Wyniki
 * 6. Inne parametry (st - status, w funkcji nie ma obsługi błędów, obsługujemy je na zewnątrz funkcji)
 * 7. Typy parametrów (int: ..., tablica: .....)
 * 8. Identyfikatory nielokalne (unikać stosowania parametrów nielokalnych)
 *  tablica - dynamiczna tablica dwuwymiarowa, type a: arrray of array of Extended...
 * 9. Treść funkcji
 * 10.Przykłady (coś się sypie, nie uzyskujemy wymaganej dokładności, dzielenie przez 0)
 *
 */
