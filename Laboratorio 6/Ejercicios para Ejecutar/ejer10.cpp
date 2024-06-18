#include <iostream> 
#include <fstream> 
using namespace std; 

int main() { 
    int i; 
    char mes[][20] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", 
                      "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", 
                      "Diciembre"};
    char cad[20]; 

    // Crear el archivo meses.dat y escribir los nombres de los meses en él
    ofstream fsalida("meses.dat", ios::out | ios::binary); 
    cout << "Crear archivo de nombres de meses:" << endl; 
    for(i = 0; i < 12; i++) {
        fsalida.write(mes[i], 20); // Escribir cada nombre de mes en el archivo, 20 caracteres por nombre
    }
    fsalida.close(); 

    // Abrir el archivo para lectura
    ifstream fentrada("meses.dat", ios::in | ios::binary); 

    // Acceso secuencial: Leer y mostrar los nombres de los meses secuencialmente
    cout << "\nAcceso secuencial:" << endl; 
    fentrada.read(cad, 20); // Leer el primer nombre de mes
    while (!fentrada.eof()) {
        cout << cad << endl; // Mostrar el nombre leído
        fentrada.read(cad, 20); // Leer el siguiente nombre de mes
    }
    fentrada.clear(); 

    // Acceso aleatorio: Leer y mostrar los nombres de los meses en orden inverso
    cout << "\nAcceso aleatorio:" << endl; 
    for(i = 11; i >= 0; i--) { // Iterar desde Diciembre hasta Enero
        fentrada.seekg(20*i, ios::beg); // Mover el puntero de lectura a la posición del mes correspondiente
        fentrada.read(cad, 20); // Leer el nombre de mes desde la posición actual
        cout << cad << endl; // Mostrar el nombre de mes
    }

    // Calcular el número de elementos almacenados en el fichero
    fentrada.seekg(0, ios::end); // Mover el puntero de lectura al final del fichero
    int pos = fentrada.tellg(); // Obtener la posición actual del puntero de lectura
    cout << "\nNúmero de registros: " << pos/20 << endl; // Calcular y mostrar el número de registros

    fentrada.close(); // Cerrar el archivo
    return 0; 
} 
