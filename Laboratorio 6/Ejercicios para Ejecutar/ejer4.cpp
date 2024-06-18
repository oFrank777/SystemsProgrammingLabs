#include <iostream> 
#include <fstream> 
using namespace std; 

int main() { 
    // Abrir el archivo "prueba.txt" en modo escritura
    ofstream fichero("prueba.txt"); 

    // Escribir la primera frase seguida de un salto de línea
    fichero << "Esto es una línea" << endl; 

    // Escribir la segunda frase sin salto de línea
    fichero << "Esto es otra"; 

    // Escribir la tercera frase continuando en la misma línea y luego un salto de línea
    fichero << " y esto es continuación de la anterior" << endl; 

    // Cerrar el archivo después de haber terminado de escribir
    fichero.close(); 

    return 0; 
}
