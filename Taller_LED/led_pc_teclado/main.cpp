#include <iostream>
#include "Led.h"

int main()
{
    char opcion = ' ';

    while (opcion != 'q')
    {
        std::cout << std::endl;
        std::cout << "Control del LED simulado" << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "1 -> 1 Hz" << std::endl;
        std::cout << "2 -> 2 Hz" << std::endl;
        std::cout << "5 -> 5 Hz" << std::endl;
        std::cout << "0 -> apagar" << std::endl;
        std::cout << "q -> salir" << std::endl;

        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == '1')
        {
            std::cout << "Frecuencia: 1 Hz" << std::endl;
            parpadearLed(1.0, 5);
        }
        else if (opcion == '2')
        {
            std::cout << "Frecuencia: 2 Hz" << std::endl;
            parpadearLed(2.0, 5);
        }
        else if (opcion == '5')
        {
            std::cout << "Frecuencia: 5 Hz" << std::endl;
            parpadearLed(5.0, 5);
        }
        else if (opcion == '0')
        {
            apagarLed();
        }
        else if (opcion == 'q')
        {
            std::cout << "Programa terminado" << std::endl;
        }
        else
        {
            std::cout << "Opcion no valida" << std::endl;
        }
    }

    return 0;
}