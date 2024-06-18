#include "deportes2.h"
#include <iostream>
#include <cstdlib> // Para funciones de generación de números aleatorios

Equipo::Equipo(std::string nombre, int victorias, int derrotas)
    : nombreEquipo(nombre), victorias(victorias), derrotas(derrotas) {}

Equipo::~Equipo() {}

Baloncesto::Baloncesto(std::string nombre, int victorias, int derrotas, int perdidas, int rebotes)
    : Equipo(nombre, victorias, derrotas), perdidasBalon(perdidas), rebotesCogidos(rebotes) {}

void Baloncesto::generarJugadores() {
    for (int i = 1; i <= 3; ++i) {
        nombresAnotadoresTriples.push_back("Jugador " + std::to_string(i));
        triplesAnotadores.push_back(rand() % 20); // Genera entre 0 y 19 triples
    }
}

void Baloncesto::mostrarInformacion() const {
    std::cout << "Equipo de Baloncesto: " << nombreEquipo << std::endl;
    std::cout << "Victorias: " << victorias << ", Derrotas: " << derrotas << std::endl;
    std::cout << "Pérdidas de balón: " << perdidasBalon << ", Rebotes cogidos: " << rebotesCogidos << std::endl;
    std::cout << "Mejores anotadores de triples:" << std::endl;
    for (size_t i = 0; i < nombresAnotadoresTriples.size(); ++i) {
        std::cout << nombresAnotadoresTriples[i] << ": " << triplesAnotadores[i] << " triples" << std::endl;
    }
}

Futbol::Futbol(std::string nombre, int victorias, int derrotas, int empates, int goles)
    : Equipo(nombre, victorias, derrotas), empates(empates), golesFavor(goles) {}

void Futbol::generarJugadores() {
    for (int i = 1; i <= 3; ++i) {
        nombresGoleadores.push_back("Jugador " + std::to_string(i));
        golesGoleadores.push_back(rand() % 10); // Genera entre 0 y 9 goles
    }
}

void Futbol::mostrarInformacion() const {
    std::cout << "Equipo de Futbol: " << nombreEquipo << std::endl;
    std::cout << "Victorias: " << victorias << ", Derrotas: " << derrotas << std::endl;
    std::cout << "Empates: " << empates << ", Goles a favor: " << golesFavor << std::endl;
    std::cout << "Goleadores:" << std::endl;
    for (size_t i = 0; i < nombresGoleadores.size(); ++i) {
        std::cout << nombresGoleadores[i] << ": " << golesGoleadores[i] << " goles" << std::endl;
    }
}
