#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>


typedef struct Nodo
{

    int elemento;
    struct Nodo *siguiente;


} Nodo;

Nodo * crearNodo(int e)
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->elemento=e;
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
    if(cima!=NULL)
        nuevo->siguiente=cima;
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

        aux1->siguiente=nuevo;

        nuevo->siguiente=aux;
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


Nodo *EliminarMedio(Nodo * cima,int mod){

    Nodo *aux;

    if(cima==NULL)
    {
        printf("La Lista esta vacia\n");
    }
    else
    {
        aux=cima;
        if(aux->elemento==mod){

            cima=cima->siguiente;
            free(aux);
        }else{
                while ( (aux->siguiente)->elemento != mod){
            aux=aux->siguiente;

           }

           free(aux->siguiente);
           aux->siguiente=(aux->siguiente)->siguiente;
           aux->siguiente=NULL;

        }




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



int main(){
FILE *Archivo;
    FILE * Archivo2;
    char aux;

    Nodo *Cima;
    Cima=NULL;

    int num,o=0,p=0,dato;

    char tam[50];
      char tam2[50];
    int num2;
    int i=0;
    int cont=0;
    char Ev[20];

    char *apC;


    Archivo= fopen("almacen1.txt","r");

    if(Archivo == NULL)
    {
        printf("El archivo no existe\n");

        exit(1);
    }

   while(!feof(Archivo))
    {

          fscanf(Archivo, "%s%d",&tam,&num);
        Archivo2= fopen("almacen2.txt","r");


             printf("%s\n",tam);
          printf("%d\n",num);


    }
fclose(Archivo);
 if(Archivo2 == NULL)
    {
        printf("El archivo no existe\n");

        exit(1);
    }

       while(!feof(Archivo2))
    {


           fscanf(Archivo2, "%s%d",&tam2,&num2);






                     printf("%s\n",tam2);
          printf("%d\n",num2);


    }
fclose(Archivo2);




return 0;
}
