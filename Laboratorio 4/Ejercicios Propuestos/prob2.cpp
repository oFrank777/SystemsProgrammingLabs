#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_LONGITUD_PALABRA = 10; // Longitud máxima de la palabra a adivinar
const int MAX_INTENTOS = 5; // Número máximo de intentos

// Función para inicializar el arreglo de la palabra oculta
void generarPalabraOculta(char* palabraOculta, int longitud) {
    for (int i = 0; i < longitud; ++i) {
        *(palabraOculta + i) = '_'; // Llena la palabra oculta con guiones bajos
    }
    *(palabraOculta + longitud) = '\0'; // Agrega el carácter nulo al final
}

// Función para mostrar la palabra oculta
void mostrarPalabraOculta(const char* palabraOculta) {
    while (*palabraOculta) {
        cout << *palabraOculta << ' '; // Muestra cada carácter de la palabra oculta seguido de un espacio
        ++palabraOculta; // Avanza al siguiente carácter
    }
    cout << endl;
}

// Función para verificar si la letra adivinada está en la palabra
bool adivinarLetra(const char* palabra, char* palabraOculta, char letra) {
    bool acierto = false;
    while (*palabra) {
        if (tolower(*palabra) == tolower(letra)) {
            *palabraOculta = *palabra; // Reemplaza el guión bajo con la letra correcta
            acierto = true;
        }
        ++palabra;
        ++palabraOculta;
    }
    return acierto; // Devuelve true si la letra se encontró en la palabra
}

// Función para verificar si el jugador ha adivinado la palabra oculta
bool adivinoPalabraOculta(const char* palabraOculta) {
    while (*palabraOculta) {
        if (*palabraOculta == '_') {
            return false; // Si hay algún guión bajo, aún no ha adivinado la palabra completa
        }
        ++palabraOculta;
    }
    return true; // Devuelve true si no hay guiones bajos, es decir, ha adivinado la palabra completa
}

// Función para generar una palabra aleatoria
void generarPalabraAleatoria(char* palabra) {
    const char* listaPalabras[] = {"programacion", "sistemas", "bash"};
    int numPalabras = sizeof(listaPalabras) / sizeof(listaPalabras[0]);
    srand(time(0)); // Inicializa la semilla para la generación aleatoria
    int indice = rand() % numPalabras; // Genera un índice aleatorio
    strcpy(palabra, listaPalabras[indice]); // Copia la palabra aleatoria al arreglo palabra
}

int main() {
    char palabra[MAX_LONGITUD_PALABRA]; // Arreglo para la palabra a adivinar
    char palabraOculta[MAX_LONGITUD_PALABRA]; // Arreglo para la palabra oculta
    char letrasErroneas[MAX_INTENTOS]; // Arreglo para las letras erróneas
    int intentosRestantes = MAX_INTENTOS; // Número de intentos restantes
    int numeroLetrasErroneas = 0; // Número de letras erróneas ingresadas inicializada en 0
    char letra; // Letra ingresada por el jugador
    int modoJuego; // Variable para almacenar el modo de juego

    // Menú para seleccionar el modo de juego
    cout << "Seleccione el modo de juego:" << endl;
    cout << "1. Dos personas" << endl;
    cout << "2. Una persona (la computadora genera la palabra)" << endl;
    cin >> modoJuego;

    // Entrada de la palabra a adivinar según el modo de juego seleccionado
    if (modoJuego == 1) {
        cout << "Jugador 1, ingrese la palabra a adivinar: ";
        cin >> palabra;
        int longitudPalabra = strlen(palabra); // Longitud de la palabra a adivinar

        // Inicializar la palabra oculta con guiones bajos
        generarPalabraOculta(palabraOculta, longitudPalabra);
        cout << "Jugador 2, intenta adivinar la palabra: ";
    } else if (modoJuego == 2) {
        generarPalabraAleatoria(palabra); // Genera una palabra aleatoria
        cout << "La computadora ha generado una palabra." << endl;
        int longitudPalabra = strlen(palabra); // Longitud de la palabra a adivinar

        // Inicializar la palabra oculta con guiones bajos
        generarPalabraOculta(palabraOculta, longitudPalabra);
        cout << "Jugador, intenta adivinar la palabra: ";
    } else {
        cout << "Modo de juego no válido." << endl;
        return 1;
    }

    // Ciclo principal del juego
    while (intentosRestantes > 0 && !adivinoPalabraOculta(palabraOculta)) {
        mostrarPalabraOculta(palabraOculta); // Muestra la palabra oculta
        cout << "Intentos restantes: " << intentosRestantes << endl;

        if (numeroLetrasErroneas > 0) {
            cout << "Letras erróneas: ";
            for (int i = 0; i < numeroLetrasErroneas; ++i) {
                cout << letrasErroneas[i] << ' '; // Muestra las letras erróneas ingresadas
            }
            cout << endl;
        }

        // Entrada de la letra adivinada
        cout << "Ingrese una letra: ";
        cin >> letra;

        if (!adivinarLetra(palabra, palabraOculta, letra)) {
            letrasErroneas[numeroLetrasErroneas++] = letra; // Agrega la letra a las letras erróneas
            --intentosRestantes; // Decrementa el número de intentos restantes
        }
    }

    if (adivinoPalabraOculta(palabraOculta)) {
        cout << "¡Felicidades! Has adivinado la palabra: " << palabra << endl; // Mensaje de victoria
    } else {
        cout << "Lo siento, has perdido. La palabra era: " << palabra << endl; // Mensaje de derrota
    }

    return 0;
}