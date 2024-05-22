#include <iostream>
using namespace std;

class Candado {
private:
    int combinacionSeguridad[3];
    int combinacionActual[3];

public:
    Candado(int combSeguridad[3], int combActual[3]) {
        for (int i = 0; i < 3; ++i) {
            combinacionSeguridad[i] = combSeguridad[i];
            combinacionActual[i] = combActual[i];
        }
    }

    void alterarDigito(int posicion, int nuevoDigito) {
        combinacionActual[posicion] = nuevoDigito;
        cout << "Se ha alterado el digito en la posicion " << posicion << " de la combinacion actual." << endl;
    }

    bool puedeAbrir() {
        for (int i = 0; i < 3; ++i) {
            if (combinacionActual[i] != combinacionSeguridad[i])
                return false;
        }
        return true;
    }

    bool mismaCombinacionActual(Candado otroCandado) {
        for (int i = 0; i < 3; ++i) {
            if (combinacionActual[i] != otroCandado.combinacionActual[i])
                return false;
        }
        return true;
    }

    void imprimirCombinacionActual() {
        cout << "La combinacion actual es: ";
        for (int i = 0; i < 3; ++i) {
            cout << combinacionActual[i];
        }
        cout << endl;
    }
};

int main() {
    int combSeguridad1[3] = {1, 2, 3}; // Combinación de seguridad para el candado 1
    int combActual1[3] = {1, 2, 3};    // Combinación actual del candado 1

    int combSeguridad2[3] = {4, 5, 6}; // Combinación de seguridad para el candado 2
    int combActual2[3] = {4, 5, 6};    // Combinación actual del candado 2

    Candado c1(combSeguridad1, combActual1);
    Candado c2(combSeguridad2, combActual2);

    cout << "Candado 1: ";
    c1.imprimirCombinacionActual();
    cout << "Candado 2: ";
    c2.imprimirCombinacionActual();

    c1.alterarDigito(2, 9); // Cambiar el tercer dígito de la combinación actual de c1
    cout << "Despues de alterar el díiito: ";
    c1.imprimirCombinacionActual();

    cout << "El candado c2 se puede abrir con la combinacion actual que programo? ";
    if (c2.puedeAbrir())
        cout << "Si." << endl;
    else
        cout << "No." << endl;

    cout << "c1 y c2 tienen las mismas combinaciones actuales? ";
    if (c1.mismaCombinacionActual(c2))
        cout << "Si." << endl;
    else
        cout << "No." << endl;

    return 0;
}
