#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir un vector de enteros
void mostrarVector(const vector<int>& valores) {
    // Iterar sobre cada elemento del vector y mostrarlo
    for (int valor : valores) {
        cout << valor << ' ';
    }
    cout << endl; // Salto de línea al final de la impresión del vector
}

/**
 * Función recursiva para generar permutaciones
 * valores: Vector de enteros que contiene los números a permutar
 * posicion: Índice actual que indica la posición en la que se está generando la permutación
 */
void crearPermutaciones(vector<int>& valores, int posicion) {
    // Si el índice alcanza el tamaño del vector, se ha generado una permutación completa
    if (posicion == valores.size()) {
        mostrarVector(valores); // Mostrar la permutación completa
        return; // Terminar la ejecución de esta llamada recursiva
    }

    // Iterar sobre los elementos restantes para generar las permutaciones
    for (int i = posicion; i < valores.size(); i++) {
        swap(valores[posicion], valores[i]); // Intercambiar el elemento en la posición actual con el elemento en i
        crearPermutaciones(valores, posicion + 1); // Llamar recursivamente para la siguiente posición
        swap(valores[posicion], valores[i]); // Deshacer el intercambio para restaurar el vector antes de la siguiente iteración
    }
}

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;

    // Crear un vector con los números del 1 al número introducido
    vector<int> valores(numero);
    for (int i = 0; i < numero; i++) {
        valores[i] = i + 1; // Llenar el vector con los números 1, 2, ..., número
    }

    // Llamar a la función crearPermutaciones para generar todas las permutaciones posibles
    crearPermutaciones(valores, 0);

    return 0; // Finalizar el programa
}