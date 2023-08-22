#include <iostream>
using namespace std;

/*V. removerTodos: dados un entero x y una lista l, remueve a x de l.*/

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
void removerTodos (Lista & L, int x) {
    Lista borrar;
    while (L != NULL && L->info == x) {
        borrar = L;
        L = L->sig;
        delete borrar;
    }
    Lista aux = L;
    while (aux != NULL && aux->sig != NULL) {
        if (aux->sig->info == x) {
            borrar = aux->sig;
            aux->sig = borrar->sig;
            delete borrar;
        }
        else 
            aux = aux->sig;
    }
}

void removerTodos_recursivo (Lista & L, int x) {
    if (L != NULL) {
        if (L->info == x) {
            Lista borrar = L;
            L = L->sig;
            delete borrar;
            removerTodos_recursivo(L,x);
        }
        else 
            removerTodos_recursivo(L->sig, x);
    }
}

int main()
{
    
    return 0;
}
