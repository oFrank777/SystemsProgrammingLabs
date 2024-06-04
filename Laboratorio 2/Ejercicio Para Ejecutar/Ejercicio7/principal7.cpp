#include "biblioteca7.h"

// Función principal
int main() {
    // El obj1 llamará al constructor por defecto
    Alumnos obj1;
    cout << "Alumno id es: " << obj1.id << endl;

    // El obj2 llamará al constructor parametrizado
    Alumnos obj2(21);
    cout << "Alumno id es: " << obj2.id << endl;

    // Finalización del programa
    return 0;
}
