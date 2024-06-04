#include <iostream> // Incluye la biblioteca estándar de entrada y salida
#include <cstdlib>  // Incluye la biblioteca estándar de C para funciones generales como rand() y srand()
#include <ctime>    // Incluye la biblioteca para obtener el tiempo actual
using namespace std; // Utiliza el espacio de nombres estándar

int main() 
{ 
    int valorrnd = 0; // Variable para almacenar el número aleatorio generado
    int valorusr = 0; // Variable para almacenar el número introducido por el jugador
    int contador = 0; // Variable para registrar el número de intentos

    srand(time(NULL)); // Genera una semilla basada en el tiempo actual para el generador de números aleatorios

    valorrnd = 1 + rand() % 10; // Genera un número aleatorio entre 1 y 10

    cout << "Este programa genera un valor entre 1 y 10, tiene 2 oportunidades" << endl; 
    cout << "para acertar el número correcto." << endl; 

    // Bucle do-while para permitir al usuario adivinar el número
    do { 
        contador += 1; // Incrementa el contador de intentos

        cout << "Escribe un número entre 1 y 10: "; 
        cin >> valorusr; // Lee el número introducido por el usuario

        // Compara el número introducido con el número aleatorio
        if (valorusr == valorrnd) { 
            cout << "¡Ganaste!, el número es correcto (" << valorrnd << ")" << endl; 
            break; // Sale del bucle si el usuario adivina correctamente
        } else { 
            cout << "Lo siento, el número no es ese." << endl << endl; 
        } 
    } while (contador < 2); // Repite mientras el contador sea menor que 2

    // Si el usuario ha alcanzado el número máximo de intentos
    if (contador == 2) { 
        cout << "Perdiste, más suerte para la próxima, el número es: " << valorrnd << endl; 
    } 

    return 0; // Retorna 0 indicando que el programa terminó correctamente
}
