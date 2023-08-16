#include <iostream>
using namespace std;
#define MAX 100

// Se declaran los siguientes arreglos para representar cadenas de caracteres de largo M y N:
// char arrM[M];
// char arrN[N];
// Escribir un programa que lea dos cadenas de la entrada, de largo M y N respectivamente, y determine si
// algún carácter de la primera cadena ocurre en la segunda cadena.


int main(){

    char arrM(MAX);
    char arrN(MAX);
    char c;
    int cantM = 0;

    cout << "Ingrese la oraci'on m'as corta" << endl;
    while ((c=getchar()) != '\n')
        arrM[cantM ++] = c;
    
        bool ok = false;
    for (int i = 0; (i < cantM) && !ok; i++) {
        for (int j = 0; (j < cantN) && !ok; j++) {
            if (arrM[i] == arrN[j])
                ok = true;
        }
    }
    if (ok)
        cout << "Algún caracter de la primera oración se encuentra en la segunda" << endl;
    else
        cout << "Ningún caracter de la primera oración se encuentra en la segunda" << endl;

    
    

    return 0;
}