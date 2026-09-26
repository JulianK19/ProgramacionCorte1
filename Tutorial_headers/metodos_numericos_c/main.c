#include <stdio.h>
#include <math.h>
#include "numerico.h"

double cuadrado(double x)   
{
    return x * x;       
}

double cuadrado_menos_dos(double x)
{
    return x * x - 2.0;
}

int main(void)     
{
    double x = 3.0;
    double h = 0.001;

    double d1 =
        derivada_central(cuadrado, x, h);    // calcula la derivada central de la función cuadrado en el punto x con un paso h

    printf("Funcion: x^2\n");
    printf("Derivada en %.2f = %.6f\n",
           x, d1);

    double d2 =
        derivada_central(sin, 0.0, h);  // calcula la derivada central de la función sin en el punto 0 con un paso h

    printf("\nFuncion: sin(x)\n");
    printf("Derivada en 0 = %.6f\n", d2);

    double integral =
        trapecio(cuadrado, 0.0, 1.0, 100);

    printf("\nIntegral de x^2 entre 0 y 1 = %.8f\n",
           integral);

    double raiz;

    raiz = biseccion(
    cuadrado_menos_dos,
    1.0,
    2.0,
    0.000001,
    100
);

printf("\nRaiz aproximada = %.8f\n", raiz);

    return 0;
}