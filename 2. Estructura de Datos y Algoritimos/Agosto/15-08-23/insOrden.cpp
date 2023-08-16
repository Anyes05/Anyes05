#include <iostream>
using namespace std;

struct nodo
{
    int info;
    nodo *sig;
};

typedef nodo *Lista;

// VER CODIGOS DEL PROFEEEE

/*III. insOrden: dados un entero x y una lista l ordenada: inserta x en l ordenadamente. Comparar con
la solución recursiva.*/

void insOrden(Lista &ptr1, int x)
{
    Lista nuevo = new nodo;
    nuevo->info = x;
    if (ptr1 == NULL || x < ptr1->info)
    {
        nuevo->sig = ptr1;
        ptr1 = nuevo;
    }
    else
    {
        Lista aux = ptr1;
        while (aux->sig != NULL && aux->sig->info < x)
            aux = aux->sig;
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
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

int main()
{

    Lista ptr1; // puntero numero 1
    ptr1 = new nodo;
    ptr1->info = 1;
    ptr1->sig = new nodo;
    ptr1->sig->info = 3;
    ptr1->sig->sig = NULL;
    imprimir(ptr1);
    cout << endl;

    int x = 2;
    insOrden(ptr1, x);

    return 0;
}
