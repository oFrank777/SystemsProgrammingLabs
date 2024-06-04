#include <iostream>
#include <string>
using namespace std;

class Sala {
private:
    string nombre;
    float ancho;
    float largo;
    bool equipado;

public:
    Sala(string nombre, float ancho, float largo, bool equipado) : nombre(nombre), ancho(ancho), largo(largo), equipado(equipado) {}

    float calcularSuperficie() {
        return ancho * largo;
    }

    int obtenerCapacidad() {
        return calcularSuperficie() / 1.5;
    }

    float calcularCostoAlquiler() {
        float costoPorMetroCuadrado = equipado ? 45 : 32;
        return calcularSuperficie() * costoPorMetroCuadrado;
    }

    string getNombre() {
        return nombre;
    }
};

int main() {
    Sala sala1("Sala 1", 8, 12, true);
    Sala sala2("Sala 2", 18, 20, false);
    Sala sala3("Sala 3", 12, 15, true);

    cout << "Datos de la primera sala:" << endl;
    cout << "Nombre: " << sala1.getNombre() << endl;
    cout << "Superficie: " << sala1.calcularSuperficie() << " m2" << endl;
    cout << "Capacidad: " << sala1.obtenerCapacidad() << " asistentes" << endl;
    cout << "Costo de alquiler: $" << sala1.calcularCostoAlquiler() << endl;

    int asistentes[4] = {200, 50, 100, 150};

    cout << "\nPosibles salas para los eventos:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Evento " << (i + 1) << ": ";
        int capacidadRequerida = asistentes[i];
        if (capacidadRequerida <= sala1.obtenerCapacidad()) {
            cout << sala1.getNombre() << endl;
        } else if (capacidadRequerida <= sala2.obtenerCapacidad()) {
            cout << sala2.getNombre() << endl;
        } else if (capacidadRequerida <= sala3.obtenerCapacidad()) {
            cout << sala3.getNombre() << endl;
        } else {
            cout << "Ninguna sala tiene la capacidad suficiente." << endl;
        }
    }

    return 0;
}
