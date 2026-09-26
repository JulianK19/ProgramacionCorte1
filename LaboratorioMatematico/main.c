#include <stdio.h>  // Inclusión de la biblioteca estándar de entrada y salida
#include <math.h>   // Inclusión de la biblioteca matemática

double PI = 3.141592653589793;  // Definición de la constante PI

void mostrarMenu(void); // Declaración de la función mostrarMenu 
void menuGeometria(void);   // Declaración de la función menuGeometria

double areaCirculo(double radio); // Declaración de la función areaCirculo
double perimetroCirculo(double radio); // Declaración de la función perimetroCirculo    
double areaTriangulo(double base, double altura); // Declaración de la función areaTriangulo

void clasificarTriangulo(double lado1, double lado2, double lado3); // Declaración de la función clasificarTriangulo

double evaluarFuncion(double a, double b, double c, double x); // Declaración de la función evaluarFuncion

double funcionLimite(double x); //  Declaración de la función funcionLimite
void aproximarLimite(void); // Declaración de la función aproximarLimite

double aproximarDerivada(double a, double b, double c, double x, double h);

void mostrarMenu(void);  // Declaración de la función mostrarMenu

int main(void)  // Función principal
{
    int opcion = 0; // Variable para almacenar la opción seleccionada por el usuario

    while (opcion != 5) // Bucle principal del programa, se ejecuta hasta que el usuario seleccione la opción 5 (Salir)
    {
        mostrarMenu();

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); // Lectura de la opción seleccionada por el usuario

        switch (opcion) // Estructura de control switch para manejar las diferentes opciones del menú
        {
            case 1:
                menuGeometria();
                break;

            case 2:
{
    double a, b, c, x;
    double resultado;

    printf("\n");
    printf("=================================\n");
    printf("      EVALUAR UNA FUNCION\n");
    printf("=================================\n");

    printf("Ingrese a: ");
    scanf("%lf", &a);

    printf("Ingrese b: ");
    scanf("%lf", &b);

    printf("Ingrese c: ");
    scanf("%lf", &c);

    printf("Ingrese x: ");
    scanf("%lf", &x);

    resultado = evaluarFuncion(a, b, c, x); // Evaluación de la función cuadrática con los valores ingresados por el usuario

    printf("f(%.2f) = %.2f\n", x, resultado); 

    break; // Salida del case 2
}

            case 3:
                aproximarLimite();
                break;

            case 4:
{
    double a, b, c, x, h;
    double resultado;

    printf("\n");
    printf("=================================\n");
    printf("        DERIVADA NUMERICA\n");
    printf("=================================\n");

    printf("Ingrese a: ");
    scanf("%lf", &a);

    printf("Ingrese b: ");
    scanf("%lf", &b);

    printf("Ingrese c: ");
    scanf("%lf", &c);

    printf("Ingrese x: ");
    scanf("%lf", &x);

    printf("Ingrese h: ");
    scanf("%lf", &h);

    if (h == 0)
    {
        printf("h no puede ser cero.\n");
    }
    else
    {
        resultado = aproximarDerivada(a, b, c, x, h);

        printf("Derivada aproximada en x = %.4f: %.6f\n",
               x, resultado);
    }

    break;
}

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida\n");
                break;
        }
    }

    return 0;
}

double aproximarDerivada(double a, double b, double c, double x, double h)
{
    double xDerecha;
    double xIzquierda;
    double valorDerecha;
    double valorIzquierda;
    double derivada;

    xDerecha = x + h;  // Cálculo del valor de x a la derecha del punto x
    xIzquierda = x - h; // Cálculo del valor de x a la izquierda del punto x

    valorDerecha = evaluarFuncion(a, b, c, xDerecha); 
    valorIzquierda = evaluarFuncion(a, b, c, xIzquierda);

    derivada = (valorDerecha - valorIzquierda) / (2.0 * h);  // Cálculo de la derivada utilizando la fórmula de diferencia central

    return derivada;
}

void aproximarLimite(void)
{
    double punto = 2.0;
    double distancia = 0.1;
    double x;
    double resultado;
    int i;

    printf("\n");
    printf("=================================\n");
    printf("       APROXIMAR UN LIMITE\n");
    printf("=================================\n");

    printf("\nAproximacion por la izquierda:\n");

    for (i = 0; i < 4; i++) // Bucle para aproximar el límite desde la izquierda
    {
        x = punto - distancia;

        resultado = funcionLimite(x); // Evaluación de la función límite en el punto x

        printf("x = %.4f   f(x) = %.4f\n", x, resultado);

        distancia = distancia / 10.0; // Reducción de la distancia para la siguiente aproximación
    }

    distancia = 0.1;

    printf("\nAproximacion por la derecha:\n");

    for (i = 0; i < 4; i++) // Bucle para aproximar el límite desde la derecha
    {
        x = punto + distancia;

        resultado = funcionLimite(x);

        printf("x = %.4f   f(x) = %.4f\n", x, resultado);

        distancia = distancia / 10.0;
    }

    printf("\nEl limite se aproxima a 4.\n");
}

void menuGeometria(void)
{
    double radio;
    double base;
    double altura;
    double lado1;
    double lado2;
    double lado3;

    printf("\n");
    printf("=================================\n");
    printf("           GEOMETRIA\n");
    printf("=================================\n");

    printf("\n--- CIRCULO ---\n");
    printf("Ingrese el radio: ");
    scanf("%lf", &radio);

    if (radio <= 0) // Validación del radio ingresado por el usuario
    {
        printf("Radio invalido.\n");
    }
    else // Si el radio es válido, se calculan y muestran el área y el perímetro del círculo
    {
        printf("Area: %.2f\n", areaCirculo(radio));
        printf("Perimetro: %.2f\n", perimetroCirculo(radio));
    }

    printf("\n--- TRIANGULO ---\n");

    printf("Ingrese la base: ");
    scanf("%lf", &base);

    printf("Ingrese la altura: ");
    scanf("%lf", &altura);

    if (base > 0 && altura > 0) // Validación de la base y altura ingresadas por el usuario
    {
        printf("Area del triangulo: %.2f\n",
               areaTriangulo(base, altura));
    }
    else // Si la base o la altura son inválidas, se muestra un mensaje de error
    {
        printf("Datos invalidos.\n");
    }

    printf("\nIngrese lado 1: ");
    scanf("%lf", &lado1);

    printf("Ingrese lado 2: ");
    scanf("%lf", &lado2);

    printf("Ingrese lado 3: ");
    scanf("%lf", &lado3);

    if (lado1 > 0 && lado2 > 0 && lado3 > 0) // Validación de los lados ingresados por el usuario
    {
        clasificarTriangulo(lado1, lado2, lado3);
    }
    else // Si alguno de los lados es inválido, se muestra un mensaje de error
    {
        printf("Los lados deben ser positivos.\n");
    }
}

double funcionLimite(double x)
{
    return (x * x - 4.0) / (x - 2.0); // Evaluación de la función límite (x^2 - 4) / (x - 2)
}

double evaluarFuncion(double a, double b, double c, double x)
{
    double resultado;

    resultado = a * x * x + b * x + c;

    return resultado;
}

double areaTriangulo(double base, double altura)
{
    return (base * altura) / 2.0;
}

void clasificarTriangulo(double lado1, double lado2, double lado3)
{
    if (lado1 == lado2 && lado2 == lado3)
    {
        printf("El triangulo es equilatero.\n");
    }
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
    {
        printf("El triangulo es isosceles.\n");
    }
    else
    {
        printf("El triangulo es escaleno.\n");
    }
}

double areaCirculo(double radio)
{
    return PI * radio * radio;
}

double perimetroCirculo(double radio)
{
    return 2 * PI * radio;
}

void mostrarMenu(void)

{
    printf("\n");
    printf("=================================\n");
    printf("      LABORATORIO MATEMATICO\n");
    printf("=================================\n");
    printf("1. Geometria\n");
    printf("2. Evaluar una funcion\n");
    printf("3. Aproximar un limite\n");
    printf("4. Calcular una derivada\n");
    printf("5. Salir\n");
}