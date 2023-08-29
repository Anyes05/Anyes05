#include <iostream>
using namespace std;

/*(d) insertar: dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista.
La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado
es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.*/

struct nodo
{
    int info;
    nodo *sig;
};
struct cabezal
{
    nodo *primero;
    nodo *actual;
};
typedef cabezal *lista;

nodo *crearLista(int n)
{
    nodo *res = new nodo;
    nodo *aux = res; 
    res->info = n;

    while (--n > 0) 
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

void insertar(lista &L, int n){

}

int main()
{

    

    /* code */
    return 0;
}
