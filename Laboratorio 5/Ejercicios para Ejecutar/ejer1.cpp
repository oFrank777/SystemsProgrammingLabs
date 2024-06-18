#include <iostream>
using namespace std;

// Definición de la estructura 'persona' que almacena datos de una persona
struct persona {
    char nombre[15];   // Nombre de la persona
    char apellido[15]; // Apellido de la persona
    int edad;          // Edad de la persona
    char sexo[15];     // Sexo de la persona
    int telefono;      // Teléfono de la persona
};

int main() {
    // Declaración de un arreglo de 5 estructuras 'persona'
    persona amigo[5]; 

    // Bucle para ingresar los datos de 5 personas
    for (int i = 0; i < 5; i++) {
        cout << "Escriba el Nombre " << i + 1 << ": ";
        cin >> amigo[i].nombre; // Lectura del nombre
        cout << "\nEscriba el Apellido " << i + 1 << ": ";
        cin >> amigo[i].apellido; // Lectura del apellido
        cout << "\nEscriba la Edad de " << i + 1 << ": ";
        cin >> amigo[i].edad; // Lectura de la edad
        cout << "\nEscriba el sexo " << i + 1 << ": ";
        cin >> amigo[i].sexo; // Lectura del sexo
        cout << "\nEscriba el Telefono de " << i + 1 << ": ";
        cin >> amigo[i].telefono; // Lectura del teléfono
        cout << endl;
    }

    // Mostrar los datos registrados de las 5 personas
    cout << "El registro de personas que se introdujeron es: \n\n";
    for (int i = 0; i < 5; i++) {
        cout << "\t" << amigo[i].nombre;    // Mostrar el nombre
        cout << "\t" << amigo[i].apellido;  // Mostrar el apellido
        cout << "\t" << amigo[i].edad;      // Mostrar la edad
        cout << "\t" << amigo[i].sexo;      // Mostrar el sexo
        cout << "\t" << amigo[i].telefono;  // Mostrar el teléfono
        cout << "\n\n";
    }

    return 0;
}
