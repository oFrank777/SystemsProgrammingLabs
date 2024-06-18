#include <iostream>
#include "Fecha.h"

using namespace std;

int main() {
    int dia1, mes1, anio1;
    int dia2, mes2, anio2;

    cout << "Ingrese la primera fecha (dia mes anio): ";
    cin >> dia1 >> mes1 >> anio1;
    cout << "Ingrese la segunda fecha (dia mes anio): ";
    cin >> dia2 >> mes2 >> anio2;

    Fecha fecha1(dia1, mes1, anio1);
    Fecha fecha2(dia2, mes2, anio2);

    int dias = Fecha::diasEntre(fecha1, fecha2);
    cout << "El numero de dias entre las dos fechas es: " << dias << std::endl;

    return 0;
}
