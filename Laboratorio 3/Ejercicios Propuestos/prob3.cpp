#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
#include <cctype>
#include <vector>

class Calculadora {
private:
    std::vector<std::string> historial; // Vector para almacenar el historial de operaciones
    std::string entradaActual; // String para almacenar la entrada actual

public:
    // Constructor de la calculadora
    Calculadora() : entradaActual("") {}

    // Métodos para operaciones básicas
    double suma(double a, double b) {
        double resultado = a + b;
        historial.push_back(std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(resultado)); // Registrar la operación en el historial
        return resultado;
    }

    double resta(double a, double b) {
        double resultado = a - b;
        historial.push_back(std::to_string(a) + " - " + std::to_string(b) + " = " + std::to_string(resultado));
        return resultado;
    }

    double multiplicacion(double a, double b) {
        double resultado = a * b;
        historial.push_back(std::to_string(a) + " * " + std::to_string(b) + " = " + std::to_string(resultado));
        return resultado;
    }

    double division(double a, double b) {
        if (b != 0) {
            double resultado = a / b;
            historial.push_back(std::to_string(a) + " / " + std::to_string(b) + " = " + std::to_string(resultado));
            return resultado;
        } else {
            std::cerr << "Error: Division por cero" << std::endl;
            return 0;
        }
    }

    double cuadrado(double a) {
        double resultado = a * a;
        historial.push_back(std::to_string(a) + "^2 = " + std::to_string(resultado));
        return resultado;
    }

    double divisionUnoEntre(double a) {
        if (a != 0) {
            double resultado = 1 / a;
            historial.push_back("1 / " + std::to_string(a) + " = " + std::to_string(resultado));
            return resultado;
        } else {
            std::cerr << "Error: Division por cero" << std::endl;
            return 0;
        }
    }

    double raizCuadrada(double a) {
        if (a >= 0) {
            double resultado = sqrt(a);
            historial.push_back("sqrt(" + std::to_string(a) + ") = " + std::to_string(resultado));
            return resultado;
        } else {
            std::cerr << "Error: Raiz cuadrada de numero negativo" << std::endl;
            return 0;
        }
    }

    double porcentaje(double a, double b) {
        double resultado = (a * b) / 100;
        historial.push_back(std::to_string(a) + " % " + std::to_string(b) + " = " + std::to_string(resultado));
        return resultado;
    }

    // Evaluar una expresión matemática ingresada por el usuario
    double evaluarExpresion(const std::string& expresion) {
        std::stack<double> operandos;
        std::stack<char> operadores;
        std::istringstream entrada(expresion);
        std::string token;

        while (entrada >> token) {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
                operandos.push(std::stod(token));
            } else if (token == "(") {
                operadores.push('(');
            } else if (token == ")") {
                while (!operadores.empty() && operadores.top() != '(') {
                    realizarOperacion(operandos, operadores);
                }
                operadores.pop(); // Eliminar '('
            } else if (esOperador(token[0])) {
                while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(token[0])) {
                    realizarOperacion(operandos, operadores);
                }
                operadores.push(token[0]);
            }
        }

        while (!operadores.empty()) {
            realizarOperacion(operandos, operadores);
        }

        double resultado = operandos.top();
        historial.push_back(expresion + " = " + std::to_string(resultado));
        return resultado;
    }

    // Métodos para manejar la entrada y el historial
    void agregarCaracter(char c) {
        entradaActual.push_back(c);
    }

    void eliminarUltimoCaracter() {
        if (!entradaActual.empty()) {
            entradaActual.pop_back();
        }
    }

    void limpiarEntrada() {
        entradaActual.clear();
    }

    void limpiarHistorial() {
        historial.clear();
    }

    std::string obtenerEntradaActual() const {
        return entradaActual;
    }

    void mostrarHistorial() const {
        for (size_t i = 0; i < historial.size(); ++i) {
            std::cout << i + 1 << ": " << historial[i] << std::endl;
        }
    }

    std::string obtenerHistorial(size_t indice) const {
        if (indice < historial.size()) {
            return historial[indice];
        } else {
            return "";
        }
    }

    void actualizarHistorial(size_t indice, const std::string& nuevaExpresion) {
        if (indice < historial.size()) {
            double nuevoResultado = evaluarExpresion(nuevaExpresion);
            historial[indice] = nuevaExpresion + " = " + std::to_string(nuevoResultado);
            std::cout << "Operación actualizada y resultado resuelto: " << nuevaExpresion << " = " << nuevoResultado << std::endl;
        }
    }

    size_t obtenerTamanoHistorial() const {
        return historial.size();
    }

private:
    // Métodos auxiliares para el manejo de operadores y precedencia
    bool esOperador(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
    }

    int precedencia(char operador) {
        if (operador == '+' || operador == '-') return 1;
        if (operador == '*' || operador == '/') return 2;
        if (operador == '^') return 3;
        return 0;
    }

    // Realizar operaciones en la evaluación de expresiones
    void realizarOperacion(std::stack<double>& operandos, std::stack<char>& operadores) {
        double b = operandos.top();
        operandos.pop();
        double a = operandos.top();
        operandos.pop();
        char operador = operadores.top();
        operadores.pop();
        switch (operador) {
            case '+': operandos.push(suma(a, b)); break;
            case '-': operandos.push(resta(a, b)); break;
            case '*': operandos.push(multiplicacion(a, b)); break;
            case '/': operandos.push(division(a, b)); break;
            case '^': operandos.push(pow(a, b)); break;
            case '%': operandos.push(porcentaje(a, b)); break;
        }
    }
};

// Función para mostrar el menú de opciones
void mostrarMenu() {
    std::cout << "Seleccione una operacion:" << std::endl;
    std::cout << "1. Suma" << std::endl;
    std::cout << "2. Resta" << std::endl;
    std::cout << "3. Multiplicacion" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Exponencial cuadrado" << std::endl;
    std::cout << "6. Division especial (1 entre un numero)" << std::endl;
    std::cout << "7. Raiz cuadrada" << std::endl;
    std::cout << "8. Porcentaje" << std::endl;
    std::cout << "9. Ingresar operacion combinada" << std::endl;
    std::cout << "10. Eliminar todo el historial (CE)" << std::endl;
    std::cout << "11. Mostrar historial" << std::endl;
    std::cout << "12. Regresar a una operacion anterior" << std::endl;
    std::cout << "13. Salir" << std::endl;
}

int main() {
    Calculadora calc;
    int opcion;
    double a, b;
    std::string expresion;
    size_t indice;

    while (true) {
        mostrarMenu();
        std::cout << "Ingrese la opcion: "; std::cin >> opcion;

        if (opcion == 13) break;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese dos numeros: ";
                std::cin >> a >> b;
                std::cout << "Resultado: " << calc.suma(a, b) << std::endl;
                break;
            case 2:
                std::cout << "Ingrese dos numeros: ";
                std::cin >> a >> b;
                std::cout << "Resultado: " << calc.resta(a, b) << std::endl;
                break;
            case 3:
                std::cout << "Ingrese dos numeros: ";
                std::cin >> a >> b;
                std::cout << "Resultado: " << calc.multiplicacion(a, b) << std::endl;
                break;
            case 4:
                std::cout << "Ingrese dos numeros: ";
                std::cin >> a >> b;
                std::cout << "Resultado: " << calc.division(a, b) << std::endl;
                break;
            case 5:
                std::cout << "Ingrese un numero: ";
                std::cin >> a;
                std::cout << "Resultado: " << calc.cuadrado(a) << std::endl;
                break;
            case 6:
                std::cout << "Ingrese un numero: ";
                std::cin >> a;
                std::cout << "Resultado: " << calc.divisionUnoEntre(a) << std::endl;
                break;
            case 7:
                std::cout << "Ingrese un numero: ";
                std::cin >> a;
                std::cout << "Resultado: " << calc.raizCuadrada(a) << std::endl;
                break;
            case 8:
                std::cout << "Ingrese el valor y el porcentaje: ";
                std::cin >> a >> b;
                std::cout << "Resultado: " << calc.porcentaje(a, b) << std::endl;
                break;
            case 9:
                std::cout << "Ingrese la expresion: ";
                std::cin.ignore();
                std::getline(std::cin, expresion);
                std::cout << "Resultado: " << calc.evaluarExpresion(expresion) << std::endl;
                break;
            case 10:
                calc.limpiarHistorial();
                std::cout << "Historial eliminado." << std::endl;
                break;
            case 11:
                calc.mostrarHistorial();
                break;
            case 12:
                std::cout << "Ingrese el numero de la operacion a la que desea regresar: ";
                std::cin >> indice;
                if (indice > 0 && indice <= calc.obtenerTamanoHistorial()) {
                    std::string operacionAnterior = calc.obtenerHistorial(indice - 1);
                    std::cout << "Operacion anterior: " << operacionAnterior << std::endl;
                    std::cout << "Ingrese la nueva expresion para actualizar: ";
                    std::cin.ignore();
                    std::getline(std::cin, expresion);
                    calc.actualizarHistorial(indice - 1, expresion);
                } else {
                    std::cerr << "Indice no valido." << std::endl;
                }
                break;
            default:
                std::cerr << "Opcion no valida." << std::endl;
                break;
        }
    }

    return 0;
}

