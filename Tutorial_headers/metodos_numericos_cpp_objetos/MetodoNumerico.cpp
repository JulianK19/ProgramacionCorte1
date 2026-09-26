#include "MetodoNumerico.h"

double MetodoNumerico::derivadaCentral(
    double (*f)(double),
    double x,
    double h
)
{
    return (f(x + h) - f(x - h))
           / (2.0 * h);
}

double MetodoNumerico::trapecio(
    double (*f)(double),
    double a,
    double b,
    int n
)
{
    double h = (b - a) / n;

    double suma =
        (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        suma += f(x);
    }

    return h * suma;
}