#include <iostream> 
#include <cstdlib> 
using namespace std; 
int main() 
{ 
    int valor = 0; 
    cout << "rand() definiendo limite inferior y especificando el"
    "valor del limite superior" << endl; valor = 10 + rand() % (26-10); 
    cout << "10 + rand()% (26-10)\t\t" << valor << endl; 
    valor = 25 + rand()% (100-25); 
    cout << "25 + rand()% (100-25)\t\t"<< valor << endl; 
    return 0; 
} 
