#include<stdio.h>
#include<stdlib.h>
struct nodo{
char dato;
nodo * siguiente;
};
//PROTOTIPOS
int prioridad(char); //Indica la prioridad de los operadores
char* leer(char[],int); //Lee un arreglo de caracteres en forma dinámica
void * crear (void *, char); //introduce un elemento a pila
void * eliminar(void *); //Elimina un elemento del tope de pila
void imprime(char[]); //Imprime la expresión infija
void postfija(char[]); //El algoritmo de transformación de infija a postfija
char topepila(void*); //Retorna lo que se tiene en tope de pila
main(){
char * a;
int i=0;
printf("Da la expresion infija:\n");
do
a=leer(a,i++);
while(a[i-1]!='\n');
imprime(a);
postfija(a);
return 0;
}
char * leer(char a[],int i){
char *b;
b=(char *)malloc(sizeof(char)*(i+1));
b[i]=getchar();
for (int j=0;j<i;j++)
b[j]=a[j];
free (a);
return b;
}
void imprime(char x[]){
int i=0;
putchar('\n');
printf("La expresion infija es:\n");
do
putchar(x[i++]);
while(x[i-1]!='\n');
}
void postfija(char a[]){
void *p=NULL;
char c;
int x=0;
printf("La expresion postfija es:\n");
while (a[x]!='\n'){
if (a[x]=='(')
p=crear(p,'(');
else if(a[x]==')'){
while((c=topepila(p))!='('){
putchar(c);
p=eliminar(p);
}
p=eliminar(p);
}
else if(a[x]>='a' && a[x]<='z')
putchar(a[x]);
else {
while (topepila(p)!='&' && prioridad(a[x])<=prioridad(topepila(p))){
putchar(topepila(p));
p=eliminar(p);
}
p=crear(p,a[x]);
}
x++;
}
while ((c=topepila(p))!='&'){
putchar(c);
p=eliminar(p);
}
}
int prioridad(char c){
int x;
switch(c){
case '^':x=3; break;
case '*':
case '/':
case '%':x=2; break;
case '+':
case '-':x=1; break;
case '(':x=0;break;
}
return x;
}
void *crear(void *p, char a){
nodo *q;
q=(nodo*)malloc(sizeof(nodo));
q->siguiente=NULL;
q->dato=a;
if(p==NULL) //La pila está vacía
p=q;
else{
q->siguiente=(nodo*)p;
p=q;
}
return(p);
}
char topepila(void *p){
nodo *q=(nodo*)p;
if (p==NULL)
return '&';
else
return q->dato;
}
void * eliminar(void * s){
nodo *p;
if(s==NULL)
printf("\npila vacia\n");
else{
p=(nodo*)s;
s=p->siguiente;
free(p);
}
return(s);
}
