// Persona.h
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>

struct Persona {
    std::string nombre;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;

    Persona(std::string nom, int dia, int mes, int anio);
};

void mostrarPersonasEnMes(const std::vector<Persona>& personas, int mes);

#endif // PERSONA_H