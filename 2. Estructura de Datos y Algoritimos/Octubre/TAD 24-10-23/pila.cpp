#include <iostream>
#include "pila.hpp"
using namespace std;

struct nodo
{
    T dato;
    nodo *sig;
};
struct nodoPila
{
    nodo *pila;
    int cant;
};

Pila crearPila()
{
    Pila p = new nodoPila;
    p->pila = NULL;
    p->cant = 0;
    return p;
}

void apilar(T i, Pila &p)
{
    nodo *nuevo = new nodo;
    nuevo->dato = i;
    nuevo->sig = p->pila;
    p->pila = nuevo;
    p->cant++;
}
