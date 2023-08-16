#include <iostream>
using namespace std;
#define MAX 100

/*Se declaran los siguientes arreglos para representar cadenas de caracteres de largo M y N:
char arrM[M];
char arrN[N];
Escribir un programa que lea dos cadenas de la entrada, de largo M y N respectivamente, y determine si
todos los caracteres de la primera cadena ocurren en la segunda cadena (en cualquier posición y orden).*/

int main()
{
    char arrM(MAX);
    char arrN(MAX);
    char c;
    int cantM = 0;

    cout << "Ingrese la oraci'on m'as corta" << endl;

    cout << "Ingrese la oraci'on m'as corta" << endl;
    while ((c = getchar()) != '\n')
    {
        arrM[cantM++] = c;
    }

    bool ok;
    for (int i = 0; (i < cantM); i++)
    {
        ok = false;
        for (int j = 0; (j < cantN) && !ok; j++)
        {
            if (arrM[i] == arrN[j])
                ok = true;
        }
        if (!ok)
        {
            break;
        }
    }
    if (ok)
        cout << "Todos los caracter de la primera oración se encuentra en la segunda" << endl;
    else
        cout << "No todos los caracteres de la primera oración se encuentran en la segunda" << endl;

    return 0;
}