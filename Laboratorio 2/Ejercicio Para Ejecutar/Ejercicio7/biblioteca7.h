#include <bits/stdc++.h>
using namespace std;

// Definición de la clase Alumnos
class Alumnos
{
public:
    int id;

    // Constructor por defecto
    Alumnos()
    {
        cout << "Constructor por defecto llamado" << endl;
        id = -1;
    }

    // Constructor parametrizado
    Alumnos(int x)
    {
        cout << "Constructor parametrizado llamado" << endl;
        id = x;
    }
};
