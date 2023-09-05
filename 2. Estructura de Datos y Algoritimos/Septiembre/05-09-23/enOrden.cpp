#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

/*I. enOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
recorrida en orden de b.*/

struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

struct nodoLista
{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

Lista insComienzo(uint elem, Lista &L)
{
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = L;
    L = nuevo;
    return L;
}

Lista merge(Lista L1, Lista L2)
{
    if (L1 == NULL)
        return L2;
    Lista aux = L1;
    while (aux->sig != NULL)
        aux = aux->sig;
    aux->sig = L2;
    return L1;
}


Lista enOrden(AB a)
{
    if (a == NULL)
        return NULL;
    Lista der = enOrden(a->der);
    Lista L = insComienzo(a->elem, der);
    return merge(enOrden(a->izq), L);
}

int main()
{
    return 0;
}
