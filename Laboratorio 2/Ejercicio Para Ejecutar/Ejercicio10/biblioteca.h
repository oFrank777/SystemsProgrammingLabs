#include "biblioteca.h"
int main()
{
    Alumnos obj1;
    obj1.id = 7;
    int i = 0;
    while ( i < 5 )
    {
        Alumnos obj2;
        obj2.id=i;
        i++;
    }//El alcance del obj2 finaliza aqui
    return 0;
}//El alcance del obj1 finaliza aqui
