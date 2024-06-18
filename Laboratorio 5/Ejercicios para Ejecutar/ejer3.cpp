#include <iostream> 
using namespace std; 

// Definición de la estructura Point
struct Point {
    int x = 0;  // Inicialización del atributo x con valor 0
    int y = 1;  // Inicialización del atributo y con valor 1
};

int main() {
    struct Point p1;  // Declaración de una instancia de la estructura Point llamada p1

    // Imprimir los valores iniciales de x e y
    cout << "x = " << p1.x << ", y = " << p1.y << endl; 
    
    // Cambiar el valor de y a 20
    p1.y = 20; 
    cout << "x = " << p1.x << ", y = " << p1.y << endl; 

    return 0; 
}
