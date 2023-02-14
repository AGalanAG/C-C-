#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo{


        int dato;
        struct Nodo *siguiente;

        }Nodo;

        Nodo * crearNodo(char d ){
            Nodo *nuevo;

        nuevo = (Nodo*) malloc(sizeof(Nodo));

        nuevo -> dato = d;
        nuevo -> siguiente=NULL;
        return nuevo;
        }


        Nodo * apilar(Nodo *cima,char d){

             Nodo *nuevo;

             nuevo=crearNodo(d);
             if(cima!=NULL)
             nuevo->siguiente=cima;
             return nuevo;

             }


             Nodo * desapilar(Nodo *cima){

                  Nodo *aux;
                  if(cima!=NULL){
                                 aux=cima;
                                 cima=cima->siguiente;
                                 free(aux);
                                 }
                                 return cima;
                  }

                  void verPila(Nodo *cima){
                       Nodo *aux;
                       aux = cima;

                       while(aux!=NULL){

                                        printf(" %c ",aux->dato);
                                        aux=aux->siguiente;
                                        }


                       }
                    



int main(){
	
	FILE *Archivo;
char aux;
	
	  Nodo *Cima;
  Cima=NULL;

int num,i=0,dato;
  
	char tam[50];
	int cont=0;
	
	 char *apA;
	     apA = tam;
	 
	Archivo= fopen("practica1.txt","r");
	
	if(Archivo == NULL){
		printf("El archivo no existe\n");
		exit(1);
	}
	
	while(!feof(Archivo)){
		fgets(tam,50,Archivo);
		cont++;	
		}
	
	   /* while(*apA != '\0'){
 Cima=apilar(Cima,tam[i]);
 i++;
    apA++;
	} 
	   verPila(Cima);*/
	   int abierto=0;
	   int cerrado=0;
printf("Archivo contiene: %s\n",tam);

while(*apA != '\0'){
aux=*apA;
//printf("%c",aux);
if(aux == '('){
	abierto++;
	apA++;
}else{
	apA++;
}
	i++;		
}

while(i!=0){
	aux=*apA;
if(aux==')')
	cerrado++;
	apA--;
	i--;	
}

	if(abierto==cerrado){
		printf("\nExpresion equilibrada: %d , %d",abierto,cerrado);
	}else{
		printf("\nExpresion no equilibrada: %d , %d",abierto,cerrado);
	}
	
	
	
}
