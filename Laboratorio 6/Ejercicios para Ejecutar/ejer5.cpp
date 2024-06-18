#include <iostream> 
#include <fstream> 
using namespace std; 

int main() { 
    // Abrir el archivo "prueba.txt" en modo lectura
    ifstream fichero("prueba.txt"); 

    // Variable para almacenar la línea leída del archivo
    string linea; 

    // Leer una línea del archivo
    fichero >> linea; 

    // Mostrar el mensaje indicando que se ha leído una línea
    cout << "Se ha leido: " << endl; 
    // Mostrar la línea leída
    cout << linea << endl; 

    // Cerrar el archivo después de haber terminado de leer
    fichero.close(); 

    return 0; 
}
