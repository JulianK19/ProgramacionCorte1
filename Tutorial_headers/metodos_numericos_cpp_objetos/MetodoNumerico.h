#ifndef METODO_NUMERICO_H
#define METODO_NUMERICO_H

class MetodoNumerico
{
public:
    double derivadaCentral(
        double (*f)(double),
        double x,
        double h
    );

    double trapecio(
        double (*f)(double),
        double a,
        double b,
        int n
    );
};

#endif