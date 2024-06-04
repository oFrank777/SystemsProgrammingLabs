#include <iostream> // Incluye la biblioteca estándar de entrada y salida
#include <cstdlib> // Incluye la biblioteca estándar de C para funciones generales como rand() y srand()
using namespace std; // Utiliza el espacio de nombres estándar

int main() 
{ 
    int valor1, valor2, valor3; // Declara variables para almacenar los valores generados

    // Bucle que se ejecuta tres veces para mostrar resultados en tres corridas
    for (int i = 1; i <= 3; i++) { 
        cout << "Corrida: " << i << endl; // Muestra el número de la corrida actual

        // Genera un número aleatorio sin inicializar la semilla
        valor1 = rand(); 
        cout << "Sin semilla: " << valor1 << endl; // Muestra el valor generado sin semilla

        // Inicializa la semilla del generador de números aleatorios con un valor fijo (40)
        srand(40); 
        // Genera un número aleatorio con la semilla inicializada a 40
        valor2 = rand(); 
        cout << "Con semilla 40: " << valor2 << endl; // Muestra el valor generado con semilla 40

        // Genera un número aleatorio en el rango de 1 a 100
        valor3 = rand() % 100 + 1; 
        cout << "Valor en rango 1-100: " << valor3 << endl; // Muestra el valor generado en el rango 1-100

        // Inicializa la semilla del generador de números aleatorios con un valor fijo (1) para la siguiente corrida
        srand(1); 
    } 

    return 0; // Retorna 0 indicando que el programa terminó correctamente
}
