#include <iostream>
using namespace std;

/*III. resto: dada una lista l no vacía, retorna la lista sin su primer elemento.*/

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

Lista resto(Lista &L)
{

    Lista aux;
    Lista borrar;
    while (L != NULL)
    {
        if (L->sig == L)
        {
            delete L;
            L = NULL;
        }
        else
        {
            Lista aux = L->sig;
            while (aux->sig != L)
            {
                aux = aux->sig;
            }
            Lista borrar = L;
            aux->sig = borrar->sig;
            L = L->sig;
            delete borrar;
        }
    }
    return L;
}

int main()
{
    int n = 10;

    Lista L = crearLista(n);

    imprimir(L);
    cout << endl;

    L = resto(L);
    imprimir(L);
    
    return 0;
}
