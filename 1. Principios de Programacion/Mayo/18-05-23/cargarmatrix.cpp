#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
char m[9][9];

// entre 97 y 122 estan los caracteres en la tabla de ascii

void modificar_celda()
{
    char c;
    int fila, col;
    for (int i = 0; i < 5; i++)
    {
        cout << "indique fila para modificar: ";
        cin >> fila;
        cout << "indique columna para modificar: ";
        cin >> col;
        cout << "indique caracter para modificar: ";
        cin >> c;
        m[fila][col] = c;
    }
}

void imprimir_matrix()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl
         << endl;
}

void cargar_matrix()
{
    srand(time(NULL));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            m[i][j] = rand() % 26 + 97;
        }
    }
}

int main()
{
    cargar_matrix();

    imprimir_matrix();

    int modifica;
    do
    {
        cout << "desea modificar una celda? \n  Ingrese 1 SI\n Ingrese 0 NO \n";
        cin >> modifica;
        if (modifica == 0)
            break;
        modificar_celda();
    } while (modifica == 1);

    imprimir_matrix();

    return 0;
}
