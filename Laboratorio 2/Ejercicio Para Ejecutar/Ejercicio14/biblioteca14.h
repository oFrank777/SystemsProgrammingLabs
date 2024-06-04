#include <iostream>
using namespace std;

// Clase base
class Vehiculo {
public:
    Vehiculo() {
        cout << "Este es un vehículo" << endl;
    }
};

// Clase base
class Faro {
public:
    Faro() {
        cout << "Faro del vehículo" << endl;
    }
};

// Primera subclase
class Carro : public Vehiculo {
};

// Segunda subclase
class Bus : public Vehiculo, public Faro {
};
