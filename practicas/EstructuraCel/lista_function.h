


/***************************\

* lista_function.h *

\***************************/

void

inicialisacion (Lista * lista)

{

lista ->inicio = NULL;

lista ->fin = NULL;

lista ->tamano = 0;

}

/* insercion en une lista vacia */

int ins_en_lista_vacia (Lista * lista, char *dato){

Elemento *nuevo_Elemento;

if ((nuevo_Elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_Elemento->dato = (char *) malloc (50 * sizeof (char)))

== NULL)

return -1;

strcpy (nuevo_Elemento->dato, dato);

nuevo_Elemento->siguiente = NULL;

lista ->inicio = nuevo_Elemento;

lista ->fin = nuevo_Elemento;

lista ->tamano++;

return 0;

}

/* inserción al inicio de la lista */

int ins_inicio_lista (Lista * lista, char *dato){

Elemento *nuevo_Elemento;

if ((nuevo_Elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_Elemento->dato = (char *) malloc (50 * sizeof (char)))

== NULL)

return -1;

strcpy (nuevo_Elemento->dato, dato);

nuevo_Elemento->siguiente = lista->inicio;

lista ->inicio = nuevo_Elemento;

lista ->tamano++;

return 0;

}

/*insercion al final de la lista */

int ins_fin_lista(Lista *lista, Elemento *actual, char *dato){

Elemento *nuevo_Elemento;

if ((nuevo_Elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_Elemento->dato = (char *) malloc (50 * sizeof (char)))

== NULL)

return -1;

strcpy (nuevo_Elemento->dato, dato);

actual->siguiente = nuevo_Elemento;

nuevo_Elemento->siguiente = NULL;

lista ->fin = nuevo_Elemento;

lista ->tamano++;

return 0;

}

/* insercion en la posicion solicitada */

int ins_lista (Lista * lista, char *dato, int pos){

if (lista ->tamano < 2)

return -1;

if (pos < 1 || pos >= lista ->tamano)

return -1;

Elemento *actual;

Elemento *nuevo_Elemento;

int i;

if ((nuevo_Elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_Elemento->dato = (char *) malloc (50 * sizeof (char)))

== NULL)

return -1;

actual = lista ->inicio;

for (i = 1; i < pos; ++i)

actual = actual->siguiente;

if (actual->siguiente == NULL)

return -1;

strcpy (nuevo_Elemento->dato, dato);

nuevo_Elemento->siguiente = actual->siguiente;

actual->siguiente = nuevo_Elemento;

lista ->tamano++;

return 0;

}

/* supresión al inicio de la lista */

int sup_inicio (Lista * lista){

if (lista ->tamano == 0)

return -1;

Elemento *sup_Elemento;

sup_Elemento = lista ->inicio;

lista ->inicio = lista ->inicio->siguiente;

if (lista ->tamano == 1)

lista ->fin = NULL;

free (sup_Elemento->dato);

free (sup_Elemento);

lista ->tamano--;

return 0;

}

/* suprimir un Elemento después de la posición solicitada */

int sup_en_lista (Lista * lista, int pos){

if (lista ->tamano = lista ->tamano)

return -1;

int i;

Elemento *actual;

Elemento *sup_Elemento;

actual = lista ->inicio;

for (i = 1; i < pos; ++i)

actual = actual->siguiente;

sup_Elemento = actual->siguiente;

actual->siguiente = actual->siguiente->siguiente;

if(actual->siguiente == NULL)

lista ->fin = actual;

free (sup_Elemento->dato);

free (sup_Elemento);

lista ->tamano--;

return 0;

}

/* visualización de la Lista */

void muestra (Lista * lista){

Elemento *actual;

actual = lista ->inicio;

while (actual != NULL){

printf ("%p - %s\n", actual, actual->dato);

actual = actual->siguiente;

}

}

/* destruir la Lista */

void destruir (Lista * lista){

while (lista->tamano > 0)

sup_inicio (lista);

}

int menu (Lista *lista,int *k){

int eleccion;

printf("********** MENU **********\n");

if (lista->tamano == 0){

printf ("1. Adición del1er Elemento\n");

printf ("2. Quitar\n");

}else if(lista->tamano == 1 || *k == 1){

printf ("1. Adición al inicio de la lista\n");

printf ("2. Adición al final de la lista\n");

printf ("4. Supresión al inicio de la lista\n");

printf ("6. Destruir la lista\n");

printf ("7. Quitar\n");

}else {

printf ("1. Adición al inicio de la lista\n");

printf ("2. Adición al final de la lista\n");

printf ("3. Adición después de la posición indicada\n");

printf ("4. Supresión al inicio de la lista\n");

printf ("5. Supresión después de la posición indicada\n");

printf ("6. Destruir la lista\n");

printf ("7. Quitar\n");

}

printf ("\n\nElegir: ");

scanf ("%d", &eleccion);

getchar();

if(lista->tamano == 0 && eleccion == 2)

eleccion = 7;

return eleccion;

}

/* -------- FIN lista_function.h --------- */
