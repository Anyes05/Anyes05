#include <iostream>
using namespace std;
#define N 4
#include <math.h>


/*Ejercicio 9
Escribir un programa que:
- lee de la entrada un entero de N dígitos que contiene un número representado en una base
 entre 2 y 10, - lee la base correspondiente al número leído y
- despliega el equivalente en base 10.
N es una constante que puede ser fijada en cualquier valor entero menor que 10. Asumir que las entradas
son válidas, es decir, si se ingresa un número en base b, los dígitos utilizados estarán entre 0 y b-1.
Recordar que la fórmula para calcular la representación decimal de un número es:
d1 * baseN-1 + d2 * baseN-2 + .... + dn
(d1, ..., dn son los N dígitos del número leído.)
Ejemplo para N=5
Numero: 32021
Base: 4
Resultado: 905*/

int main()
{
    int digitos[N], base, resultado = 0, num, potencia, verdad;

    cout << "Ingrese un Numero: ";
    cin >> num, verdad;

    cout << "Ingrese la Base del Numero: ";
    cin >> base;

    for (int i = N - 1; i >= 0; i--)
    {
        digitos[N - 1] = num % 10;
        num = num / 10;
    }

    for (int j = N - 1; j >= 0; j--)
    {
        resultado += digitos[j] * pow (base, potencia);
        potencia ++;
    }

    cout << "El numero" << verdad << "de base" << base << "en base 10 es: " << resultado;

    return 0;
}
