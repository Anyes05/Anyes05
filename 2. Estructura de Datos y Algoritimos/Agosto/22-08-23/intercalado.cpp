#include <iostream>
using namespace std;

/*intercalado: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas
listas.*/

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

// Pre-condición: las listas no tienen elementos en común.
Lista intercalado(Lista L1, Lista L2)
{
    // Creo un nodo ficticio para evitar tener muchos casos. A lo último lo elimino.
    Lista res = new nodo;
    Lista aux = res;
    while (L1 != NULL || L2 != NULL)
    {
        aux->sig = new nodo;
        aux = aux->sig;
        if ((L1 == NULL) || (L2 != NULL && L1->info > L2->info))
        {
            aux->info = L2->info;
            L2 = L2->sig;
        }
        else
        {
            aux->info = L1->info;
            L1 = L1->sig;
        }
    }
    aux->sig = NULL;
    Lista borrar = res;
    res = res->sig;
    delete borrar;
    return res;
}

int main()
{
    int n = 10;
    int i = 3;

    Lista L1 = crearLista(n);
    Lista L2 = crearLista(i);

    imprimir(L1);
    cout << endl;
    imprimir(L2);
    cout << endl;

    imprimir(intercalado(L1, L2));

    return 0;
}
