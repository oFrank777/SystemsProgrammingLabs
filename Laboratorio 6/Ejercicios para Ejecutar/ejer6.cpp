#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

int main() { 
    // Solicitar al usuario el nombre del fichero
    cout << "Dime el nombre del fichero: "; 
    string nombre; 
    getline(cin, nombre); // Leer el nombre del fichero desde la entrada estándar

    // Abrir el archivo especificado por el usuario en modo lectura
    ifstream fichero(nombre.c_str()); 

    // Verificar si el archivo se abrió correctamente
    if (!fichero.is_open()) {
        cout << "No se pudo abrir el fichero." << endl;
        return 1; // Salir del programa con código de error
    }

    // Variable para almacenar la línea leída del archivo
    string linea; 
    getline(fichero, linea); // Leer toda la línea del archivo

    // Mostrar el mensaje indicando que se ha leído una línea
    cout << "Se ha leido: " << endl; 
    // Mostrar la línea leída del archivo en la consola
    cout << linea << endl; 

    // Cerrar el archivo después de haber terminado de leer
    fichero.close(); 

    return 0; // Salir del programa con éxito
}
