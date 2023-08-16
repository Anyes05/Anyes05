
#include <bits/stdc++.h>
using namespace std;

// Generar todos los números primos menores que n.
bool primo(int n, bool esPrimo[])
{
    // Inicializar todas las entradas
    // de matriz booleana como
    // verdadero. un valor en
    // isPrime[i] finalmente
    // ser falso si no soy un
    // primo, de lo contrario verdadero
    // bool esPrimo[n+1];
    esPrimo[0] = esPrimo[1] = false;
    for (int i = 2; i <= n; i++)
        esPrimo[i] = true;

    for (int p = 2; p * p <= n; p++)
    {

        // Si esPrimo[p] no se cambia, entonces es
        // un primo
        if (esPrimo[p] == true)
        {
            // Actualizar todos los múltiplos de p
            for (int i = p * 2; i <= n; i += p)
                esPrimo[i] = false;
        }
    }
}

// Devuelve verdadero si n es truncable por la derecha,
// más falso
bool truncable(int n)
{
    // Generando números primos usando Sieve
    bool esPrimo[n + 1];
    primo(n, esPrimo);

    // Comprobando si el número permanece
    // prime cuando el último ("correcto")
    // el dígito se elimina sucesivamente
    while (n)
    {
        if (esPrimo[n])
            n = n / 10;
        else
            return false;
    }
    return true;
}

// programa controlador
int main()
{
    int n = 137;
    if (truncable(n))
        cout << "si" << endl;
    else
        cout << "No" << endl;
    return 0;
}