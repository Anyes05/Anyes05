#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

void imprimir(AB a)
{
    if (a != NULL)
    {
        cout << a->elem << "    ";
        imprimir(a->izq);
        imprimir(a->der);
    }
}

/*IV. función altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es
0.*/
uint altura(AB a)
{
    if (a == NULL)
        return 0;
}
