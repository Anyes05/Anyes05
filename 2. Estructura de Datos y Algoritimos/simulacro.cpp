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
árbol vacío.*/

AB cortarArbol(AB &a, int x)
{
    if (a == NULL)
        return NULL;

    AB res;

    if (a->info == x)
    {
        res = a;
        a = NULL;
    }
    else
    {
        res = cortarArbol(a->izq, x);
        if (res == NULL)
            res = cortarArbol(a->der, x);
    }
    return res;
}

/*Un árbol perfecto es un árbol en el cual todos los nodos interiores tienen dos hijos y todos las hojas
están en el mismo nivel. Un árbol vacío y un árbol con un sólo nodo son árboles perfectos.
Implemente una función recursiva maxAlturaPerfecto que, dado un árbol a devuelve la altura del
subárbol máximo perfecto con la misma raíz que a. Notar que la altura del subárbol máximo perfecto
está determinada por el nodo más cercano a la raíz que no tenga alguno de los hijos, ver nodo 6 de la
Figura. Recordar que la altura del árbol vacío es 0 y la de un árbol con un sólo nodo es 1. */

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

/*Implemente una función recursiva menor que dado un árbol general no vacío a, sin elementos
repetidos y un número natural k mayor que 0, retorne el mínimo elemento de a que se encuentra en
los primeros k niveles del árbol. Si k es mayor a la altura de a, el procedimiento debe retornar el
mínimo elemento del árbol. Puede asumir que cuenta con una función minimo que dados dos
enteros retorna el más chico de ellos.*/

struct nodoAG
{
    int info;
    nodoAG *pH, *sH;
};
typedef nodoAG *AG;

int menor(AG a, int k)
{
    int res = a->info;
    int min;
    if (a->sH != NULL)
    {
        min = menor(a->sH, k);
        res = MIN(min, res);
    }
}

struct nodo_lista
{
    int info;
    nodo_lista *sig;
};

typedef nodo_lista *Lista;

struct nodo_ocurrencias
{
    int info;
    unsigned cant;
    nodo_ocurrencias *sig;
};

typedef nodo_ocurrencias *ListaOcurrencias;

// Recorre la lista L, crea una lista con múltiples ocurrencias y la retorna
// Pre-Condición: L está ordenada de menor a mayor, pudiendo contener elementos repetidos
// Post-Condición: la lista resultante deberá estar ordenada de menor a mayor
ListaOcurrencias crear_lista_ocurrencias(Lista L)
{
    ListaOcurrencias res = new nodo_ocurrencias;
    res->sig = NULL;
    if (L->sig == NULL)
        return res;
    ListaOcurrencias aux = res;
    aux = aux->sig;
    L = L->sig;
    aux->info = L->info;
    aux->cant = 1;
    while (L->sig != NULL)
    {
        L = L->sig;
        if (L->info != aux->info)
        {
            aux->sig = new nodo_ocurrencias;
            aux = aux->sig;
            aux->info = L->info;
            aux->cant = 1;
        }
        else
            aux->cant;
    }
    aux->sig = NULL;
    return res;
}

// Retorna true si L contiene a todos sus
// elementos contiguos separados por 2 unidades
// Pre-Condición: L está ordenada de menor a mayor

bool separados(Lista L)
{
    if (L == NULL)
        return true;
    if (L->sig == NULL)
        return true;
    if (L->sig->info <= L->info + 2)
        return separados(L->sig);
    return false;
}

struct nodoLista
{
    int info;
    nodoLista *sig;
};
typedef nodoLista *Lista;

/*Se pide implementar iterativamente el siguiente procedimiento, que junta todas las ocurrencias de
elementos repetidos en la lista de acuerdo al orden en que aparecen. Asuma que la lista no está
pasada por Celda Dummy sino utilizando directamente el puntero al primer nodo*/

// Pre-Condición: L no vacía, L puede contener elementos repetidos en cualquier orden
void juntarRepetidos(Lista L)
{
    Lista aux = L, temp;

    while (aux->sig->info != NULL)
    {
        if (aux->sig->info == L->info)
        {
            L = L->sig;
            aux = L;
        }
        else
        {
            temp = aux->sig;
            while (temp->sig != NULL)
            {
                if (temp->sig->info != L->info)
                    temp = temp->sig;
                else
                {
                    aux = temp->sig;
                    temp->sig = aux->sig;
                    aux->sig = L->sig;
                    L->sig = aux;
                }
            }
            L = aux->sig;
            aux = L;
        }
    }
}

int main()
{

    return 0;
}
