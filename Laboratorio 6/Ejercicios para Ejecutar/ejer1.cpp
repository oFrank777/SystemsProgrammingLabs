#include <iostream> 
#include <fstream> 
using namespace std; 

int main() { 
    // Declaramos una variable de tipo ofstream para manejar la salida de archivos
    ofstream ficheroSalida; 
    
    // Abrimos (creamos) el archivo "ficheroTexto.txt"
    ficheroSalida.open("ficheroTexto.txt"); 
    
    // Escribimos la frase "Texto para el fichero" en el archivo
    ficheroSalida << "Texto para el fichero"; 
    
    // Cerramos el archivo para asegurarnos de que se guarden los cambios
    ficheroSalida.close(); 
    
    return 0; 
}
