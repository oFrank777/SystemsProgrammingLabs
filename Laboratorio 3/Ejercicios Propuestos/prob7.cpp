#include <iostream>
#include <vector>

using namespace std;

void generarSubconjuntos(int n, vector<int>& subconjunto, int indice) {
    // Imprimir el subconjunto actual
    for (int i = 0; i < subconjunto.size(); ++i) {
        cout << subconjunto[i] << " ";
    }
    cout << endl;

    // Generar subconjuntos adicionales incluyendo elementos restantes uno por uno
    for (int i = indice; i < n; ++i) {
        // Agregar el elemento actual al subconjunto
        subconjunto.push_back(i + 1);

        // Generar subconjuntos adicionales con el elemento actual incluido
        generarSubconjuntos(n, subconjunto, i + 1);

        // Eliminar el elemento actual y volver a intentar con otros
        subconjunto.pop_back();
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    vector<int> subconjunto;
    cout << "Los subconjuntos no vacios de {1, 2, ..., " << n << "} son:" << endl;
    generarSubconjuntos(n, subconjunto, 0);

    return 0;
}
