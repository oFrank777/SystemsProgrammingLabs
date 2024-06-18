#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

int main() { 
    fstream ficheroEntrada; // Declaración de fstream para lectura/escritura de archivos
    string nombre; // Variable para almacenar el nombre del archivo ingresado por el usuario
    string frase; // Variable para almacenar cada línea leída del archivo

    // Solicitar al usuario el nombre del archivo
    cout << "Dime el nombre del fichero: ";
    getline(cin, nombre); 

    // Abrir el archivo indicado por el usuario en modo lectura
    ficheroEntrada.open(nombre.c_str(), ios::in); 

    // Verificar si el archivo se abrió correctamente
    if (ficheroEntrada.is_open()) { 
        // Leer el archivo línea por línea hasta el final
        while (!ficheroEntrada.eof()) { 
            getline(ficheroEntrada, frase); 
            cout << "Leido: " << frase << endl; 
        } 
        // Cerrar el archivo después de la lectura
        ficheroEntrada.close(); 
    } 
    else {
        // Mostrar mensaje si el archivo no se pudo abrir
        cout << "Fichero inexistente o faltan permisos para abrirlo" << endl; 
    } 

    return 0; 
}
