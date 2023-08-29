#include <iostream>
using namespace std;

struct nodo
{
    int info;
    nodo *sig;
};
typedef nodo *Lista;

/*ultimo: dada una lista no vacía, retorna su último elemento*/

// precondicion: L no es vacia
int ultimo(Lista L /*es lo mismo que poner nodo * L*/)
{
    while (L->sig != NULL)
        L = L->sig;
    return L->info;
}

nodo *crearN(int n)
{
    nodo *res = new nodo;
    nodo *aux = res; // los dos punterso apuntan al mismo lado
    res->info = n;

    while (--n > 0) // primero resta y despues compara
    {
        aux->sig = new nodo;
        aux = aux->sig;
        aux->info = n;
    }
    aux->sig = NULL;
    return res;
}

void imprimir(nodo *q)
{
    while (q != NULL)
    {
        cout << "|" << q->info << "| - ";
        q = q->sig;
    }
    cout << "#";
}

int main()
{
    int n = 5;
    Lista L = crearN(n);
    imprimir(L);
    cout << endl;
    cout << "el utimo numero en lista es: " << ultimo(L) << endl;

    return 0;
}
