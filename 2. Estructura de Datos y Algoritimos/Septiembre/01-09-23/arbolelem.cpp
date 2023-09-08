#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// II. función contarElems: que recibe un árbol y retorna la cantidad de elementos del mismo.

typedef unsigned int uint;

struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};

typedef nodoAB *AB;

uint contarElems(AB a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + contarElems(a->izq)+contarElems(a->der);
}
AB constArbol(uint x, AB sub_izq, AB sub_der)
{

    AB raiz = new nodoAB;
    raiz->elem = x;
    raiz->izq = sub_izq;
    raiz->der = sub_der;
    return raiz;
}
int main()
{

    AB izq = constArbol(3, NULL, NULL);
    AB der = constArbol(7, NULL, NULL);
    AB raiz=constArbol(8, izq, der);
    cout << "La cantidad de elementos es: " << contarElems(raiz) << endl;
    return 0;
}
