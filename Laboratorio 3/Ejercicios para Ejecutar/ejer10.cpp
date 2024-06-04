#include <iostream> // Incluye la biblioteca estándar de entrada y salida
#include <cstdlib> // Incluye la biblioteca estándar de C para funciones generales como rand()
using namespace std; // Utiliza el espacio de nombres estándar

int main() 
{ 
    int valor = 0; // Declara una variable entera para almacenar los valores generados

    // Muestra un mensaje explicando el propósito del programa
    cout << "rand() definiendo limite inferior e inferior" << endl; 

    // Genera un número aleatorio en el rango de 1 a 100 y lo almacena en 'valor'
    valor = 1 + rand() % 100; 
    // Muestra el valor generado
    cout << "1 + rand() % 100\t\t" << valor << endl; 

    // Genera un número aleatorio en el rango de 25 a 124 (99+25) y lo almacena en 'valor'
    valor = 25 + rand() % 75; // Se usa 75 en lugar de 100 para asegurar el rango deseado (25 a 99)
    // Muestra el valor generado
    cout << "25 + rand() % 75\t\t" << valor << endl; 

    // Genera un número aleatorio en el rango de 0 a 50 y lo almacena en 'valor'
    valor = rand() % 51; 
    // Muestra el valor generado
    cout << "0 + rand() % 51\t\t" << valor << endl << endl; 

    return 0; // Retorna 0 indicando que el programa terminó correctamente
}
