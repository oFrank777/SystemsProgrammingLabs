//Programa en C++ para explicar los destructores
#include <bits/stdc++.h>
using namespace std;
class Alumnos
{
    public:
        int id;
        //Definición de destructor
        ~Alumnos()
        {
        cout << "Destructor llamado por id:" << id << endl;
        }
};
