
#include <iostream> 
using namespace std; 

int main() 
{ 
    try {
        throw 'a'; // Lanza una excepción de tipo char
    } 
    catch (int x) { 
        cout << "Capturado"; // Este bloque no se ejecutará porque la excepción lanzada no es de tipo int
    } 
    return 0; 
} 
