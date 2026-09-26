#include <iostream>
#include "numerico.h"

double funcion(double x)
{
    return x * x - 2.0;
}

int main()
{
    double raiz =
        Numerico::biseccion(
            funcion,
            1.0,
            2.0,
            0.000001,
            100
        );

    std::cout
        << "Raiz aproximada = "
        << raiz
        << std::endl;

    return 0;
}