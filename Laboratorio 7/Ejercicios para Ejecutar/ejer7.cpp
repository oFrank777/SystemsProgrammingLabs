#include <iostream> 
using namespace std; 

// Función que puede lanzar excepciones de tipo int* e int
void fun(int *ptr, int x) 
{ 
    // Si el puntero es NULL, lanza una excepción de tipo int*
    if (ptr == NULL) 
        throw ptr; 
    
    // Si x es 0, lanza una excepción de tipo int
    if (x == 0) 
        throw x; 
    
    // Alguna funcionalidad: eleva x al cuadrado y asigna el resultado a la dirección de memoria apuntada por ptr
    *ptr = x * x; 
} 

int main() 
{ 
    try { 
        int valor;
        int *ptr = &valor;
        int x = 0; // Cambia este valor para probar diferentes casos

        // Llama a la función fun
        fun(ptr, x);

        // Imprime el valor después de la operación (No se ejecutará si se lanza una excepción)
        cout << "El valor después de elevar al cuadrado es: " << *ptr << endl;
    } 
    catch(int *excp) { 
        // Captura la excepción de tipo int*
        cout << "Puntero NULL pasado a fun()" << endl; 
    } 
    catch(int x) { 
        // Captura la excepción de tipo int
        cout << "Valor de x es 0, no se puede proceder" << endl; 
    } 
    catch(...) { 
        // Captura cualquier otra excepción
        cout << "Capturando la excepción desde fun()" << endl; 
    } 
    return 0; 
}
