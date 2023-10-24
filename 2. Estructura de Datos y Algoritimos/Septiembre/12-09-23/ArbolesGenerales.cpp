#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

struct nodoAG
{
    int dato;
    nodoAG *pH;
    nodoAG *sH;
};
typedef nodoAG *AG;

/*(d) insertar: Dados un árbol y dos enteros h y p, inserta a h como el primer hijo de p en el árbol (hijo más
a la izquierda) si p pertenece al árbol y h no pertenece al árbol. En caso contrario la operación no tiene
efecto.*/

void insertar(AG &a, int h, int p)
{

    if (a->dato != h)
    {
        if (a->dato == p)
        {
            AG nuevo = new nodoAG;
            nuevo->dato = h;
            nuevo->pH = NULL;
            nuevo->sH = a->pH;
            a->pH = nuevo;
        }
        else
        {
            if (a->pH != NULL)
                insertar(a->sH, h, p);
            if (a->sH != NULL)
                insertar(a->sH, h, p);
        }
    }
}

/*(e) borrar: Dados un árbol y un entero x, elimina a x del árbol si es una hoja del árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se debe liberar la
memoria asignada a él.*/

void borrar(AG a, int x)
{
    if (a->pH != NULL)
    {
        if (a->pH->dato == x)
            a->pH->pH = NULL;
        AG borrar = a->pH;
        a->pH = borrar->sH;
        delete borrar;
        return;
    }
}

/*(f) borrarSub: Dados un árbol y un entero x, elimina a x del árbol, si pertenece al árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se deberá liberar la
memoria asignada a los elementos que están en el subárbol dependiente de éste.*/



/*------EJERCICIO 9------*/

/*Implemente la función AG padre(AG g, int x) que retorne un puntero al nodo padre en g del nodo que
tenga a x como dato. Asumimos que g no tiene elementos repetidos. Si x no está en g o si x es la raíz de
g, la función padre deberá retornar NULL. No se pueden definir operaciones auxiliares para implementar
padre*/


AG padre(AG g, int x){
    // Caso base: si el árbol está vacío o el nodo actual contiene el valor x, retorna NULL
    if (g == NULL || g->dato == x) {
        return NULL;
    }
    
    // Caso base: si el primer hijo del nodo actual contiene el valor x, retorna el nodo actual
    if (g->pH != NULL && g->pH->dato == x) {
        return g;
    }
    
    // Caso recursivo: busca en los hermanos del nodo actual
    AG hermano = g->sH;
    while (hermano != NULL) {
        if (hermano->dato == x) {
            return g;
        }
        hermano = hermano->sH;
    }
    
    // Caso recursivo: busca en los hijos del nodo actual
    AG hijo = g->pH;
    while (hijo != NULL) {
        AG resultado = padre(hijo, x);
        if (resultado != NULL) {
            return resultado;
        }
        hijo = hijo->sH; // Avanza al siguiente hijo
    }
    
    // Si no se encontró el nodo con valor x en este subárbol, retorna NULL
    return NULL;
}


