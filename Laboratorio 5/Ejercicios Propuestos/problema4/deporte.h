#ifndef DEPORTE_H
#define DEPORTE_H

#include <string>

// Clase base para representar un equipo deportivo
class Equipo {
protected:
    std::string nombreEquipo;
    int victorias;
    int derrotas;

public:
    Equipo(std::string nombre, int victorias, int derrotas);
    virtual ~Equipo();

    virtual void mostrarInformacion() const = 0; // Método virtual puro
};

// Clase para equipos de baloncesto
class Baloncesto : public Equipo {
private:
    int perdidasBalon;
    int rebotesCogidos;
    std::string nombreMejorAnotadorTriples;
    int triplesMejorAnotador;

public:
    Baloncesto(std::string nombre, int victorias, int derrotas, int perdidas, int rebotes, std::string nombreAnotador, int triples);
    void mostrarInformacion() const override;
};

// Clase para equipos de fútbol
class Futbol : public Equipo {
private:
    int empates;
    int golesFavor;
    std::string nombreGoleador;
    int golesGoleador;

public:
    Futbol(std::string nombre, int victorias, int derrotas, int empates, int goles, std::string nombreGoleador, int golesGoleador);
    void mostrarInformacion() const override;
};

#endif // DEPORTE_H
