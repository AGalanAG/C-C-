#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <string.h>


typedef struct Nodo
{

    int edad;
    char nombre[20];
    struct Nodo *siguiente;

} Nodo;

Nodo * crearNodo(char *d,int e)
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    strcpy(nuevo ->nombre,d)  ;
    nuevo->edad=e;
    nuevo -> siguiente=NULL;
    return nuevo;
}


Nodo * insertar(Nodo *cima,char *d,int e)
{

    Nodo *nuevo;

    nuevo=crearNodo(d,e);
    Nodo * aux=cima;
    if(cima==NULL){
    return nuevo;

    }else{
      while(aux->siguiente!=NULL){

        aux=aux->siguiente;


      }
      aux->siguiente=nuevo;
      return cima;
    }



}


Nodo * Eliminar(Nodo *cima)
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

int verFila(Nodo *cima)
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

        printf("Nombre: %s \n",aux->nombre);
        printf("Edad: %d \n",aux->edad);
        aux=aux->siguiente;
    }
    return 0;

}

int medidaFila(Nodo* top)
{
    int cont;
    Nodo* aux;
    aux = top;
    cont = 0;
    if(aux == NULL)
        printf("La fila esta vacia  \n");
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


int main(){


  Nodo * FILA;
  FILA=NULL;

int num,op,edad;

char nombre[20];

    do

    {
        system("cls");
    	printf( "Selecciona una opcion \n" );
        printf( "1. Insertar \n" );
        printf( "2. Eliminar \n" );
        printf( "3. Consulta \n" );
        printf( "4. Tamano de la fila \n" );
        printf( "5. Salir \n" );
        scanf( "%d", &op );
        switch (op)

        {

            case 1:

                printf("Ingresa el nombre \n");
                fflush(stdin);
                gets(nombre);

                printf("Ingresa la edad \n");
                scanf("%d",&edad);
                FILA=insertar(FILA,nombre,edad);

                     system("PAUSE");

					break;



            case 2:

                FILA=Eliminar(FILA);

                 system("PAUSE");

                    break;



            case 3:

                verFila(FILA);

                 system("PAUSE");

                break;



            case 4:

                num = medidaFila(FILA);

                printf("El tamano de la fila es: %d \n", num);

                 system("PAUSE");

                break;

        }

    } while (op != 5);
      system("PAUSE");


}
