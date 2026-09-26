#include <stdio.h>
#include "matematicas.h"

int main(void)
{
    double x = 3.0;

    printf("x = %.2f\n", x);
    printf("x^2 = %.2f\n", cuadrado(x));
    printf("x^3 = %.2f\n", cubo(x));
    printf("Promedio entre 4 y 8 = %.2f\n",
           promedio(4.0, 8.0));

    return 0;
}