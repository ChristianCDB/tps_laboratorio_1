

#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassengers.h"
#include "inputs.h"
#include "prototipos.h"
#define LEN 2000



int main(void) {
	setbuf(stdout, NULL);
	sPassenger lista[LEN];
	int opcion;
	int retornoInit;
	int banderaAlta = 0;
	int retornoAlta;

	retornoInit = initPassengers(lista, LEN);

	if(retornoInit == 0){
		printf("Lista inicializada con exito.\n");
	} else {
		printf("Error, no se pudo inicializar la lista.\n");
	}


	do{
		printf("1)ALTA.\n");
		printf("2)MODIFICAR.\n");
		printf("3)BAJA.\n");
		printf("4)INFORMAR.\n");
		printf("5)CARGA FORZADA.\n");
		printf("6)SALIR.\n");
		scanf("%d", &opcion);

		switch(opcion){
		case 1:
			retornoAlta = loadInList(lista, LEN);
			switch(retornoAlta){
				case -1:
					printf("Error, no hay espacios disponibles.\n");
					break;
				default:
					printf("\nLa carga se realizo con exito en la posicion %d\n", retornoAlta);
					banderaAlta=1;
					break;
			}
			break;
		case 2:
			if(banderaAlta != 1){
				printf("Error, no se ingreso ningun pasajero...\n");
			} else {
				modifyPassenger(lista, LEN);
			}
			break;
		case 3:
			if(banderaAlta != 1){
				printf("Error, no se ingreso ningun pasajero...\n");
			} else {
				removePassenger(lista, LEN);
			}
			break;
		case 4:
			if(banderaAlta != 1){
				printf("Error, no se ingreso ningun pasajero...\n");
			} else {
				inform(lista, LEN);
			}
			break;
		case 5:
			if(banderaAlta != 1){
				printf("Error, no se ingreso ningun pasajero...\n");
			} else {
				harcodear(lista, LEN);
			}
			break;
		case 7:
			if(banderaAlta != 1){
				printf("Error, no se ingreso ningun pasajero...\n");
			} else {
				printPassenger(lista, LEN);
			}
			break;
		default:
			printf("Ingrese una opcion valida...(1 a 6)\n");
			break;
		}


	}while(opcion != 6);



	return EXIT_SUCCESS;
}
