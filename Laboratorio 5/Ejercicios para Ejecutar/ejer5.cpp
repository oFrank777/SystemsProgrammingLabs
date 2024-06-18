#include <iostream> 
using namespace std;

// Definición de la estructura Point
struct Point {
    int x, y;  // Atributos de la estructura Point: x e y
};

int main() {
    // Crear un arreglo de estructuras Point con tamaño 10
    struct Point arr[10]; 
    
    // Acceder y asignar valores a los atributos de la primera estructura en el arreglo
    arr[0].x = 10; 
    arr[0].y = 20; 
    
    // Imprimir los valores de los atributos x e y de la primera estructura en el arreglo
    cout << "arr[0].x = " << arr[0].x << ", arr[0].y = " << arr[0].y << endl; 
    
    return 0; 
}
