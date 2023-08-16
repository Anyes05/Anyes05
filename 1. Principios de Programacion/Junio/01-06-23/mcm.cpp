#include <iostream>
using namespace std;
#include <math.h>

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
    return exp;
}

int mcd(int a, int b)
{
    int primosA[100], primosB[100];
    int expA[100], expB[100];
    int largoA, largoB;
    descomposicion(a, primosA, expA, largoA);
    descomposicion(b, primosB, expB, largoB);
    int posA = 0, posB = 0, mcm = 1;
    while ((posA < largoA) || (posB < largoB))
    {
        if (primosA[posA] < primosB[posB])
        {
            mcm *= pow(primosA[posA], expA[posA]);
            posA++;
            continue;
        }
        if (primosA[posA] > primosB[posB])
        {
            mcm *= pow(primosB[posB], expA[posB]);
            posB++;
            continue;
        }
        // los primos son iguales

        if (expA[posA] > expB[posB])
        {
            mcm *= pow(primosA[posA], expA[posA]);
        }
        else
        {
            mcm *= pow(primosB[posB], expB[posB]);
        }
        posA++;
        posB++;
    }
    return mcm;
}
int main()
{

    return 0;
}
