#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <string.h>
#include <windows.h>


typedef struct Nodo
{

    int articulos;
    char id[10];
    struct Nodo *siguiente;

} Nodo;

Nodo * crearNodo(char *d,int e)
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    strcpy(nuevo ->id,d)  ;
    nuevo->articulos=e;
    nuevo -> siguiente=NULL;
    return nuevo;
}


Nodo * insertar(Nodo *cima,char *d,int e)
{

    Nodo *nuevo;

    nuevo=crearNodo(d,e);
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

        printf("ID: %s \n",aux->id);
        printf("Cantidad de articulos: %d \n",aux->articulos);
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



int main()
{
    Nodo * FILA;
    FILA=NULL;

    Nodo *CR1;
    CR1=NULL;

    Nodo *CR2;
    CR2=NULL;

    Nodo *CR3;
    CR3=NULL;

char ident[10];
int cant;

char ident2[10];
int cant2;
char ident3[10];
int cant3;
    int numero,op,edad;

    char pkid[10];
    char ncadena[5];

    // Declaracion de variables
    int numero2,cantidad,contador;
    int hora = time(NULL);

    // Semilla de rand();
    srand(hora);
    int i =1;
    printf("Formando personas... \n");
    for(contador = 0; contador<10; contador++)
    {
        Sleep(1000);

        numero = rand()%10+1;
        itoa(i,ncadena,10);

        strcpy(pkid,"PK");

        strcat(pkid,ncadena);
        i++;

        FILA=insertar(FILA,pkid,numero);
        strcpy(pkid,"");
        strcpy(pkid,"PK");

        numero2 = rand()%10+1;
        itoa(i,ncadena,10);

        strcat(pkid,ncadena);

        FILA=insertar(FILA,pkid,numero2);
        i++;

    }
printf("UNIFILA \n");
    verFila(FILA);
    int medida = medidaFila(FILA);

    while(medida>0)
    {
        op = rand()%3+1;
// printf("\n num:%d",op);
        switch (op)
        {
        case 1:

            strcpy(ident,FILA->id);

            cant=FILA->articulos;
            CR1=insertar(CR1,ident,cant);
            FILA=Eliminar(FILA);

            break;

        case 2:

            strcpy(ident2,FILA->id);

             cant2=FILA->articulos;
            CR2=insertar(CR2,ident2,cant2);
            FILA=Eliminar(FILA);
            break;
        case 3:

            strcpy(ident3,FILA->id);

            cant3=FILA->articulos;
            CR3=insertar(CR3,ident3,cant3);
            FILA=Eliminar(FILA);
            break;

        }



        medida--;
    }
     printf("\n\nCaja rapida 1: \n");
    verFila(CR1);
        printf("\n\nCaja rapida 2: \n");
    verFila(CR2);
         printf("\n\nCaja rapida 3:| \n");
    verFila(CR3);



    return 0;
}
