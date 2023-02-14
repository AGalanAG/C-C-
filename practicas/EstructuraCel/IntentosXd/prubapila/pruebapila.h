typedef struct _Nodo{  
    int dato;
    struct _Nodo *sig;

}Nodo;


Nodo* crearNodo(int );
Nodo* apilar(Nodo* , int );
Nodo* desapilar(Nodo*);
void verPila(Nodo*);
int medidaPila(Nodo* top);
