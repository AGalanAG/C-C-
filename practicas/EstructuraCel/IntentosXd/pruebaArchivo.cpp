#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>



int main(){
	
char cadA[10]={"A*B"};

char cadB[10]={"A=4"};

	 char *apA;
	     apA = cadA;
char aux;
int i=0;

printf("%s\n",cadA);
while (*apA !='\0'){
	
	//aux=*apA;
//printf("%s\n",cadA);
if(*apA == cadB[0])
	*apA=cadB[2];
	apA++;
	i++;
}
printf("\n%s",cadA);
	
	

	
	
	
}
