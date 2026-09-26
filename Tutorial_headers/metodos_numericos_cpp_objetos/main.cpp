#include <iostream>
#include "MetodoNumerico.h"

double cuadrado(double x)
{
    return x * x;
}

int main()
{
    MetodoNumerico metodo;

    double derivada =
        metodo.derivadaCentral(
            cuadrado,
            3.0,
            0.001
        );

    double integral =
        metodo.trapecio(
            cuadrado,
            0.0,
            1.0,
            100
        );

    std::cout
        << "Derivada = "
        << derivada
        << std::endl;

    std::cout
        << "Integral = "
        << integral
        << std::endl;

    return 0;
}