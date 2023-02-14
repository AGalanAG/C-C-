#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Empleado //Declaración de la clase empleado.
{
	public: //Declaración de los atributos para la clase empleado con tipo de visibilidad publica. 
		string usuario;
		string contra;
		
		void login();//Declaración de el metodo para la calse empleado afectado por el mismo tipo de visibilida en que fueron declarados los atributos.
};

void Empleado::login()//Desarrollamiento de el metodo login para la clase empleado.
{
	do{//Ciclo propuesto para ser repetido hasta que el empleado ingrese correctamente el nombre de usuario y contraseña.
	cout << endl << "|-------------------------------------|";
	cout << endl << "|            ï¿½ LOGIN ï¿½            |";
	cout << endl << "|------------------|------------------|";
	cout << endl << "|  Usuario: ";
	cin>>usuario;
	cout << "|                                     | ";
	cout << endl << "|  Passwd: ";
	cin>>contra;
	cout << "|                                     | ";
	cout << endl << "|------------------|------------------|";
	system("cls");	
		
	}while(usuario.compare("empleado")!=0 && contra.compare("empleadouno")!=0);//Aqui la condicon que valida exactamente que nombre de usuario y contraseña son.
		
	cout<<"\n\n\t    BIENVENIDO!\n\n";
	
}

class Producto //Declaración de la clase Producto.
{
	public:
		string tipo; //Declaración de los atributos para la clase Producto con tipo de visibilidad publica. 
		string tamano;
		string sabor;
		float precio;
		
		void impProd(); //Declaración de los metodos para la calse Producto afectado por el mismo tipo de visibilida en que fueron declarados los atributos.
		void llenarTipo (string);
		void llenarSabor (string);
		void llenarTam_Pre (string);
};

void Producto::llenarTipo(string tip) //Desarrollamiento de el metodo llenar tipo para la clase Producto.
{ 
	tipo=tip; //Con el proposito de recibir un string para que sea pasado al atributo tipo. 
}

void Producto::llenarSabor(string sab) //Desarrollamiento de el metodo llenar sabor para la clase Producto.
{
	sabor=sab; //Con el proposito de recibir un string para que sea pasado al atributo sabor. 
}

void Producto::llenarTam_Pre(string tam) //Desarrollamiento de el metodo tamaño/precio para la clase Producto.
{
tamano=tam; //Donde recibe un string que le es pasado al atributo tamaño y con base a este string evaluar posteriormente que precio corresponde. 
	
if(tipo.compare("helado")==0) //Condicional propuesto por Sí el tipo de producto solicitado por el cliente es igual a helado. 
{
	if(tamano.compare("normal")==0) //Si lo es, lo siguiente es comprobar si el helado que requiere es de tamaño normal. 
		precio=12.5; //Precio que le es asignado al producto por si se trata de un helado de tamaño normal.
	
	if(tamano.compare("grande")==0) //Si no es de tamaño normal entrara a esta condicion donde se evalura si es de tamaño grande.
		precio=17.5; //Precio que le es asignado al producto por si se trata de un helado de tamaño grande.		
}
else //De no ser un helado entonces entrara a este bloque de sentencias donde especificamente hay puros condicionales para encontrar el tipo de producto 
{    //solicitado por el cliente. 
	if(tipo.compare("paleta")==0) //Condicional propuesto por Sí el tipo de producto solicitado por el cliente es igual a Paleta.
	{
		if(tamano.compare("normal")==0) //Si lo es, lo siguiente es comprobar si la paleta que requiere es de tamaño normal.
			precio=10.5; //Precio que le es asignado al producto por si se trata de una paleta de tamaño normal.
			
		if(tamano.compare("grande")==0) //Si no es de tamaño normal entrara a esta condicion donde se evalura si es de tamaño grande.
			precio=13.5; //Precio que le es asignado al producto por si se trata de una paleta de grande.
	}
	else //De no ser un helado ni una paleta entrara a este bloque de sentencias donde especificamente hay puros condicionales para eencontara el 
	{   //tipo de producto.
		if(tipo.compare("agua")==0) //Condicional que evalua si el tipo de producto solicitado por el cliente es igual a un agua .
		{
			if(tamano.compare("normal")==0) //Si lo es, lo siguiente es comprobar si el agua que requiere es de tamaño normal.
				precio=16.5; //Precio que le es asignado al producto por si se trata de un helado de tamaño normal.

			if(tamano.compare("grande")==0) //Si no es de tamaño normal entrara a esta condicion donde se evalura si es de tamaño grande.
				precio=22.5; //Precio que le es asignado al producto por si se trata de un helado de tamaño grande.
		}
		else //Si el producto solicitado por el cliente no es ni un helado, paleta o agua, le mostrar el error en pantalla al cliente.
			cout<<"ERROR"<<endl;	
	}	
}


}


void Producto::impProd() //Desarrollamiento del metodo imprimir producto para la clase Pruducto.
{
	cout<<"\n   Producto: "<<tipo<<endl; //Donde su finalidad es justo eso, mostrar en pantalla el tipo de pruducto, tamaño, sabor y precio de cada producto 
	cout<<"   Tamano: "<<tamano<<endl;  //solicitado por el cliente con anterioridad. 
	cout<<"   Sabor: "<<sabor<<endl;
	cout<<"   Precio: $"<<precio<<endl;
}



class Pedido //Declaración de la clase Pedido.
{
	public: //Declaración de los atributos para la clase Pedido con tipo de visibilidad publica.
		Producto produc[10]; //Declaracion de una composicion perteneciente a la clase Producto que esta a su vez es un arreglo con tamaño 10 para que como maxi- 
		int cantidad;        //mo cada cliente pueda solicitar 10 productos.

		Pedido(); //Declaracion del constructor perteneciente a la case Pedido.
		void cantidad_set(int); //Declaración de los metodos para la calse Pedido afectado por el mismo tipo de visibilida en que fueron declarados los atributos
		float calcularPago(float); //y constructor.

	
};

Pedido::Pedido() //Desarrollamiento del constructor de la clase pedido.
{
	cantidad=0; //Donde la finalidad de haberse creado es inicializar este atributo en cero. 
}

void Pedido::cantidad_set(int cant) 
{
	cantidad=cant;
}

float Pedido::calcularPago(float p)
{
	float tot=0;
	tot+=p;
	return tot; 	
}




class Metodo_de_Pago //Declaración de la clase base metodo de pago.
{
	public: //Declaración del atributo para la clase metodo de pago con tipo de visibilidad publica.
		float cantidad;
};



class Efectivo:public Metodo_de_Pago //Realizacion de una herencia simple de tipo publica para que la clase derivada pueda ver o heredar el atributo
{                                   // de la clase base.
public: //Declaración del atributo para la clase efectivo con tipo de visibilidad publica.
	float cambio;

	void calcularCambio(float);	//Declaración de los metodos para la calse Pedido afectado por el mismo tipo de visibilida en que fueron declarados los atributos.
};

void Efectivo::calcularCambio(float t) //Desarrollamiento del metodo calcular cambio para la clase efectivo.
{
				int Turno,p,cont,q,Metodo,op; //Declaracion de las variables que solo son de uso y existencia en este metodo.
				float Total=0,Cantidad,Cambio;
	Total=t;
		Pagar:
			 	cout<<"Cantidad a pagar: $"<<Total<<endl; //Al cliente se le es mostrado cuanto debe pagar por los productos comprados.
				cout<<"Cantidad pagada es: $"<<endl; //Al cliente se le solicita que ingrese con cuanto dinero pagara.
				cin>>Cantidad;	
				if (Cantidad>Total) //Condicional para saber Sí el cliente ingresa una cantidad mayor al precio de su compra. 
				{
					Cambio=Cantidad-Total; //Se realiza el calculo para saber cuanto se debera de dar de cambio al cliente.
					cout<<"Su cambio es de $:"<<Cambio; //Imprime cambio.
					cout<<"\nGracias por su compra, vuelva vronto"<<endl;
					system("pause");
				}
				if (Cantidad==Total) //Condicional para saber si el cliente ingresa la cantidad exacta a la de su compra.
				{
					cout<<"Gracias por su compra, vuelva pronto"<<endl;
					system("pause");
				}
				if (Cantidad<Total) //Condicional para saber si el cliente ingresa una cantidad menor a la de su compra.
				{
					cout<<"No se puede cobrar, dinero insuficiente\n";
					goto Pagar; //ir a etiqueta pagar para que el cliente pueda volver a ver la cantidad a pagar e ingresar de nuevo una cantidad.
				}
	
}

class Tarjeta:public Metodo_de_Pago //Realizacion de una herencia simple de tipo publica para que la clase derivada pueda ver o heredar el atributo
{                                   // de la clase base.
	public: //Declaración de los atributos para la clase Tarjeta con tipo de visibilidad publica. 
		int numero;
		int nip;
		
		int validacion(); //Declaración del metodo para la calse Tarjeta afectado por el mismo tipo de visibilida en que fueron declarados los atributos.
};


int Tarjeta::validacion() //Desarrollamiento del metodo validacion para la clase efectivo.
{	
	if(numero=123456789 && nip==123) //Condicional por Si el cliente ingresa este numero de tarjeta y este nip.
	{
		cout<<"Se realizo el cargo a su tarjeta, gracias por su compra, vuelva pronto"<<endl;
		return 0;
		system("pause");
	}
	else //De lo contrario le mostrara un error.
		cout<<"ERROR num de tarjeta o nip erroneo"<<endl;
}


class Paleteria //Declaración de la clase Paleteria.
{
	public: //Declaración de los atributos para la clase paleteria con tipo de visibilidad publica. 
		Empleado empleado; //Declaracion de una composicion perteneciente a la clase empleado (paleteria contiene empleado y tiene acceso a sus atributos y metodos)
		Pedido ped[10]; //Declaracion de una composicion que a su vez es un arreglo de tamaño 10 perteneciente a la calse empleado (paleteria contiene empleado y tiene acceso a sus atributos y metodos)
		int turnoPedido;
		Metodo_de_Pago mpago; //Declaracion de una composicion perteneciente a la clase Metodo de pagao (paleteria contiene Metodo de pago y tiene acceso a sus atributos y metodos)
		Efectivo efec; //Declaracion de una composicion perteneciente a la clase Efectivo (paleteria contiene a Efectivo y tiene acceso a sus atributos y metodos)
		Tarjeta Tar;//Declaracion de una composicion perteneciente a la clase Tarjeta (paleteria contiene a Tarjeta y tiene acceso a sus atributos y metodos)
		
		Paleteria(); //Declaracion del constructor perteneciente a la case Paleteria.
     	void generarTurno(); //Declaración de los metodos para la calse Paleteria afectado por el mismo tipo de visibilida en que fueron declarados los atributos.
		void atender();	
};


Paleteria::Paleteria() //Desarrollamiento del constructor paleteria.
{
	turnoPedido=1; //Con la finalidad de inicializar el atrubuto turno pedido en uno.
}

void Paleteria::generarTurno() //Desarrollamiento del metodo generar turno para la clase Paleteria.
{
int opcion_menu=0,i,j=0; //Declaracion de variables que solo son de uso y existencia dentro de este metodo.
int opcion=0,sabor,tamano,imp=0;
i=turnoPedido; //la variable i inicializa en turno pedido.
											
do{ //Ciclo propuesto para ser repetido hasta que el usuario eliga finalizar.
	system("cls");
	cout << endl << "|-------------------------------------|";
	cout << endl << "|            ° ORDENAR °              |";
	cout << endl << "|------------------|------------------|";
	cout << endl << "| 1. Paletas       | 4. Finalizar     |";
	cout << endl << "| 2. Helados       |                  |";
	cout << endl << "| 3. Aguas         |                  |";
	cout << endl << "|------------------|------------------|";
	cout << endl << endl << " Escoja una Opcion: ";
	cin>>opcion; //Cliente elige que desea ordear.
		
	switch(opcion) //Se evalua la opcion elegida en distintos casos dentro del switch.
	{	
		case 1: //En caso de haber seleccionado la opcion 1 se muestra al cliente los sabores que hay para las paletas.
			ped[i].produc[j].llenarTipo("paleta"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tipo y 
												 // al mismo tiempo se le mete la cadena 'paleta' para hacerle saber al metodo que se trata de ese tipo de producto. 		 
			system("cls");	
			cout << endl << "|----------------|";
			cout << endl << "|   ° Sabor °    |";
			cout << endl << "|----------------|";
			cout << endl << "| 1. Limon       |";
			cout << endl << "| 2. Fresa       |";
			cout << endl << "| 3. Horchata    |";
			cout << endl << "|----------------|";
			
			do{ //Ciclo propuesto para que sea repetido hasta que forzosamente eliga alguna de las tres opciones.
				cout << endl << endl << " Escoja una Opcion: ";
				cin>>sabor;	
			}while(sabor!=1 && sabor !=2 && sabor !=3); //Condicion que evalua si se ingreso alguna de las dichas opciones.
			
			switch(sabor){ //Se evalua en distintos casos el sabor que haya elegido el cliente.
				case 1:
					ped[i].produc[j].llenarSabor("Limon"); //En caso de haber elegido el sabor 1, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'limon' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
					break;
				case 2:
					ped[i].produc[j].llenarSabor("Fresa"); //En caso de haber elegido el sabor 2, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'fresa' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
					break;
				
				case 3:
					ped[i].produc[j].llenarSabor("Horchata");//En caso de haber elegido el sabor 3, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'horchata' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
					break;
				
				default: //De haber selecionado una opcion no existente en el menu se mostrara un error en pantalla. 
					cout << endl << endl << " Opcion No Valida " << endl << endl;
			}
			
			system("cls"); //Se limpia pantalla y le es mostrado al cliente el menu de tamaños.
			cout << endl << "|----------------|";
			cout << endl << "|   ° Tamano °   |";
			cout << endl << "|----------------|";
			cout << endl << "| 1. Normal      |";
			cout << endl << "| 2. Grande      |";
			cout << endl << "|----------------|";
			do{ //Ciclo propuesto que es repetido hasta que el cliente ingrese alguno de los tamaños mostrados anteriormente en el menu. 
				cout << endl << endl << " Escoja una Opcion: ";
				cin>>tamano;	
			}while(tamano!=1 && tamano !=2); //Condicion que rompe el ciclo si el cliente ingresa alguno de los dos tamaños.
		
			switch(tamano){ //Se evalua en distintos casos el tamaño que haya elegido el cliente.
				case 1:
					ped[i].produc[j].llenarTam_Pre("normal"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tamaño/precio y 
										  // al mismo tiempo se le mete la cadena 'normal' para hacerle saber al metodo que se trata de ese tamaño de producto.
					break;
				
				case 2:
					ped[i].produc[j].llenarTam_Pre("grande"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tamaño/precio y 
										  // al mismo tiempo se le mete la cadena 'grande' para hacerle saber al metodo que se trata de ese tamaño de producto.
					break;
				
				default: //De no haber ingresado alguna de las dos opciones mostradas anteriormente en el menu al cliente se le muestra un error.
					cout << endl << endl << " Opcion No Valida " << endl << endl;
			}        
		
			
			j++; //Especie de contador que determina cuantos productos a solicitado cierto cliente.		
			break;
				
		
		case 2: //En caso de haber seleccionado la opcion 2 se muestra al cliente los sabores que hay para los helados.
	
			ped[i].produc[j].llenarTipo("helado"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tipo y 
												 // al mismo tiempo se le mete la cadena 'helado' para hacerle saber al metodo que se trata de ese tipo de producto. 	
			system("cls"); //Se limpia pantalla y le es mostrado al cliente el menu de tamaños.
			cout << endl << "|----------------|";
			cout << endl << "|   ° Sabor °    |";
			cout << endl << "|----------------|";
			cout << endl << "| 1. Limon       |";
			cout << endl << "| 2. Fresa       |";
			cout << endl << "| 3. Horchata    |";
			cout << endl << "|----------------|";
			
			do{ //Ciclo propuesto para que sea repetido hasta que forzosamente eliga alguna de las tres opciones.
				cout << endl << endl << " Escoja una Opcion: ";
				cin>>sabor;	
			}while(sabor!=1 && sabor !=2 && sabor !=3); //Condicion que evalua si se ingreso alguna de las dichas opciones.
			
			switch(sabor){ //Se evalua en distintos casos el sabor que haya elegido el cliente.
				case 1:
					ped[i].produc[j].llenarSabor("Limon"); //En caso de haber elegido el sabor 1, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'limon' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
					break;
				
				case 2:
					ped[i].produc[j].llenarSabor("Fresa"); //En caso de haber elegido el sabor 2, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'fresa' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
					break;
				
				case 3:
					ped[i].produc[j].llenarSabor("Horchata"); //En caso de haber elegido el sabor 3, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'horchata' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
					break;
				
				default: //De no haber ingresado alguna de las tres opciones mostradas anteriormente en el menu al cliente se le muestra un error.
					cout << endl << endl << " Opcion No Valida " << endl << endl;
				}
			
			system("cls"); //Se limpia pantalla y le es mostrado al cliente el menu de tamaños.
			cout << endl << "|----------------|";
			cout << endl << "|   ° Tamano °   |";
			cout << endl << "|----------------|";
			cout << endl << "| 1. Normal      |";
			cout << endl << "| 2. Grande      |";
			cout << endl << "|----------------|";
			
			do{ //Ciclo propuesto que es repetido hasta que el cliente ingrese alguno de los tamaños mostrados anteriormente en el menu. 
				cout << endl << endl << " Escoja una Opcion: ";
				cin>>tamano;	
			}while(tamano!=1 && tamano !=2 ); //Condicion que rompe el ciclo si el cliente ingresa alguno de los dos tamaños.
			
			switch(tamano){ //Se evalua en distintos casos el tamaño que haya elegido el cliente.
				
				case 1:
					ped[i].produc[j].llenarTam_Pre("normal"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tamaño/precio y 
										  // al mismo tiempo se le mete la cadena 'normal' para hacerle saber al metodo que se trata de ese tamaño de producto.
					break;
				case 2:
					ped[i].produc[j].llenarTam_Pre("grande"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tamaño/precio y 
										  // al mismo tiempo se le mete la cadena 'grande' para hacerle saber al metodo que se trata de ese tamaño de producto.
					break;
				
				default: //De no haber ingresado alguna de las dos opciones mostradas anteriormente en el menu al cliente se le muestra un error.
					cout << endl << endl << " Opcion No Valida " << endl << endl;
				}        
			
			j++; //Especie de contador que determina cuantos productos a solicitado cierto cliente.
			break;
			
			
			case 3: //En caso de haber seleccionado la opcion 3 se muestra al cliente los sabores que hay para las aguas.
			
				ped[i].produc[j].llenarTipo("agua"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tipo y 
												 // al mismo tiempo se le mete la cadena 'agua' para hacerle saber al metodo que se trata de ese tipo de producto.
				system("cls"); //Se limpia pantalla y le es mostrado al cliente el menu de tamaños.
				cout << endl << "|----------------|";
				cout << endl << "|   ° Sabor °    |";
				cout << endl << "|----------------|";
				cout << endl << "| 1. Limon       |";
				cout << endl << "| 2. Fresa       |";
				cout << endl << "| 3. Horchata    |";
				cout << endl << "|----------------|";
				
				do{  //Ciclo propuesto para que sea repetido hasta que forzosamente eliga alguna de las tres opciones.
					cout << endl << endl << " Escoja una Opcion: ";
					cin>>sabor;	
				}while(sabor!=1 && sabor !=2 && sabor !=3); //Condicion que evalua si se ingreso alguna de las dichas opciones.
				
				switch(sabor){ //Se evalua en distintos casos el sabor que haya elegido el cliente.
					
					case 1:
						ped[i].produc[j].llenarSabor("Limon"); //En caso de haber elegido el sabor 1, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'limon' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
						break;
					
					case 2:
						ped[i].produc[j].llenarSabor("Fresa"); //En caso de haber elegido el sabor 2, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'fresa' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
						break;
					
					case 3:
						ped[i].produc[j].llenarSabor("Horchata"); //En caso de haber elegido el sabor 3, el cliente x con n cantidad de productos ya seleccionados manda
														  // a llamar el metodo llenar sabor y al mismo tiempo se le mete la cadena 'horchata' para hacerle saber
														// al metodo que se trata de ese sabor de producto.
						break;
					
					default: //De no haber ingresado alguna de las tres opciones mostradas anteriormente en el menu al cliente se le muestra un error.
						cout << endl << endl << " Opcion No Valida " << endl << endl;
						}
						
				system("cls"); //Se limpia pantalla y le es mostrado al cliente el menu de tamaños.
				cout << endl << "|----------------|";
				cout << endl << "|   ° Tamano °   |";
				cout << endl << "|----------------|";
				cout << endl << "| 1. Normal      |";
				cout << endl << "| 2. Grande      |";
				cout << endl << "|----------------|";
						
				do{ //Ciclo propuesto que es repetido hasta que el cliente ingrese alguno de los tamaños mostrados anteriormente en el menu. 
					cout << endl << endl << " Escoja una Opcion: ";
					cin>>tamano;	
				}while(tamano!=1 && tamano !=2 ); //Condicion que rompe el ciclo si el cliente ingresa alguno de los dos tamaños.
						          			
				switch(tamano){ //Se evalua en distintos casos el tamaño que haya elegido el cliente.
					case 1:
						ped[i].produc[j].llenarTam_Pre("normal"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tamaño/precio y 
										  // al mismo tiempo se le mete la cadena 'normal' para hacerle saber al metodo que se trata de ese tamaño de producto.
						break;
					
					case 2:
						ped[i].produc[j].llenarTam_Pre("grande"); //Para el cliente x con n cantidad de productos ya seleccionados manda a llamar el metodo llenar tamaño/precio y 
										  // al mismo tiempo se le mete la cadena 'grande' para hacerle saber al metodo que se trata de ese tamaño de producto.
						break;
						
					default: //De no haber ingresado alguna de las dos opciones mostradas anteriormente en el menu al cliente se le muestra un error.
						cout << endl << endl << " Opcion No Valida " << endl << endl;
						system("pause");
					}  
				      
				j++; //Especie de contador que determina cuantos productos a solicitado cierto cliente.
				break;
				
				
				
			case 4: //En caso de haber seleccionado la opcion 4 se muestra al cliente su cuenta.
				
				int p,cant; //Declaracion de variables que seran utilizadas en este caso.
				cant=0;
				
				cout<<" Pedio:  "<<endl; 
				cout<<"Num turno :"<<i<<endl; //Se muestra al cliente el numero de turno que es.
				p=j-1; //A la cantidad de productos de cierto cliente se le resta uno y se asigna en p.
		
				while(p>=0){ //Mientras el cliente x tenga igual o mas de 1 producoto se repetira el ciclo.
					ped[i].produc[p].impProd(); //A x cliente por cada n producto manda a llamar el metodo imprimir producto.
					cant++; //La variable cantidad aumenta.
					p--; //Como ya se mostro n producto cuando se vuelva a repetir el ciclo si es que lo hace ahora debera mostrar el n-1 producto.
				}
							
				ped[i].cantidad_set(cant); //El cliente x manda a llamar al metodo cantidad y este a su ves se le mete la variable cantidad.
				cout<<"\n  Productos pedidos: "<<ped[i].cantidad<<endl; //Se imprime la cantidad de productos pedidos por el cliente x.
				cant=0; 
				turnoPedido++; //Como la cuenta a sido cerrada se espera un x+1 cliente.
				j=0; //Cantidad de productos vuelve a ser 0.
				
				cout << endl << endl << " GRACIAS " << endl << endl;
				system("pause");
				break;
			
			
			default: //De no haber ingresado alguna de las cuatro opciones mostradas anteriormente en el menu al cliente se le muestra un error.
				cout << endl << endl << " Opcion No Valida " << endl << endl;
		}
	} while (opcion != 4); //Condicion que rompe el ciclo si el cliente eligio finalizar.
	
}


void Paleteria::atender() //Desarrollamiento del metodo atender para la clase Paleteria.
{
int Turno,p,cont,q,Metodo,op,inten; //Declaracion de variables de uso y existencia solo en este metodo.
float Total,Cantidad,Cambio;
cont=0;
Total=0;
inten=0;				

do{ //Ciclo propuesto que es repetido hasta que el empleado ingrese algun turno valido. 
if(inten==2){
	goto CANCELAR;
}else{
cout<<"Ingrese el turno: ";
	cin>>Turno;
}
inten++;	
}while(ped[Turno].cantidad==0); // Dado que por defecto tiene cero productos todos los turnos hasta que se agregue se concidera un turno valido
				
p=ped[Turno].cantidad; //Despues de ser validado se asigna esa cantidad a una variable 
q=0;						

while(q<p){
	ped[Turno].produc[q].impProd();	// Con la variable de cantidad mostramos cuantos productos tenga el turno
	q++;
}
                
cout<<endl<<"  Cantidad de productos: "<<p<<endl;
while(p>0){
    Total+=ped[Turno].calcularPago(ped[Turno].produc[cont].precio);//Obtenemos los precios de los productos para mandar las cantidades a la funcion que las suma
    cont++;                                                        //Despues se guardan y se suma en la variable Total
	p--;
}
				
cont=0;
mpago.cantidad=Total;// Con el total obtenido se lo asignamos a su respectiva variable
cout<<"  Total a pagar: $"<<mpago.cantidad<<endl<<endl;
CANCELAR:
system("pause");
	
}





int main(){
Paleteria nPaleteria;  //Creacion de un objeto llamado nPaleteria de la clase Paleteria.
int opcion_menu=0; //Declaracion de variable utilizada en la funcion principal.

		
do{ //Ciclo propuesto que es repetido hasta que el cliente ingrese alguna opcion valida. 
	system("cls"); //Se limpia pantalla y le es mostrado al cliente el menu principal.
	cout << endl << "|-------------------------------------|";
	cout << endl << "|            ° PALETERIA °            |";
	cout << endl << "|------------------|------------------|";
	cout << endl << "| 1. Ordenar       |        2. Cobrar |";
	cout << endl << "|             3. Cerrar               |";
	cout << endl << "|------------------|------------------|";
	cout << endl << endl << " Escoja una Opcion: ";
	cin>>opcion_menu;
		
	
	switch(opcion_menu){ //Se evalua en distintos casos lo que haya seleccionado el cliente.		
			
			case 1: //En caso de haber seleccionado la opcion 1 el objeto de la clase Paleteria manda a llamar el metodo generar turno.
				nPaleteria.generarTurno(); 
				break;
				
			case 2:
				int Turno,p,cont,q,Metodo,op;//Declaracion de variables utilizadas para este caso.
				float Total,Cantidad,Cambio;
				cont=0;
				
				Total=nPaleteria.mpago.cantidad;// Obtenemos la cantidad a pagar
				nPaleteria.empleado.login();// Inicia sesion el empleado
				nPaleteria.atender();// Se ingresa y muestra los datos del turno

				do{
					cout<<"Desea pagar \n 1-Si \n 2-No"<<endl;// Se le cuestiona al cliente si quiere continuar con su compra
					cin>>op;
				}while(op!=1 && op!=2);
				
				if(op==1){
					
					do{
						cout<<"Ingrese su metodo de pago\n 1-Efectivo\n 2-Tarjeta\nOpcion: "<<endl;; //El cliete debe elegir entre una opcion de pago disponible
					 	cin>>Metodo;
					}while(Metodo!=1 && Metodo!=2);	
				 
				 	switch (Metodo)
				 	{
					 	case 1:
				 	    //Se llama al metodo para calcular su cambio si es que se tiene que dar
				 	    nPaleteria.efec.calcularCambio(nPaleteria.mpago.cantidad);
				 	
						break;
						
						case 2:	
							cout<<"Su total a pagar es de: "<<nPaleteria.mpago.cantidad<<endl;
							cout<<"Ingrese su numero de tarjeta: ";
							cin>>nPaleteria.Tar.numero;  //Se asigna el numero dado a su variable correspondiente
							cout<<"Ingrese su NIP: ";
							cin>>nPaleteria.Tar.nip;  //Se asigna el numero dado a su variable correspondiente
							nPaleteria.Tar.validacion(); //Se llama al metodo para validar los datos de la tarjeta y continuar con el pago
							system("pause");
							break;
						
						case 3:
							cout << endl << endl << " Programa finalizado..." << endl << endl;
							break;
						
						default:
							cout << endl << endl << " Opcion No Valida " << endl << endl;
					}
				}
			}

}while(opcion_menu!=3);
return 0;	
}
