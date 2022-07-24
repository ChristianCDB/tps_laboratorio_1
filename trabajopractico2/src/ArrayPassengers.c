#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassengers.h"
#include "inputs.h"
#include "prototipos.h"


#define LIBRE 0
#define OCUPADO 1
#define lenTypePassenger 3
#define lenStatusFlight 3
#define lenHardcodeo 5

static int idIncremental = 1000;

static sTypePassenger listaTipoPasajero[lenTypePassenger] = {{1, "Turista"}, {2, "Economico"}, {3, "VIP"}};
static sStatusFlight listaEstadoVuelo[lenStatusFlight] = {{1, "En vuelo"}, {2, "Demorado"}, {3, "No despego"}};


int idGenerico() {
	idIncremental++;
	return idIncremental;
}

int initPassengers(sPassenger lista[], int len){
	int retorno = -1;

	for(int i = 0; i < len; i++){
		lista[i].isEmpty = LIBRE;
	}

	for(int i = 0; i < len; i++){
		if(lista[i].isEmpty == LIBRE){
			retorno = 0;
		}
	}

	return retorno;
}

int findEmptySpace(sPassenger lista[], int len){
	int index = -1;

	for(int i = 0; i < len; i++){
		if(lista[i].isEmpty == LIBRE){
			index = i;
			break;
		}
	}

	return index;
}

int loadInList(sPassenger lista[], int len){
	int index = -1;

	index = findEmptySpace(lista, len);

	if(index != -1){
		lista[index] = addPassenger();
	}

	return index;
}

sPassenger addPassenger(){
	sPassenger unPasajero;

	unPasajero.id = idGenerico();
	PedirCadena(unPasajero.name, "Ingrese el nombre del pasajero.\n");
	PedirCadena(unPasajero.lastname, "Ingrese el apellido del pasajero.\n");
	unPasajero.price = PedirFlotante("Ingrese el precio del vuelo.\n");
	printf("Ingrese el codigo del vuelo.\n");
	scanf("%s", unPasajero.flycode);
	ShowTypePassenger();
	unPasajero.typePassenger = PedirEntero("Ingrese el tipo de pasajero: (1,2 o 3)\n");
	validateTypePassenger(&unPasajero.typePassenger, listaTipoPasajero, lenTypePassenger);
	unPasajero.isEmpty = OCUPADO;



	return unPasajero;
}

void ShowTypePassenger(){
	printf("TIPOS DE PASAJEROS:\n");
	for(int i = 0; i < lenTypePassenger; i++){
		printf("tipo de pasajero %d: %s\n",listaTipoPasajero[i].id, listaTipoPasajero[i].nombre);
	}
}

void validateTypePassenger(int* idTypePassenger, sTypePassenger tiposDePasajeros[], int len){
	int bandera = 0;

	for(int i = 0; i < len; i++){
		if(*idTypePassenger == tiposDePasajeros[i].id){
			bandera = 1;
			break;
		}
	}

	if(bandera == 0){
		printf("--------------------------------------------\n");
		printf("- - - - - - - - - E R R O R - - - - - - - - \n");
		printf("--------------------------------------------\n");
		printf("Ingrese un tipo de pasajero valido... (entre 1 y 3)");

		ShowTypePassenger();
		*idTypePassenger=PedirEntero("Ingrese tipo de pasajero.\n");
	}
}

int findPassengerById(sPassenger lista[], int len,int id){
	int index = -1;

	for(int i = 0; i<len; i++){
		if(lista[i].id == id){
			index = id;
		}
	}

	return index;
}

void removePassenger(sPassenger lista[], int len){
	int index;
	int indexId;
	char respuesta;
	int pasajeroLleno = findFullPassengers(lista, len);


	if(pasajeroLleno == 1){
		//PrinteoDevuelta...
		printf("Ingrese el pasajero que quiera remover de la lista. \n");
		scanf("%d", &index);
		indexId = findPassengerById(lista, len,index);
		if(indexId == -1){
			printf("Error, no se encontro el id ingresado... Intentelo otra vez.\n");
			//PrinteoDevuelta...
			printf("Ingrese id de persona que quiere modificar");
			scanf("%d",&index);
			indexId = findPassengerById(lista, len,index);
		} else {
			printf("Usuario encontrado.\n");
		}
		ShowPassengerData(lista[indexId]);
		respuesta = removeConfirmation("Desea eliminar este pasajero?\n");
		if(respuesta == 's'){
			lista[indexId].isEmpty = LIBRE;
		} else {
			printf("Operacion cancelada.\n");
		}
	} else {
		printf("Error, no se encontro ningun pasajero cargado en la lista...\n");
	}
}

int printPassenger(sPassenger lista[], int len){
	int indexListaTipoPasajeros;
	int indexListaEstadoVuelo;
	int pasajeroLleno;
	int retorno = -1;

	pasajeroLleno = findFullPassengers(lista, len);

	if(pasajeroLleno == 1){
		for(int i = 0; i<len; i++){
			if(lista[i].isEmpty == OCUPADO){
				indexListaTipoPasajeros = findTypePassenger(lista[i]);
				indexListaEstadoVuelo = findStatusFlight(lista[i]);
				ShowOnePassenger(lista[i], listaTipoPasajero[indexListaTipoPasajeros], listaEstadoVuelo[indexListaEstadoVuelo]);
			}
		}

	} else {
		printf("No hay ningun pasajero cargado en lista... \n");
	}

	return retorno;

}

int findFullPassengers(sPassenger lista[], int len){
	int retorno = -1;


	for(int i=0; i<len; i++){
		if(lista[i].isEmpty == OCUPADO){
			retorno = 1;
		}
	}

	return retorno;
}

int findTypePassenger(sPassenger lista){
	int index = -1;

	for(int i = 0; i < lenTypePassenger; i++){
		if(lista.id == listaTipoPasajero[i].id){
			index = i;
			break;
		}
	}

	return index;
}

int findStatusFlight(sPassenger lista){
	int index = -1;

	for(int i = 0; i<lenStatusFlight; i++){
		if(lista.id == listaEstadoVuelo[i].id){
			index = i;
			break;
		}
	}

	return index;
}

void ShowOnePassenger(sPassenger unPasajero, sTypePassenger tipoPasajero, sStatusFlight estadoVuelo){
	printf(" %d || %s || %s || %.2f || %s || %s || \n",
																unPasajero.id, unPasajero.name, unPasajero.lastname,
																unPasajero.price, tipoPasajero.nombre,
																estadoVuelo.nombre);
}

void ShowPassengerData(sPassenger unPasajero){
	printf("%d || %s || %s", unPasajero.id,unPasajero.name,unPasajero.lastname);
}

char removeConfirmation(char mensaje[]){
	char respuesta;
	printf("%s", mensaje);
	scanf("%c", &respuesta);

	while(respuesta!='s' && respuesta!='n')
	{
		printf("\n ERROR: Ingrese opcion correcta (s/n)\n");
		printf(mensaje);
		scanf("%c",&respuesta);
	}

	return respuesta;
}

void modifyPassenger(sPassenger lista[], int len){
	int opcion;
	int indexId;
	int id;
	sPassenger auxPassenger;
	char respuesta;

	printPassenger(lista, len);
	printf("Ingrese el id de el pasajero que quiere modificar:\n");
	scanf("%d", &id);
	indexId = findPassengerById(lista, len, id);
	while(indexId == -1){
		printf("\n ERROR \n");
		printPassenger(lista, len);
		printf("Ingrese id de persona que quiere modificar.\n");
		scanf("%d",&id);
		indexId=findPassengerById(lista, len, id);
	}

	printf("Usuario encontrado con exito.\n");

	do
	{
		printf("Ingrese que desea modificar:\n");
		printf("1. Nombre [%s]\n",lista[indexId].name);
		printf("2. Apellido [%s]\n",lista[indexId].lastname);
		printf("3. Precio [%f]\n", lista[indexId].price);
		printf("4. Tipo de Pasajero [%s] \n",lista[findTypePassenger(lista[indexId])].name);
		printf("5. Salir.");
		fflush(stdin);
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				PedirCadena(auxPassenger.name, "Ingrese Nombre:\n");
				respuesta=removeConfirmation("Desea cambiar el nombre?\n");
				if(respuesta=='s')
				{
					strcpy(lista[indexId].name,auxPassenger.name);
					printf("Cambio de nombre realizado con exito.\n");
				}
				else
				{
					printf("Modificacion cancelada\n");
				}

			break;

			case 2:
				PedirCadena(auxPassenger.lastname, "Ingrese apellido:\n");
				respuesta=removeConfirmation("Desea cambiar el apellido?\n");
				if(respuesta=='s')
				{
					strcpy(lista[indexId].lastname,auxPassenger.lastname);
					printf("Cambio de apellido realizado con exito.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}

			break;

			case 3:
				auxPassenger.price=PedirFlotante("Ingrese precio.\n");
				respuesta=removeConfirmation("Desea cambiar el precio?\n");
				if(respuesta=='s')
				{
					lista[indexId].price=auxPassenger.price;
					printf("Cambio de precio realizado con exito\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}


			break;

			case 4:
				ShowTypePassenger();
				auxPassenger.id=PedirEntero("Ingrese tipo de pasajero.\n");
				respuesta=removeConfirmation("Desea cambiar el tipo de pasajero?\n");
				if(respuesta=='s')
				{
					lista[indexId].id=auxPassenger.typePassenger;
					printf("Cambio de precio realizado con exito.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
			break;
			default:
				printf("Opcion incorrecta.\n");
			break;
		}

	}while(opcion!=5);
}

void inform(sPassenger lista[], int len){
	int opcion;
	int opcion2;
	int opcion3;


	do{
		printf("1. Listado de los pasajeros ordenados alfabaticamente por Apellido y Tipo de pasajero.\n");
		printf("2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
		printf("3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n");
		printf("4. Volver.\n");
		fflush(stdin);
		scanf("%d",&opcion);

		switch(opcion){
			case 1:
				printf("1. Ordenar de forma ascendente.\n");
				printf("2. Ordenar de forma descendente.\n");
				scanf("%d", &opcion2);
				if(opcion2 != 1 && opcion2 != 2){
					printf("Error, elija una opcion valida(1 o 2)\n");
					break;
				} else {
					OrdenarListaAlfabeticamente(lista, len, opcion2);
					printPassenger(lista, len);
				}
				break;
			case 2:
				PromediosPrecios(lista, len);
				break;
			case 3:
				printf("1. Ordenar de forma ascendente.\n");
				printf("2. Ordenar de forma descendente.\n");
				scanf("%d",&opcion3);
				if(opcion3 != 1 && opcion3 != 2){
					printf("Error, elija una opcion valida(1 o 2)\n");
				} else {
					OrdenarPorCodigoDeVuelo(lista, len, opcion3);
					printPassenger(lista, len);
				}
				break;
			default:
				printf("Ingrese una opcion correcta(1 a 4)\n");
				break;
		}

	}while(opcion != 4);
}
void OrdenarListaAlfabeticamente(sPassenger lista[], int len, int opcion){
	if(opcion == 1){
		AlfabeticamenteAscendente(lista, len);
	} else {
		if(opcion == 2){
			AlfabeticamenteDescendente(lista, len);
		}
	}
}
void AlfabeticamenteAscendente(sPassenger lista[],int len){
	sPassenger auxPassenger;

	for(int i=0;i<len; i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if((strcmp(lista[i].lastname,lista[j].lastname))>0)
			{
				auxPassenger=lista[i];
				lista[i]=lista[j];
				lista[j]=auxPassenger;
			}
			if((strcmp(lista[i].lastname,lista[j].lastname))==0)
			{
				if(lista[i].typePassenger>lista[j].typePassenger)
				{
					auxPassenger=lista[i];
					lista[i]=lista[j];
					lista[j]=auxPassenger;

				}
			}
		}
	}
}

void AlfabeticamenteDescendente(sPassenger lista[],int len){
	sPassenger auxPassenger;

	for(int i=0;i<len; i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if((strcmp(lista[i].lastname,lista[j].lastname))<0)
			{
				auxPassenger=lista[i];
				lista[i]=lista[j];
				lista[j]=auxPassenger;
			}
			if((strcmp(lista[i].lastname,lista[j].lastname))==0)
			{
				if(lista[i].typePassenger<lista[j].typePassenger)
				{
					auxPassenger=lista[i];
					lista[i]=lista[j];
					lista[j]=auxPassenger;

				}
			}

		}
	}
}

void PromediosPrecios(sPassenger lista[],int len){
	float acumulador;
	int contador;
	float promedio;

	acumulador=0;
	contador=0;

	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==OCUPADO)
		{
			acumulador=acumulador+lista[i].price;
			contador++;
		}

	}
	promedio=acumulador/contador;
	printf("El total de ingresos es %f y el promedio es %f\n",acumulador,promedio);
}

void OrdenarPorCodigoDeVuelo(sPassenger lista[], int len, int opcion){
	if(opcion==1){
		codigoDeVueloAscendente(lista, len);
	}
	if(opcion==2){
		codigoDeVueloDescendente(lista, len);
	}
}

void codigoDeVueloAscendente(sPassenger lista[], int len)
{
	sPassenger auxiliar;

		for(int i=0;i<len; i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if((strcmp(lista[i].flycode,lista[j].flycode))>0)
				{
					auxiliar=lista[i];
					lista[i]=lista[j];
					lista[j]=auxiliar;
				}
			}
		}
}

void codigoDeVueloDescendente(sPassenger lista[], int len){
	sPassenger auxiliar;

	for(int i=0;i<len; i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if((strcmp(lista[i].flycode,lista[j].flycode))<0)
			{
				auxiliar=lista[i];
				lista[i]=lista[j];
				lista[j]=auxiliar;
			}
		}
	}
}

void harcodear(sPassenger lista[],int len){
	int index;

	sPassenger listaHarcodeo[lenHardcodeo]={{idGenerico(),"Christian","Ormachea",14089,"S8D4X",2,1},
			{idGenerico(),"Karina","Albornoz",50477, "KSI04",3,2},
			{idGenerico(),"Rolando","Ormachea", 3000, "KSD24",2,2},
			{idGenerico(),"Milagros","Ormachea", 2304, "HCX45",1,1},
			{idGenerico(),"Matias", "Gimenez", 32340,"ILD46",3,1}};


	for(int i=0; i<lenHardcodeo;i++)
	{
		index=findEmptySpace(lista, len);
		if(index!=-1)
		{
			lista[index]=listaHarcodeo[i];
			lista[index].isEmpty=OCUPADO;
		}
	}
}

