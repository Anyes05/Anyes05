#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

nodo *crearN(int n)
{
    nodo *res = NULL;
    nodo *aux;
    int i = 1;

    while (i <= n)
    {
        aux = new nodo;
        aux->dato = i++;
        aux->sig = res;
        res = aux;
    }
    return res;
}

int main()
{

    return 0;
}
