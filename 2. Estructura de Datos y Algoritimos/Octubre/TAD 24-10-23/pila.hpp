
/*------ESPECIFICACIONES DE PILAS------*/

typedef struct nodoPila * Pila;

typedef int T;

//----CONSTRUCTORAS----

// Crea una la pila vacía.
Pila crearPila ();

// Inserta i en la cima de p
void apilar (T i, Pila &p);

//----SELECTORAS----

// Devuelve la cima de p.
//Precondicion: no puede ser vacia la pila
T cima (Pila p);

// Remueve la cima de p.
//Precondicion: no puede ser vacia la pila
void desapilar (Pila &p);

//----PREDICADOS----

// Devuelve true si y sólo si p es vacia.
bool esVaciaPila (Pila p);

//----DESTRUCTORA----

// Libera toda la memoria ocupada por la pila.
void destruirPila (Pila &p);
