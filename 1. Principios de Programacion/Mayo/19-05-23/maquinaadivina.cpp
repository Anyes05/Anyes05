#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#define MAX_RANGO 100000

int main()
{

    cout << "piense en un numero" << endl;
    int min = 0, max = MAX_RANGO, medio, opcion, num;

    do
    {
        medio = (min + max) / 2;
        cout << "   Es el numero: " << medio << "?" << endl;
        cout << "   Opciones: " << endl;
        cout << "   1. Si" << endl;
        cout << "   2. mi numero es mayor" << endl;
        cout << "   3. mi numero es menor" << endl;
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "gane jeje";
            break;
        case 2:
            min = medio;
            break;
        case 3:
            max = medio;
            break;
        }
    } while (opcion != 1);

    return 0;
}
