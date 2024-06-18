#include <iostream> 
using namespace std; 

// Definición de la estructura marks
struct marks { 
    int num; 
    
    // Función miembro Set para asignar un valor a 'num'
    void Set(int temp) 
    { 
        num = temp; 
    } 
    
    // Función miembro display para mostrar el valor de 'num'
    void display() 
    { 
        cout << "num = " << num << endl; 
    } 
}; 

// Programa principal
int main() 
{ 
    marks m1; // Creación de un objeto 'marks' llamado m1
    
    m1.Set(9); // Llamada al método Set para asignar el valor 9 a 'num'
    m1.display(); // Llamada al método display para mostrar el valor de 'num'
    
    return 0; 
} 
