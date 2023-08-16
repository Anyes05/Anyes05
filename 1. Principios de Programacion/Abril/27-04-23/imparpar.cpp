#include <iostream>
using namespace std;

int main()
{
    /*dado un arreglo de numeros enteros, contar cantas veces aparece cada numero par y cuabntas veces aparace cada numero impar*/
    int MAX = 5, resto;
    int num[MAX] = {1, 45, 30, 21, 33};
    int arr[2] = {0};

    for (int i = 0; i < MAX; i++)
    {
        resto = num[i] % 2;
        arr[resto]++;
    }

    cout << "la cantidad de pares son " << arr[0] << endl;
    cout << "la cantidad de impares son " << arr[1] << endl;

    return 0;
}
