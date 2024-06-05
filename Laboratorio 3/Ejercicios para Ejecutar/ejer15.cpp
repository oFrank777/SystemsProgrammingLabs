#include <bits/stdc++.h> 
using namespace std; 
void imprimirtodaslascadenasgrabadas(char set[], string prefix, int n, int k) 
{ 
    //Caso base de k es 0 
    //imprimir prefijo 
    if (k==0) 
    { 
        cout << (prefix) << endl; 
        return; 
    } 
    //uno a     uno todos los caracteres 
    //desde el conjunto recursivo 
    //llamados desde k igual a k - 1 
    for (int i = 0; i < n; i ++) 
    { 
        string newPrefix; 
        newPrefix = prefix + set[i]; 
        //k es decreciendo 
        //porque se añadio un nuevo caracter 
        imprimirtodaslascadenasgrabadas(set, newPrefix, n, k - 1); 
    } 
} 

void imprimirtodaslascadenas(char set[], int k, int n) 
    { 
        imprimirtodaslascadenasgrabadas(set, "", n, k); 
    } 

int main() 
{ 
    cout << "primera prueba" << endl; 
    char set1[] = {'a', 'b'}; 
    int k =3; 
    
    imprimirtodaslascadenas(set1, k, 2); 
}
