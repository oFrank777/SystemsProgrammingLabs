#include <iostream>
using namespace std;

// Definición de la estructura Record
struct Record {
    static int x; // Declaración de un miembro estático 'x' dentro de la estructura
};

// Inicialización del miembro estático 'x'
int Record::x = 0;

// Programa principal
int main() {
    return 0;
}
