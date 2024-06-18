#include "deportes2.h"
#include <iostream>
#include <cstdlib> // Para funciones de generación de números aleatorios
#include <ctime>   // Para inicialización de semilla aleatoria

int main() {
    // Inicialización de la semilla aleatoria
    srand(static_cast<unsigned int>(time(nullptr)));

    // Crear equipos de baloncesto y fútbol
    Baloncesto equipoBaloncesto("Equipo de Baloncesto", 10, 5, 15, 30); // Ejemplo de valores
    Futbol equipoFutbol("Equipo de Futbol", 8, 3, 2, 20); // Ejemplo de valores

    // Generar jugadores para cada equipo
    equipoBaloncesto.generarJugadores();
    equipoFutbol.generarJugadores();

    // Mostrar información de los equipos
    std::cout << "Información del equipo de baloncesto:" << std::endl;
    equipoBaloncesto.mostrarInformacion();
    std::cout << std::endl;

    std::cout << "Información del equipo de futbol:" << std::endl;
    equipoFutbol.mostrarInformacion();
    std::cout << std::endl;

    // Listado de los mejores anotadores de triples del equipo de baloncesto
    std::cout << "Mejores anotadores de triples del equipo de baloncesto:" << std::endl;
    equipoBaloncesto.mostrarInformacion();
    std::cout << std::endl;

    // Máximo goleador de la liga de fútbol
    int maxGoles = -1;
    std::string maxGoleador;
    for (size_t i = 0; i < 3; ++i) {
        if (equipoFutbol.golesGoleadores[i] > maxGoles) {
            maxGoles = equipoFutbol.golesGoleadores[i];
            maxGoleador = equipoFutbol.nombresGoleadores[i];
        }
    }
    std::cout << "Máximo goleador de la liga de futbol: " << maxGoleador << " con " << maxGoles << " goles." << std::endl;
    std::cout << std::endl;

    // Calcular puntos en fútbol (3 puntos por victoria, 1 por empate)
    int puntosEquipoFutbol = equipoFutbol.victorias * 3 + equipoFutbol.empates;

    // Equipo ganador de la liga de fútbol
    std::cout << "Equipo ganador de la liga de futbol: ";
    if (puntosEquipoFutbol > equipoBaloncesto.victorias) {
        std::cout << equipoFutbol.nombreEquipo << " con " << puntosEquipoFutbol << " puntos." << std::endl;
    } else {
        std::cout << equipoBaloncesto.nombreEquipo << " con " << equipoBaloncesto.victorias << " puntos." << std::endl;
    }

    // Equipo ganador de la liga de baloncesto (por victorias)
    std::cout << "Equipo ganador de la liga de baloncesto: ";
    if (equipoBaloncesto.victorias > equipoFutbol.victorias) {
        std::cout << equipoBaloncesto.nombreEquipo << " con " << equipoBaloncesto.victorias << " victorias." << std::endl;
    } else {
        std::cout << equipoFutbol.nombreEquipo << " con " << equipoFutbol.victorias << " victorias." << std::endl;
    }

    return 0;
}
