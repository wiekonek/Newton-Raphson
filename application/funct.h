#ifndef FUNCT_H
#define FUNCT_H

class Funct {
private:
    double a, b, c;
public:
    Funct();
    Funct(double);
    Funct(double, double);
    Funct(double, double, double);
    double operator() (double);
    Funct* derivative() const;
};

#endif // FUNCT_H
