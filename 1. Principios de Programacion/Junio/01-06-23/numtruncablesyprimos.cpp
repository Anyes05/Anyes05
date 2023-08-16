#include <iostream>
using namespace std;
#include <math.h>

bool esPrimo(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int cantdigitos(int num){
    int cont = 0;
    while (num !=0)
    {
        num /= 10
        cont++;
    }
    return cont;
}

int descartarIzq(int n){
    int digitos = cantdigitos(n);
    int factor = pow(10,digitos-1);
    return n%factor;
}

bool primotruncable(int n){
    while (esPrimo (n))
    {
        n=descartarIzq(n);
    }
    return n==0;
    
}

int main()
{
    int n=9137;
    primotruncable(n);
    return 0;
}
