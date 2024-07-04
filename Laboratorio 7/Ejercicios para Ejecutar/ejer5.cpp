#include <iostream> 
using namespace std; 

// Función que puede lanzar excepciones
void fun(int *ptr, int x) 
{ 
    // Si el puntero es NULL, lanza una excepción
    if (ptr == NULL) 
        throw ptr; 

    // Si x es 0, lanza una excepción
    if (x == 0) 
        throw x; 

    // Alguna funcionalidad
    *ptr = x * x; // Eleva x al cuadrado y asigna el resultado a la dirección de memoria apuntada por ptr
} 

int main() 
{ 
    try { 
        int valor;
        int *ptr = &valor;
        int x; // Cambia este valor para probar diferentes casos

        // Llama a la función fun
        fun(ptr, x);

        // Imprime el valor después de la operación
        cout << "El valor después de elevar al cuadrado es: " << *ptr << endl;
    } 
    catch(int *excp) { 
        cout << "Puntero NULL pasado a fun()" << endl; 
    } 
    catch(int x) { 
        cout << "Valor de x es 0, no se puede proceder" << endl; 
    } 
    catch(...) { 
        cout << "Capturando la excepción desde fun()" << endl; 
    } 
    return 0; 
}

