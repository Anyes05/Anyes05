#include <iostream>
using namespace std;

/*IV. insFinal: dados un entero x y una lista l, inserta x al final de l*/

struct nodo
{
    int info;
    nodo *sig;
};

typedef nodo *Lista;

nodo *crearN(int n)
{
    nodo *res = new nodo;
    nodo *aux = res; // los dos punterso apuntan al mismo lado
    res->info = n;

    while (--n > 0) // primero resta y despues compara
    {
        aux->sig = new nodo;
        aux = aux->sig;
        aux->info = n--;
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

void insFinal(Lista &L, int x)
{
    Lista nuevo = new nodo;
    nuevo->info = x;
    nuevo->sig = NULL;
    if (L == NULL)
        L = nuevo;
    else
    {
        Lista aux = L;
        while (L->sig != NULL)
            L = L->sig;
        L->sig = aux;
        aux->info = x;
        aux->sig=NULL;
    }
}

int main()
{

    return 0;
}
