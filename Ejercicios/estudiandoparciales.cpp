#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct nodoAB
{
    int info;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

/*Defina una función recursiva cortarArbol que dados un AB a y un entero x, corte del árbol original
el subárbol que comienza por x y lo retorne. En caso de no encontrarse el elemento se retornará el
árbol vacío. */

AB cortarArbol(AB &a, int x)
{

    if (a == NULL)
        return NULL;

    AB nuevo = NULL;

    if (a->info == x)
    {
        nuevo = a;
        a = NULL;
    }
    else
    {
        nuevo = cortarArbol(a->izq, x);
        if (nuevo == NULL)
        {
            cortarArbol(a->der, x);
        }
    }

    return nuevo;
}

int min(int a, int b)
{
    if (b > a)
        return a;
    return b;
}

int maxAlturaPerfecto(AB a)
{
    if (a == NULL)
        return 0;
    if (a->izq == NULL || a->der == NULL)
        return 1;
    else
        return 1 + min(maxAlturaPerfecto(a->izq), maxAlturaPerfecto(a->der));
}



/*Implemente iterativamente una función int maximo (ABB a) que dado un árbol binario de
búsqueda a de tipo ABB no vacío, retorne el valor máximo que contiene. La función debe
evitar recorrer nodos de a que no sean estrictamente necesarios.*/

struct nodoABB
{
    int raiz;
    nodoABB *izq;
    nodoABB *der;
};
typedef nodoAB *ABB;

int maximo (ABB b){

    while (b->der != NULL)
        b=b->der;
    return b->raiz;
}

