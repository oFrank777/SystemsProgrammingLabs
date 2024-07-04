#include <iostream>
using namespace std;

int main() {
    try {
        try {
            try {
                // Lanzar una excepción de tipo char
                throw 5.4f; 
            }
            catch(int i) {
                // Bloque catch para excepciones de tipo int (no será ejecutado)
            }
            catch(float k) {
                // Bloque catch para excepciones de tipo float (no será ejecutado)
            }
        }
        catch(unsigned int x) {
            // Bloque catch para excepciones de tipo unsigned int (no será ejecutado)
        }
    }
    catch(char c) {
        // Bloque catch para excepciones de tipo char
        cout << "El valor de c es: " << c << endl;
    }
    return 0;
}
