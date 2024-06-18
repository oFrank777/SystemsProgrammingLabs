#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

int Fecha::diasEnMes() const {
    static const int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mes == 2 && esBisiesto()) {
        return 29;
    }
    return diasPorMes[mes - 1];
}

bool Fecha::esBisiesto() const {
    if (anio % 4 == 0) {
        if (anio % 100 == 0) {
            return anio % 400 == 0;
        }
        return true;
    }
    return false;
}

int Fecha::diasDesdeInicio() const {
    int dias = dia;
    for (int m = 1; m < mes; ++m) {
        Fecha tempFecha(1, m, anio);
        dias += tempFecha.diasEnMes();
    }
    dias += (anio - 1) * 365 + (anio - 1) / 4 - (anio - 1) / 100 + (anio - 1) / 400;
    return dias;
}

int Fecha::diasEntre(const Fecha& fecha1, const Fecha& fecha2) {
    int dias1 = fecha1.diasDesdeInicio();
    int dias2 = fecha2.diasDesdeInicio();
    return dias2 - dias1;
}
