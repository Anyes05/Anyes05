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

bool esSubLista (Lista L1, Lista L2) {
    if (L2 == NULL)
        return true;
    if (L1 == NULL)
        return false;
    if (L1->info != L2->info)
        return esSubLista(L1->sig, L2);
    else 
        return esSubLista(L1->sig, L2->sig) || esSubLista(L1->sig, L2);
}

bool esSubLista_iterativo (Lista L1, Lista L2) {
    Lista aux1 = L1;
    Lista aux2 = L2;
    while (L2 != NULL && L1 != NULL) {
        if (L1->info == L2->info) {
            L1 = L1->sig;
            L2 = L2->sig;
        }
        else {
            aux1 = L1 = aux1->sig;
            if (L2 != aux2)
                L2 = aux2;
        }
    }
    return (L2 == NULL);
}


int main()
{

    return 0;
}
