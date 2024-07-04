#include <exception>
#include <iostream>
#include <math.h>

using namespace std;

// Definición de la clase de excepción personalizada RaizExepcion
class RaizExepcion : public exception {
public:
    // Constructor que inicializa el motivo de la excepción
    RaizExepcion(int mot) : exception(), motivo(mot) {}

    // Método what() que devuelve un mensaje descriptivo del error
    const char *what() const throw();

private:
    int motivo;  // Variable que almacena el motivo del error
};

// Implementación del método what() para devolver el mensaje de error
const char *RaizExepcion::what() const throw() {
    switch (motivo) {
        case 1:
            return "No_raices_reales";  // Error cuando no hay raíces reales
        case 2:
            return "primer_coeficiente_cero";  // Error cuando el primer coeficiente es cero
        default:
            return "Error desconocido";  // Cualquier otro error desconocido
    }
}

// Función que resuelve la ecuación cuadrática
double *resolverEC(int a, int b, int c) {
    if (a == 0) {
        throw RaizExepcion(2);  // Lanza excepción si el primer coeficiente es cero
    }

    int dec = b * b - 4 * a * c;
    if (dec < 0) {
        throw RaizExepcion(1);  // Lanza excepción si no hay raíces reales
    }

    // Calcula las raíces y las almacena en un arreglo
    double *sol = new double[2];
    sol[0] = (-b + sqrt(dec)) / (2 * a);
    sol[1] = (-b - sqrt(dec)) / (2 * a);
    return sol;
}

int main() {
    int a = 1;
    int b = 9;
    int c = 2;

    try {
        // Llama a la función resolverEC y muestra las soluciones si no hay excepciones
        double *sols = resolverEC(a, b, c);
        cout << "Soluciones: " << sols[0] << ", " << sols[1] << endl;
    } catch (const RaizExepcion &e) {
        // Captura y muestra el mensaje de error si se lanza una excepción
        cout << "Excepción: " << e.what() << endl;
    }

    return 0;
}
