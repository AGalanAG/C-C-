#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#define KUP 72
#define KDOWN 80
#define KLEEFT 75
#define KRIGHT 77
#define ENTER 13
#define ESCAPE 27

FILE *Alumnos;
struct Nombre
{
    char Nombre[20];
    char Apellidos[30];
};

struct Fecha
{
    char Anio[4];
    char Mes[2];
    char Dia[2];

};

struct Direccion
{
    char Calle[20];
    char Numero[15];
    char Colonia[30];
    char Ciudad[20];
    char Estado[20];
};

struct Padre
{
    struct Nombre Nombre_Padre;
    struct Direccion Direccion_Padre;
    char Telefono[15];
};


typedef struct Alumno  //DEFINICION DE LA ESTRUCTURA
{
    char Curp[20];
    struct Nombre Nombre_Alumno;
    struct Fecha Fecha_Alumno;
    struct Direccion Direccion_Alumno;
    struct Padre Mama;
    struct Padre Papa;
    struct Alumno *apsiguiente;
} nodo_Alumno;                  //DECLARAMOS UN NUEVO TIPO DE DATO ESTRUCTURA GRACIAS A LA SENTENCIA TYPEDEF LLAMADO nodo_Alumno

nodo_Alumno* apInicio=NULL;    //DECLARAMOS UN NUEVO TIPO DE DATO APUNTADOR A ESTRUCTURA
nodo_Alumno* apRecorre=NULL; //DECLARAMOS VARIABLES DEL NUEVO TIPO DE DATO APUNTADOR A ESTRUCTURA
struct Alumno nodoAlumno;

void agregar();
void imprimir_uno();
void imprimir();
void modificar();
void carga();
void borrar();
int guardaRegistros();
void coordXY(int x, int y);
void Menu();

void coordXY(int x, int y)
{
    COORD coordenadas;
    coordenadas.X=x;
    coordenadas.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordenadas);
}

void Menu()
{
	system("color 0");
    char Tecleado;
    int i=16;
//SetConsoleCursorPosition(10,10);
    int x=0,y=0;
    coordXY(0,0);
    printf("Agregar");
    coordXY(18,0);
    printf("Cargar");
    coordXY(36,0);
    printf("Consultar");
    coordXY(54,0);
    printf("Consultar UNO");
    coordXY(72,0);
    printf("Eliminar");
    coordXY(90,0);
    printf("Editar");
    coordXY(108,0);
    printf("Salir");




    do
    {
        if(kbhit())
        {
            Tecleado=getch();
            system("cls");
            switch(Tecleado)
            {
	case KUP:
		system("color 1");
  	    {
  	    	coordXY(30,0);
  	    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);	
  	printf("Oprime la flecha <- Izquierda o Derecha -> para regresar");
		y--;
		}
		break;
	
	case KDOWN:
		system("color 1");
		{
			coordXY(30,0);
		SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
  	printf("Oprime la flecha  <- Izquierda o Derecha -> para regresar");
		y++;
		}
		break;

            case ENTER:
            {
                if(x==0&&y==0)
                {

                    printf("\n\n\n");
               
                    agregar();
                
                    Menu();
                }

                if(x==18&&y==0)
                {
                    printf("\n\n\n");
             
                    carga();
         
                    Menu();
                }

                if(x==36&&y==0)
                {
          
                    imprimir();
                    Menu();
						
		
                }
                
                 if(x==54&&y==0)
                {
                    imprimir_uno();
                    Menu();	
		
					
                }

                if(x==72&&y==0)
                {
                    printf("\n\n\n");
                    borrar();
                    Menu();
                }


                if(x==90&&y==0)
                {
                    printf("\n\n\n");
                    modificar();
                    Menu();
                }

                if(x==108&&y==0)
                {
					coordXY(30,0);
		SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
  	printf("ADIOS");
		exit (-1);
                }

            }
            break;

	case ESCAPE:
		{
					coordXY(30,0);
		SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
  	printf("ADIOS");
  
		exit (-1);
		}
		break;
		
            case KRIGHT:
            {
            	system("color 1");
            	
                SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),i);
                x+=18;

                if (x==0&&y==0)
                {
                    coordXY(0,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Agregar");
                }
                else
                {
                    coordXY(0,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Agregar");
                }

                if (x==18&&y==0)
                {
                    coordXY(18,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Cargar");
                }
                else
                {
                    coordXY(18,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Cargar");
                }

                if (x==36&&y==0)
                {
                    coordXY(36,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Consultar");
                }
                else
                {
                    coordXY(36,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Consultar");
                }
                                if (x==54&&y==0)
                {
                    coordXY(54,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Consultar UNO");
                }
                else
                {
                    coordXY(54,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Consultar UNO");
                }

                if (x==72&&y==0)
                {
                    coordXY(72,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Eliminar");
                }
                else
                {
                    coordXY(72,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Eliminar");
                }

                if (x==90&&y==0)
                {
                    coordXY(90,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Editar");
                }
                else
                {
                    coordXY(90,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Editar");
                }


                if (x==108&&y==0)
                {
                    coordXY(108,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Salir");
                }
                else
                {
                    coordXY(108,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Salir");
                }


            }
            break;

            case KLEEFT:
            	system("color 1");
                x-=18;
                {
                    if (x==0&&y==0)
                    {
                        coordXY(0,0);
                        SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                        printf("Agregar");
                    }
                    else
                    {
                        coordXY(0,0);
                        SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                        printf("Agregar");
                    }

                    if (x==18&&y==0)
                    {
                        coordXY(18,0);
                        SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                        printf("Cargar");
                    }
                    else
                    {
                        coordXY(18,0);
                        SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                        printf("Cargar");
                    }

                    if (x==36&&y==0)
                    {
                        coordXY(36,0);
                        SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                        printf("Consultar");
                    }
                    else
                    {
                        coordXY(36,0);
                        SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                        printf("Consultar");
                    }

                                                   if (x==54&&y==0)
                {
                    coordXY(54,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Consultar UNO");
                }
                else
                {
                    coordXY(54,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Consultar UNO");
                }

                if (x==72&&y==0)
                {
                    coordXY(72,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Eliminar");
                }
                else
                {
                    coordXY(72,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Eliminar");
                }

                if (x==90&&y==0)
                {
                    coordXY(90,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Editar");
                }
                else
                {
                    coordXY(90,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Editar");
                }


                if (x==108&&y==0)
                {
                    coordXY(108,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),112);
                    printf("Salir");
                }
                else
                {
                    coordXY(108,0);
                    SetConsoleTextAttribute((GetStdHandle(STD_OUTPUT_HANDLE)),7);
                    printf("Salir");
                }

                }
                break;
            }
	if (x==126)
	{
		x=0;
		
	}
	if (y==1)
	{
		
		y=0;
	}
			
	if (x==-18)
	{
		x=108;
		
	}
	if (y==-1)
	{
		
		y=0;
	}
        }
        coordXY(x,y);
    }
    while(Tecleado!=27);
}

int main()
{
    Menu();
}


void carga()
{
    int i, x;
    if((Alumnos = fopen ("Alumnos.dat","rb"))== NULL)
    {
        printf("\n\t\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        printf("\n\t\t%c\t    NO EXISTE EL ARCHIVO!\t\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
        system("pause");
    }
    else
    {
        printf("\n\t\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        printf("\n\t\t%c\tSE ENCONTRO UN ARCHIVO!\t\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
        while(!feof(Alumnos))
        {
            if ((fread (&nodoAlumno,sizeof(nodo_Alumno),1,Alumnos)!=1)&& !feof(Alumnos))
            {
                printf("\n\t\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                printf("\n\t\t%c\t    ARCHIVO DA%cNADO!\t\t %c",186,164,186);
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);
                break;
            }
            else if(!feof(Alumnos))
            {
                nodo_Alumno* apNodo=(nodo_Alumno*)malloc(sizeof(nodo_Alumno));

                if(apInicio == NULL)
                {
                    apInicio = apNodo;
                }
                else
                {
                    apRecorre = apInicio;

                    while(apRecorre->apsiguiente != NULL)
                    {
                        apRecorre = apRecorre->apsiguiente;
                    }

                    apRecorre->apsiguiente = apNodo;


                }
                strcpy(apNodo->Curp,nodoAlumno.Curp);
                strcpy(apNodo->Nombre_Alumno.Nombre,nodoAlumno.Nombre_Alumno.Nombre);
                strcpy(apNodo->Nombre_Alumno.Apellidos,nodoAlumno.Nombre_Alumno.Apellidos);
                strcpy(apNodo->Fecha_Alumno.Dia,nodoAlumno.Fecha_Alumno.Dia);
                strcpy(apNodo->Fecha_Alumno.Mes,nodoAlumno.Fecha_Alumno.Mes);
                strcpy(apNodo->Fecha_Alumno.Anio,nodoAlumno.Fecha_Alumno.Anio);
                strcpy(apNodo->Direccion_Alumno.Calle,nodoAlumno.Direccion_Alumno.Calle);
                strcpy(apNodo->Direccion_Alumno.Numero,nodoAlumno.Direccion_Alumno.Numero);
                strcpy(apNodo->Direccion_Alumno.Colonia,nodoAlumno.Direccion_Alumno.Colonia);
                strcpy(apNodo->Direccion_Alumno.Ciudad,nodoAlumno.Direccion_Alumno.Ciudad);
                strcpy(apNodo->Direccion_Alumno.Estado,nodoAlumno.Direccion_Alumno.Estado);
                strcpy(apNodo->Papa.Nombre_Padre.Nombre,nodoAlumno.Papa.Nombre_Padre.Nombre);
                strcpy(apNodo->Papa.Nombre_Padre.Apellidos,nodoAlumno.Papa.Nombre_Padre.Apellidos);
                strcpy(apNodo->Papa.Direccion_Padre.Calle,nodoAlumno.Papa.Direccion_Padre.Calle);
                strcpy(apNodo->Papa.Direccion_Padre.Numero,nodoAlumno.Papa.Direccion_Padre.Numero);
                strcpy(apNodo->Papa.Direccion_Padre.Colonia,nodoAlumno.Papa.Direccion_Padre.Colonia);
                strcpy(apNodo->Papa.Direccion_Padre.Ciudad,nodoAlumno.Papa.Direccion_Padre.Ciudad);
                strcpy(apNodo->Papa.Direccion_Padre.Estado,nodoAlumno.Papa.Direccion_Padre.Estado);
                strcpy(apNodo->Papa.Telefono,nodoAlumno.Papa.Telefono);
                strcpy(apNodo->Mama.Nombre_Padre.Nombre,nodoAlumno.Mama.Nombre_Padre.Nombre);
                strcpy(apNodo->Mama.Nombre_Padre.Apellidos,nodoAlumno.Mama.Nombre_Padre.Apellidos);
                strcpy(apNodo->Mama.Direccion_Padre.Calle,nodoAlumno.Mama.Direccion_Padre.Numero);
                strcpy(apNodo->Mama.Direccion_Padre.Numero,nodoAlumno.Mama.Direccion_Padre.Numero);
                strcpy(apNodo->Mama.Direccion_Padre.Colonia,nodoAlumno.Mama.Direccion_Padre.Colonia);
                strcpy(apNodo->Mama.Direccion_Padre.Ciudad,nodoAlumno.Mama.Direccion_Padre.Ciudad);
                strcpy(apNodo->Mama.Direccion_Padre.Estado,nodoAlumno.Mama.Direccion_Padre.Estado);
                strcpy(apNodo->Mama.Telefono,nodoAlumno.Mama.Telefono);


                (!feof(Alumnos));

                apNodo->apsiguiente = NULL;

            }
        }
    }
}

void agregar()
{
    int i, x;
    nodo_Alumno* nuevo=(nodo_Alumno*)malloc(sizeof(nodo_Alumno));
    fflush(stdin);
    coordXY(15,1);
    printf("\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    printf("\n\t\t%c\t  D A T O S   A L U M N O        %c\n\t\t%c\t\t\t\t\t %c",186,186,186,186);
    printf("\n\t\t%c  CURP: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Nombre: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Apellidos: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Dia: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Mes: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  A%co: \t\t\t\t %c",186,164,186);
    printf("\n\t\t%c  Calle: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Numero: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Colonia: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Ciudad: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Estado: \t\t\t\t %c",186,186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    coordXY(25,4);
    gets(nuevo->Curp);
    fflush(stdin);
    coordXY(27,5);
    gets(nuevo->Nombre_Alumno.Nombre);
    fflush(stdin);
    coordXY(30,6);
    gets(nuevo->Nombre_Alumno.Apellidos);
    fflush(stdin);
    coordXY(24,7);
    gets(nuevo->Fecha_Alumno.Dia);
    fflush(stdin);
    coordXY(24,8);
    gets(nuevo->Fecha_Alumno.Mes);
    fflush(stdin);
    coordXY(24,9);
    gets(nuevo->Fecha_Alumno.Anio);
    fflush(stdin);
    coordXY(26,10);
    gets(nuevo->Direccion_Alumno.Calle);
    fflush(stdin);
    coordXY(27,11);
    gets(nuevo->Direccion_Alumno.Numero);
    fflush(stdin);
    coordXY(28,12);
    gets(nuevo->Direccion_Alumno.Colonia);
    fflush(stdin);
    coordXY(27,13);
    gets(nuevo->Direccion_Alumno.Ciudad);
    fflush(stdin);
    coordXY(27,14);
    gets(nuevo->Direccion_Alumno.Estado);
    system("cls");
    //DATOS PADRES
    coordXY(15,1);
    printf("\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    printf("\n\t\t%c\t  D A T O S   P A D R E          %c\n\t\t%c\t\t\t\t\t %c",186,186,186,186);
    printf("\n\t\t%c  Nombre: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Apellidos: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Calle: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Numero: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Colonia: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Ciudad: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Estado: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Telefono: \t\t\t\t %c",186,186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    fflush(stdin);
    coordXY(27,4);
    gets(nuevo->Papa.Nombre_Padre.Nombre);
    fflush(stdin);
    coordXY(30,5);
    gets(nuevo->Papa.Nombre_Padre.Apellidos);
    fflush(stdin);
    coordXY(26,6);
    gets(nuevo->Papa.Direccion_Padre.Calle);
    fflush(stdin);
    coordXY(27,7);
    gets(nuevo->Papa.Direccion_Padre.Numero);
    fflush(stdin);
    coordXY(28,8);
    gets(nuevo->Papa.Direccion_Padre.Colonia);
    fflush(stdin);
    coordXY(27,9);
    gets(nuevo->Papa.Direccion_Padre.Ciudad);
    fflush(stdin);
    coordXY(27,10);
    gets(nuevo->Papa.Direccion_Padre.Estado);
    coordXY(27,11);
    gets(nuevo->Papa.Telefono);
    system("cls");
    //DATOS MADRE
    coordXY(15,1);
    printf("\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    printf("\n\t\t%c\t  D A T O S   M A D R E          %c\n\t\t%c\t\t\t\t\t %c",186,186,186,186);
    printf("\n\t\t%c  Nombre: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Apellidos: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Calle: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Numero: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Colonia: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Ciudad: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Estado: \t\t\t\t %c",186,186);
    printf("\n\t\t%c  Telefono: \t\t\t\t %c",186,186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    fflush(stdin);
    coordXY(27,4);
    gets(nuevo->Mama.Nombre_Padre.Nombre);
    fflush(stdin);
    coordXY(30,5);
    gets(nuevo->Mama.Nombre_Padre.Apellidos);
    fflush(stdin);
    coordXY(26,6);
    gets(nuevo->Mama.Direccion_Padre.Calle);
    fflush(stdin);
    coordXY(27,7);
    gets(nuevo->Mama.Direccion_Padre.Numero);
    fflush(stdin);
    coordXY(28,8);
    gets(nuevo->Mama.Direccion_Padre.Colonia);
    fflush(stdin);
    coordXY(27,9);
    gets(nuevo->Mama.Direccion_Padre.Ciudad);
    fflush(stdin);
    coordXY(27,10);
    gets(nuevo->Mama.Direccion_Padre.Estado);
    coordXY(27,11);
    gets(nuevo->Mama.Telefono);
    printf("\n\t\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    printf("\n\t\t%c\t    REGISTRO EXISTOSO!\t\t %c",186,186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    if(apInicio==NULL)
    {
        apInicio = nuevo;

    }
    else
    {
        apRecorre=apInicio;
        while(apRecorre->apsiguiente != NULL)
        {
            apRecorre = apRecorre->apsiguiente;
        }
        apRecorre->apsiguiente = nuevo;
    }
    nuevo->apsiguiente = NULL;
    printf("\n\n\t\t");
    guardaRegistros();
    system("pause");
    system("cls");
}

void imprimir()
{	
    int x, i;
    nodo_Alumno* actual=(nodo_Alumno*)malloc(sizeof(nodo_Alumno));
    actual = apInicio;
    	
    if(apInicio!=NULL)
    {
    
        while(actual != NULL)
        {
        	 	
            printf("\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            
            printf("\n\t\t\tD A T O S   A L U M N O\t");
            printf("\n\n\t\tCurp: %s ",actual->Curp);
            printf("\n\t\tNombre: %s",actual->Nombre_Alumno.Nombre);
            printf("\n\t\tApellidos: %s ",actual->Nombre_Alumno.Apellidos);
            printf("\n\t\tDia: %s ",actual->Fecha_Alumno.Dia);
            printf("\n\t\tMes: %s ",actual->Fecha_Alumno.Mes);
            printf("\n\t\tA%co: %s ",164,actual->Fecha_Alumno.Anio);
            printf("\n\t\tCalle: %s",actual->Direccion_Alumno.Calle);
            printf("\n\t\tNumero: %s ",actual->Direccion_Alumno.Numero);
            printf("\n\t\tColonia: %s ",actual->Direccion_Alumno.Colonia);
            printf("\n\t\tCiudad: %s ",actual->Direccion_Alumno.Ciudad);
            printf("\n\t\tEstado: %s ",actual->Direccion_Alumno.Estado);
            printf("\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("\n\t\t\tD A T O S   P A D R E\t");
            printf("\n\t\tNombre: %s",actual->Papa.Nombre_Padre.Nombre);
            printf("\n\t\tApellidos: %s ",actual->Papa.Nombre_Padre.Apellidos);
            printf("\n\t\tCalle: %s",actual->Papa.Direccion_Padre.Calle);
            printf("\n\t\tNumero: %s ",actual->Papa.Direccion_Padre.Numero);
            printf("\n\t\tColonia: %s ",actual->Papa.Direccion_Padre.Colonia);
            printf("\n\t\tCiudad: %s ",actual->Papa.Direccion_Padre.Ciudad);
            printf("\n\t\tEstado: %s ",actual->Papa.Direccion_Padre.Estado);
            printf("\n\t\tTelefono: %s ",actual->Papa.Telefono);
            printf("\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("\n\t\t\tD A T O S   M A D R E\t");
            printf("\n\t\tNombre: %s",actual->Mama.Nombre_Padre.Nombre);
            printf("\n\t\tApellidos: %s ",actual->Mama.Nombre_Padre.Apellidos);
            printf("\n\t\tCalle: %s",actual->Mama.Direccion_Padre.Calle);
            printf("\n\t\tNumero: %s ",actual->Mama.Direccion_Padre.Numero);
            printf("\n\t\tColonia: %s ",actual->Mama.Direccion_Padre.Colonia);
            printf("\n\t\tCiudad: %s ",actual->Mama.Direccion_Padre.Ciudad);
            printf("\n\t\tEstado: %s ",actual->Mama.Direccion_Padre.Estado);
            printf("\n\t\tTelefono: %s ",actual->Mama.Telefono);
            printf("\n\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            actual = actual->apsiguiente;

        }
    }
    else
    {
        printf("\t\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        printf("\n\t\t%c\t      LISTA VACIA!\t\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
    }
    printf("\n\t\t");
    system("pause");
    system("cls");

}

void borrar()
{
    int i, x;
    nodo_Alumno* actual=(nodo_Alumno*)malloc(sizeof(nodo_Alumno));
    actual = apInicio;
    nodo_Alumno* anterior=(nodo_Alumno*)malloc(sizeof(nodo_Alumno));
    anterior = NULL;
    char nodoBuscado[20];
    int encontrado = 0;
    fflush(stdin);
    coordXY(15,1);
    printf("\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    coordXY(28,2);
    printf("ELIMINAR REGISTRO");
    coordXY(16,2);
    printf("%c",186);
    coordXY(57,2);
    printf("%c",186);
    coordXY(16,3);
    printf("%c",186);
    coordXY(57,3);
    printf("%c",186);
    coordXY(16,4);
    printf("%c CURP: ",186);
    coordXY(57,4);
    printf("%c",186);
    coordXY(16,5);
    printf("%c",186);
    coordXY(57,5);
    printf("%c",186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    coordXY(24,4);
    gets(nodoBuscado);
    if(apInicio!=NULL)
    {
        while(actual != NULL && encontrado != 1)
        {

            if(strcmp(actual->Curp,nodoBuscado)==0)
            {

                if(actual == apInicio)
                {
                    apInicio = apInicio->apsiguiente;
                }
                else if(actual == apRecorre)
                {
                    anterior->apsiguiente = NULL;
                    apRecorre = anterior;
                }
                else
                {
                    anterior->apsiguiente = actual->apsiguiente;
                }
                coordXY(15,7);
                printf("\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                coordXY(15,8);
                printf("\t%c\t    Eliminado con exito\t\t %c",186,186);
                guardaRegistros();
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);
                encontrado = 1;
            }
            anterior = actual;
            actual = actual->apsiguiente;
            
        }
        if(encontrado == 0)
        {
            coordXY(15,1);
            printf("\t%c",201);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",187);
            coordXY(15,2);
            printf("\t%c\t      CURP ENCONTRADO\t\t %c",186,186);
            printf("\n\t\t%c",200);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",188);
        }
        else
        {
            free(anterior);
        }
    }
    else
    {
        coordXY(15,1);
        printf("\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        coordXY(15,2);
        printf("\t%c\t      LISTA VACIA\t\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
    }
    
    printf("\n\n\n\n\t\t");
    system("pause");
    system("cls");

}

void modificar()
{
    int i, x;
    nodo_Alumno* actual = (nodo_Alumno*) malloc(sizeof(nodo_Alumno));
    actual = apInicio;
    char nodoBuscado[20];
    int encontrado= 0;
    fflush(stdin);
    coordXY(15,1);
    printf("\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    coordXY(15,2);
    printf("\t%c\t\tMODIFICAR\t\t %c",186,186);
    coordXY(15,3);
    printf("\t%c    CURP: \t\t\t\t %c",186,186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    coordXY(27,3);
    gets(nodoBuscado);
    if(apInicio!=NULL)
    {
        while(actual != NULL && encontrado != 1)
        {

            if(strcmp(actual->Curp,nodoBuscado)==0)
            {
                coordXY(15,1);
                printf("\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                coordXY(15,2);
                printf("\t%c\t      CURP ENCONTRADO\t\t %c",186,186);
                coordXY(15,3);
                printf("\t%c    Ingrese Nuevos Datos:\t\t %c",186,186);
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);

                coordXY(15,5);
                printf("\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                printf("\n\t\t%c\t  D A T O S   A L U M N O        %c\n\t\t%c\t\t\t\t\t %c",186,186,186,186);
                printf("\n\t\t%c  CURP: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Nombre: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Apellidos: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Dia: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Mes: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  A%co: \t\t\t\t %c",186,164,186);
                printf("\n\t\t%c  Calle: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Numero: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Colonia: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Ciudad: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Estado: \t\t\t\t %c",186,186);
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);
                fflush(stdin);
                coordXY(25,8);
                gets(actual->Curp);
                fflush(stdin);
                coordXY(27,9);
                gets(actual->Nombre_Alumno.Nombre);
                fflush(stdin);
                coordXY(30,10);
                gets(actual->Nombre_Alumno.Apellidos);
                fflush(stdin);
                coordXY(24,11);
                gets(actual->Fecha_Alumno.Dia);
                fflush(stdin);
                coordXY(24,12);
                gets(actual->Fecha_Alumno.Mes);
                fflush(stdin);
                coordXY(24,13);
                gets(actual->Fecha_Alumno.Anio);
                fflush(stdin);
                coordXY(26,14);
                gets(actual->Direccion_Alumno.Calle);
                fflush(stdin);
                coordXY(27,15);
                gets(actual->Direccion_Alumno.Numero);
                fflush(stdin);
                coordXY(28,16);
                gets(actual->Direccion_Alumno.Colonia);
                fflush(stdin);
                coordXY(27,17);
                gets(actual->Direccion_Alumno.Ciudad);
                fflush(stdin);
                coordXY(27,18);
                gets(actual->Direccion_Alumno.Estado);
                system("cls");

                //DATOS PADRES
                coordXY(15,1);
                printf("\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                printf("\n\t\t%c\t  D A T O S   P A D R E          %c\n\t\t%c\t\t\t\t\t %c",186,186,186,186);
                printf("\n\t\t%c  Nombre: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Apellidos: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Calle: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Numero: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Colonia: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Ciudad: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Estado: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Telefono: \t\t\t\t %c",186,186);
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);
                fflush(stdin);
                coordXY(27,4);
                gets(actual->Papa.Nombre_Padre.Nombre);
                fflush(stdin);
                coordXY(30,5);
                gets(actual->Papa.Nombre_Padre.Apellidos);
                fflush(stdin);
                coordXY(26,6);
                gets(actual->Papa.Direccion_Padre.Calle);
                fflush(stdin);
                coordXY(27,7);
                gets(actual->Papa.Direccion_Padre.Numero);
                fflush(stdin);
                coordXY(28,8);
                gets(actual->Papa.Direccion_Padre.Colonia);
                fflush(stdin);
                coordXY(27,9);
                gets(actual->Papa.Direccion_Padre.Ciudad);
                fflush(stdin);
                coordXY(27,10);
                gets(actual->Papa.Direccion_Padre.Estado);
                coordXY(29,11);
                gets(actual->Papa.Telefono);
                system("cls");
                //DATOS MADRE
                coordXY(15,1);
                printf("\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                printf("\n\t\t%c\t  D A T O S   M A D R E          %c\n\t\t%c\t\t\t\t\t %c",186,186,186,186);
                printf("\n\t\t%c  Nombre: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Apellidos: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Calle: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Numero: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Colonia: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Ciudad: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Estado: \t\t\t\t %c",186,186);
                printf("\n\t\t%c  Telefono: \t\t\t\t %c",186,186);
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);
                fflush(stdin);
                coordXY(27,4);
                gets(actual->Mama.Nombre_Padre.Nombre);
                fflush(stdin);
                coordXY(30,5);
                gets(actual->Mama.Nombre_Padre.Apellidos);
                fflush(stdin);
                coordXY(26,6);
                gets(actual->Mama.Direccion_Padre.Calle);
                fflush(stdin);
                coordXY(27,7);
                gets(actual->Mama.Direccion_Padre.Numero);
                fflush(stdin);
                coordXY(28,8);
                gets(actual->Mama.Direccion_Padre.Colonia);
                fflush(stdin);
                coordXY(27,9);
                gets(actual->Mama.Direccion_Padre.Ciudad);
                fflush(stdin);
                coordXY(27,10);
                gets(actual->Mama.Direccion_Padre.Estado);
                coordXY(29,11);
                gets(actual->Mama.Telefono);
                printf("\n\t\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                printf("\n\t\t%c\t  MODIFICADO EXISTOSO!\t\t %c",186,186);
                printf("\n\t\t%c",200);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",188);

                encontrado = 1;
            }

            actual = actual->apsiguiente;
        }
        if(encontrado == 0)
        {
            coordXY(15,5);
            printf("\n\t\t%c",201);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",187);
            printf("\n\t\t%c\t  CURP NO ENCONTRADO\t\t %c",186,186);
            printf("\n\t\t%c",200);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",188);
        }
    }
    else
    {
        coordXY(15,5);
        printf("\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        coordXY(15,6);
        printf("\t%c\t      LISTA VACIA\t\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
    }
    guardaRegistros();
    printf("\n\n\n\t\t");
    system("pause");
    system("cls");
}


void imprimir_uno(){
	 int i, x;
    nodo_Alumno* actual = (nodo_Alumno*) malloc(sizeof(nodo_Alumno));
    actual = apInicio;
    char nodoBuscado[20];
    int encontrado= 0;
    fflush(stdin);
    coordXY(15,1);
    printf("\t%c",201);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",187);
    coordXY(15,2);
    printf("\t%c CONSULTAR UN REGISTRO\t\t\t %c",186,186);
    coordXY(15,3);
    printf("\t%c    CURP: \t\t\t\t %c",186,186);
    printf("\n\t\t%c",200);
    for(i=0; i<40; i++)
    {
        printf("%c",205);
        x++;
    }
    printf("%c",188);
    coordXY(27,3);
    gets(nodoBuscado);
    if(apInicio!=NULL)
    {
        while(actual != NULL && encontrado != 1)
        {

            if(strcmp(actual->Curp,nodoBuscado)==0)
            {
                coordXY(15,7);
                printf("\t%c",201);
                for(i=0; i<40; i++)
                {
                    printf("%c",205);
                    x++;
                }
                printf("%c",187);
                coordXY(15,8);
                printf("\t%c\t   CURP ENCONTRADO\t\t %c",186,186);
                coordXY(15,8);

 	
            printf("\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            
            printf("\n\t\t\tD A T O S   A L U M N O\t");
            printf("\n\n\t\tCurp: %s ",actual->Curp);
            printf("\n\t\tNombre: %s",actual->Nombre_Alumno.Nombre);
            printf("\n\t\tApellidos: %s ",actual->Nombre_Alumno.Apellidos);
            printf("\n\t\tDia: %s ",actual->Fecha_Alumno.Dia);
            printf("\n\t\tMes: %s ",actual->Fecha_Alumno.Mes);
            printf("\n\t\tA%co: %s ",164,actual->Fecha_Alumno.Anio);
            printf("\n\t\tCalle: %s",actual->Direccion_Alumno.Calle);
            printf("\n\t\tNumero: %s ",actual->Direccion_Alumno.Numero);
            printf("\n\t\tColonia: %s ",actual->Direccion_Alumno.Colonia);
            printf("\n\t\tCiudad: %s ",actual->Direccion_Alumno.Ciudad);
            printf("\n\t\tEstado: %s ",actual->Direccion_Alumno.Estado);
            printf("\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("\n\t\t\tD A T O S   P A D R E\t");
            printf("\n\t\tNombre: %s",actual->Papa.Nombre_Padre.Nombre);
            printf("\n\t\tApellidos: %s ",actual->Papa.Nombre_Padre.Apellidos);
            printf("\n\t\tCalle: %s",actual->Papa.Direccion_Padre.Calle);
            printf("\n\t\tNumero: %s ",actual->Papa.Direccion_Padre.Numero);
            printf("\n\t\tColonia: %s ",actual->Papa.Direccion_Padre.Colonia);
            printf("\n\t\tCiudad: %s ",actual->Papa.Direccion_Padre.Ciudad);
            printf("\n\t\tEstado: %s ",actual->Papa.Direccion_Padre.Estado);
            printf("\n\t\tTelefono: %s ",actual->Papa.Telefono);
            printf("\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("\n\t\t\tD A T O S   M A D R E\t");
            printf("\n\t\tNombre: %s",actual->Mama.Nombre_Padre.Nombre);
            printf("\n\t\tApellidos: %s ",actual->Mama.Nombre_Padre.Apellidos);
            printf("\n\t\tCalle: %s",actual->Mama.Direccion_Padre.Calle);
            printf("\n\t\tNumero: %s ",actual->Mama.Direccion_Padre.Numero);
            printf("\n\t\tColonia: %s ",actual->Mama.Direccion_Padre.Colonia);
            printf("\n\t\tCiudad: %s ",actual->Mama.Direccion_Padre.Ciudad);
            printf("\n\t\tEstado: %s ",actual->Mama.Direccion_Padre.Estado);
            printf("\n\t\tTelefono: %s ",actual->Mama.Telefono);
            printf("\n\n\t\t");
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }

                encontrado = 1;
            }

            actual = actual->apsiguiente;
        }
        if(encontrado == 0)
        {
            coordXY(15,1);
            printf("\n\t\t%c",201);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",187);
            printf("\n\t\t%c\t  CURP NO ENCONTRADO\t\t %c",186,186);
            printf("\n\t\t%c",200);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",188);
        }
    }
    else
    {
        coordXY(15,1);
        printf("\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        coordXY(15,2);
        printf("\t%c\t      LISTA VACIA\t\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
    }
    guardaRegistros();
    system("pause");
    system("cls");
	
}



int guardaRegistros()
{
    int x, i;
    if((Alumnos = fopen ("Alumnos.dat","wb"))== NULL)
    {
        coordXY(15,1);
        printf("\n\t\t%c",201);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",187);
        printf("\n\t\t%c    NO SE PUEDE ABRIR EL ARCHIVO\t %c",186,186);
        printf("\n\t\t%c",200);
        for(i=0; i<40; i++)
        {
            printf("%c",205);
            x++;
        }
        printf("%c",188);
        return 0;
    }

    apRecorre=apInicio;

    while (apRecorre!=NULL)
    {
        nodoAlumno=*apRecorre;

        if (fwrite(&nodoAlumno,sizeof(nodo_Alumno),1,Alumnos)!=1)
        {
            coordXY(15,1);
            printf("\n\t\t%c",201);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",187);
            printf("\n\t\t%c\t      ERROR AL GUARDAR\t\t %c",186,186);
            printf("\n\t\t%c",200);
            for(i=0; i<40; i++)
            {
                printf("%c",205);
                x++;
            }
            printf("%c",188);
            fclose(Alumnos);
            return 0;
        }
        apRecorre=apRecorre->apsiguiente;
    }
    fclose(Alumnos);
    return 1;
}


