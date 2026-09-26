#ifndef NUMERICO_H
#define NUMERICO_H

namespace Numerico
{
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

    double biseccion(
        double (*f)(double),
        double a,
        double b,
        double tolerancia,
        int maxIteraciones
    );
}

#endif