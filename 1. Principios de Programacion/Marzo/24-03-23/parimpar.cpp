#include <iostream>
#include <math.h> //incluje funciones de matematica
using namespace std;

/*
OPERADORES BOOLEANOS

= asignacion
== comparacion
!= distinto de
! negacion
<= menor o igual
>= mayor o igual
&& y
|| o
% modulo
nomvariables ++ incrementar uno
total += califiaciones // la va a sumar a si mismo

*/

int main()
{
    /*que un usario ingrese un numero y que sea par*/

    int num;

    cout << "Ingrese un numero: ";
    cin >> num;

    if (num % 2 == 0)
    {
        cout << "El numero es par";
    }
    else
    {
        cout << "El numero es impar";
    }

    return 0;
}
