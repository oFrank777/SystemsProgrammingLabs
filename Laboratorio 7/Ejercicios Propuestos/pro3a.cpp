#include <iostream>
using namespace std;

int main() {
    try {
        // Intentar asignar memoria para un arreglo grande
        int* arr = new int[0]; // Intentar asignar un billón de enteros
        // Usar el arreglo (por ejemplo, asignar un valor al primer elemento)
        cerr << "Arreglo creado con exito. ";
        arr[0] = 1;
        cerr << "Elemento asignado con exito. ";
        // Liberar la memoria asignada
        delete[] arr;
    } catch (const bad_alloc& e) {
        cerr << "Error: No se pudo asignar memoria. " << e.what() << endl;
    }
    
    return 0;
}
