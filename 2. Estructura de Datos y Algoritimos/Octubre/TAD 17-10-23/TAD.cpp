#include <iostream>
using namespace std;

/*------Lista Indizada no acotada------*/

struct lista
{
    int dato;
    lista *sig;
};

typedef lista *Lis;

/*Constructoras.
Lista_Vacia: construye la lista vacía.
Insertar: dados una lista, un entero n y un elemento e, inserta e en la lista en la posición n. Si la lista tiene longitud m, con m menor a n-1, lo inserta en la posición m+1. Si la lista tiene longitud m, con m mayor o igual a n-1, inserta e en la posición n y desplaza en una posición los elementos que estuvieran en las posiciones siguientes.*/

Lis Listas_Vacia(Lis L)
{
    Lis res = L;
    if (L == NULL)
    {
        res = new lista;
        L->dato = NULL;
        L->sig = NULL;
    }
    return res;
}

Lis Insertar(Lis L, int e, int n)
{

    Lis res = new lista;
    res->dato = e;

    if (n == 1)
    {
        res->sig = L;
        return res;
    }

    Lis aux = L;
    int posicion = 1;
    while (aux != NULL)
    {
        if (posicion + 1 == n)
        {
            res->sig = aux->sig;
            aux->sig = res;
            return L;
        }

        aux = aux->sig;
        posicion++;
    }

    return L;
}

/*Predicados.
Esta_Vacia: retorna true si, y solamente si, la lista es Vacía.
Esta_Definido: dados una lista y un entero n, retorna true si, y solamente si, la lista está definida en la posición n.*/

bool Esta_Vacia(Lis L)
{
    if (L == NULL)
        return true;
    return false;
}

bool Esta_Definido(Lis L){
    
}

/*Selectoras:
Elemento: dados una lista y un entero n, retorna el elemento en la posición n. Si la lista tiene longitud menor a n, la operación está indefinida.
Borrar: dados una lista y un entero n, elimina de la lista el elemento en la posición n. Si la posición no está definida, la operación no hace nada. Si la posición está definida, elimina el elemento en dicha posición y desplaza en una posición los elementos que estuvieran en las posiciones siguientes (contrae la lista).*/

/*Destructora:
Destruir: destruye una lista, liberando la memoria que ésta ocupa.*/

/*------Lista no acotada de posiciones implícitas------*/

/*Crear la lista vacía*/

/*Insertar un elemento luego de la posición actual. Si la lista es vacía, se agrega el elemento. Si la posición actual es la del último elemento, se agrega el nuevo elemento al final de la lista. La posición actual pasa a ser en cualquier caso la del elemento insertado*/

/*Insertar un elemento antes de la posición actual. Si la lista es vacía, se agrega el elemento. Si la posición actual es la del primer elemento, se agrega el nuevo elemento al comienzo de la lista. La posición actual pasa a ser en cualquier caso la del elemento insertado*/

/*Fijar la posición actual al comienzo de la lista (en el primer elemento), si ésta no es vacía*/

/*Avanzar la posición actual al próximo elemento de la lista, si ésta no es vacía y la posición actual no corresponde a la del último elemento*/

/*Chequear si la lista es vacía*/ 

/*Chequear si la posición actual es la del último elemento (se encuentra al final de la lista), si la lista no es vacía*/

/* Retornar el elemento en la posición actual, si la lista no es vacía*/

/* Eliminar el elemento en la posición actual, si la lista es no vacía. La posición actual pasa a ser la del elemento siguiente en la lista. Si se elimina el último elemento, la posición actual pasa a ser la del ultimo elemento de la lista resultante, si ésta es no vacía.*/

/*Implemente en C el TAD Lista no acotada de posiciones implícitas de elementos de un tipo T de tal manera que todas las operaciones tengan O(1) de tiempo de ejecución en el peor caso. Se sugiere utilizar una estructura de lista dinámica doblemente encadenada.*/



