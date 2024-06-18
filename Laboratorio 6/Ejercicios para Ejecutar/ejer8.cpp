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
    
    // Verificar si el fichero tiene contenido
    if (!fichero.eof()) { 
        getline(fichero, linea); 
        if (linea == "") { 
            cout << "Fichero vacío" << endl; 
            exit(1); // Salir del programa con código de error
        } 
    } 

    // Si se ha leído alguna línea, el fichero tiene contenido
    cout << "El fichero tiene contenido" << endl; 

    // Cerrar el archivo después de haber terminado de leer
    fichero.close(); 

    return 0; // Salir del programa con éxito
} 
