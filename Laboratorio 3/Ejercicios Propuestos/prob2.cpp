#include <iostream>
using namespace std;

// Declaración de funciones
double CalcularAreaCuadrilatero(double lado1, double lado2); // Prototipo de función para calcular el área de cuadriláteros
double CalcularAreaTriangulo(double base, double altura);   // Prototipo de función para calcular el área de triángulos

// Función principal del programa
int main() {
    double lado1, lado2; // Variables para almacenar las medidas de los lados de la figura
    int opcionFigura;    // Variable para almacenar la opción seleccionada del menú
    bool continuar = true; // Variable de control para repetir el menú

    // Bucle do-while para repetir el menú de opciones y cálculo de áreas
    do { 
        // Menú para seleccionar la figura
        cout << "Seleccione la figura para calcular su área:\n";
        cout << "1 Cuadrado\n";
        cout << "2 Rectángulo\n";
        cout << "3 Triángulo\n";
        cout << "0 Salir\n";
        cin >> opcionFigura; // Leer la opción seleccionada por el usuario
        cout << endl;
        
        // Estructura switch para realizar acciones según la opción seleccionada
        switch (opcionFigura) { 
            case 1:
                // Solicitar el valor del lado del cuadrado
                cout << "Introduzca el valor de los lados del cuadrado (por ejemplo: 2):" << endl;
                cin >> lado1; // Leer el valor del lado
                if (lado1 <= 0) { // Validación de los datos de entrada
                    cout << "Los lados deben ser positivos y mayores que cero" << endl;
                } else {
                    // Calcular y mostrar el área del cuadrado
                    cout << "El área del cuadrado es: " << CalcularAreaCuadrilatero(lado1, lado1) << endl << endl;
                }
                break;
            case 2:
                // Solicitar los valores de los lados del rectángulo
                cout << "Introduzca el valor de los lados del rectángulo (por ejemplo: 2 3):" << endl;
                cin >> lado1 >> lado2; // Leer los valores de los lados
                if (lado1 <= 0 || lado2 <= 0) { // Validación de los datos de entrada
                    cout << "Los lados deben ser positivos y mayores que cero" << endl;
                } else {
                    // Calcular y mostrar el área del rectángulo
                    cout << "El área del rectángulo es: " << CalcularAreaCuadrilatero(lado1, lado2) << endl << endl;
                }
                break;
            case 3:
                // Solicitar los valores de la base y la altura del triángulo
                cout << "Introduzca el valor de la base y la altura del triángulo (por ejemplo: 2 3):" << endl;
                cin >> lado1 >> lado2; // Leer los valores de la base y la altura
                if (lado1 <= 0 || lado2 <= 0) { // Validación de los datos de entrada
                    cout << "La base y la altura deben ser positivas y mayores que cero" << endl;
                } else {
                    // Calcular y mostrar el área del triángulo
                    cout << "El área del triángulo es: " << CalcularAreaTriangulo(lado1, lado2) << endl << endl;
                }
                break;
            case 0:
                // Opción para salir del programa
                cout << "Saliendo del programa" << endl;
                continuar = false; // Cambiar el valor de la variable de control para salir del bucle
                break;
            default:
                // Manejo de opciones no válidas
                cout << "Opción no válida" << endl;
                break;
        }
    } while (continuar); // Repetir el menú mientras la variable continuar sea verdadera
    
    return 0;
}

// Definición de funciones

// Función para calcular el área de cuadriláteros (cuadrado y rectángulo)
double CalcularAreaCuadrilatero(double lado1, double lado2) {
    return lado1 * lado2; // Área de un cuadrilátero es igual a la multiplicación de sus dos lados
}

// Función para calcular el área de triángulos
double CalcularAreaTriangulo(double base, double altura) {
    return (base * altura) / 2; // Área de un triángulo es igual a la mitad del producto de su base por su altura
}