#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#define MAX 6

int main()
{
    int persona = 0, maquina = 0, intentos, dado1, dado2, dado3, dado4;

    while (intentos <= 5)
    {
        cout << "Tirando dados..." << endl;

        srand(time(NULL));

        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        dado3 = rand() % 6 + 1;
        dado4 = rand() % 6 + 1;

        persona = persona + dado1 + dado2;
        maquina = maquina + dado3 + dado4;

        intentos++;
    }

    if (persona > maquina)
    {
        cout << "Ganaste Vos Persona: " << persona << "Maquina: " << maquina;
    }
    else
    {
        cout << "Gano la Maquina" << endl
             << "Persona: " << persona << "Maquina: " << maquina;
    }

    return 0;
}
