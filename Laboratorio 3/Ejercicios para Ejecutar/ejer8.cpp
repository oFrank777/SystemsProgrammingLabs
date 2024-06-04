#include <iostream> // Incluye la biblioteca estándar de entrada y salida
#include <cstdlib> // Incluye la biblioteca estándar de C para funciones generales como rand()
using namespace std; // Utiliza el espacio de nombres estándar

int main() 
{ 
    int valor = 0; // Declara una variable entera para almacenar los valores generados

    // Muestra un mensaje explicando el propósito del programa
    cout << "rand() definiendo límite superior, el rango va de 0 a (límite -1)" << endl; 

    // Genera un número aleatorio en el rango de 0 a 1 y lo almacena en 'valor'
    valor = rand() % 2; 
    // Muestra el valor generado
    cout << "rand() % 2\t\t" << valor << endl; 

    // Genera un número aleatorio en el rango de 0 a 9 y lo almacena en 'valor'
    valor = rand() % 10; 
    // Muestra el valor generado
    cout << "rand() % 10\t\t" << valor << endl; 

    // Genera un número aleatorio en el rango de 0 a 1499 y lo almacena en 'valor'
    valor = rand() % 1500; 
    // Muestra el valor generado
    cout << "rand() % 1500\t\t" << valor << endl; 

    // Genera un número aleatorio en el rango de 0 a 65535 y lo almacena en 'valor'
    valor = rand() % 65536; 
    // Muestra el valor generado
    cout << "rand() % 65536\t\t" << valor << endl; 

    return 0; // Retorna 0 indicando que el programa terminó correctamente
} 
