#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

// Clase derivada de "exception" para manejar excepciones de copia de ficheros.
class CopiaEx: public exception {
public:
    CopiaEx(int mot) : exception(), motivo(mot) {}
    const char* what() const throw();
private:
    int motivo;
};

// Implementación del método what() que devuelve la descripción del error
const char* CopiaEx::what() const throw() {
    switch(motivo) {
        case 1:
            return "Fichero de origen no existe";
        case 2:
            return "No es posible abrir el fichero de salida";
    }
    return "Error inesperado";
}

// Declaración de la función que realiza la copia del fichero
void CopiaFichero(const char* Origen, const char *Destino);

int main() {
    char Desde[] = "excepcion.cpp";  // Nombre del fichero origen
    char Hacia[] = "excepcion.cpy";  // Nombre del fichero destino
    try {
        CopiaFichero(Desde, Hacia);  // Intentar copiar el fichero
    }
    catch(CopiaEx &ex) {
        cout << ex.what() << endl;  // Capturar y mostrar la excepción
    }
    return 0;
}

// Implementación de la función que realiza la copia del fichero
void CopiaFichero(const char* Origen, const char *Destino) {
    unsigned char buffer[1024];
    int leido;
    ifstream fe(Origen, ios::in | ios::binary);
    if(!fe.good()) throw CopiaEx(1);  // Lanzar excepción si el fichero origen no existe
    ofstream fs(Destino, ios::out | ios::binary);
    if(!fs.good()) throw CopiaEx(2);  // Lanzar excepción si no se puede abrir el fichero destino
    do {
        fe.read(reinterpret_cast<char *> (buffer), 1024);
        leido = fe.gcount();
        fs.write(reinterpret_cast<char *> (buffer), leido);
    } while(leido);
    fe.close();
    fs.close();
}
