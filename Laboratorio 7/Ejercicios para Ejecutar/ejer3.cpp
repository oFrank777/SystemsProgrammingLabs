
#include <iostream> 
using namespace std; 

int main() 
{ 
    try { 
        throw 'a'; // Lanza una excepción de tipo char
    } 
    catch (int x) { 
        cout << "Capturado " << x; // Este bloque no se ejecutará porque la excepción lanzada no es de tipo int
    } 
    catch (...) { 
        cout << "Excepción por defecto\n"; // Este bloque se ejecutará porque no hay un bloque catch para tipo char
    } 
    return 0; 
}
