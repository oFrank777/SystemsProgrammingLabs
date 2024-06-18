#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

int main() { 
    ifstream ficheroEntrada; // Declaración de ifstream para lectura de archivos
    string frase; // Variable para almacenar la línea leída del archivo

    // Abrir el archivo "ficheroTexto.txt" en modo lectura
    ficheroEntrada.open("ficheroTexto.txt"); 
    
    // Leer una línea del archivo usando la función getline
    getline(ficheroEntrada, frase); 
    
    // Cerrar el archivo después de la lectura
    ficheroEntrada.close(); 
    
    // Mostrar la línea leída por pantalla
    cout << "Frase leida: " << frase << endl; 
    
    return 0; 
}
