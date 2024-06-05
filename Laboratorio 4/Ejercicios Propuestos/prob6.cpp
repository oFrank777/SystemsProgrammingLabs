#include <iostream>

using namespace std;

const int N = 3; // Tamaño de la matriz NxN

// Función para calcular la transpuesta de la matriz
void transpuesta(int* matriz, int* transpuesta, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            *(transpuesta + j * n + i) = *(matriz + i * n + j);
        }
    }
}

// Función para verificar si la matriz es simétrica
bool esSimetrica(int* matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (*(matriz + i * n + j) != *(matriz + j * n + i)) {
                return false;
            }
        }
    }
    return true;
}

// Función para verificar si la matriz es antisimétrica
bool esAntisimetrica(int* matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (*(matriz + i * n + j) != -*(matriz + j * n + i)) {
                return false;
            }
        }
    }
    return true;
}

// Función para verificar si la matriz es triangular superior
bool esTriangularSuperior(int* matriz, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (*(matriz + i * n + j) != 0) {
                return false;
            }
        }
    }
    return true;
}

// Función para verificar si la matriz es triangular inferior
bool esTriangularInferior(int* matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (*(matriz + i * n + j) != 0) {
                return false;
            }
        }
    }
    return true;
}

// Función para imprimir la matriz
void imprimirMatriz(int* matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << *(matriz + i * n + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[N][N] = {};


    // Descomenta esta sección para pedir la matriz al usuario
    cout << "Ingrese los elementos de la matriz (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Mostrar la matriz ingresada por el usuario
    cout << "Matriz a operar:" << endl;
    imprimirMatriz(&matriz[0][0], N);

    int transpuestaMatriz[N][N];

    int opcion;
    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Calcular la transpuesta de A" << endl;
        cout << "2. Verificar si A es simetrica o antisimetrica" << endl;
        cout << "3. Verificar si A es triangular superior o triangular inferior" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                transpuesta(&matriz[0][0], &transpuestaMatriz[0][0], N);
                cout << "La transpuesta de la matriz es:" << endl;
                imprimirMatriz(&transpuestaMatriz[0][0], N);
                break;
            case 2:
                if (esSimetrica(&matriz[0][0], N)) {
                    cout << "La matriz es simetrica" << endl;
                } else if (esAntisimetrica(&matriz[0][0], N)) {
                    cout << "La matriz es antisimetrica" << endl;
                } else {
                    cout << "La matriz no es ni simetrica ni antisimetrica" << endl;
                }
                break;
            case 3:
                if (esTriangularSuperior(&matriz[0][0], N)) {
                    cout << "La matriz es triangular superior" << endl;
                } else if (esTriangularInferior(&matriz[0][0], N)) {
                    cout << "La matriz es triangular inferior" << endl;
                } else {
                    cout << "La matriz no es ni triangular superior ni triangular inferior" << endl;
                }
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
