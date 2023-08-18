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

void insOrden(Lista &L, int x)
{
    //precondicion: siempre es necesario agregar este nodo, porque siempre falta en la lista.
    Lista nuevo = new nodo;
    nuevo->info = x;
    //agrega un nodo al inicio de la lista
    if (L == NULL || x < L->info)
    {
        nuevo->sig = L; //no podemos p
        L = nuevo;
    }
    //agrega un nodo que se encuentre entre medio
    else
    {
        Lista aux = L;
        while (aux->sig != NULL && aux->sig->info < x)//por ejemplo: si es el caso que queremos agregar el 3 en lista, entonces el aux sidiciendo si el siguiente es distintio de null y es menor que el 3, avanza, si es el caso que no es null y el aux es igual a 3, hace un nuevo nodo y le dice que el siguiente es el 4 y despues dice que el 2 esta antes. Al cuatro le avisa que el nuevo es el que esta antes de el.
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

    Lista L; // puntero numero 1
    L = new nodo;
    L->info = 1;
    L->sig = new nodo;
    L->sig->info = 3;
    L->sig->sig = NULL;
    imprimir(L);
    cout << endl;

    int x = 2;
    insOrden(L, x);

    return 0;
}
