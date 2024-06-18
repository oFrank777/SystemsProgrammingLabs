#include <iostream> 
#include <fstream> 
#include <string> 
#include <cstdlib> 
using namespace std; 

int main() { 
    string nombre; 
    string linea; 

    // Solicitar al usuario el nombre del fichero
    cout << "Dime el nombre del fichero: "; 
    getline(cin, nombre); 

    // Intentar abrir el archivo especificado por el usuario en modo lectura
    ifstream fichero(nombre.c_str()); 

    // Verificar si la apertura del archivo falló
    if (fichero.fail()) { 
        cout << "No existe el fichero!" << endl; 
        exit(1); // Salir del programa con código de error
    } 

    // Leer y mostrar cada línea del archivo hasta llegar al final
    while (!fichero.eof()) { 
        getline(fichero, linea); 
        if (!fichero.eof()) // Evitar mostrar una línea extra al final del archivo
            cout << linea << endl;
    } 

    // Cerrar el archivo después de haber terminado de leer
    fichero.close(); 

    return 0; // Salir del programa con éxito
} 
