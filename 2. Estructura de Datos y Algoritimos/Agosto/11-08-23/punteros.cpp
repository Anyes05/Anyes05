#include <iostream>
using namespace std;

// estamos haciedno listas, esto es a pedal, hay fromas mejores de resolver esto

// ESTO NO SE HACEEE

struct nodo
{
    int dato;
    nodo *sig;
};

void imprimir(nodo *q)
{
    while (q != NULL)
    {
        cout << q->dato << " ";
        q = q->sig;
    }
    cout << "#";
}

void imprimir_recursivo(nodo *q)
{
    if (q != NULL)
    {
        cout << q->dato << " ";
        imprimir_recursivo(q->sig);
    }
}

int main()
{
    nodo *ptr1; // puntero numero 1
    ptr1 = new nodo;
    ptr1->dato = 1;
    ptr1->sig = new nodo;
    ptr1->sig->dato = 2;
    ptr1->sig->sig = NULL;
    imprimir_recursivo(ptr1);

    return 0;
}