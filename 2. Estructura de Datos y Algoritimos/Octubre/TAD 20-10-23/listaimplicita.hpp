
/*------ESPECIFICACIONES DE LISTAS IMPLICITAS------*/

typedef struct nodoListaImplicita * Lista;
typedef int T;

struct nodo;

/*Crear la lista vacía;*/
Lista Listas_Vacia();

//-----------CONSTRUCTORAS
/*• Insertar un elemento luego de la posición actual. Si la lista es vacía, se agrega el elemento. 
Si la posición actual es la del último elemento, se agrega el nuevo elemento al final de la lista.
La posición actual pasa a ser en cualquier caso la del elemento insertado*/
void InsertarActual(Lista, T);

/*• Insertar un elemento antes de la posición actual. Si la lista es vacía, se agrega el elemento.
Si la posición actual es la del
primer elemento, se agrega el nuevo elemento al comienzo de
la lista. La posición actual pasa a ser en cualquier caso la del
elemento insertado*/
void InsertarAntes(Lista, T);

/*Fijar la posición actual al comienzo de la lista (en el primer elemento), si ésta no es vacía*/
// pre-condiccion: la lista no pued es er vacia
void posicionComienzo(Lista);

/*Avanzar la posición actual al próximo elemento de la lista, si
ésta no es vacía y la posición actual no corresponde a la del
último elemento*/
//pre-condicion: la lista no puede ser vacia, y posicion actual no es la ultima
void prosicionSigiente(Lista);

//--------PREDICADOS
/*Chequear si la lista es vacía*/
bool esVacia(Lista);

/*Chequear si la posición actual es la del último elemento (se
encuentra al final de la lista), si la lista no es vacía*/
//pre-condicon: lista no vacia
bool esUltimo(Lista);

/*Retornar el elemento en la posición actual, si la lista no es
vacía*/
//pre-condicon: lista no vacia
T darActual(Lista);

//----------DESTRUCTORA
/*Eliminar el elemento en la posición actual, si la lista es no
vacía. La posición actual pasa a ser la del elemento siguiente
en la lista. Si se elimina el último elemento, la posición actual
pasa a ser la del ultimo elemento de la lista resultante, si ésta
es no vacía.*/
void eliminarActual(Lista);
