#include <iostream>
using namespace std;

/*III. insOrden: dados un entero x y una lista l ordenada: inserta x en l ordenadamente. ahora de forma recursiva*/

struct nodo
{
    int info;
    nodo *sig;
};

typedef nodo *Lista;

void insOrden_Recursivo(Lista &L, int x)
{
    if (L == NULL || L->info > x)
    {
        Lista nuevo = new nodo;
        nuevo->info = x;
        nuevo->sig = L;
        L = nuevo;
    }
    else
        insOrden_Recursivo(L->sig, x); // con mi puntero L, le mando L ->sig como parametro, no estamos modificando L, eso se hace asi: L = l->sing.
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

    return 0;
}
