#include <iostream>
#include "listaimplicita.hpp"
using namespace std;

struct nodoLista
{
    T info;
    nodoLista *ant;
    nodoLista *sig;
};

typedef nodoLista *lis;

struct nodoListaImplicita
{
    lis inicio;
    lis actual;
};

typedef nodoListaImplicita *Lista;

Lista Listas_Vacia()
{
    Lista ret = new nodoListaImplicita;
    ret->actual = ret->inicio = NULL;
    return ret;
}

void InsertarActual(Lista L, T e)
{
    lis nuevo = new nodoLista;
    nuevo->info = e;

    if (L->inicio == NULL)
    {
        nuevo->ant = nuevo->sig = NULL;
        L->inicio = L->actual = nuevo;
    }
    else
    {
        nuevo->sig = L->actual->sig;
        if (nuevo->sig != NULL)
            nuevo->sig->ant = nuevo;
        L->actual->sig = nuevo;
        nuevo->ant = L->actual;
        L->actual = nuevo;
    }
}

void InsertarAntes(Lista L, T e)
{
    lis nuevo = new nodoLista;
    nuevo->info = e;

    if (L->inicio == NULL)
    {
        nuevo->ant = nuevo->sig = NULL;
        L->inicio = L->actual = nuevo;
    }
    else
    {
        nuevo->ant = L->actual->ant;
        if (nuevo->ant == NULL)
            L->inicio = nuevo;
        else
            nuevo->ant->sig = nuevo;
        L->actual->ant = nuevo;
        nuevo->sig = L->actual;
        L->actual = nuevo;
    }
}

void posicionComienzo(Lista L)
{
    L->actual = L->inicio;
}
void prosicionSigiente(Lista L)
{
    L->actual = L->actual->sig;
}

bool esVacia(Lista);
bool esUltimo(Lista);

T darActual(Lista L)
{
    return L->actual->info;
}

void eliminarActual(Lista L)
{
    lis borrar = L->actual;
    if (L->actual = L->actual->sig)
    {
        L->actual = L->actual->sig;
        L->actual->ant = borrar->ant;
        if (borrar->ant != NULL)
            borrar->ant->sig = L->actual;
        else
            L->inicio = L->actual;
    }
    else
    {
        if (L->actual->ant == NULL)
            L->actual = L->inicio = NULL;
        else
        {
            L->actual = L->actual->ant;
            L->actual->sig = NULL;
        }
    }
    delete borrar;
}