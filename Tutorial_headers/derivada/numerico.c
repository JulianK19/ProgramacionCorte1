#include "numerico.h"

static double funcion(double x)  // existe una funcion llamada funcion que recibe un double y devuelve un double
{
    return x * x;
}

double derivada_central(double x, double h)  
{
    return (funcion(x + h) - funcion(x - h))  // calcula la derivada central de la funcion en el punto x con un paso h
           / (2.0 * h);
}