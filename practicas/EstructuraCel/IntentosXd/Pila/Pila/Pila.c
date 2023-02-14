#include "Pila.h"

Nodo* crearNodo(int d){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato=d;
    nuevo->sig=NULL;
    return nuevo;

}

Nodo* apilar(Nodo* top, int d){
    Nodo *nuevo;
    nuevo = crearNodo(d);
    if(top!=NULL){
    nuevo -> sig = top;

    }    return nuevo;
    }

Nodo* desapilar(Nodo* top){
    Nodo* aux;
    aux = top;
    if(aux != NULL){
        top=top->sig;
        free(aux); //free libera la memoria
    }
    return top;
}

void verPila(Nodo* top){
Nodo* aux;
aux= top;
if(aux==NULL)
printf("Pila vacia \n");
else{
    while(aux != NULL){
        printf("Valor %d  \n", aux->dato);
        aux = aux->sig;
    }
}
}

int medidaPila(Nodo* top){
    int cont;
    Nodo* aux;
    aux = top;
    cont = 0;
    if(aux == NULL)
    printf("La pila esta vacia  \n");
    else{
        while(aux != NULL){
            cont ++;
            aux = aux->sig;
        }
    }
    return cont;
}
