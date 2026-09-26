#include <math.h>
#include "numerico.h"

double derivada_central(   // calcula la derivada central de la función f en el punto x con un paso h
    double (*f)(double),    // f es un puntero a una función que recibe un double y devuelve un double
    double x,
    double h
)
{
    return (f(x + h) - f(x - h))    // calcula la derivada central de la función f en el punto x con un paso h
           / (2.0 * h);
}

double trapecio(
    double (*f)(double),  // f es un puntero a una función que recibe un double y devuelve un double
    double a,  // a es el límite inferior de integración, b es el límite superior de integración
    double b,  // a es el límite inferior de integración, b es el límite superior de integración
    int n  // n es el número de subintervalos en los que se divide el intervalo [a, b]
)
{
    double h = (b - a) / n;  // calcula el ancho de cada subintervalo

    double suma =
        (f(a) + f(b)) / 2.0;  // calcula la suma de las áreas de los trapecios en los extremos del intervalo

    for (int i = 1; i < n; i++)  // recorre los subintervalos y suma las áreas de los trapecios
    {
        double x = a + i * h;   // calcula el punto medio del subintervalo
        suma += f(x);
    }

    return h * suma;
}

double biseccion(
    double (*f)(double),
    double a,
    double b,
    double tolerancia,
    int max_iteraciones
)
{
    double c = 0.0;

    for (int i = 0; i < max_iteraciones; i++)
    {
        c = (a + b) / 2.0;

        if (fabs(f(c)) < tolerancia)
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