#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <string.h>
#include <windows.h>


typedef struct Nodo
{

    int elemento;
    struct Nodo *anterior;
    struct Nodo *siguiente;


} Nodo;

Nodo * crearNodo(int e)
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->elemento=e;
    nuevo->anterior=NULL;
    nuevo -> siguiente=NULL;
    return nuevo;
}
int medidaLista(Nodo* top)
{
    int cont;
    Nodo* aux;
    aux = top;
    cont = 0;
    if(aux == NULL)
        printf("La Lista esta vacia  \n");
    else
    {
        while(aux != NULL)
        {
            cont ++;
            aux = aux->siguiente;
        }
    }
    return cont;
}

Nodo * insertarInicio(Nodo *cima,int e)
{

    Nodo *nuevo;

    nuevo=crearNodo(e);
    if(cima!=NULL){
        nuevo->siguiente=cima;
        cima->anterior=nuevo;
    }

    return nuevo;

}


Nodo * insertarFinal(Nodo *cima, int e){
    Nodo *nuevo;

    nuevo=crearNodo(e);
    Nodo * aux=cima;
    if(cima==NULL)
    {
        return nuevo;

    }
    else
    {
        while(aux->siguiente!=NULL)
        {

            aux=aux->siguiente;


        }

        aux->siguiente=nuevo;
       nuevo->anterior=aux;
        return cima;
    }



}

Nodo * insertarMedio(Nodo * cima,int e,int pos)
{
    int i=1;

    Nodo *nuevo;
    Nodo *aux;
    Nodo *aux1;
    nuevo=crearNodo(e);

    if(cima==NULL)
    {
        return nuevo;
    }
    else
    {
        if(pos>(medidaLista(cima)+1)){
                printf("La posicion no esta diponible\n");
                system("PAUSE");
        return cima;

        }


        if(pos==(medidaLista(cima)+1)){

            return insertarFinal(cima,e);
        }
        if(pos==1){
            nuevo=crearNodo(e);
    if(cima!=NULL)
        nuevo->siguiente=cima;
    return nuevo;

        }
        aux=cima;

        while ( i != pos)
        {
            aux1=aux;
            aux=aux->siguiente;
        i++;
        }
        aux1=aux->anterior;

        aux1->siguiente=nuevo;
        nuevo->anterior=aux;

        nuevo->siguiente=aux;
        aux->anterior=nuevo;
    }
    return cima;


}

Nodo *Modificar(Nodo *cima,int e,int mod){


    Nodo *aux;

    if(cima==NULL)
    {
        printf("La Lista esta vacia\n");
    }
    else
    {
        aux=cima;

        while ( aux != NULL)
        {
           if (aux->elemento==mod){
            aux->elemento=e;

           }

            aux=aux->siguiente;

        }


    }
    return cima;


}

Nodo *EliminarInicio(Nodo *cima){

    Nodo *aux;
    if(cima!=NULL)
    {
        aux=cima;
        cima=cima->siguiente;
        free(aux);
    }
    return cima;

}

Nodo *EliminarFinal(Nodo *cima){

    Nodo * aux;
    Nodo *aux1;
    aux=cima;
    aux1=cima;
    if(cima==NULL)
    {
       printf("La lista esta vacia\n");

    }
    else
    {
        aux=aux->siguiente;
        while(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
            aux1=aux1->siguiente;
        }

        aux1->siguiente=NULL;

        return cima;
    }

}

Nodo *EliminarMedio(Nodo * cima,int pos){

      int i=1;

    Nodo *aux2;
    Nodo *aux;
    Nodo *aux1;

    if(cima==NULL)
    {
        return cima;
    }
    else
    {
        if(pos>(medidaLista(cima)+1)){
                printf("La posicion no esta diponible\n");
                system("PAUSE");
        return cima;

        }


        if(pos==(medidaLista(cima))){

            return EliminarFinal(cima);
        }
        if(pos==1){

    return EliminarInicio(cima);

        }
        aux=cima;

        while ( i != pos)
        {

            aux=aux->siguiente;
        i++;
        }
        aux1=aux->anterior;
        aux2=aux->siguiente;
        aux2->anterior=aux1;
        aux1->siguiente=aux2;
        free(aux);
    }






    return cima;



}

int verLista(Nodo *cima)
{
    Nodo *aux;
    aux = cima;

    if(aux==NULL)
    {
        printf("La Lista esta vacia\n");
        return 1;
    }

    while(aux!=NULL)
    {

        printf("Elemento: %d \n",aux->elemento);

        aux=aux->siguiente;
    }
    return 0;

}

Nodo * ordenar(Nodo *cima){
   Nodo *aux;
   Nodo *pivote=NULL;
   Nodo *actual=NULL;

   pivote=cima;

   aux=cima;

   if(cima!=NULL){

        int i=1;
   int tam;
   tam=medidaLista(cima);

   while(i<tam){
    aux=aux->siguiente;
    i++;
   }

int tem=0;


while(pivote!=aux){
actual=pivote->siguiente;


while(actual!=NULL){

        if(pivote->elemento > actual->elemento){
         tem=pivote->elemento;
         pivote->elemento=actual->elemento;
         actual->elemento=tem;

        }
        actual=actual->siguiente;

}


pivote=pivote->siguiente;
}



return cima;
   }else{

       printf("La Lista esta vacia\n");
        return cima;


   }


}



int main(){

    Nodo * Lista;
    Lista=NULL;

    FILE *archivo;
    archivo = fopen("practica.txt", "rt");
    int num;
    while (!feof(archivo)) {
        fscanf (archivo, "%d", &num);
        Lista= insertarFinal(Lista,num);

    }
    fclose(archivo);
   printf("Lista Desordenada:\n");
    verLista(Lista);


    Lista=ordenar(Lista);
  printf("Lista Ordenada:\n");
    verLista(Lista);








}
