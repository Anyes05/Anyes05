#include <iostream>
#include <string>
using namespace std;

/*III. función contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
subárboles son vacíos) del mismo.*/

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

// precondicion: que sea null o hoja
uint contarHojas(AB a)
{

    if (a == NULL)
        return 0;
    if (a->izq == NULL && a->der == NULL)
        return 1;

    return contarHojas(a->izq) + contarHojas(a->der);
}

void imprimir(AB a)
{
    if (a != NULL)
    {
        cout << a->elem << "    ";
        imprimir(a->izq);
        imprimir(a->der);
    }
}

int main()
{
    AB izq = constArbol(3, NULL, NULL);
    AB der = constArbol(7, NULL, NULL);
    AB raiz = constArbol(8, izq, der);
    imprimir(raiz);

    return 0;
}