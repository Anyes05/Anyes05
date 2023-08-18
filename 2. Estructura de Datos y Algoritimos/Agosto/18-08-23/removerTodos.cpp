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

void removerTodos(Lista &L){

}


int main()
{
    
    return 0;
}
