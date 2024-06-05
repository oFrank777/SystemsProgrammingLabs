#include <iostream>
#include <iomanip>

using namespace std;

// Funcion para calcular y llenar el triangulo de Pascal en un arreglo
void calcularTrianguloPascal(int *triangulo, int numRows) {
    for (int i = 0; i < numRows; ++i) { // Recorremos las filas del triangulo
        for (int j = i; j >= 0; --j) { // Recorremos las columnas del triangulo
            if (j == 0 || j == i) { // Si estamos en el borde del triangulo, asignamos 1
                triangulo[i*(i+1)/2 + j] = 1; // Formula para indexar un arreglo unidimensional
            } else {
                // Calculamos el valor basado en los valores superiores
                triangulo[i*(i+1)/2 + j] = triangulo[(i-1)*i/2 + j-1] + triangulo[(i-1)*i/2 + j]; 
            }
        }
    }
}

// Funcion para imprimir el triangulo de Pascal centrado
void imprimirTrianguloPascal(int *triangulo, int numRows) {
    for (int i = 0; i < numRows; ++i) { // Recorremos las filas del triangulo
        // Imprimir espacios en blanco para centrar el triangulo
        cout << setw((numRows - i - 1) * 3) << "";
        for (int j = 0; j <= i; ++j) { // Recorremos las columnas del triangulo
            // Imprimir el valor del triangulo de Pascal
            cout << setw(3) << triangulo[i*(i+1)/2 + j] << setw(3) << " ";
        }
        cout << endl;
    }
}

int main() {
    int numFilas;

    cout << "Ingrese el numero de filas del Triangulo de Pascal: ";
    cin >> numFilas;

    // Crear un arreglo unidimensional para almacenar el triangulo de Pascal
    int *triangulo = new int[numFilas*(numFilas+1)/2];

    // Calcular y llenar el triangulo de Pascal
    calcularTrianguloPascal(triangulo, numFilas);

    // Imprimir el Triangulo de Pascal
    imprimirTrianguloPascal(triangulo, numFilas);

    // Liberar la memoria asignada al arreglo
    delete[] triangulo;

    return 0;
}
