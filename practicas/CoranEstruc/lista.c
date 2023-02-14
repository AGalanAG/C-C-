#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo{
    int dato;
    struct _Nodo *sig;
    struct _Nodo *ant;
}Nodo;

Nodo * crearNodo(int d){
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato=d;
    nuevo->sig=NULL;
    nuevo->ant=NULL;
    return nuevo;
}

int longitud(Nodo* top){
    Nodo *aux;
    aux = top;
    int longitud=0;
    while(aux != NULL){
        longitud++;
        aux = aux->sig;
    }
    return longitud;
}

Nodo * alta_Inicial(int dato, Nodo* top){
    Nodo* nuevo;
    nuevo = crearNodo(dato);
    if(top != NULL){
        nuevo -> sig = top;
        top -> ant = nuevo;
    }
    return nuevo;
}

Nodo * alta_Final(int dato, Nodo* top){
    Nodo *nuevo,*aux;
    aux = NULL;
    aux = NULL;
    nuevo = crearNodo(dato);
    if(top == NULL){
        return nuevo;
    }else{
        aux = top;
        while(aux -> sig!=NULL){
            aux = aux -> sig;
        }
        aux -> sig = nuevo;
        nuevo -> ant = aux;
    }
    return top;
}

Nodo * alta_Posicion(Nodo *top, int dato, int pos){
    Nodo *aux,*aux1,*nuevo;
    int i=0;
    if(top!=NULL){
        aux=top;
        nuevo=crearNodo(dato);
        for(i=1;i<pos-1;i++){
            aux=aux->sig;
        }
        aux1=aux->sig;
        aux->sig=nuevo;
        nuevo->sig=aux1;
        aux1->ant=nuevo;
        nuevo->ant= aux;
    }
    return top;
}

Nodo * Baja_Inicial(Nodo* top){
    Nodo* aux;
    if(top == NULL){
        printf("Tu Lista no tiene datos");
    }else if(top->sig == NULL){
        free(top);
        return NULL;
    }
    if(top != NULL){
        aux = top;
        top = aux -> sig;
        top -> ant = NULL;
        free(aux);
    }
    return top;
}

Nodo * baja_Final(Nodo *top){
    Nodo *aux,*aux1;
    aux=top;
    if(top!=NULL){
        if(aux->sig==NULL){
            free(aux);
            return NULL;
        }
        while(aux->sig->sig!=NULL){
            aux=aux->sig;
        }
        aux1=aux->sig;
        aux->sig=NULL;
        free(aux1);
    }
    return top;
}

Nodo * baja_Posicion(Nodo *top, int pos, int longitud){
    Nodo *aux, *borrar;
    int i;
    if (top == NULL){
        printf("No hay datos en tu fila, intenta de nuevo");
    }else{
        if(pos>longitud||pos<0){
            printf("Posicion inexistente");
            return aux;
        }
        aux = top;
        for (i = 0; i < pos ; ++i) {
            aux = aux -> sig;
        }
        borrar = aux->sig;
        aux->sig = borrar->sig;
        borrar -> sig -> ant = aux;
        free(borrar);
    }
    return top;
}

Nodo * modificar_Posicion(Nodo *top,int longitud , int pos, int dato){
    Nodo *aux;
    int i;
    if (top == NULL){
        puts("No hay datos en la Lista");
    }else{
        aux = top;
        while(pos < 0 || pos > longitud){
            printf("Ingresa una posicion existente");
            scanf("%d",pos);
        }
        for (i = 0; i < pos ; i++) {
            aux = aux -> sig;
        }
        aux -> dato = dato;
    }
    return top;
}

Nodo * cambioVal(Nodo *top,int dato_busqueda){
    Nodo *aux;
    aux = top;
    int dato_nuevo;
    while(aux != NULL){
        if(aux->dato==dato_busqueda){
            printf("Ingresa el nuevo valor.\n");
            scanf("%d",dato_nuevo);
            fflush(stdin);
            aux->dato=dato_nuevo;
        }
        aux = aux->sig;
        if(aux->sig==NULL);
            printf("No existe el valor.\n");
    }
    return top;
}

void verLista(Nodo *top){
    Nodo *aux;
    aux=NULL;
    aux= top;
    if(aux==NULL)
        printf("Lista vacia \n");
    else{
        int i=1;
        while(aux != NULL){
            printf("%d - %d\n", i,aux->dato);
            aux = aux->sig;
            i++;
        }
    }
}

int tope(Nodo * top){
    Nodo* aux;
    aux= top;
    if(aux==NULL) return '0';
    else return aux->dato;
}

void quick_sort (int * vector, int tamano) {
    int pared, actual, pivote, tmp;
    if (tamano < 2) return;
    pivote = vector[tamano - 1];
    pared  = actual = 0;
    while (actual<tamano) {
        if (vector[actual] <= pivote) {
            if (pared != actual) {
                tmp=vector[actual];
                vector[actual]=vector[pared];
                vector[pared]=tmp;
            }
            pared ++;
        }
        actual ++;
    }
    quick_sort(vector, pared - 1);
    quick_sort(vector + pared - 1, tamano - pared + 1);
}

int main (){
    int valorInt;
    FILE *archivo1;
    Nodo* lista = NULL;
    int todo [100];
    int i = 0, j = 0, a = 0, b = 0, aux = 0;

    archivo1 = fopen("numeros.txt", "rt");
    while (!feof(archivo1)) {
        fscanf (archivo1, "%d", &valorInt);
        lista = alta_Final(valorInt, lista);
        i++;
    }
    fclose(archivo1);
    //verLista(lista);
    for(j=0; j<i-1; j++){
        todo[j] = tope(lista);
        lista = Baja_Inicial(lista);
    }
    lista = Baja_Inicial(lista);
    quick_sort(todo, i);
    for(a=0; a<i-1; a++){
        lista = alta_Final(todo[a], lista);
    }
    printf("Lista ordenada de números por método Quicksort: \n\n");
    verLista(lista);
    return 0;
}
