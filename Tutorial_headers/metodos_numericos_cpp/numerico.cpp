#include <cmath>
#include "numerico.h"

double Numerico::derivadaCentral(
    double (*f)(double),
    double x,
    double h
)
{
    return (f(x + h) - f(x - h))
           / (2.0 * h);
}

double Numerico::trapecio(
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

double Numerico::biseccion(
    double (*f)(double),
    double a,
    double b,
    double tolerancia,
    int maxIteraciones
)
{
    double c = 0.0;

    for (int i = 0; i < maxIteraciones; i++)
    {
        c = (a + b) / 2.0;

        if (std::fabs(f(c)) < tolerancia)
        {
            return c;
        }

        if (f(a) * f(c) < 0.0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    return c;
}