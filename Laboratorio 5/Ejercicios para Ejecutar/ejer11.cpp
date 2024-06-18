#include <iostream> 
using namespace std; 

// Definición de la estructura Punto que contiene las coordenadas x e y
struct Punto { 
    int x, y; 
}; 

int main() { 
    // Declaración e inicialización de un arreglo de estructuras Punto para almacenar las coordenadas
    Punto punto[7] = {0, 0}; 
    
    // Ciclo para ingresar la altura de la curva en el dominio [-3, 3]
    for(int i = 0; i < 7; i++) { 
        cout <<"Introduce la altura de la curva en " << i - 3; 
        cout << ": "; 
        cin >> punto[i].y; 
        cout << endl; 
    } 
    
    // Imprimir las coordenadas resultantes
    cout <<"Las coordenadas son: " << endl; 
    for(int i = 0; i < 7; i++) { 
        cout <<"(" << i - 3 << "," << punto[i].y << ")\n"; 
    } 
    
    return 0; 
} 
