#include <fstream> 
#include <iostream> 
using namespace std; 

int main() { 
    char l; // Variable para almacenar cada caracter leído o escrito
    long i, lon; // Variables para índices y longitud del archivo

    // Abrir el archivo prueba.dat en modo lectura/escritura binaria, truncando si existe
    fstream fich("prueba.dat", ios::in | ios::out | ios::trunc | ios::binary); 

    // Escribir la palabra "abracadabra" en el archivo y asegurarse de que se guarde
    fich << "abracadabra" << flush; 

    // Obtener la longitud actual del archivo
    fich.seekg(0L, ios::end); 
    lon = fich.tellg(); 

    // Recorrer el archivo caracter por caracter
    for(i = 0L; i < lon; i++) { 
        fich.seekg(i, ios::beg); 
        fich.get(l); // Leer el caracter en la posición actual

        // Si el caracter es 'a', reemplazarlo por 'e'
        if(l == 'a') { 
            fich.seekp(i, ios::beg); // Mover el puntero de escritura a la posición actual
            fich << 'e'; // Escribir 'e' en lugar de 'a'
        } 
    } 

    cout << "Salida:" << endl; 

    // Mostrar el contenido modificado del archivo
    fich.seekg(0L, ios::beg); 
    for(i = 0L; i < lon; i++) { 
        fich.get(l); // Leer cada caracter del archivo
        cout << l; // Mostrar el caracter leído
    } 
    cout << endl; 

    fich.close(); // Cerrar el archivo
    return 0; 
} 
