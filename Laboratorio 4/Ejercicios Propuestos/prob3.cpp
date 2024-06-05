#include <iostream>

using namespace std;

// Funcion para encontrar el punto de silla en una matriz
void encontrarPuntoDeSilla(float **matriz, int filas, int columnas) {
    bool encontrado = false; // Variable para registrar si se encontro un punto de silla

    for (int i = 0; i < filas; ++i) { // Iterar sobre las filas de la matriz
        // Encontrar el minimo de la fila
        float minFila = *(*(matriz + i) + 0);
        int columnaMinFila = 0;
        for (int j = 1; j < columnas; ++j) { // Iterar sobre las columnas de la fila actual
            if (*(*(matriz + i) + j) < minFila) {
                minFila = *(*(matriz + i) + j);
                columnaMinFila = j; // Mantener la columna del minimo de la fila
            }
        }

        // Verificar si el minimo de la fila es el maximo de su columna
        bool puntoDeSilla = true;
        for (int k = 0; k < filas; ++k) { // Iterar sobre las filas de la matriz
            if (*(*(matriz + k) + columnaMinFila) > minFila && k != i) { // Comparar con la columna correspondiente en otras filas
                puntoDeSilla = false;
                break;
            }
        }

        // Si es un punto de silla, imprimir su posicion
        if (puntoDeSilla) {
            encontrado = true;
            cout << "Punto de silla encontrado en la posicion (" << i << ", " << columnaMinFila << "): " << minFila << endl;
        }
    }

    // Si no se encuentra ningun punto de silla
    if (!encontrado) {
        cout << "No se encontro ningun punto de silla en la matriz." << endl;
    }
}

int main() {
    int filas, columnas;
    // Entrada de datos: numero de filas y columnas
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> columnas;

    // Crear la matriz usando punteros
    float **matriz = new float*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new float[columnas];
    }

    // Entrada de datos: elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> *(*(matriz + i) + j);
        }
    }
    // Buscar punto de silla
    encontrarPuntoDeSilla(matriz, filas, columnas);

    // Liberar la memoria asignada para la matriz
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}
