#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * Archivo;
	
		Archivo= fopen("p2.txt","rb");
		   
	char Ev[50];
	int cont=0;
		char cadA[10]={"A*B"};

//char cadB[10]={"A=4"};

	 char *apA;
	     apA = cadA;
char aux;
int i=0;
	 char *apB;
	     apB = Ev;
	

	if(Archivo == NULL){
		printf("El archivo no existe\n");
		exit(1);
	}
	
	while(!feof(Archivo)){
		fgets(Ev,50,Archivo);
		printf("%s\n",Ev);
	//	printf("%s\n",Ev+2);
		printf("%s\n",cadA);
while (*apA !='\0'){
	//aux=*apA;
//printf("%s\n",cadA);
if(*apA == Ev[0]){
*apA=Ev[2];
}
    apA++;
	i++;
}
while(i!=0){
	apA--;
	i--;	
}
printf("\n%s\n",apA);
printf("\n%s\n",cadA);
		}
	
//printf("%s \n",Ev);



	
		
	
}
