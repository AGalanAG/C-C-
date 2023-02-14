#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{


    int dato;
    struct Nodo *siguiente;

} Nodo;

Nodo * crearNodo(int d )
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo -> dato = d;
    nuevo -> siguiente=NULL;
    return nuevo;
}


Nodo * apilar(Nodo *cima,int d)
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

void verPila(Nodo *cima)
{
    Nodo *aux;
    aux = cima;

    while(aux!=NULL)
    {

        printf("Valor: %d\t \n",aux->dato);
        aux=aux->siguiente;
    }


}

int medidaPila(Nodo* top)
{
    int cont;
    Nodo* aux;
    aux = top;
    cont = 0;
    if(aux == NULL)
        printf("La pila esta vacia  \n");
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

int verTop(Nodo *cima)
{
    Nodo *aux;
    aux = cima;

    if(aux!=NULL)
    {

        printf("Valor: %d\t \n",aux->dato);
        return aux->dato;
    }


}




int main(int argc, char *argv[])
{

    Nodo *Cima;
    Cima=NULL;

    int num,op,dato;
    int to;



    do
    {
        system("cls");
        printf( "Selecciona una opcion \n" );
        printf( "1. Insertar \n" );
        printf( "2. Eliminar \n" );
        printf( "3. Consulta \n" );
        printf( "4. Tamano de pila \n" );
        printf( "5. Ver top de pila \n" );
        printf( "6. Salir \n" );

        scanf( "%d", &op );



        switch (op)
        {
        case 1:
            printf("Ingresa el dato \n");
            scanf( "%d", &dato );
            Cima=apilar(Cima,dato);
            system("PAUSE");
            break;

        case 2:
            Cima=desapilar(Cima);
            system("PAUSE");
            break;

        case 3:
            verPila(Cima);
            system("PAUSE");
            break;

        case 4:
            num = medidaPila(Cima);
            printf("El tamano es: %d \n", num);
            system("PAUSE");
            break;
              case 5:

            to=verTop(Cima);
            printf("\n\n%d\n",to);
            system("PAUSE");
            break;
        }



    }
    while (op != 6);




    system("PAUSE");
    return 0;
}
//Realizar la funcion de conteo de mueros de elementos que tiene y realizar un do while con opciones para hacer del usuariop
