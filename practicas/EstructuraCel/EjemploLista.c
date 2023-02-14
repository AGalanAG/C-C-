
/**********************\

* lista.c *

\**********************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <string.h>
#include <windows.h>


#include "lista.h"

#include "lista_function.h"

int main (void)

{

char eleccion;

char *nom;

Lista *lista;

Elemento *actual;

if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)

return -1;

if ((nom = (char *) malloc (50)) == NULL)

return -1;

actual = NULL;

eleccion = 'o';

inicialisacion (lista);

int pos, k;

while (eleccion!= 7){

eleccion = menu (lista, &k);

switch (eleccion){

case 1:

printf ("Ingrese un Elemento : ");

scanf ("%s", nom);

getchar ();

if (lista->tamano == 0)

ins_en_lista_vacia (lista, nom);

else

ins_inicio_lista (lista, nom);

printf ("%d Elementos:ini=%s,fin=%s\n", lista->tamano,

lista->inicio->dato, lista->fin->dato);

muestra (lista);

break;

case 2:

printf ("Ingrese un Elemento: ");

scanf ("%s", nom);

getchar ();

ins_fin_lista (lista, lista->fin, nom);

printf ("%d Elementos:ini=%s,fin=%s\n", lista->tamano,

lista->inicio->dato, lista->fin->dato);

muestra (lista);

break;

case 3:

printf ("Ingrese un Elemento: ");

scanf ("%s", nom);

getchar ();

do{

printf ("Ingrese la posicion: ");

scanf ("%d", &pos);

}

while (pos < 1 || pos > lista->tamano);

getchar ();

if (lista->tamano == 1 || pos == lista->tamano){

k = 1;

printf("-----------------------------------------------\n");

printf("/!\\Fracaso la insercion.Utilice el menu {1|2} /!\\\n");

printf("-----------------------------------------------\n");

break;

}

ins_lista (lista, nom, pos);

printf ("%d Elementos:ini=%s,fin=%s\n", lista->tamano,

lista->inicio->dato, lista->fin->dato);

muestra (lista);

break;

case 4:

sup_inicio (lista);

if (lista->tamano != 0)

printf ("%d Elementos:ini=%s,fin=%s\n", lista->tamano,

lista->inicio->dato, lista->fin->dato);

else

printf ("lista vacia\n");

muestra (lista);

break;

case 5:

do{

printf ("Ingrese la posicion : ");

scanf ("%d", &pos);

}

while (pos < 1 || pos > lista->tamano);

getchar ();

sup_en_lista (lista, pos);

if (lista->tamano != 0)

printf ("%d Elementos:ini=%s,fin=%s\n", lista->tamano,

lista->inicio->dato, lista->fin->dato);

else

printf ("lista vacia\n");

muestra (lista);

break;

case 6:

destruir (lista);

printf ("la lista ha sido destruida: %d Elementos\n", lista->tamano);

break;

}

}

return 0;

}
