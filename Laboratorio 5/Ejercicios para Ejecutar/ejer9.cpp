#include <iostream> 
using namespace std; 

// Definición de la estructura 'persona' que contiene los datos de cada persona
struct persona { 
    char nombre[15];     // Nombre de la persona
    char apellido[15];   // Apellido de la persona
    int edad;            // Edad de la persona
    char sexo[15];       // Sexo de la persona
    int telefono;        // Teléfono de la persona
};

int main() { 
    persona amigo[2];    // Arreglo de estructuras 'persona' para almacenar los datos de cinco personas
    
    // Ciclo para ingresar los datos de las cinco personas
    for (int i = 0; i < 2; i++) { 
        cout <<"Escriba el Nombre "<< i + 1 << ": "; 
        cin >> amigo[i].nombre; 
        
        cout << "\nEscriba el Apellido " << i + 1 << ": "; 
        cin >> amigo[i].apellido; 
        
        cout << "\nEscriba la Edad de " << i + 1 << ": "; 
        cin >> amigo[i].edad; 
        
        cout << "\nEscriba el sexo " << i + 1 << ": "; 
        cin >> amigo[i].sexo; 
        
        cout << "\nEscriba el Telefono de " << i + 1 << ": "; 
        cin >> amigo[i].telefono; 
        
        cout << endl; 
    } 
    
    // Imprimir los datos registrados de las personas ingresadas
    cout << "El registro de personas que se introdujeron es: \n\n"; 
    for (int i = 0; i < 2; i++) { 
        cout << "\t" << amigo[i].nombre; 
        cout << "\t" << amigo[i].apellido; 
        cout << "\t" << amigo[i].edad; 
        cout << "\t" << amigo[i].sexo; 
        cout << "\t" << amigo[i].telefono << "\n\n"; 
    } 
    
    return 0; 
}
