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

AB copiar(AB a){
    if (a== NULL)
        return NULL;
    AB nuevo = new nodoAB;
    nuevo ->elem = a->elem;
    nuevo -> izq = copiar(a->izq);
    nuevo -> der = copiar (a->der);
    return nuevo;
}

int main()
{
    AB izq = constArbol(3, NULL, NULL);
    AB der = constArbol(7, NULL, NULL);
    AB raiz = constArbol(8, izq, der);
    imprimir(raiz);



    return 0;
}
