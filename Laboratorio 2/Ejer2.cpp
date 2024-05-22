#include <iostream>

class Tanque {
    double contenido;
public:
    static const int capacidad = 5000.0;
    
    Tanque() : contenido(0.0) {} // Constructor
    
    double getContenido() const {
        return contenido;
    }
    
    void agregar(double cantidad) {
        if (contenido + cantidad <= capacidad)
            contenido += cantidad;
        else
            std::cout << "No se puede agregar más al tanque, ha alcanzado su capacidad máxima." << std::endl;
    }
    
    void sacar(double cantidad) {
        if (cantidad <= contenido)
            contenido -= cantidad;
        else
            std::cout << "No se puede sacar esa cantidad, no hay suficiente en el tanque." << std::endl;
    }
    
    void sacaMitad() {
        if (contenido > 0.0)
            contenido /= 2.0;
    }
};

int main() {
    Tanque t;
    t.agregar(100); // Agrega 100 unidades al tanque
    
    while (t.getContenido() >= 1.0) {
        t.sacaMitad();
        std::cout << "Contenido actual del tanque: " << t.getContenido() << std::endl;
    }
    
    std::cout << "El contenido del tanque es menor a 1.0. Deteniendo el bucle." << std::endl;
    
    return 0;
}
