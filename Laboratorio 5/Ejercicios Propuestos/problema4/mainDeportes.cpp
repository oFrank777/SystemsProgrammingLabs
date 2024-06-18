#include "deporte.h"
#include <iostream>
#include <limits> // Para limpiar el buffer de entrada

int main() {
    // Ingreso de datos para un equipo de baloncesto
    std::string nombreEquipoBaloncesto, nombreMejorAnotadorTriples;
    int victoriasBaloncesto, derrotasBaloncesto, perdidasBalon, rebotesCogidos, triplesMejorAnotador;

    std::cout << "Ingrese nombre del equipo de baloncesto: ";
    std::getline(std::cin, nombreEquipoBaloncesto);
    std::cout << "Ingrese número de victorias: ";
    std::cin >> victoriasBaloncesto;
    std::cout << "Ingrese número de derrotas: ";
    std::cin >> derrotasBaloncesto;
    std::cout << "Ingrese número de pérdidas de balón: ";
    std::cin >> perdidasBalon;
    std::cout << "Ingrese número de rebotes cogidos: ";
    std::cin >> rebotesCogidos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada
    std::cout << "Ingrese nombre del mejor anotador de triples: ";
    std::getline(std::cin, nombreMejorAnotadorTriples);
    std::cout << "Ingrese número de triples del mejor anotador de triples: ";
    std::cin >> triplesMejorAnotador;

    // Crear objeto de tipo Baloncesto
    Baloncesto equipoBaloncesto(nombreEquipoBaloncesto, victoriasBaloncesto, derrotasBaloncesto, perdidasBalon, rebotesCogidos, nombreMejorAnotadorTriples, triplesMejorAnotador);

    // Mostrar información del equipo de baloncesto ingresado
    std::cout << "\nInformación del equipo de baloncesto ingresado:" << std::endl;
    equipoBaloncesto.mostrarInformacion();

    // Limpiar el buffer de entrada
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ingreso de datos para un equipo de fútbol
    std::string nombreEquipoFutbol, nombreGoleador;
    int victoriasFutbol, derrotasFutbol, empates, golesFavor, golesGoleador;

    std::cout << "\nIngrese nombre del equipo de futbol: ";
    std::getline(std::cin, nombreEquipoFutbol);
    std::cout << "Ingrese número de victorias: ";
    std::cin >> victoriasFutbol;
    std::cout << "Ingrese número de derrotas: ";
    std::cin >> derrotasFutbol;
    std::cout << "Ingrese número de empates: ";
    std::cin >> empates;
    std::cout << "Ingrese número de goles a favor: ";
    std::cin >> golesFavor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada
    std::cout << "Ingrese nombre del goleador: ";
    std::getline(std::cin, nombreGoleador);
    std::cout << "Ingrese número de goles del goleador: ";
    std::cin >> golesGoleador;

    // Crear objeto de tipo Futbol
    Futbol equipoFutbol(nombreEquipoFutbol, victoriasFutbol, derrotasFutbol, empates, golesFavor, nombreGoleador, golesGoleador);

    // Mostrar información del equipo de fútbol ingresado
    std::cout << "\nInformación del equipo de futbol ingresado:" << std::endl;
    equipoFutbol.mostrarInformacion();

    return 0;
}
