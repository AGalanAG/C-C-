#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo
{


    char dato;
    struct Nodo *siguiente;

} Nodo;

Nodo * crearNodo(char d )
{
    Nodo *nuevo;

    nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo -> dato = d;
    nuevo -> siguiente=NULL;
    return nuevo;
}


Nodo * apilar(Nodo *cima,char d)
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
int verPila(Nodo *cima)
{
    Nodo *aux;
    aux = cima;

    if(aux==NULL)
    {
        printf("Fila vacia\n");
        return 1;
    }
    printf("Fila vacia\n");


    while(aux!=NULL)
    {

        printf("Valor: %c\t \n",aux->dato);
        aux=aux->siguiente;
        return 0;
    }


}

void comprobar(char *ecuacion){
Nodo *Cima;
    Cima=NULL;



    int i=strlen(ecuacion);
    int j=0;
    int eq=0;
    while(j != i)
    {
        if(ecuacion[j]=='('){
            Cima=apilar(Cima,ecuacion[j]);
           }else{
           if(ecuacion[j]==')'){
            if(Cima==NULL){
                eq=1;
            }else{
                Cima=desapilar(Cima);
            }
           }else{

           }

           }


        j++;

        }

        if(eq!=0 || Cima!=NULL )
        {
            printf("La expresion no es equilibrada %s\n",ecuacion);
            verPila(Cima);
        }
        else
        {
            printf("La expresion es equilibrada %s\n",ecuacion);
            verPila(Cima);
        }

}




int main()
{
       char ecuacion[50];

    printf("Ingresa la ecuacion: \n");
    scanf("%s",ecuacion);

       comprobar(ecuacion);



        system("PAUSE");
        return 0;


    }
