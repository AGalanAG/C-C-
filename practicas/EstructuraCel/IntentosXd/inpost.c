#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>


typedef struct Nodo
{


    char dato;
    struct Nodo *siguiente;

} Nodo;

Nodo * crearNodo(char d )
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo -> dato = d;
    nuevo -> siguiente=NULL;
    return nuevo;
}


Nodo * apilar(Nodo *cima,char d)
{

    Nodo *nuevo;

    nuevo=crearNodo(d);
    if(cima!=NULL)
        nuevo->siguiente=cima;
    return nuevo;

}


Nodo * desapilar(Nodo *cima)
{

    Nodo *aux;
    if(cima!=NULL)
    {
        aux=cima;
        cima=cima->siguiente;
        free(aux);
    }
    return cima;
}

int verPila(Nodo *cima)
{
    Nodo *aux;
    aux = cima;

    if(aux==NULL)
    {
        printf("La Fila esta vacia\n");
        return 1;
    }

    while(aux!=NULL)
    {

        printf(" %c ",aux->dato);
        aux=aux->siguiente;
    }
    return 0;

}



int main(){


}
