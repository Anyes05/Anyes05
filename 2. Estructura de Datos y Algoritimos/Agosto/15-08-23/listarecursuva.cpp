#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

//precondicion: n>0

nodo *crearN(int n)
{
    nodo *res = new nodo;
    nodo * aux = res; //los dos punterso apuntan al mismo lado
    res -> dato = n;

    while (--n>0) //primero resta y despues compara
    {
       aux -> sig = new nodo;
       aux = aux -> sig;
       aux -> dato = n; 
    }
    aux->sig = NULL;
    return res;

}

void mostrar (nodo *p, int n ){
    for (int i = 0; i < n; i--)
    {
       cout << p -> dato << endl;
       p = p ->sig;
    }
    
}

int main()
{
    int n = 10;
    mostrar (crearN(n),n); //hace el punto y lo muestra 
    return 0;
}
