#include <iostream>
using namespace std;

int main() {
    int *x; // Declarar un puntero a int
    int y = 999999999999999999; // Definir el tamaño del arreglo

    try {
        // Intentar asignar memoria para el arreglo de tamaño y
        x = new int[y];

        // Asignar un valor al primer elemento del arreglo
        x[0] = 10;

        // Imprimir la dirección del puntero
        cout << "Puntero: " << (void *) x << endl;

        // Liberar la memoria asignada
        delete[] x;
    } 
    catch(std::bad_alloc&) {
        // Capturar la excepción std::bad_alloc si la asignación de memoria falla
        cout << "Memoria insuficiente" << endl;
    }

    return 0;
}

