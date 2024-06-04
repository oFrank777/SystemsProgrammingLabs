#include <iostream>
#include <cstdlib> // Incluye las funciones srand() y rand() para la generación de números aleatorios
#include <ctime>   // Incluye la función time() para inicializar la semilla de números aleatorios
using namespace std;

// Función para tirar un dado y obtener un número entre 1 y 6
int tirarDado() {
    return 1 + rand() % 6; // Genera un número aleatorio entre 1 y 6
}

int main() {
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios usando el tiempo actual
    int dadoA, dadoB, resultado, objetivo; // Declaración de variables para los dados, el resultado de la suma y el objetivo

    // Primer tiro de los dados
    dadoA = tirarDado(); // Tirar el primer dado
    dadoB = tirarDado(); // Tirar el segundo dado
    resultado = dadoA + dadoB; // Sumar los resultados de los dos dados

    // Mostrar el resultado del primer tiro
    cout << "El jugador tira los dados: " << dadoA << " y " << dadoB << " -> Suma: " << resultado << endl;

    // Regla 3: Si la suma es 7 u 11 en el primer tiro, el jugador gana
    if (resultado == 7 || resultado == 11) {
        cout << "Felicidades. El jugador ha ganado en el primer tiro." << endl;
    }
    // Regla 4: Si la suma es 2, 3 o 12 en el primer tiro, el jugador pierde
    else if (resultado == 2 || resultado == 3 || resultado == 12) {
        cout << "Craps. El jugador ha perdido en el primer tiro." << endl;
    }
    // Regla 5: Si la suma es 4, 5, 6, 8, 9 o 10, se convierte en el "objetivo"
    else {
        objetivo = resultado; // Establecer el objetivo para los siguientes tiros
        cout << "El objetivo es: " << objetivo << endl;

        // Regla 6 y 7: Continuar tirando hasta que se haga el "objetivo" o salga un 7
        bool juegoFinalizado = false; // Variable de control para el bucle de tiros adicionales
        while (!juegoFinalizado) { // Bucle para continuar tirando hasta que el juego termine
            dadoA = tirarDado(); // Tirar el primer dado nuevamente
            dadoB = tirarDado(); // Tirar el segundo dado nuevamente
            resultado = dadoA + dadoB; // Sumar los resultados de los dos dados

            // Mostrar el resultado del tiro actual
            cout << "\tEl jugador tira los dados: " << dadoA << " y " << dadoB << " -> Suma: " << resultado << endl;

            // Si la suma es igual al "objetivo", el jugador gana
            if (resultado == objetivo) {
                cout << "Felicidades. El jugador ha ganado." << endl;
                juegoFinalizado = true; // Terminar el juego
            }
            // Si la suma es 7 antes de igualar el "objetivo", el jugador pierde
            else if (resultado == 7) {
                cout << "El jugador ha perdido" << endl;
                juegoFinalizado = true; // Terminar el juego
            }
        }
    }

    return 0; // Finalizar el programa
}