#include <iostream> 
#include <cstdlib> //rand, srand
#include <ctime> //time 
using namespace std; 

int main() 
{ 
    int valor = 0; 
    srand(time(NULL)); 
    for (int i=1; i<=20; i++){ 
        valor = 5 + rand()%(10-5); 
        cout << "Calificacion Simulada" << i << ": " << valor << "\t\t\t\t"; 
        if (i%2 == 0) cout << endl; 
    } return 0; 
} 
