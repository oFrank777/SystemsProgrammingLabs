// main.cpp
#include <iostream>
#include <vector>
#include "Persona.h"
using namespace std;

int main() {
    vector<Persona> personas;

    // Solicitar datos de 8 personas
    for (int i = 0; i < 2; ++i) {
        string nombre;
        int dia, mes, anio;
        cout << "Ingrese nombre de la persona " << i + 1 << ": ";
        cin >> nombre;
        cout << "Ingrese dia de nacimiento de " << nombre << ": ";
        cin >> dia;
        cout << "Ingrese mes de nacimiento de " << nombre << ": ";
        cin >> mes;
        cout << "Ingrese anio de nacimiento de " << nombre << ": ";
        cin >> anio;
        personas.emplace_back(nombre, dia, mes, anio);
    }

    // Solicitar número de mes y mostrar personas que cumplen años en ese mes
    while (true) {
        int mes;
        cout << "Ingrese un numero de mes (0 para salir): ";
        cin >> mes;
        if (mes == 0) break;
        mostrarPersonasEnMes(personas, mes);
    }

    return 0;
}