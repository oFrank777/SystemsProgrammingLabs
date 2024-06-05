#include <iostream> 
#include <cstdlib> 
using namespace std; 

int main() 
{ 
    int opcion; 
    bool repetir = true; 
    do{ 
        //system("cls"); 
        //Texto del menú que se verá cada vez 
        cout << "\n\nMenu de Opciones"<< endl; 
        cout << "1. Opcion 1" << endl; 
        cout << "2. Opcion 2" << endl; 
        cout << "3. Opcion 3" << endl; 
        cout << "4. Opcion 4" << endl; 
        cout << "0. SALIR" << endl; 

        cout << "\nIngrese un Opcion: "; 
        cin >> opcion; 

        switch (opcion) { 
            case 1: 
                break; 
            case 2: 
                break; 
            case 3: 
                break; 
            case 4: 
                break; 
            case 0: 
                repetir = false; 
                break; 
        } 
    } while(repetir); 

    return 0; 
}
