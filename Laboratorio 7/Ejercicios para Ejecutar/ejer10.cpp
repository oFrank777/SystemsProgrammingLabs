#include <iostream>
using namespace std;

int main() {
    try {
        // Lanzar una excepción de tipo char
        throw '5'; 
    } 
    catch(char c) {
        // Capturar la excepción de tipo char
        cout << "El valor de c es: " << c << endl;
    } 
    catch(int n) {
        // Capturar la excepción de tipo int (no será ejecutado en este caso)
        cout << "El valor de n es: " << n << endl;
    }
    return 0;
}
