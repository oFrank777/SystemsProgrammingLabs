#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función que muestra el menú de opciones
void mostrarMenu() {
    // Muestra las opciones disponibles al usuario
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Determinar pares e impares de 10" 
            "numeros enteros." << endl;
    cout << "2. Mostrar los primeros 100 numeros" 
            "perfectos." << endl;
    cout << "3. Invertir un numero entero de cuatro" 
            "digitos." << endl;
    cout << "4. Salir" << endl;
}

// Función para determinar pares e impares de 10 números 
// enteros ingresados por el usuario
void paresEImpares() {
    // Se crea un vector para almacenar los 10 números 
    // ingresados por el usuario
    vector<int> numeros(10);
    cout << "Ingrese 10 numeros enteros separados por"
            "espacios:" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> numeros[i];
    }

    // Muestra los números pares
    cout << "Numeros pares:" << endl;
    for (int num : numeros) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
    }
    cout << endl;

    // Muestra los números impares
    cout << "Numeros impares:" << endl;
    for (int num : numeros) {
        if (num % 2 != 0) {
            cout << num << " ";
        }
    }
    cout << endl;
}

// Función para determinar si un número es perfecto
void numerosPerfectos() {
    // Función lambda para determinar si un número es perfecto
    auto esNumeroPerfecto = [](int num) {
        int sum = 1;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }
        return sum == num;
    };

    // Inicialización de variables
    int contador = 0;
    int num = 1;
    cout << "Primeros 100 numeros perfectos:" << endl;
    // Bucle para encontrar los primeros 100 números perfectos
    while (contador < 4) {
        if (esNumeroPerfecto(num)) {
            cout << num << " ";
            ++contador;
        }
        ++num;
    }
    cout << endl;
}

// Función para invertir un número entero de cuatro dígitos
int invertirNumero(int num) {
    int invertido = 0;
    // Se invierte el número
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}

void invertirNumeroCuatroDigitos() {
    // Se solicita al usuario ingresar un número entero de cuatro dígitos
    int num;
    cout << "Ingrese un numero entero de cuatro digitos: ";
    cin >> num;
    // Se verifica si el número tiene cuatro dígitos
    if (num < 1000 || num > 9999) {
        cout << "El numero no tiene cuatro digitos." << endl;
        return;
    }
    // Se invierte el número y se muestra el resultado
    int invertido = invertirNumero(num);
    cout << "Numero invertido: " << invertido << endl;
}

int main() {
    // Variable para almacenar la opción seleccionada por el usuario
    int opcion;
    // Menú interactivo
    do {
        mostrarMenu();
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                paresEImpares();
                break;
            case 2:
                numerosPerfectos();
                break;
            case 3:
                invertirNumeroCuatroDigitos();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor,"
                "seleccione una opcion valida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
