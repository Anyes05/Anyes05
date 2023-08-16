#include <iostream>
using namespace std;

struct nodo {
    int dato;
    nodo * sig;
};

void imprimir (nodo * q) {
    while (q != NULL) {
        cout << "|" << q->dato << "| - ";
        q = q->sig;
    }
    cout << "#";
}

void imprimir_recursivo (nodo * q) {
    if (q != NULL) {
        imprimir_recursivo(q->sig);
        cout << "|" << q->dato << "| - ";
    }
}

int main () {
    nodo * ptr3;
    ptr3 = new nodo;
    ptr3->dato = 3;
    ptr3->sig = NULL;
    
    nodo * ptr2 = new nodo;
    ptr2->dato = 2;
    ptr2->sig = ptr3;
    
    nodo * ptr1 = new nodo;
    ptr1->dato = 1;
    ptr1->sig = ptr2;

    imprimir_recursivo(ptr1);
    return 0;
}