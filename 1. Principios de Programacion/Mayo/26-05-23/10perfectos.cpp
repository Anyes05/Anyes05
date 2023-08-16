#include <iostream>
using namespace std;

/*cargar los primos 10 numeros perfectos*/

int main()
{
    long i = 1, j = 0, contador;
    int n = 0;
    long perfecto[4];
    int maximos = 0;

    while (true)
    {
        contador = 0;
        i++;
        for (j = 1; j < i - 1; j++)
        {
            if (i % j == 0)
                contador = contador + j;
        }
        if (contador == i)
        {
            perfecto[n] = i;
            n++;
            maximos++;
        }
        if (maximos == 4)
            break;
    }

    std::cout << "numeros perfectos" << endl;

    for (n = 0; n < 4; n++)
        std::cout << perfecto[n] << endl;

    std::cout << endl;

    return 0;
}
