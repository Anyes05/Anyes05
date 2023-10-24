#include <iostream>
#include <string>
using namespace std;

/*------EJERCICIO 1 - LISTAS SIMPLES------*/

struct nodo
{
    int info;
    nodo *sig;
};

typedef nodo *Lista;

// I. ultimo: dada una lista no vacía, retorna su último elemento.

int ultimo(Lista L /*es lo mismo que poner nodo * L*/)
{
    while (L->sig != NULL)
        L = L->sig;
    return L->info;
}

// II. promedio: dada una lista no vacía, retorna el promedio de sus elementos.

float promedio(Lista L)
{
    float total = 0;
    int cant = 0;
    while (L != NULL)
    {
        total += L->info;
        cant++;
        L = L->sig;
    }
    return total / cant;
}

// III. insOrden: dados un entero x y una lista l ordenada: inserta x en l ordenadamente. Comparar con la solución recursiva.

void insOrden(Lista &L, int x)
{
    // precondicion: siempre es necesario agregar este nodo, porque siempre falta en la lista.
    Lista nuevo = new nodo;
    nuevo->info = x;
    // agrega un nodo al inicio de la lista
    if (L == NULL || x < L->info)
    {
        nuevo->sig = L; // no podemos p
        L = nuevo;
    }
    // agrega un nodo que se encuentre entre medio
    else
    {
        Lista aux = L;
        while (aux->sig != NULL && aux->sig->info < x) // por ejemplo: si es el caso que queremos agregar el 3 en lista, entonces el aux sidiciendo si el siguiente es distintio de null y es menor que el 3, avanza, si es el caso que no es null y el aux es igual a 3, hace un nuevo nodo y le dice que el siguiente es el 4 y despues dice que el 2 esta antes. Al cuatro le avisa que el nuevo es el que esta antes de el.
            aux = aux->sig;
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

void insOrden_Recursivo(Lista &L, int x)
{
    if (L == NULL || L->info > x)
    {
        Lista nuevo = new nodo;
        nuevo->info = x;
        nuevo->sig = L;
        L = nuevo;
    }
    else
        insOrden_Recursivo(L->sig, x); // con mi puntero L, le mando L ->sig como parametro, no estamos modificando L, eso se hace asi: L = l->sing.
}

// IV. insFinal: dados un entero x y una lista l, inserta x al final de l.

void insFinal(Lista &L, int x)
{
    Lista nuevo = new nodo;
    nuevo->info = x;
    nuevo->sig = NULL;
    if (L == NULL)
        L = nuevo;
    else
    {
        Lista aux = L;
        while (L->sig != NULL)
            L = L->sig;
        L->sig = aux;
        aux->info = x;
        aux->sig = NULL;
    }
}

// V. removerTodos: dados un entero x y una lista l, remueve a x de l.

void removerTodos(Lista &L, int x)
{
    Lista borrar;
    while (L != NULL && L->info == x)
    {
        borrar = L;
        L = L->sig;
        delete borrar;
    }
    Lista aux = L;
    while (aux != NULL && aux->sig != NULL)
    {
        if (aux->sig->info == x)
        {
            borrar = aux->sig;
            aux->sig = borrar->sig;
            delete borrar;
        }
        else
            aux = aux->sig;
    }
}

/*VI. esSubLista: dadas dos listas l y p, verifica si l esta incluida en p. Una lista l1 está incluida en l2 si
y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3 l1 l4. Tenga en cuenta que las listas
pueden ser vacías.*/

bool esSubLista(Lista L1, Lista L2)
{
    if (L2 == NULL)
        return true;
    if (L1 == NULL)
        return false;
    if (L1->info != L2->info)
        return esSubLista(L1->sig, L2);
    else
        return esSubLista(L1->sig, L2->sig) || esSubLista(L1->sig, L2);
}

bool esSubLista_iterativo(Lista L1, Lista L2)
{
    Lista aux1 = L1;
    Lista aux2 = L2;
    while (L2 != NULL && L1 != NULL)
    {
        if (L1->info == L2->info)
        {
            L1 = L1->sig;
            L2 = L2->sig;
        }
        else
        {
            aux1 = L1 = aux1->sig;
            if (L2 != aux2)
                L2 = aux2;
        }
    }
    return (L2 == NULL);
}

/*------EJERCICIO 2 - FUNCIONES QUE NO COMPARTE MEMORIA------*/

// (a) primeros: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de l.

Lista primeros(Lista L, int i)
{
    Lista otro = NULL; // puntero otro que  sera de i elementos.
    Lista aux;         // para recorrer y construir la nueva lista enlazada.s

    while (L != NULL && i-- > 0)
    { // Se inicia un bucle while que recupera la lista original L y copia los primeros i elementos.

        if (otro == NULL)
        {
            otro = new nodo;
            otro->info = L->info;
            aux = otro;
        }
        else
        {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->info = L->info;
        }
        L = L->sig;
    }
    if (otro != NULL)
        aux->sig = NULL;
    return otro;
}

// (b) sinPrimeros: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de l.

Lista sinPrimeros(Lista L, int i)
{
    Lista res = NULL;
    Lista aux;
    while (L != NULL && i-- > 0)
        L = L->sig;
    while (L != NULL)
    {
        if (res == NULL)
        {
            res = new nodo;
            res->info = L->info;
            aux = res;
        }
        else
        {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->info = L->info;
        }
        L = L->sig;
    }
    if (res != NULL)
        aux->sig = NULL;
    return res;
}

// (c) intercalado: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas listas.

// Pre-condición: las listas no tienen elementos en común.
Lista intercalado(Lista L1, Lista L2)
{
    // Creo un nodo ficticio para evitar tener muchos casos. A lo último lo elimino.
    Lista res = new nodo;
    Lista aux = res;
    while (L1 != NULL || L2 != NULL)
    {
        aux->sig = new nodo;
        aux = aux->sig;
        if ((L1 == NULL) || (L2 != NULL && L1->info > L2->info))
        {
            aux->info = L2->info;
            L2 = L2->sig;
        }
        else
        {
            aux->info = L1->info;
            L1 = L1->sig;
        }
    }
    aux->sig = NULL;
    Lista borrar = res;
    res = res->sig;
    delete borrar;
    return res;
}
// (d) concatenacion: dadas dos listas l y p, retorna una lista que contiene a los elementos de l y luego a los elementos de p, en el mismo orden. Comparar con la solución recursiva.

/*------EJERCICIO 3 - LISTA DOBLEMENTE ENCADENADA------*/

struct nodo_doble
{
    int info;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef nodo_doble *Listadob;

// I. listaVacia: retorna una lista vacía.

// II. insPrincipio: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.

Listadob insPrincipio(Listadob L, int x)
{
    Listadob nuevo = new nodo_doble;
    nuevo->info = x;
    nuevo->ant = NULL;
    nuevo->sig = L;
    if (L != NULL)
        L->ant = nuevo;
    return nuevo;
}

// III. esVacia: dada una lista l, verifica si l esta vacía.

// IV. esElemento: dados un entero x y una lista l, verifica si x pertenece a l.

bool estaElemento(Listadob L, int x)
{
    if (L == NULL)
        return false;
    Listadob der = L;
    Listadob izq = L->ant;
    while (izq != NULL || der != NULL)
    {
        if (der != NULL)
        {
            if (der->info == x)
                return true;
            der = der->sig;
        }
        if (izq != NULL)
        {
            if (izq->info == x)
                return true;
            izq = izq->ant;
        }
    }
    return false;
}

// V. removerTodos: dados un entero x y una lista l, retorna el resultado de eliminar todas las ocurrencias de x de l.

// VI. insOrd: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.

// VII. remomverUltimo: dada una lista l ordenada, retorna el resultado de eliminar el último elemento de l.

// EXTRA
void insFinalDoble(Listadob &L, int x)
{
    Listadob nuevo = new nodo_doble;
    nuevo->info = x;
    nuevo->sig = NULL;
    if (L == NULL)
    {
        nuevo->ant = NULL;
        L = nuevo;
    }
    else
    {
        while (L->sig != NULL)
            L = L->sig;
        L->sig = nuevo;
        nuevo->ant = L;
    }
}

void insComienzoDoble(Listadob &L, int x)
{
    Listadob nuevo = new nodo_doble;
    nuevo->info = x;
    nuevo->ant = NULL;
    if (L == NULL)
    {
        nuevo->sig = NULL;
        L = nuevo;
    }
    else
    {
        while (L->ant != NULL)
            L = L->ant;
        L->ant = nuevo;
        nuevo->sig = L;
    }
}

/*------EJERCICIO 4 - LISTA CIRCULAR------*/

// I. listaVacia: retorna una lista vacía.

// II. esVacia: dada una lista l, verifica si l esta vacía.

// III. resto: dada una lista l no vacía, retorna la lista sin su primer elemento.

void resto(Lista &L)
{
    if (L->sig == L)
    {
        delete L;
        L = NULL;
    }
    else
    {
        Lista aux = L->sig;
        while (aux->sig != L)
        {
            aux = aux->sig;
        }
        Lista borrar = L;
        aux->sig = borrar->sig;
        L = L->sig;
        delete borrar;
    }
}

// IV. ultimo: dada una lista l no vacía, retorna su último elemento.

// V. insOrden: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l
// ordenadamente.

void insOrdCircular(Lista &L, int x)
{
    Lista nuevo = new nodo;
    nuevo->info = x;
    if (L == NULL)
    {
        nuevo->sig = nuevo;
        L = nuevo;
        return;
    }
    Lista aux;
    if (L->info > x)
    {
        nuevo->sig = L;
        aux = L->sig;
        while (aux->sig != L)
            aux = aux->sig;
        aux->sig = nuevo;
        L = nuevo;
    }
    else
    {
        aux = L;
        while ((aux->sig != L) && (aux->sig->info < x))
        {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

/*------EJERCICIO 5 - LISTA CON MANEJO IMPLÍCITO DE POSICIONES------*/

struct cabezal
{
    nodo *primero;
    nodo *actual;
};
typedef cabezal *ListaIndizada;

// (a) listaVacia: crea una lista vacía.

ListaIndizada listaVacia()
{
    ListaIndizada L = new cabezal;
    L->primero = L->actual = NULL;
    return L;
}

// (b) inicio: dada una lista l no vacía, coloca la posición actual al inicio de l.

void inicio(ListaIndizada L)
{
    L->actual = L->primero;
}

// (c) siguiente: dada una lista l no vacía, mueve la posición actual al siguiente nodo (elemento). En caso de que la posición actual sea el final de la lista, coloca la posición actual al inicio de la lista (tiene un comportamiento circular).

void siguiente(ListaIndizada L)
{
    if (L->actual->sig == NULL)
        L->actual = L->primero;
    else
        L->actual = L->actual->sig;
}

// (d) insertar: dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista. La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.

void insertarListaIndizada(ListaIndizada L, int x)
{
    Lista nuevo = new nodo;
    nuevo->info = x;
    if (L->primero == NULL)
    {
        L->primero = L->actual = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = L->actual->sig;
        L->actual->sig = nuevo;
        L->actual = nuevo;
    }
}

// (e) elemento: dada una lista l no vacía, retorna el elemento en la posición actual de l.

int elemento(ListaIndizada L)
{
    return L->actual->info;
}