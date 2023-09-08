#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

struct nodoABB
{
    uint elem;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

/*procedimiento insertarABB: que recibe un natural x, y un ABB b, e inserta x en b manteniendo su
cualidad de árbol binario de búsqueda. Si x pertenece al árbol la operación no tiene efecto.*/

void insertarABB(ABB &a, uint x)
{
    if (a == NULL)
    {
        a = new nodoABB;
        a->elem = x;
        a->izq = a->der = NULL;
        return;
    }
    if (x < a->elem)
        insertarABB(a->izq, x);
    if (x > a->elem)
        insertarABB(a->der, x);
}

/*función perteneceABB: que recibe un natural x y un ABB b y devuelve true si y solo si x es un elemento
del árbol b.*/

bool pertenece(ABB a, uint x)
{
    if (a == NULL)
        return false;
    if (a->elem == x)
        return false;
    if (x < a->elem)
        return pertenece(a->izq, x);
    else
        return pertenece(a->der, x);
}

/*función maxABB: que recibe un ABB no vacío b y devuelve el elemento de máximo valor en b*/

ABB constArbol(uint x, ABB sub_izq, ABB sub_der)
{

    ABB raiz = new nodoABB;
    raiz->elem = x;
    raiz->izq = sub_izq;
    raiz->der = sub_der;
    return raiz;
}

void imprimir(ABB a)
{
    if (a != NULL)
    {
        cout << a->elem << "    ";
        imprimir(a->izq);
        imprimir(a->der);
    }
}

uint maxABB(ABB b)
{
    if (b == NULL)
        return 0;
    while (b->der != NULL)
        b = b->der;
    return b->elem;
}

/*procedimiento removerMaxABB: que recibe un ABB no vacío b y elimina el elemento de máximo valor
en b.*/

uint removerMaxABB(ABB &b){
    if(b->der ==NULL){
        ABB borrar = b;
        b=b->izq;
        delete borrar;
    }else{
        removerMaxABB(b->der);
    }
}

int main()
{
    ABB izq = constArbol(3, NULL, NULL);
    ABB der = constArbol(7, NULL, NULL);
    ABB raiz = constArbol(8, izq, der);

    imprimir(raiz);

   cout << maxABB(raiz);
    return 0;
}