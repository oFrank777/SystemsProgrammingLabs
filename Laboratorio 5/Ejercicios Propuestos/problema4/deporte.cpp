#include "deporte.h"
#include <iostream>

// Implementación de Equipo
Equipo::Equipo(std::string nombre, int victorias, int derrotas)
    : nombreEquipo(nombre), victorias(victorias), derrotas(derrotas) {}

Equipo::~Equipo() {}

// Implementación de Baloncesto
Baloncesto::Baloncesto(std::string nombre, int victorias, int derrotas, int perdidas, int rebotes, std::string nombreAnotador, int triples)
    : Equipo(nombre, victorias, derrotas), perdidasBalon(perdidas), rebotesCogidos(rebotes), nombreMejorAnotadorTriples(nombreAnotador), triplesMejorAnotador(triples) {}

void Baloncesto::mostrarInformacion() const {
    std::cout << "Equipo de Baloncesto: " << nombreEquipo << std::endl;
    std::cout << "Victorias: " << victorias << ", Derrotas: " << derrotas << std::endl;
    std::cout << "Pérdidas de balón: " << perdidasBalon << ", Rebotes cogidos: " << rebotesCogidos << std::endl;
    std::cout << "Mejor anotador de triples: " << nombreMejorAnotadorTriples << " con " << triplesMejorAnotador << " triples." << std::endl;
}

// Implementación de Futbol
Futbol::Futbol(std::string nombre, int victorias, int derrotas, int empates, int goles, std::string nombreGoleador, int golesGoleador)
    : Equipo(nombre, victorias, derrotas), empates(empates), golesFavor(goles), nombreGoleador(nombreGoleador), golesGoleador(golesGoleador) {}

void Futbol::mostrarInformacion() const {
    std::cout << "Equipo de Futbol: " << nombreEquipo << std::endl;
    std::cout << "Victorias: " << victorias << ", Derrotas: " << derrotas << std::endl;
    std::cout << "Empates: " << empates << ", Goles a favor: " << golesFavor << std::endl;
    std::cout << "Goleador: " << nombreGoleador << " con " << golesGoleador << " goles." << std::endl;
}
