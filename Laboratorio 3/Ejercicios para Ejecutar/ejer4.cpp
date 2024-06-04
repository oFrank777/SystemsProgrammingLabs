#include <iostream> // Incluye la biblioteca estándar de entrada y salida
using namespace std; // Utiliza el espacio de nombres estándar

int main() 
{ 
    int m; // Declara una variable entera para almacenar la opción del menú

    // Imprime el menú de opciones
    cout << "\t\t\tElija una opción\n\n"; 
    cout << "1 Ingreso\n"; 
    cout << "2 Modificación\n"; 
    cout << "3 Consultas\n"; 
    cout << "4 Reportes\n"; 
    cout << "5 Utilidades\n"; 
    cout << "6 Salir\n\n"; 

    // Lee la opción seleccionada por el usuario
    cin >> m; 

    // Evalúa la opción seleccionada usando una estructura switch
    switch(m) 
    {
        case 1:
            // Opción 1: Mostrar un mensaje relacionado con el ingreso
            cout << "Ud tiene S/. 2500" << endl; 
            break; 
        case 2:
            // Opción 2: Mostrar un mensaje para modificar
            cout << "¿Que desea modificar?" << endl; 
            break; 
        case 3:
            // Opción 3: Mostrar un mensaje para consultas
            cout << "Escriba su consulta aqui: " << endl; 
            break; 
        case 4:
            // Opción 4: Mostrar un mensaje para reportes
            cout << "Ud. no presenta reportes" << endl; 
            break; 
        case 5:
            // Opción 5: Mostrar un mensaje para utilidades
            cout << "Este servicio esta bloqueado por el momento" << endl; 
            break; 
        case 6:
            // Opción 6: Mostrar un mensaje para salir
            cout << "Ya esta fuera" << endl; 
            break; 
        default:
            // Opción inválida: Mostrar un mensaje de error
            cout << "El valor ingresado no esta en el menu" << endl; 
    } 

    // Espera a que el usuario presione Enter antes de terminar el programa
    cin.ignore(); 
    return 0; // Retorna 0 indicando que el programa terminó correctamente
} 
