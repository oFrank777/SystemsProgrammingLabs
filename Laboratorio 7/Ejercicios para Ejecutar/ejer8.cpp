#include <iostream>
using namespace std;

class Test {
public:
    // Constructor de la clase Test
    Test() { 
        cout << "Constructor de la prueba " << endl; 
    }
    // Destructor de la clase Test
    ~Test() { 
        cout << "Destructor de la prueba " << endl; 
    }
};

int main() {
    try {
        // Crear un objeto de la clase Test
        Test t1;
        
        // Lanzar una excepción de tipo int
        throw 10;

        // Este código nunca se ejecutará porque se lanza una excepción
        cout << "Después de throw (Nunca ejecutado)" << endl;
    } 
    catch (int i) {
        // Capturar la excepción de tipo int
        cout << "Capturado " << i << endl;
    }

    // Final del programa
    return 0;
}
