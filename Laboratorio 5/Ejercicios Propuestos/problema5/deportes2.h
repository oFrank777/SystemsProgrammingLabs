#ifndef DEPORTES2_H
#define DEPORTES2_H

#include <string>
#include <vector>

class Equipo {
public:
    std::string nombreEquipo;
    int victorias;
    int derrotas;

public:
    Equipo(std::string nombre, int victorias, int derrotas);
    virtual ~Equipo();

    virtual void mostrarInformacion() const = 0;
};

class Baloncesto : public Equipo {
public:
    int perdidasBalon;
    int rebotesCogidos;
    std::vector<std::string> nombresAnotadoresTriples;
    std::vector<int> triplesAnotadores;

public:
    Baloncesto(std::string nombre, int victorias, int derrotas, int perdidas, int rebotes);
    void generarJugadores();
    void mostrarInformacion() const override;
};

class Futbol : public Equipo {
public:
    int empates;
    int golesFavor;
    std::vector<std::string> nombresGoleadores;
    std::vector<int> golesGoleadores;

public:
    Futbol(std::string nombre, int victorias, int derrotas, int empates, int goles);
    void generarJugadores();
    void mostrarInformacion() const override;
};

#endif // DEPORTES2_H
