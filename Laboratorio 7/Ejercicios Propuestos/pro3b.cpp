#include <iostream>
#include <stdexcept> // Para std::invalid_argument
using namespace std;
#include <limits>  // Para std::numeric_limits

int main() {
    try {
        int num;
        cout << "Ingrese un número entero: ";
        cin >> num;

        if (cin.fail()) {
            // Limpiar el estado de cin
            cin.clear();
            // Ignorar el resto del input no válido
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Lanzar una excepción de tipo std::invalid_argument
            throw invalid_argument("Error: Entrada no válida. Se esperaba un número entero.");
        }

        cout << "El número ingresado es: " << num << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
