#include <iostream>  //biblioteca se flujo de entrada y salida
using namespace std; // con esta biblioteca o hay que poner el std abajo

/*
TIPOS DE VARIABLES
int entero
char caracter
float real
bool 0 o 1
unsigned natural o entero positvio
*/

int main()
{

    // PRIMER PROGRAMA

    cout << "Hola Mundo" << endl; // << se utiliza para impirmir
    cout << "Como estan" << endl; // endl salto de linea

    // MAYOR MENOR
    int edad = 20;
    cout << "El numero es: " << edad << ", está clarisimo.";

    if (edad > 10)
    {
        cout << "El numero es  mayor que 10" << endl;
        cout << "El numero es: " << edad << ", está clarisimo.";
    }
    else
    {
        cout << "El numero es  menor que 10" << endl;
        cout << "El numero es: " << edad << ", está clarisimo.";
    }

    // PRIMER WHILE
    int prod = 2;
    while (prod < 1000)
    {
        prod = prod * 2;
    }
    cout << "El numoer es: " << prod << endl;

    int edad;
    cout << "Que edad tenes" << endl;
    cin >> edad;
    cout << "Tu edad es: " << edad << endl;

    

    return 0;
}