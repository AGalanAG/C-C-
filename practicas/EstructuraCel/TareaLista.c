#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <string.h>
#include <windows.h>


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






int main()
{
    Nodo * Lista;
    Lista=NULL;
    int elm,op,lug;
    int med;
    int mod,edicion,numlib;

    do
    {
        system("cls");
        printf( "Selecciona una opcion \n" );
        printf( "1. Insertar al inicio \n" );
        printf( "2. Insertar en una posicion \n" );
        printf( "3. Insertar al final \n" );
        printf( "4. Modificar \n" );
        printf( "5. Eliminar al inicio \n" );
        printf( "6. Eliminar en una posicion \n" );
        printf( "7. Eliminar al final \n" );
        printf( "8. Consulta \n" );
        printf( "9. Tamano de la Lista \n" );
        printf( "10. Salir \n" );
        scanf( "%d", &op );
        switch (op)
        {
        case 1:
            printf( "Ingresa el Elemento \n" );
            scanf( "%d", &elm );
            Lista=insertarInicio(Lista,elm);
            break;
        case 2:

            printf( "Ingresa el Elemento \n" );
            scanf( "%d", &elm );
            printf( "Ingresa la posicion \n" );
            scanf( "%d", &lug );
            if(Lista==NULL){
                printf("La lista se encuentra vacia... \n Se insertara en la primera posicion\n");
               system("PAUSE");
               Lista=insertarInicio(Lista,elm);
            }else{
            Lista=insertarMedio(Lista,elm,lug);

            }

            break;
        case 3:
            printf( "Ingresa el Elemento \n" );
            scanf( "%d", &elm );
            Lista=insertarFinal(Lista,elm);
            break;
        case 4:
            printf( "Ingresa el Elemento a modificar \n" );
            scanf( "%d", &mod );
            printf( "Ingresa  el nuevo elemento \n" );
            scanf( "%d", &elm );

            Lista=Modificar(Lista,elm,mod);


            break;
        case 5:
            Lista=EliminarInicio(Lista);
            printf("Se elimino el primer elemento\n");
            verLista(Lista);
            system("PAUSE");
            break;
        case 6:
             printf( "Ingresa el Elemento a modificar \n" );
            verLista(Lista);
            scanf( "%d", &mod );

            Lista=EliminarMedio(Lista,mod);
           // printf("Se elimino el elemento de la posicion:%d\n",mod);
            verLista(Lista);
            system("PAUSE");

            break;
        case 7:
            Lista=EliminarFinal(Lista);
            printf("Se elimino el ultimo elemento\n");
            verLista(Lista);
            system("PAUSE");
            break;

        case 8:

            verLista(Lista);
            system("PAUSE");
            break;
        case 9:
            med=medidaLista(Lista);
            printf("\nTamano: %d\n",med);
            system("PAUSE");

            break;


        }



    }
    while(op!= 10);
    system("PAUSE");




        return 0;
}
