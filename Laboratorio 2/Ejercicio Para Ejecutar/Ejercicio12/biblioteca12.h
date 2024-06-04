#include <iostream>
using namespace std;

// Clase base
class Vehiculo {
public:
    Vehiculo() {
        cout << "Esto es un vehículo" << endl;
    }
};

// Primera subclase derivada de la clase vehículo
class CuatroRuedas : public Vehiculo {
public:
    CuatroRuedas() {
        cout << "Objeto con cuatro ruedas son vehículos" << endl;
    }
};

// Subclase derivada de la clase base CuatroRuedas
class Carro : public CuatroRuedas {
public:
    Carro() {
        cout << "Carro tiene 4 ruedas" << endl;
    }
};
