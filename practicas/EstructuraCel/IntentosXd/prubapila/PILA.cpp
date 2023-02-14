#include <pruebapila.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int opcion;
    int m;
    int d;
    Nodo* top;
    top= NULL;
    do
    {
        printf( "Menu de opciones \n" );
        printf( "1. Apilar \n" );
        printf( "2. Desapilar \n" );
        printf( "3. Ver \n" );
        printf( "4. Longitud \n" );
        printf( "5 salir \n" );

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                printf("Ingresa el dato que quieres apilar(entero) \n");
                scanf( "%d", &d );
                top=apilar(top,d);
                    break;

            case 2:
                top=desapilar(top);
                    break;

            case 3:
                verPila(top);
                break;

            case 4:
                m = medidaPila(top);
                printf("la pila mide %d \n", m);
                break;
        }

         /* Fin del anidamiento */

    } while ( opcion != 5 );
    return 0;
}

