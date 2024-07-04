#include <iostream>
using namespace std;

// Definición de una clase de excepción personalizada
class DivisionByZeroException {
public:
    const char* what() const {
        return "Error: División por cero";
    }
};

// Función que realiza la división de dos números
double divide(double numerator, double denominator) {
    try {
        if (denominator == 0) {
            // Generar una excepción en caso de división por cero
            throw DivisionByZeroException();
        }
        return numerator / denominator;
    } catch (const DivisionByZeroException& e) {
        // Capturar la excepción y manejarla dentro de la función
        cerr << "Excepción capturada en la función divide: " << e.what() << endl;
        // Relanzar la excepción para que sea tratada en el main
        throw;
    }
}

int main() {
    double num, denom;
    
    // Solicitar al usuario que ingrese el numerador y el denominador
    cout << "Ingrese el numerador: ";
    cin >> num;
    cout << "Ingrese el denominador: ";
    cin >> denom;
    
    try {
        // Intentar realizar la división
        double result = divide(num, denom);
        // Mostrar el resultado si no hay excepción
        cout << "El resultado es: " << result << endl;
    } catch (const DivisionByZeroException& e) {
        // Capturar y manejar la excepción si el divisor es cero
        cerr << "Excepción capturada en main: " << e.what() << endl;
    }
    
    return 0;
}