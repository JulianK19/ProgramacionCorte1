#ifndef NUMERICO_H
#define NUMERICO_H

double derivada_central(
    double (*f)(double),   // f es un puntero a una función que recibe un double y devuelve un double
    double x,
    double h
);

double trapecio(
    double (*f)(double),  
    double a,  // a es el límite inferior de integración, b es el límite superior de integración
    double b,  // a es el límite inferior de integración, b es el límite superior de integración
    int n  // n es el número de subintervalos en los que se divide el intervalo [a, b]
); 

double biseccion(
    double (*f)(double),
    double a, // a es el límite inferior del intervalo, b es el límite superior del intervalo
    double b, // a es el límite inferior del intervalo, b es el límite superior del intervalo
    double tolerancia,  // tolerancia para el criterio de convergencia  
    int max_iteraciones       // número máximo de iteraciones permitidas
);

#endif