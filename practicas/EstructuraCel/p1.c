#include <stdio.h>
#include <stdlib.h>


 struct coordenadas{

int C1[2];
int C2[2];

int A;
int b;
int h;

};




int main(){

struct coordenadas cord;


do {
        printf("x1 debe ser mayor a x2\n");
    printf(" Ingresa la primera coordenada x\n");
scanf("%d",&cord.C1[0]);
printf("x1= %d\n",cord.C1[0]);


printf(" Ingresa la segunda coordenada x\n");
scanf("%d",&cord.C2[0]);
printf("x2= %d\n",cord.C2[0]);
}while(cord.C1[0] < cord.C2[0]);


do{

printf(" Ingresa la primera coordenada y\n");
scanf("%d",&cord.C1[1]);
printf("y1= %d\n",cord.C1[1]);

printf(" Ingresa la segunda coordenada y\n");
scanf("%d",&cord.C2[1]);
printf("y2= %d \n",cord.C2[1]);

}while(cord.C1[1]<cord.C2[1]);


cord.b=cord.C2[0] - cord.C1[0];

printf("b= %d\n",cord.b);

cord.h= cord.C1[1] - cord.C2[1];

printf("h= %d\n",cord.h);


cord.A= cord.b*cord.h;
printf("Area= %d\n",cord.A);

return 0;
}
