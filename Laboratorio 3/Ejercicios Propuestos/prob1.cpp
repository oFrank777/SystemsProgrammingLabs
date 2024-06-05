#include <iostream>
using namespace std;

double Suma(double x, double y) {
    return x + y;
}

double Producto(double x, double y) {
    return x * y;
}

int main() {
    double a, b;
    int c;
    
    cout << "Escribe un numero: ";
    cin >> a;
    cout << "Escribe otro numero: ";
    cin >> b;
    cout << "Que operacion deseas hacer? (1 para suma, 2 para producto): ";
    cin >> c;

    if (c == 1) {
        cout << "El resultado de la suma es: " << Suma(a, b) << endl;
    } else if (c == 2) {
        cout << "El resultado del producto es: " << Producto(a, b) << endl;
    } else {
        cout << "Opcion no válida." << endl;
    }

    return 0;
}
