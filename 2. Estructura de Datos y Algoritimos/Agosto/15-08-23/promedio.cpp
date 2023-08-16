#include <iostream>
using namespace std;

struct nodo
{
    int info;
    nodo *sig;
};

typedef nodo *Lista;

/*II. promedio: dada una lista no vacía, retorna el promedio de sus elementos.*/

float promedio(Lista L)
{
    float total = 0;
    int cant = 0;
    while (L != NULL)
    {
        total += L->info;
        cant++;
        L = L->sig;
    }
    return total / cant;
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

int main()
{
    int n = 5;
    Lista L = crearN(n);
    imprimir(L);
    cout << endl;
    cout << "el promedio de la lista es: " << promedio(L) << endl;

    return 0;
}
