#include <iostream> 
using namespace std; 

int main() 
{ 
    int x = -1; // Se inicializa x con un valor negativo

    // Mensaje antes de entrar al bloque try
    cout << "Antes del bloque try \n"; 

    try { 
        // Mensaje dentro del bloque try
        cout << "Dentro del bloque try \n"; 
        
        // Verificar si x es negativo y lanzar una excepción
        if (x < 0) { 
            throw x; // Lanza la excepción con el valor de x
            cout << "Después de throw (Nunca ejecutado) \n"; // Esta línea nunca se ejecuta
        } 
    } 
    catch (int x ) { 
        // Captura la excepción de tipo entero
        cout << "Capturando la excepción \n"; 
    } 
    
    // Mensaje después del catch
    cout << "Después del catch (Será ejecutado) \n"; 
    
    return 0; 
}
