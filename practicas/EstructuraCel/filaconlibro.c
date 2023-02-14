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

typedef struct Libro
{

    int edicion;
    char Titulo[20];
    struct Libro *siguiente;

} Libro;

Libro * crearLibro(char *d,int e)
{
    Libro *nuevo;

    nuevo = (Libro*) malloc(sizeof(Libro));

    strcpy(nuevo ->Titulo,d)  ;
    nuevo->edicion=e;
    nuevo -> siguiente=NULL;
    return nuevo;
}


Libro * insertarlib(Libro *cima,char *d,int e)
{

    Libro *nuevo;

    nuevo=crearLibro(d,e);
    Libro * aux=cima;
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


Libro * Eliminarlib(Libro *cima)
{

    Libro *aux;
    if(cima!=NULL)
    {
        aux=cima;
        cima=cima->siguiente;
        free(aux);
    }
    return cima;
}

int verFilalib(Libro *cima)
{
    Libro *aux;
    aux = cima;

    if(aux==NULL)
    {
        printf("La Fila esta vacia\n");
        return 1;
    }

    while(aux!=NULL)
    {

        printf("Titulo del libro: %s \n",aux->Titulo);
        printf("Edicion: %d \n",aux->edicion);
        aux=aux->siguiente;
    }
    return 0;

}




int main(){


  Nodo * FILA;
  FILA=NULL;

    Libro * FILAlib;
  FILAlib=NULL;

int num,op,edad;
int subop,edicion,numlib;

char nombre[20];
char titulo[20];

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

                  	printf( "Que quieres insertar? \n" );
        printf( "1. Alumno \n" );
        printf( "2. Libro \n" );
 scanf( "%d", &subop );


        if(subop==1){

                printf("Ingresa el nombre \n");
                fflush(stdin);
                gets(nombre);

                printf("Ingresa la edad \n");
                scanf("%d",&edad);
                FILA=insertar(FILA,nombre,edad);

                     system("PAUSE");


        }else{

                printf("Ingresa el titulo \n");
                fflush(stdin);
                gets(titulo);

                printf("Ingresa la edicion \n");
                scanf("%d",&edicion);
                FILAlib=insertarlib(FILAlib,titulo,edicion);

                     system("PAUSE");

        }

					break;



            case 2:

                                  	printf( "Que quieres eliminar? \n" );
        printf( "1. Alumno \n" );
        printf( "2. Libro \n" );
 scanf( "%d", &subop );


        if(subop==1){


                FILA=Eliminar(FILA);

                 system("PAUSE");
        }else{

                FILAlib=Eliminarlib(FILAlib);

                 system("PAUSE");

        }

                    break;



            case 3:
                                  	printf( "Que quieres ver? \n" );
        printf( "1. Alumno \n" );
        printf( "2. Libro \n" );
 scanf( "%d", &subop );


        if(subop==1){


                verFila(FILA);

                 system("PAUSE");

        }else{

                verFilalib(FILAlib);

                 system("PAUSE");

        }

                break;



            case 4:

                                  	printf( "Que quieres eliminar? \n" );
        printf( "1. Alumno \n" );
        printf( "2. Libro \n" );
 scanf( "%d", &subop );


        if(subop==1){


                num = medidaFila(FILA);

                printf("El tamano de la fila de alumnos es: %d \n", num);

                 system("PAUSE");

        }else{

                numlib = medidaFila(FILAlib);

                printf("El tamano de la fila de los libros es: %d \n", numlib);

                 system("PAUSE");

        }

                break;

        }

    } while (op != 5);
      system("PAUSE");


}
