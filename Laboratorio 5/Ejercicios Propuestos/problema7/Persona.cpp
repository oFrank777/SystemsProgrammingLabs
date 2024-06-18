// Persona.cpp
#include "Persona.h"
#include <iostream>

Persona::Persona(std::string nom, int dia, int mes, int anio)
    : nombre(nom), diaNacimiento(dia), mesNacimiento(mes), anioNacimiento(anio) {}

void mostrarPersonasEnMes(const std::vector<Persona>& personas, int mes) {
    for (const auto& persona : personas) {
        if (persona.mesNacimiento == mes) {
            std::cout << "Nombre: " << persona.nombre
                      << ", Fecha de Nacimiento: " << persona.diaNacimiento
                      << "/" << persona.mesNacimiento
                      << "/" << persona.anioNacimiento << std::endl;
        }
    }
}