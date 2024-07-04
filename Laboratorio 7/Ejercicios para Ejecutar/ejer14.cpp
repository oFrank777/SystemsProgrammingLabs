
#include <iostream>
using namespace std;

// Declaración de la función Programa
void Programa();

int main() {
    try {
        // Llamada a la función Programa
        Programa();
    }
    catch(int x) {
        // Captura de la excepción relanzada
        cout << "Excepción relanzada capturada." << endl;
        cout << "error: " << x << endl;
    }
    catch(...) {
        // Captura de cualquier otra excepción
        cout << "Excepción inesperada." << endl;
    }
    cin.get();
    return 0;
}

// Implementación de la función Programa
void Programa() {
    try {
        // Operaciones que pueden lanzar excepciones
        throw 10;
    }
    catch(int x) {
        // Relanzar la excepción, no se maneja aquí
        throw;
    }
}
