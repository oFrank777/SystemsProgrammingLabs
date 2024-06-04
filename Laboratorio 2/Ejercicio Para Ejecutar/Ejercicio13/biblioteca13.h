#include <iostream>
using namespace std;

// Clase base
class Vehiculo {
public:
    Vehiculo() {
        cout << "Esto es un vehículo" << endl;
    }
};

// Primera subclase
class Carro : public Vehiculo {
};

// Segunda subclase
class Bus : public Vehiculo {
};
