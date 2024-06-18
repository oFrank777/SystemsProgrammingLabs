#ifndef FECHA_H
#define FECHA_H

struct Fecha {
    int dia;
    int mes;
    int anio;

    Fecha(int d, int m, int a);
    int diasEnMes() const;
    bool esBisiesto() const;
    int diasDesdeInicio() const;
    static int diasEntre(const Fecha& fecha1, const Fecha& fecha2);
};

#endif // FECHA_H
