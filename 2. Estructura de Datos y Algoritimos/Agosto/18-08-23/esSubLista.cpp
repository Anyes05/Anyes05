#include <iostream>
using namespace std;

/*VI. esSubLista: dadas dos listas l y p, verifica si l esta incluida en p. Una lista l1 está incluida en l2 si
y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3 l1 l4. Tenga en cuenta que las listas
pueden ser vacías.*/

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

bool esSubLista(Lista &L, Lista &P, int x)
{
    
}

int main()
{

    return 0;
}
