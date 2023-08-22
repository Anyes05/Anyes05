#include <iostream>
using namespace std;

/*esElemento: dados un entero x y una lista l, verifica si x pertenece a l.*/

struct nodo_doble
{
    int info;
    nodo_doble *sig;
    nodo_doble *ant;
};

typedef nodo_doble *Lista;

bool esElemtno(Lista L, int x)
{
    if (L == NULL)
        return false;
    if (L->info == x)
        return true;

    Lista der = L->sig;

    while (der != NULL)
    {
        if (der->info == x)
            return true;
        der = der->sig;
    }
    Lista izq = L->ant;
    while (izq != NULL)
    {
        if (izq->info == x)
            return true;
        izq = izq->sig;
    }
}