#include <iostream>
#include <string>
using namespace std;

/*------EJERCICIO 1 - ÁRBOLES BINARIOS------*/

typedef unsigned int uint;

struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

// I. función consArbol: que retorna un árbol no vacío a partir de un natural y otros dos árboles.

AB consArbol(uint x, AB subArbol_izq, AB subArbol_der)
{
    AB res = new nodoAB;
    res->elem = x;
    res->izq = subArbol_izq;
    res->der = subArbol_der;
    return res;
}

// II. función contarElems: que recibe un árbol y retorna la cantidad de elementos del mismo.

uint contarElems(AB a)
{
    if (a == NULL)
        return 0;
    return 1 + contarElems(a->izq) + contarElems(a->der);
}

// III. función contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos subárboles son vacíos) del mismo.

uint contarHojas(AB a)
{
    if (a == NULL)
        return 0;
    if (a->izq == NULL && a->der == NULL)
        return 1;
    return contarHojas(a->izq) + contarHojas(a->der);
}

// IV. función altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es 0.

uint altura(AB a)
{
    if (a == NULL)
        return 0;
    return 1 + max(altura(a->izq), altura(a->der));
}

// V. función copiar: que recibe un árbol y retorna una copia limpia (que no comparte registros de memoria) del mismo.

AB copiar(AB a)
{
    if (a == NULL)
        return NULL;
    AB res = new nodoAB;
    res->elem = a->elem;
    res->izq = copiar(a->izq);
    res->der = copiar(a->der);
    return res;
}

// VI. procedimiento liberarArbol: que recibe un árbol y elimina del mismo todos los nodos, liberando la memoria asociada a cada uno de ellos.

void liberarArbol(AB &a)
{
    if (a != NULL)
    {
        liberarArbol(a->izq);
        liberarArbol(a->der);
        delete a;
        a = NULL;
    }
}

/*------EJERCICIO 2 - ÁRBOLES BINARIOS------*/

// ----------- PARTE A -------------
struct nodoLista
{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

// I. enOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la recorrida en orden de b.

Lista merge(Lista L1, Lista L2)
{
    if (L1 == NULL)
        return L2;
    Lista aux = L1;
    while (aux->sig != NULL)
        aux = aux->sig;
    aux->sig = L2;
    return L1;
}

Lista insComienzo(uint elem, Lista L)
{
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = L;
    return nuevo;
}

Lista enOrden(AB a)
{
    if (a == NULL)
        return NULL;
    Lista der = enOrden(a->der);
    Lista izq = enOrden(a->izq);
    der = insComienzo(a->elem, der);

    return merge(izq, der);
}

// II. preOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la recorrida en pre orden de b. raiz, izq, der

Lista preOrden(AB a)
{
    if (a == NULL)
        return NULL;

    Lista der = preOrden(a->der);
    Lista izq = preOrden(a->izq);
    izq = insComienzo(a->elem, izq);

    return merge(izq, der);
}

// III. postOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la recorrida en post orden de b. izq, der, raiz

Lista insFinal(uint elem, Lista L)
{
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = NULL;
    if (L == NULL)
        L = nuevo;
    else
    {
        Lista aux = L;
        while (L->sig != NULL)
            L = L->sig;
        L->sig = aux;
        aux->elem = elem;
        aux->sig = NULL;
    }
}

Lista postOrden(AB a)
{
    if (a == NULL)
        return NULL;

    Lista der = enOrden(a->der);
    Lista izq = enOrden(a->izq);

        der = insFinal(a->elem, der);

    return merge(izq, der);
}

// IV. esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino desde la raíz a un hoja de b.

bool esCamino(Lista L, AB a)
{
    if (a == NULL || L == NULL)
        return false;
    if (a->elem != L->elem)
        return false;
    if (a->izq == NULL && a->der == NULL)
        return L->sig == NULL;
    return esCamino(L->sig, a->izq) || esCamino(L->sig, a->der);
}

// V. caminoMasLargo: que recibe un árbol b y retorna una lista con los elementos del camino más largo de b (desde la raíz a una hoja). En caso de haber más de un camino de igual longitud a la del camino más largo, retorna cualquiera de ellos.

bool mayor(Lista L1, Lista L2)
{
    if (L2 == NULL)
        return true;
    if (L1 == NULL)
        return false;
    return mayor(L1->sig, L2->sig);
}

Lista camino_mas_largo(AB a)
{
    if (a == NULL)
        return NULL;
    Lista izq = camino_mas_largo(a->izq);
    Lista der = camino_mas_largo(a->der);
    if (mayor(izq, der))
        return insComienzo(a->elem, izq);
    else
        return insComienzo(a->elem, der);
}

// ----------- PARTE B -------------

bool esPerfecto(AB a, uint h)
{
    if (a == NULL)
        return h == 0;
    if (a->izq == NULL && a->der == NULL)
        return h == 1;
    if (a->izq == NULL || a->der == NULL)
        return false;
    return (h > 1 && esPerfecto(a->izq, h - 1) && esPerfecto(a->der, h - 1));
}

// ----------- PARTE C -------------
// ----------- PARTE D -------------

/*------EJERCICIO 3 - ÁRBOLES BINARIOS DE BÚSQUEDA------*/

struct nodoABB
{
    uint elem;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

// (a) procedimiento insertarABB: que recibe un natural x, y un ABB b, e inserta x en b manteniendo su cualidad de árbol binario de búsqueda. Si x pertenece al árbol la operación no tiene efecto.

void insertarABB(ABB &a, uint x)
{
    if (a == NULL)
    {
        a = new nodoABB;
        a->elem = x;
        a->der = a->izq = NULL;
        return;
    }
    if (x < a->elem)
        insertarABB(a->izq, x);
    if (x > a->elem)
        insertarABB(a->der, x);
}

// (b) función perteneceABB: que recibe un natural x y un ABB b y devuelve true si y solo si x es un elemento del árbol b.

bool pertenece(ABB a, uint x)
{
    if (a == NULL)
        return false;
    if (a->elem == x)
        return true;
    if (x < a->elem)
        return pertenece(a->izq, x);
    else
        return pertenece(a->der, x);
}

bool pertenece_iterativo(ABB a, uint x)
{
    while (a != NULL)
    {
        if (a->elem == x)
            return true;
        if (x < a->elem)
            a = a->izq;
        else
            a = a->der;
    }
    return false;
}

// (c) función maxABB: que recibe un ABB no vacío b y devuelve el elemento de máximo valor en b.

// pre-condición: a no es vacío
uint maxABB(ABB a)
{
    while (a->der != NULL)
        a = a->der;
    return a->elem;
}

// (d) procedimiento removerMaxABB: que recibe un ABB no vacío b y elimina el elemento de máximo valor en b.

// pre-condición: a no es vacío
void removerMaxABB(ABB &a)
{
    if (a->der == NULL)
    {
        ABB borrar = a;
        a = a->izq;
        delete borrar;
    }
    else
        removerMaxABB(a->der);
}

// (e) procedimiento removerABB: que recibe un natural x y un ABB b y elimina el elemento de valor x de b, manteniendo su cualidad de ABB.

// (f) función k-esimo: que recibe un natural k y un ABB b y retorna el subárbol que tiene al k-ésimo menor elemento de b como raíz. Si en b hay menos de k elementos o k es cero, la función debe retornar el árbol vacío. Si k es 1, se refiere al menor elemento del árbol, si k es 2 al 2do elemento más pequeño del árbol y así sucesivamente. La solución no puede visitar ningún nodo más de una vez.

/*------EJERCICIO 4 - ÁRBOLES BINARIOS DE BÚSQUEDA Y FILATRADO------*/

struct EstInfo
{
    uint nota; // dato
    int ci;    // clave
};

struct nodoABBEstudiantes
{
    EstInfo info;
    nodoABBEstudiantes *izq, *der;
};
typedef nodoABBEstudiantes *ABBEstudiantes;

// Se dispone de las operaciones maxABB y removerMaxABB definidas en el ejercicio anterior. Se debe implementar la función filtrado, sin definir procedimientos auxiliares, para obtener un nuevo árbol solo con los estudiantes que superen una determinada nota: Devuelve un arbol con los elemntos de "b" en los que "nota" es mayor que "cota"

// SOLUCIÓN FÁCIL
void insertarABBEstudiantes(ABBEstudiantes &a, EstInfo x)
{
    if (a == NULL)
    {
        a = new nodoABBEstudiantes;
        a->info = x;
        a->der = a->izq = NULL;
        return;
    }
    if (x.ci < a->info.ci)
        insertarABBEstudiantes(a->izq, x);
    if (x.ci > a->info.ci)
        insertarABBEstudiantes(a->der, x);
}

void incluir(ABBEstudiantes a, uint cota, ABBEstudiantes &res)
{
    if (a != NULL)
    {
        if (a->info.nota > cota)
        {
            insertarABBEstudiantes(res, a->info);
        }
        incluir(a->izq, cota, res);
        incluir(a->der, cota, res);
    }
}

ABBEstudiantes filtrado_facil(ABBEstudiantes a, uint cota)
{
    ABBEstudiantes res = NULL;
    incluir(a, cota, res);
    return res;
}

// SOLUCIÓN TAL COMO LO PIDEN EN LA LETRA

// pre-condición: a no es vacío
EstInfo maxABBEstudiantes(ABBEstudiantes a)
{
    while (a->der != NULL)
        a = a->der;
    return a->info;
}

// pre-condición: a no es vacío
void removerMaxABBEstudiantes(ABBEstudiantes &a)
{
    if (a->der == NULL)
    {
        ABBEstudiantes borrar = a;
        a = a->izq;
        delete borrar;
    }
    else
        removerMaxABBEstudiantes(a->der);
}

ABBEstudiantes filtrado(ABBEstudiantes a, uint cota)
{
    if (a == NULL)
        return NULL;
    ABBEstudiantes res_izq = filtrado(a->izq, cota);
    ABBEstudiantes res_der = filtrado(a->der, cota);
    if (a->info.nota > cota)
    {
        ABBEstudiantes res = new nodoABBEstudiantes;
        res->info = a->info;
        res->izq = res_izq;
        res->der = res_der;
        return res;
    }
    if (res_izq == NULL)
        return res_der;
    EstInfo mayor = maxABBEstudiantes(res_izq);
    removerMaxABBEstudiantes(res_izq);
    ABBEstudiantes res = new nodoABBEstudiantes;
    res->info = mayor;
    res->izq = res_izq;
    res->der = res_der;
    return res;
}

/*------EJERCICIO 5 - ÁRBOLES GENERALES------*/

struct nodoAG
{
    int elem;
    nodoAG *pH;
    nodoAG *sH;
};
typedef nodoAG *AG;

// (a) arbolHoja: Dado un entero x retorna un árbol que sólo contiene a x (como una hoja).

AG arbolHoja(int x)
{
    AG a = new nodoAG;
    a->elem = x;
    a->sH = a->pH = NULL;
    return a;
}

// (b) esArbolHoja: Dado un árbol, retorna true si y solo si el árbol es un árbol hoja (tiene un solo elemento).

// pre-condición: a no es vacío
bool esArbolHoja(AG a)
{
    return a->pH == NULL;
}

// (c) pertenece: Dados un árbol y un entero x, retorna true si y solo si x pertenece al árbol.

// pertenece: Dados un árbol y un entero x, retorna true si y solo si x pertenece al árbol.
bool pertenece(AG a, int x)
{
    if (a == NULL)
        return false;
    if (a->elem == x)
        return true;
    return pertenece(a->sH, x) || pertenece(a->pH, x);
}

// (d) insertar: Dados un árbol y dos enteros h y p, inserta a h como el primer hijo de p en el árbol (hijo más a la izquierda) si p pertenece al árbol y h no pertenece al árbol. En caso contrario la operación no tiene efecto.

// pre-condición: a no es vacío
void insertar(int p, int h, AG a)
{
    if (a->elem != h)
    {
        if (a->elem == p)
        {
            AG nuevo = new nodoAG;
            nuevo->elem = h;
            nuevo->pH = NULL;
            nuevo->sH = a->pH;
            a->pH = nuevo;
        }
        else
        {
            if (a->pH != NULL)
                insertar(p, h, a->pH);
            if (a->sH != NULL)
                insertar(p, h, a->sH);
        }
    }
}

// (e) borrar: Dados un árbol y un entero x, elimina a x del árbol si es una hoja del árbol y no es la raíz del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se debe liberar la memoria asignada a él.

void borrar(AG a, int x)
{
    if (a->elem == x)
        return; // para evitar recorridas innecesarias si la raiz tiene a x
    if (a->pH != NULL)
    {
        if (a->pH->elem == x)
        {
            if (a->pH->pH == NULL)
            {
                // es hoja, hay que eliminar
                AG borrar = a->pH;
                a->pH = borrar->sH;
                delete borrar;
            }
            return; // ya lo encontré, no puede estar repetido
        }
        else
            borrar(a->pH, x);
    }
    if (a->sH != NULL)
    {
        if (a->sH->elem == x)
        {
            if (a->sH->pH == NULL)
            {
                // es hoja, hay que eliminar
                AG borrar = a->sH;
                a->sH = borrar->sH;
                delete borrar;
            }
            return; // ya lo encontré, no puede estar repetido
        }
        else
            borrar(a->sH, x);
    }
}

// (f) borrarSub: Dados un árbol y un entero x, elimina a x del árbol, si pertenece al árbol y no es la raíz del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se deberá liberar la memoria asignada a los elementos que están en el subárbol dependiente de éste.

// Procedimiento auxiliar que borra todo para abajo y para la derecha
void borrarTodo(AG &a)
{
    if (a != NULL)
    {
        borrarTodo(a->sH);
        borrarTodo(a->pH);
        delete a;
        a = NULL;
    }
}

void borrarSub(AG &a, int x)
{
    if (a->elem == x)
        return; // para evitar recorridas innecesarias si la raiz tiene a x
    if (a->pH != NULL)
    {
        if (a->pH->elem == x)
        {
            borrarTodo(a->pH->pH); // borra todos los descendientes del nodo a borrar
            AG borrar = a->pH;     // luego voy a borrar el nodo en cuestión
            a->pH = borrar->sH;
            delete borrar;
            return; // ya lo encontré, no puede estar repetido
        }
        else
            borrarSub(a->pH, x);
    }
    if (a->sH != NULL)
    {
        if (a->sH->elem == x)
        {
            borrarTodo(a->sH->pH); // borra todos los descendientes del nodo a borrar
            AG borrar = a->sH;     // luego voy a borrar el nodo en cuestión
            a->sH = borrar->sH;
            delete borrar;
            return; // ya lo encontré, no puede estar repetido
        }
        else
            borrarSub(a->sH, x);
    }
}

/*------EJERCICIO 6 - ÁRBOLES GENERALES------*/

/*Defina una función recursiva copiaParcial que dados un árbol g de tipo AG y un entero positivo k, retorne
una copia de g, sin compartir memoria con éste, con todos los nodos que están en un nivel menor o igual a
k. En un árbol no vacío la raíz está en el nivel 1. Si g es vacío o k es cero, el resultado debe ser el árbol vacío.
Asuma que g->sH es NULL. No use operaciones auxiliares propias en la implementación de copiaParcial*/

AG copiaParcial(AG g, uint k) {}

/*------EJERCICIO 7 - ÁRBOLES GENERALES------*/

/*Defina una función recursiva esPrefijo que dada una lista de enteros y un árbol general de enteros, retorne
TRUE si y sólo si la lista es un prefijo de algún camino del árbol general, comenzando desde la raíz. Se dice
que la secuencia x es prefijo de la secuencia z si z es xy, esto es, la concatenación de x e y. Cualquiera
de las secuencias x, y, z pueden ser vacías. En particular si x es vacía es prefijo de cualquier secuencia, y
toda secuencia es prefijo de sí misma. No se deben usar funciones o procedimientos auxiliares en este
ejercicio. Utilice la definición de lista presentada en el ejercicio 2.*/

/*------EJERCICIO 8 - ÁRBOLES GENERALES------*/

/*Implemente una función que retorne la amplitud del nodo del árbol de mayor amplitud. La amplitud de un nodo se define como la cantidad de hijos (directos) que tiene. Si el árbol es vacío o la raíz no tiene hijos, la función debe retornar 0.*/

int mayorAmplitud(AG g) {}

/*------EJERCICIO 9 - ÁRBOLES GENERALES------*/

/*Considere un árbol general de enteros representado mediante un árbol binario de enteros con la semántica: puntero al primer hijo (pH), puntero al siguiente hermano (sH). Implemente la función AG padre(AG g, int x) que retorne un puntero al nodo padre en g del nodo que
tenga a x como dato. Asumimos que g no tiene elementos repetidos. Si x no está en g o si x es la raíz de
g, la función padre deberá retornar NULL. No se pueden definir operaciones auxiliares para implementar
padre.*/

AG padre(AG a, int x)
{
    if (a == NULL || a->elem == x)
        return NULL;
    AG hijo = a->pH;
    AG res = NULL;
    while (hijo != NULL && res == NULL)
    {
        if (hijo->elem == x)
            return a;
        else
            res = padre(hijo, x);
        hijo = hijo->sH;
    }
    return res;
}