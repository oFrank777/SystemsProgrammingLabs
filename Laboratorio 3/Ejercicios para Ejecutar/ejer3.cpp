/* el programa pregunta dos números y muestra el resultado */ 
#include <iostream> 
using namespace std;

int main (void) 
    { 
        double x, y, z; 

        cout << "Introduzca el primer numero" << endl; 
        cin >> x; 
        cout << "Introduzca el segundo numero" << endl; 
        cin >> y; 

        z = x + y; 

        cout << x << "+" << y << "=" << z << endl; 

        return 0; 
    } 
