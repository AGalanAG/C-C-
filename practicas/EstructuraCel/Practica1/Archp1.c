#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>


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
        printf("La Fila esta vacia\n");
        return 1;
    }

    while(aux!=NULL)
    {

        printf(" %c ",aux->dato);
        aux=aux->siguiente;
    }
    return 0;

}




int comprobar(char *tam)
{
    Nodo *Cima2;
    Cima2=NULL;

    int i=strlen(tam);
    int j=0;
    int eq=0;
    while(j != i)
    {
        if(tam[j]=='(')
        {
            Cima2=apilar(Cima2,tam[j]);
        }
        else
        {
            if(tam[j]==')')
            {
                if(Cima2==NULL)
                {
                    eq=1;
                }
                else
                {
                    Cima2=desapilar(Cima2);
                }
            }
            else
            {

            }

        }


        j++;

    }

    if(eq!=0 || Cima2!=NULL )
    {
        //printf("La expresion no es equilibrada %s\n",tam);
        //  verPila(Cima2);
        return 1;
    }
    else
    {
        //printf("La expresion es equilibrada %s\n",tam);
        //verPila(Cima2);
        return 0;
    }

}

int comprobar2(char *tam)
{
    Nodo *Cima2;
    Cima2=NULL;

    int i=strlen(tam);
    int j=0;
    int eq=0;
    while(j != i)
    {
        if(tam[j]=='[')
        {
            Cima2=apilar(Cima2,tam[j]);
        }
        else
        {
            if(tam[j]==']')
            {
                if(Cima2==NULL)
                {
                    eq=1;
                }
                else
                {
                    Cima2=desapilar(Cima2);
                }
            }
            else
            {

            }

        }


        j++;

    }

    if(eq!=0 || Cima2!=NULL )
    {
        // printf("La expresion no es equilibrada %s\n",tam);
        //  verPila(Cima2);
        return 1;
    }
    else
    {
        //printf("La expresion es equilibrada %s\n",tam);
        //verPila(Cima2);
        return 0;
    }

}

int comprobar3(char *tam)
{
    Nodo *Cima2;
    Cima2=NULL;

    int i=strlen(tam);
    int j=0;
    int eq=0;
    while(j != i)
    {
        if(tam[j]=='{')
        {
            Cima2=apilar(Cima2,tam[j]);
        }
        else
        {
            if(tam[j]=='}')
            {
                if(Cima2==NULL)
                {
                    eq=1;
                }
                else
                {
                    Cima2=desapilar(Cima2);
                }
            }
            else
            {

            }

        }


        j++;

    }

    if(eq!=0 || Cima2!=NULL )
    {

        //printf("La expresion no es equilibrada %s\n",tam);
        //  verPila(Cima2);
        return 1;
    }
    else
    {
        //printf("La expresion es equilibrada %s\n",tam);
        //verPila(Cima2);
        return 0;
    }

}


char verTop(Nodo *cima)
{
    Nodo *aux;
    aux = cima;

    if(aux!=NULL)
    {

        // printf("Valor: %c\t \n",aux->dato);
        return aux->dato;
    }


}


int EsOperador(char simbolo)
{

    if((simbolo=='+') || (simbolo=='-') || (simbolo=='*') || (simbolo=='/') || (simbolo=='^') || (simbolo=='%'))
        return 1;

    return 0;
}

int EsOperando(char simbolo)
{


    if(((simbolo>=65)&&(simbolo<=90)) || ((simbolo>=97) && (simbolo<=122)))
        return 1;

    return 0;

}


int Prio(char operador)
{

    if(operador=='^')
        return 3;

    if((operador=='*') || (operador=='/') || (operador=='%'))
        return 2;

    if((operador=='+') || (operador=='-'))
        return 1;

    if(operador=='(')
        return 0;


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


typedef struct Nodoint
{
    float dato2;
    struct Nodoint *siguiente2;

} Nodoint;

Nodoint * crearNodoint(float d )
{
    Nodoint *nuevo2;

    nuevo2 = (Nodoint*) malloc(sizeof(Nodoint));

    nuevo2 -> dato2 = d;
    nuevo2 -> siguiente2=NULL;
    return nuevo2;
}


Nodoint * apilar2(Nodoint *cima2,float d)
{

    Nodoint *nuevo2;

    nuevo2=crearNodoint(d);
    if(cima2!=NULL)
        nuevo2->siguiente2=cima2;
    return nuevo2;

}


Nodoint * desapilar2(Nodoint *cima2)
{

    Nodoint *aux2;
    if(cima2!=NULL)
    {
        aux2=cima2;
        cima2=cima2->siguiente2;
        free(aux2);
    }
    return cima2;
}

int verPila2(Nodoint *cima2)
{
    Nodoint *aux2;
    aux2 = cima2;

    if(aux2==NULL)
    {
        printf("La Fila esta vacia\n");
        return 1;
    }

    while(aux2!=NULL)
    {

        printf(" %d ",aux2->dato2);
        aux2=aux2->siguiente2;
    }
    return 0;

}

float verTop2(Nodoint *cima2)
{
    Nodoint *aux2;
    aux2 = cima2;

    if(aux2!=NULL)
    {

      //  printf("Valor: %f\t \n",aux2->dato2);
        return aux2->dato2;
    }


}


int main()
{

    FILE *Archivo;
    FILE * Archivo3;
    char aux;

    Nodo *Cima;
    Cima=NULL;

    int num,o=0,p=0,dato;

    char tam[50];
    int cont=0;

    char *apA;
    apA = tam;

    Archivo= fopen("p4.txt","r");

    if(Archivo == NULL)
    {
        printf("El archivo no existe\n");
        exit(1);
    }

    while(!feof(Archivo))
    {
        fgets(tam,50,Archivo);
        printf("\n%s\n",tam);
        int a=  comprobar(tam);
        int b=  comprobar2(tam);
        int c= comprobar3(tam);
        if(a==1 || b==1 || c==1)
        {

        Archivo3= fopen("p3.txt","a");
       fprintf (Archivo3, "ERROR \n La expresion no esta equilibrada %s \n Por favor modifique el archivo\n\n",tam);
       fclose(Archivo3);

            printf("La expresion no esta equilibrada %s \n Por favor modifique el archivo",tam);
           // exit(0);
        }
        else
        {
            printf("La expresion esta equilibrada %s",tam);





  Nodo *Pila;
        Pila=NULL;
        Nodo *Postfija;
        Postfija=NULL;
        //char expresion[50];
        int ta=0;
        int i=0;


//   printf("Escribir la expresion:");
        // scanf("%s",expresion);
        strcat(tam,")");
        ta=strlen(tam);


        Pila=apilar(Pila,'(');

//    printf("\n%s\n",tam);

        while(ta>i)
        {
            if(tam[i]=='(')
            {
                Pila=apilar(Pila,tam[i]);
            }
            else
            {
                if(EsOperando(tam[i])==1)
                {
                    Postfija=apilar(Postfija,tam[i]);



                }
                else
                {
                    if(EsOperador(tam[i])==1)
                    {
                        if(Prio(tam[i])>=Prio(verTop(Pila)))
                        {
                            Pila=apilar(Pila,tam[i]);
                        }
                        else
                        {
                            Postfija=apilar(Postfija,verTop(Pila));

                            Pila=desapilar(Pila);
                            Pila=apilar(Pila,tam[i]);
                        }

                    }
                    else
                    {

                        if(tam[i]==')')
                        {
                            while(verTop(Pila)!='(')
                            {
                                Postfija=apilar(Postfija,verTop(Pila));

                                Pila=desapilar(Pila);
                            }
                            Pila=desapilar(Pila);
                        }
                        else
                        {
                            //printf("\n%c",tam[i]);
                        }
                    }

                }
            }

            //verPila(Pila);
            //printf("\n");

            i++;

        }


        int medida=medidaPila(Postfija);
        char post[50];
        int valor=medida;
        char t;
        int j=0;
        while(j<valor)
        {
            t=verTop(Postfija);
            fflush(stdin);
            post[medida-1]=t;
            Postfija=desapilar(Postfija);
            medida--;
            j++;
        }
         post[valor]='\0';

        printf("\nPostfija: %s\n\n",post);

        Archivo3= fopen("p3.txt","a");
        fprintf (Archivo3, "Expresion Infija: %s Posfija:%s \n\n ",tam, post);


        FILE * Archivo2;

        Archivo2= fopen("practica1_ev.txt","rb");

        char Ev[50];
        int cont=0;
        char cadA[50];

//char cadB[10]={"A=4"};
        strcpy(cadA,post);
        char *apC;
        apC = cadA;
        char aux;

        char *apB;
        apB = Ev;


        if(Archivo2 == NULL)
        {
            printf("El archivo no existe\n");
            exit(1);
        }

        while(!feof(Archivo2))
        {
            fgets(Ev,50,Archivo2);
            //printf("%s\n",Ev);
            //	printf("%s\n",Ev+2);
            //printf("%s\n",cadA);
            while (*apC !='\0')
            {
                //aux=*apC;
//printf("%s\n",cadA);
                if(*apC == Ev[0])
                {
                    *apC=Ev[2];
                }
                apC++;
                o++;
            }
            while(o!=0)
            {
                apC--;
                o--;
            }

        }
        fclose(Archivo2);

        printf("\nEvaluacion de valores:\n");
        printf("\n%s\n",cadA);




        Nodoint *pilaR;
        pilaR=NULL;

        char exp[50];
        strcpy(exp,cadA);
        int tap=strlen(exp);
        int p=0;
        char valorf;
        
   int nvalor;
	
	float vflotante ;
        
        fflush(stdin);
        while(tap>0)
        {
            if((exp[p]>=48) && (exp[p]<=57))
            {
                fflush(stdin);
                valorf=exp[p];
                nvalor= valorf-'0';
                vflotante=nvalor;
                fflush(stdin);
                pilaR=apilar2(pilaR,vflotante);
                // printf("%d\n",verTop(pilaR));

            }
            else
            {
                //printf("1");
                fflush(stdin);
                float val1 =verTop2(pilaR) ;
                pilaR=desapilar2(pilaR);
                fflush(stdin);
                //printf("2");
                float val2 = verTop2(pilaR);
                pilaR=desapilar2(pilaR);
                switch (exp[p])
                {
                case '+':
                    pilaR=apilar2(pilaR, val2 + val1);
                    break;
                case '-':
                    pilaR=apilar2(pilaR, val2 - val1);
                    break;
                case '*':
                    pilaR=apilar2(pilaR, val2 * val1);
                    break;
                case '/':
                    pilaR=apilar2(pilaR, val2/val1);
                    break;
                case '%':
                   pilaR=apilar2(pilaR, (int)val2%(int)val1);
                 break;
                case '^':
                    pilaR=apilar2(pilaR, pow((double)val2,(double)val1));
                    break;
                }

            }
            p++;
            tap--;
            //
        }
        float res=verTop2(pilaR);
         //printf("%d\n",res);

        fflush(stdin);

        char total=res+'0';
        char msn[50]="Resultado de la evaluacion:";
        msn[27]=total;
        fflush(stdin);

        printf("%s\t  verificacion:",msn);
       printf("%f\n",res);

        fprintf (Archivo3, "Valores sustituidos: %s Evaluacion: %f\n\n\n",cadA, res);


        }


      



    }

    fclose(Archivo);
    fclose(Archivo3);



}

