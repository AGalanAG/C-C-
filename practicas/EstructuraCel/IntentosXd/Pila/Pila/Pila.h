#ifndef PEPEPILA_H_INCLUDED
#define PEPEPILA_H_INCLUDED
#include <stdio.h>  //entrada y salida
#include <stdlib.h> //sustitucion del .conio y hacer operaciones con apuntadores

typedef struct _Nodo{   //se utiliza para crear un tipo de dato "typedef struct" palabra reservada
    int dato;
    struct _Nodo *sig;

}Nodo;


Nodo* crearNodo(int );
Nodo* apilar(Nodo* , int );
Nodo* desapilar(Nodo*);
void verPila(Nodo*);
int medidaPila(Nodo* top);

#endif // PEPEPILA_H_INCLUDED
