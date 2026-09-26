#include <stdio.h>
#include "numerico.h"

int main(void)
{
    double x = 3.0;
    double h = 0.001;

    double resultado = derivada_central(x, h);

    printf("x = %.4f\n", x);
    printf("h = %.6f\n", h);
    printf("Derivada aproximada = %.6f\n", resultado);

    return 0;
}