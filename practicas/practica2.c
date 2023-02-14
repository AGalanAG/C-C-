#include <stdlib.h>
#include <stdio.h>


void taman(char *apA);

int main()
{
	char apA[20];





   // Calcular el numero de caracteres de las cadenas

      printf("Escriba una cadena de caracteres \n");
      gets(apA);

     taman(apA);

}


void taman(char *apA){

     int num_chars,i=0;
          while(*apA != '\0'){
	i++;
    apA++;

	}

   printf("El numero de la cadena es %d",i);


}
