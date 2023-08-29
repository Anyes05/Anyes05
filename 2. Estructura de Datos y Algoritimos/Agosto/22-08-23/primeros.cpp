#include <iostream>
using namespace std;

/*primeros: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de
l.*/

struct nodo
{
    int info;
    nodo *sig;
};

typedef nodo *Lista;

nodo *crearLista(int n)
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

Lista primeros(Lista L, int i)
{
    Lista otro = NULL; // puntero otro que  sera de i elementos.
    Lista aux;         // para recorrer y construir la nueva lista enlazada.s

    while (L != NULL && i-- > 0)
    { // Se inicia un bucle while que recupera la lista original L y copia los primeros i elementos.

        if (otro == NULL)
        {
            otro = new nodo;
            otro->info = L->info;
            aux = otro;
        }
        else
        {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->info = L->info;
        }
        L = L->sig;
    }
    if (otro != NULL)
        aux->sig = NULL;
    return otro;
}

int main()
{

    int n = 10;
    int i = 3;
    Lista L = crearLista(n);
    imprimir(L);
    cout << endl;
    imprimir(primeros(L, i));

    return 0;
}
