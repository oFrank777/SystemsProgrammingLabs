#include <iostream>

using namespace std;

// Funcion para multiplicar matrices
void multiplicarMatrices(float **matrizA, float **matrizB, float **resultado, int filasA, int columnasA, int columnasB) {
    // Iterar sobre cada elemento de la matriz resultado
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            // Inicializar el valor del elemento de la matriz resultado en (i, j) como 0
            *(*(resultado + i) + j) = 0;
            // Calcular el elemento de la matriz resultado en (i, j) como el producto punto de la fila i de A y la columna j de B
            for (int k = 0; k < columnasA; ++k) {
                *(*(resultado + i) + j) += *(*(matrizA + i) + k) * *(*(matrizB + k) + j);
            }
        }
    }
}

// Funcion para imprimir una matriz
void imprimirMatriz(float **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // Imprimir el elemento de la matriz en la posicion (i, j)
            cout << *(*(matriz + i) + j) << " ";
        }
        // Salto de linea al final de cada fila
        cout << endl;
    }
}

int main() {
    int filasA, columnasA, filasB, columnasB;

    // Entrada de datos: dimensiones de las matrices
    cout << "Ingrese el numero de filas de la matriz A: ";
    cin >> filasA;
    cout << "Ingrese el numero de columnas de la matriz A: ";
    cin >> columnasA;
    cout << "Ingrese el numero de filas de la matriz B: ";
    cin >> filasB;
    cout << "Ingrese el numero de columnas de la matriz B: ";
    cin >> columnasB;

    // Verificar si las matrices pueden multiplicarse
    if (columnasA != filasB) {
        // Imprimir un mensaje de error si las dimensiones no son validas
        cout << "Error: Las matrices no pueden multiplicarse debido a dimensiones invalidas." << endl;
        return 1;
    }

    // Crear las matrices utilizando punteros
    float **matrizA = new float*[filasA];
    float **matrizB = new float*[filasB];
    float **resultado = new float*[filasA];
    for (int i = 0; i < filasA; ++i) {
        matrizA[i] = new float[columnasA];
        resultado[i] = new float[columnasB];
    }
    for (int i = 0; i < filasB; ++i) {
        matrizB[i] = new float[columnasB];
    }

    // Entrada de datos: elementos de las matrices
    cout << "Ingrese los elementos de la matriz A:" << endl;
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasA; ++j) {
            // Leer y almacenar el elemento de la matriz A en la posicion (i, j)
            cin >> *(*(matrizA + i) + j);
        }
    }
    cout << "Ingrese los elementos de la matriz B:" << endl;
    for (int i = 0; i < filasB; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            // Leer y almacenar el elemento de la matriz B en la posicion (i, j)
            cin >> *(*(matrizB + i) + j);
        }
    }

    // Multiplicar las matrices
    multiplicarMatrices(matrizA, matrizB, resultado, filasA, columnasA, columnasB);

    // Imprimir la matriz resultado
    cout << "El resultado de la multiplicacion es:" << endl;
    imprimirMatriz(resultado, filasA, columnasB);

    // Liberar la memoria asignada para las matrices
    for (int i = 0; i < filasA; ++i) {
        delete[] matrizA[i];
        delete[] resultado[i];
    }
    for (int i = 0; i < filasB; ++i) {
        delete[] matrizB[i];
    }
    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;

    return 0;
}


