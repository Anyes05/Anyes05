#include <iostream>
#include <string>
using namespace std;

/*IV. esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino
desde la raíz a un hoja de b.*/

typedef unsigned int uint;

struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

struct nodoLista
{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

AB constArbol(uint x, AB sub_izq, AB sub_der)
{

    AB raiz = new nodoAB;
    raiz->elem = x;
    raiz->izq = sub_izq;
    raiz->der = sub_der;
    return raiz;
}

void imprimir (AB a) {
    if (a != NULL) {
        cout << a->elem << "    ";
        imprimir(a->izq);
        imprimir(a->der);
    }
}



bool esCamino(Lista L, AB a){
    if (a == NULL && L == NULL)
        return true;
    if (a == NULL &&  L != NULL )
        return false;
    if (a != NULL &&  L == NULL)
        return false;
    
    if (a->elem == L->elem)
    {
        return esCamino(L->sig, a->der);
    }
    
    
    


    
}


int main()
{
    
    return 0;
}
