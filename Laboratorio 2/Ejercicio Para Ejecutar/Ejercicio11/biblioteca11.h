#include <iostream>
using namespace std;

// Primera clase base
class Vehiculo {
public:
    Vehiculo() {
        cout << "Este es un vehículo" << endl;
    }
};

// Segunda clase base
class CuatroRuedas {
public:
    CuatroRuedas() {
        cout << "Este es un vehículo de cuatro ruedas" << endl;
    }
};

// Clase Carro que hereda de Vehiculo y CuatroRuedas
class Carro : public Vehiculo, public CuatroRuedas {
};
