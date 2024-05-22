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

    // Método para obtener el número de asientos ocupados
    int obtenerAsientosOcupados() const {
        int count = 0;
        for (bool asiento : asientos) {
            if (asiento) {
                ++count;
            }
        }
        return count;
    }

    // Método para verificar si es de primera clase
    bool esPrimera() const {
        return esPrimeraClase;
    }
};

class Train {
private:
    std::vector<Carriage> vagones;
    std::string estacionPartida;
    std::string estacionLlegada;
    double precioPrimeraClase;
    double precioSegundaClase;

public:
    // Constructor
    Train(const std::string& partida, const std::string& llegada, double precio1ra, double precio2da)
        : estacionPartida(partida), estacionLlegada(llegada), precioPrimeraClase(precio1ra), precioSegundaClase(precio2da) {}

    // Método para agregar un vagón
    void agregarVagon(bool primeraClase) {
        vagones.emplace_back(primeraClase);
    }

    // Método para ocupar asientos en todos los vagones
    void ocuparAsientosEnVagones() {
        for (auto& vagon : vagones) {
            vagon.ocuparAsientos();
        }
    }

    // Método para calcular el total de ventas de tickets
    double calcularTotalVentas() const {
        double totalVentas = 0;
        for (const auto& vagon : vagones) {
            int asientosOcupados = vagon.obtenerAsientosOcupados();
            if (vagon.esPrimera()) {
                totalVentas += asientosOcupados * precioPrimeraClase;
            } else {
                totalVentas += asientosOcupados * precioSegundaClase;
            }
        }
        return totalVentas;
    }

    // Método para imprimir el estado de todos los vagones
    void imprimirEstadoVagones() const {
        for (size_t i = 0; i < vagones.size(); ++i) {
            std::cout << "Vagon " << i + 1 << " (" << (vagones[i].esPrimera() ? "Primera" : "Segunda") << " clase):" << std::endl;
            for (int j = 0; j < 40; ++j) {
                std::cout << "Asiento " << j + 1 << ": " << (vagones[i].obtenerEstadoAsiento(j) ? "Ocupado" : "Vacante") << std::endl;
            }
        }
    }
};

int main() {
    // Inicializar la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Crear un objeto Train
    Train tren("Madrid", "Barcelona", 100.0, 50.0);

    // Agregar vagones al tren
    tren.agregarVagon(true);  // Vagón de primera clase
    tren.agregarVagon(false); // Vagón de segunda clase
    tren.agregarVagon(false); // Vagón de segunda clase

    // Ocupar asientos aleatoriamente en todos los vagones
    tren.ocuparAsientosEnVagones();

    // Imprimir el estado de cada vagón
    tren.imprimirEstadoVagones();

    // Calcular y mostrar el total de ventas de tickets
    double totalVentas = tren.calcularTotalVentas();
    std::cout << "Total de ventas de tickets: " << totalVentas << " euros" << std::endl;

    return 0;
}
