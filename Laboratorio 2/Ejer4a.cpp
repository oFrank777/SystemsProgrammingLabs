#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Carriage {
private:
    std::vector<bool> asientos;
    bool esPrimeraClase;
    
public:
    // Constructor
    Carriage(bool primeraClase) : esPrimeraClase(primeraClase) {
        asientos.resize(40, false); // Inicialmente todos los asientos están vacantes
    }

    // Método para obtener el estado de un asiento
    bool obtenerEstadoAsiento(int indice) const {
        if (indice < 0 || indice >= asientos.size()) {
            std::cerr << "Índice fuera de rango." << std::endl;
            return false;
        }
        return asientos[indice];
    }

    // Método para actualizar el estado de un asiento
    void actualizarEstadoAsiento(int indice, bool estado) {
        if (indice < 0 || indice >= asientos.size()) {
            std::cerr << "Índice fuera de rango." << std::endl;
            return;
        }
        asientos[indice] = estado;
    }

    // Método para ocupar asientos aleatoriamente
    void ocuparAsientos() {
        double probabilidad = esPrimeraClase ? 0.1 : 0.4;
        for (int i = 0; i < asientos.size(); ++i) {
            double randomValue = static_cast<double>(rand()) / RAND_MAX;
            if (randomValue < probabilidad) {
                asientos[i] = true;
            }
        }
    }

    // Método para imprimir el estado de los asientos
    void imprimirEstadoAsientos() const {
        for (int i = 0; i < asientos.size(); ++i) {
            std::cout << "Asiento " << i + 1 << ": " << (asientos[i] ? "Ocupado" : "Vacante") << std::endl;
        }
    }
};

int main() {
    // Inicializar la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    // Crear un objeto Carriage de segunda clase
    Carriage vagon(false);
    // Ocupar asientos aleatoriamente
    vagon.ocuparAsientos();
    // Imprimir el estado de cada asiento
    vagon.imprimirEstadoAsientos();

    return 0;
}
