#include "biblioteca9.h"

// Función principal
int main() {
    Hijo obj1;

    // Un objeto de clase Hijo tiene todos los datos de la clase Padre
    // y todas las funciones de la clase Padre del padre
    obj1.id_c = 7;
    obj1.id_p = 91;

    cout << "El id del hijo es: " << obj1.id_c << endl;
    cout << "El id del padre es: " << obj1.id_p << endl;

    // Finalización del programa
    return 0;
}
