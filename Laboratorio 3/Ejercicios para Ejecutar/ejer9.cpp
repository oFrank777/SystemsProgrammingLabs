#include <iostream> 
#include <cstdlib> 

using namespace std; 

int main() 
{ 
    int valor = 0; 

    cout << "rand() definiendo limite inferior" << endl; 
    valor = 10 + rand(); 
    cout << "10 + rand()\t\t" << valor << endl; 
    valor = 65000 + rand(); 
    cout << "65000 + rand()\t\t"<< valor << endl; 

    return 0; 
} 
