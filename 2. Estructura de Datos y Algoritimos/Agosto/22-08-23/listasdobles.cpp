#include <iostream>
using namespace std;

/*Una variante de listas encadenadas es la llamada Lista Doblemente Encadenada. En dicha
implementación cada elemento de la lista referencia al siguiente elemento y al elemento anterior*/

/*insPrincipio: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.*/

struct nodo_doble
{
    int info;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef nodo_doble *Lista;

Lista insPrincipio(Lista L, int x)
{
    Lista nuevo = new nodo_doble;
    nuevo->info = x;
    nuevo->ant = NULL;
    nuevo->sig = L;
    if (L != NULL)
        L->ant = nuevo;
    return nuevo;
}

int main()
{

    return 0;
}
