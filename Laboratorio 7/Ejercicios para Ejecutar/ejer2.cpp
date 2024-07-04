#include <iostream> 
using namespace std; 

int main() 
{ 
    try { 
        throw 10; // Lanza una excepción de tipo entero
    } 
    catch (char *excp) { 
        cout << "Capturado " << excp; // Captura excepción de tipo char* (no se ejecutará en este caso)
    } 
    catch (...) { 
        cout << "Excepción por defecto\n"; // Captura cualquier otra excepción no manejada
    } 
    return 0; 
}
