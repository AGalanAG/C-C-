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


char infix_string[20], postfix_string[20];
int top;
int stack[20];

int pop();
int precedence(char symbol);
int isEmpty();
void infix_to_postfix();
int check_space(char symbol);
void push(long int symbol);


int comprobar(char *tam){
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

int comprobar2(char *tam){
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

int comprobar3(char *tam){
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


int main()
{

    FILE *Archivo;
    char aux;

    Nodo *Cima;
    Cima=NULL;

    int num,i=0,o=0,p=0,dato;

    char tam[50];
    int cont=0;

    char *apA;
    apA = tam;

    Archivo= fopen("p1.txt","r");

    if(Archivo == NULL)
    {
        printf("El archivo no existe\n");
        exit(1);
    }

    while(!feof(Archivo))
    {
        fgets(tam,50,Archivo);
        printf("%s\n",tam);
       int a=  comprobar(tam);
        int b=  comprobar2(tam);
         int c= comprobar3(tam);
          if(a==1 || b==1 || c==1){
            printf("La expresion no esta equilibrada %s",tam);

          }else{
          printf("La expresion esta equilibrada %s",tam);

          printf("\n porsfija:%s",postfix_string);

          }





    }


//verPila(Cima);

//printf("Archivo contiene: %s\n",tam);





}



void infix_to_postfix()
{
    unsigned int count, temp = 0;
    char next;
    char symbol;
    for(count = 0; count < strlen(infix_string); count++)
    {
        symbol = infix_string[count];  // Scanning the input expression
        if(!check_space(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '(')    // pop until '(' is encountered
                {
                    postfix_string[temp++] = next;
                }
                break;

            case '{':
                push(symbol);
                break;
            case '}':
                while((next = pop()) != '{')    // pop until '(' is encountered
                {
                    postfix_string[temp++] = next;
                }
                break;

            case '[':
                push(symbol);
                break;
            case ']':
                while((next = pop()) != '[')    // pop until '(' is encountered
                {
                    postfix_string[temp++] = next;
                }
                break;


            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))   // Check precedence and push the higher one
                    postfix_string[temp++] = pop();
                push(symbol);
                break;
            default:
                postfix_string[temp++] = symbol;
            }
        }
    }
    while(!isEmpty())
    {
        postfix_string[temp++] = pop();
    }
    postfix_string[temp] = '\0';
}

/* Function to check precedence of operators */
int precedence(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int check_space(char symbol)
{
    if(symbol == '\t' || symbol == ' ' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(long int symbol)
{
    if(top > 20)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = symbol;    // Push the symbol and make it as TOP
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return(stack[top--]);  // Pop the symbol and decrement TOP
}
