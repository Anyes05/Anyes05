#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#define MAX 10

int main()
{
    int num, intentos = 0, secreto;

    srand(time(NULL));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            secreto = rand() % 100 + 1;
        }
    }

    while (intentos < MAX)
    {
        cout << "En que num pense?" << endl;
        cin >> num;

        intentos++;
        if (secreto == num)
        {
            cout << "CORRECTO!! Ganaste el Juego" << endl;
            break;
        }
        else if (num < secreto)
        {
            cout << "El numero que busca es mas grande" << endl;
        }
        else
        {
            cout << "El numero que busca es mas chico" << endl;
        }

        if (intentos >= MAX)
        {
            cout << "Perdiste. El número que elegí fue " << secreto << endl;
            break;
        }
    }
    return 0;
}
