#include <iostream> // Incluye la biblioteca estándar de entrada y salida
#include <cstdlib> // Incluye la biblioteca estándar de C para funciones generales
using namespace std; // Utiliza el espacio de nombres estándar

// Declaración de las funciones
void funcion1(); 
void funcion2(); 
void funcion3(); 
void funcion4(); 

int main() 
{ 
    int opcion; // Declara una variable para almacenar la opción del usuario
    bool repetir = true; // Declara una variable booleana para controlar el ciclo del menú

    do 
    { 
        // Muestra el menú de opciones
        cout << "\n\n\t\tMenu de Opciones" << endl; 
        cout << "\t\t -----------------" << endl; 
        cout << "\n\t1. Función 1" << endl; 
        cout << "\t2. Función 2" << endl; 
        cout << "\t3. Función 3" << endl; 
        cout << "\t4. Función 4" << endl; 
        cout << "\t0. SALIR" << endl; 
        cout << "\n\tIngrese una opción: "; 
        cin >> opcion; // Lee la opción seleccionada por el usuario

        // Estructura switch para evaluar la opción seleccionada
        switch (opcion) 
        { 
            case 1: 
                // Llama a la función 1
                funcion1(); 
                break; 
            case 2: 
                // Llama a la función 2
                funcion2(); 
                break; 
            case 3: 
                // Llama a la función 3
                funcion3(); 
                break; 
            case 4: 
                // Llama a la función 4
                funcion4(); 
                break; 
            case 0: 
                // Cambia la variable repetir a false para salir del ciclo
                repetir = false; 
                break; 
            default:
                // Muestra un mensaje si la opción no es válida
                cout << "\n\tOpción no válida\n"; 
        } 
    } 
    while (repetir); // Repite el ciclo mientras repetir sea true

    return 0; // Retorna 0 indicando que el programa terminó correctamente
} 

// Definición de las funciones
void funcion1() 
{ 
    // Muestra el mensaje de la función 1
    cout << "\n\tFunción 1\n"; 
} 

void funcion2() 
{ 
    // Muestra el mensaje de la función 2
    cout << "\n\tFunción 2\n"; 
} 

void funcion3() 
{ 
    // Muestra el mensaje de la función 3
    cout << "\n\tFunción 3\n"; 
} 

void funcion4() 
{ 
    // Muestra el mensaje de la función 4
    cout << "\n\tFunción 4\n"; 
} 
