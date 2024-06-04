#include <iostream> 
// Incluye la biblioteca estándar para entrada y salida.
#include "biblioteca1.cpp" 
// Incluye el archivo biblioteca1.cpp donde se define la función suma.

using namespace std; 
// Utiliza el espacio de nombres estándar para evitar tener que usar std:: constantemente.

int main() {
    int resultado = suma(1, 1); 
    // Llama a la función suma con los valores 1 y 1 y almacena el resultado.
    cout << "El resultado es: " << resultado << "\n"; 
    // Imprime el resultado de la suma.
    return 0; 
    // Retorna 0 indicando que el programa finalizó correctamente.
}
