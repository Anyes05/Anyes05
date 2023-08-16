#include <iostream>
using namespace std;

bool esPrimo(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int cantPrimosMenores(int num)
{
    int cont = 0;
    for (int i = 0; i < num; i++)
    {
        if (esPrimo(i))
        {
            cont++;
        }
    }
    return cont;
}

void descomposicion(int num, int primos[100], int exponentes[100], int &cont)
{
    cont = 0;
    int exp;
    for (int i = 2; i <= num; i++)
    {
        if (esPrimo(i))
        {
            exp = 0;
            while (num % i == 0)
            {
                exp++;
                num /= i;
            }
            if (exp > 0)
            {
                primos[cont] == i;
                exponentes[cont] == exp;
                cont++;
            }
        }
    }
}

int main()
{
    int num = 3, primos[100], exponentes[100], cont;
    std::cout << esPrimo(num) << endl;
    std::cout << cantPrimosMenores(num);
    descomp =cdddfr descomposicion(18, primos, exponentes, cont);
    return 0;
}