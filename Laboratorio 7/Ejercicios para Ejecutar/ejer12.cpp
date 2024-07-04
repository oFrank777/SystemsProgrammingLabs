
#include <iostream>
#include <cmath>
using namespace std;

// Definición de constantes para diferentes tipos de errores
static const int EDOMINIO = 100;
static const int ERANGO = 101;

// Clase para manejar errores matemáticos
class ErrorMat {
public:
    ErrorMat() : motivo(0) {};  // Constructor por defecto
    ErrorMat(int m) : motivo(m) {};  // Constructor con motivo de error
    const char* porque() const throw();  // Método para obtener la descripción del error
private:
    int motivo;  // Código del motivo del error
};

// Implementación del método que devuelve la descripción del error
const char* ErrorMat::porque() const throw() {
    switch (motivo) {
        case EDOMINIO: return "Error de Dominio"; break;
        case ERANGO: return "Error de Rango"; break;
        default: return "Error Desconocido";  // En rigor no debería ocurrir tal Excepción
    }
}

// Función que calcula el logaritmo y maneja excepciones
double logaritmo(const double n) {
    try {
        if (n < 0) throw(ErrorMat(EDOMINIO));  // Lanza excepción si el número es negativo
        if (n == 0) throw(ErrorMat(ERANGO));   // Lanza excepción si el número es cero
        return log(n);  // Calcula el logaritmo si no hay excepciones
    }
    catch(ErrorMat& e) {
        cout << e.porque();  // Muestra la descripción del error
    }
    return 0;  // Retorna 0 en caso de error
}

// Función principal del programa
int main() {
    double r = -100;
    cout << "log(" << r << ") = " << logaritmo(r) << endl;       // Logaritmo de un número positivo
    cout << "log(-" << r << ") = " << logaritmo(-r) << endl;     // Logaritmo de un número negativo
    cin.get();
    return 0;
}
