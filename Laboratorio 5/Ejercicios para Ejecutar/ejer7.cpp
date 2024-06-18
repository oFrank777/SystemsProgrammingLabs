#include <iostream> 
using namespace std; 

int main() 
{ 
    // Definición de una estructura anónima en el contexto de la función main
    struct 
    { 
        string nombre;   // Atributo para almacenar el nombre de la persona
        char inicial;    // Atributo para almacenar la inicial del nombre
        int edad;        // Atributo para almacenar la edad de la persona
        float nota;      // Atributo para almacenar la nota de la persona
    } persona;  // Declaración de una variable tipo estructura persona

    // Asignación de valores a los atributos de la estructura persona
    persona.nombre = "Juan";    // Asigna el nombre "Juan" al atributo nombre
    persona.inicial = 'J';      // Asigna la inicial 'J' al atributo inicial
    persona.edad = 20;          // Asigna la edad 20 al atributo edad
    persona.nota = 7.5;         // Asigna la nota 7.5 al atributo nota

    // Impresión del valor del atributo edad de la estructura persona
    cout << "La edad es " << persona.edad << endl; 

    return 0; 
}
