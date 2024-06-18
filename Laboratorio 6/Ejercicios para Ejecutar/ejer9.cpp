#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

int main() { 
    string nombre;        // Variable para almacenar el nombre del fichero
    char datos[256];      // Arreglo para almacenar datos leídos del fichero
    int compresion;       // Variable para determinar el tipo de compresión

    cout << "Comprobador de imágenes BMP" << endl;
    cout << "Dime el nombre del fichero: "; 
    getline(cin, nombre); // Solicitar al usuario el nombre del fichero

    // Abrir el fichero en modo binario
    ifstream fichero(nombre.c_str(), ifstream::binary); 

    // Verificar si la apertura del archivo falló
    if (fichero.fail()) {
        cout << "No encontrado" << endl; 
    } else {
        // Mover el puntero de lectura al byte 30 desde el inicio del fichero
        fichero.seekg(30, fichero.beg); 
        
        // Leer 1 byte (el byte de compresión) a partir de la posición actual
        fichero.read(datos, 1); 
        
        // Cerrar el fichero después de la lectura
        fichero.close(); 
        
        // Obtener el valor del byte leído, que indica si la imagen está comprimida
        compresion = datos[0]; 
        
        // Mostrar el resultado basado en el valor del byte de compresión
        if (compresion == 0) {
            cout << "Sin compresión" << endl; 
        } else {
            cout << "BMP Comprimido" << endl; 
        } 
    } 
    return 0; 
} 
