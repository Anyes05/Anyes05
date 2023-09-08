#include <iostream>
#include <string>
using namespace std;

/*(b) Se dice que un árbol es perfecto si todas las hojas están en el mismo nivel y todos los nodos internos
tiene dos subárboles no vacíos, o sea, si todos los niveles están completos. ¿Cuántos nodos tiene un
árbol binario perfecto de altura h? Escriba una función booleana que dados un árbol binario b y un
natural h, retorne TRUE si y solo si b es un árbol perfecto de altura h. Implemente dicha función sin usar
operaciones auxiliares para calcular la cantidad de nodos o la altura de un árbol. Cada nodo se puede
visitar a lo sumo una vez y no se deben visitar nodos innecesarios.*/

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

void imprimir(AB a)
{
    if (a != NULL)
    {
        cout << a->elem << "    ";
        imprimir(a->izq);
        imprimir(a->der);
    }
}

bool abrolPerfecto(AB b, uint h)
{

    if (b == NULL)
        return h==0;
    if (b->izq == NULL && b->der == NULL)
        return h==1;
    if (b->izq ==NULL || b-> der == NULL || h<2)
        return false;
    
    return abrolPerfecto(b->izq, h-1)&& abrolPerfecto(b->der, h-1);

}

int main()
{
     AB izq = constArbol(3, NULL, NULL);
    AB der = constArbol(7, NULL, NULL);
    AB raiz=constArbol(8, izq, der);

    imprimir(raiz);

    abrolPerfecto(raiz, 2);
    return 0;
}
