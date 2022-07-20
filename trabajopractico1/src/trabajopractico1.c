#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(void) {
	setbuf(stdout, NULL);
	int retornoKm;
	int banderaKm = 0;
	int km;

	int retornoAerolinea;
	int banderaAerolineaArgentina = 0;
	int banderaLATAM = 0;
	int aerolinea;
	int precioAA;
	int precioLATAM;

	int banderaCalcular = 0;
	int banderaInformar = 0;

	int retornoCalcular;
	int opcion;

	do{
		printf("1. Ingresar Kilómetros: ( km=x)\n");
		printf("2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
		printf("3. Calcular todos los costos:\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		scanf("%d", &opcion);

		switch(opcion){
		case 1:
			printf("------------------------------------------------\n");
			printf("Ingreso de kilometros \n");
			printf("------------------------------------------------\n");
			retornoKm = IngresarKm(&km);
			if(retornoKm != 1){
				printf("Error, no se pudo ingresar los km, intentelo otra vez...\n");
			} else {
				printf("Kilometros ingresados correctamente!\n");
				banderaKm = 1;
				clear();
			}
			break;
		case 2:
			if(banderaKm == 1){
				printf("------------------------------------------------\n");
				printf("Ingrese la Aerolinea al que quiere agregarle el precio.\n");
				printf("1 para Aerolineas Argentinas, 2 para LATAM\n");
				printf("------------------------------------------------\n");
				scanf("%d", &aerolinea);

				switch(aerolinea){
				case 1:
					retornoAerolinea =  IngresoPrecioAA(&precioAA);
					if(retornoAerolinea != 1){
						printf("Error, no se ha podido ingresar el precio de Aerolinea...\n");
						printf("Intente nuevamente\n");
						banderaAerolineaArgentina = 0;
					} else {
						printf("Precio del vuelo ingresado correctamente\n");
						banderaAerolineaArgentina = 1;
					}
					break;
				case 2:
					retornoAerolinea = IngresoPrecioLATAM(&precioLATAM);
					if(retornoAerolinea != 1){
						printf("Error, no se ha podido ingresar el precio de LATAM...\n");
						printf("Intente nuevamente\n");
						banderaLATAM = 0;
					} else {
						printf("Precio del vuelo ingresado correctamente\n");
						banderaLATAM = 1;
					}
					break;
				default:
					printf("ERROR\n");
					printf("Ingrese una aerolinea valida...\n");
					printf("1 para Aerolineas Argentinas, 2 para LATAM\n");
					break;
				}
			} else {
				printf("Error, ingrese primero los km para ingresar el precio de los vuelos\n");
			}
			break;
		case 3:
			if(banderaKm == 1){
				if(banderaAerolineaArgentina == 1 || banderaLATAM == 1){
					retornoCalcular = CalcularTodosLosCostos(banderaAerolineaArgentina, banderaLATAM, precioAA, precioLATAM, km);
				if(retornoCalcular != 1){
					printf("------------------------------------------------\n");
					printf("---------------------ERROR----------------------\n");
					printf("Error, no se ha podido calcular los costos...\n");
					printf("------------------------------------------------\n");
					printf("---------------------ERROR----------------------\n");
				} else {
					printf("Los costos se han calculado correctamente\n");
					banderaCalcular = 1;
				}
			}
			} else {
				printf("------------------------------------------------\n");
				printf("---------------------ERROR----------------------\n");
				printf("Error, primero debe ingresar los datos de los campos anteriores...\n");
				printf("---------------------ERROR----------------------\n");
				printf("------------------------------------------------\n");
			}

			break;
		case 4:
			if(banderaKm == 1){
				if(banderaAerolineaArgentina == 1 || banderaLATAM == 1){
					if(banderaCalcular == 1){
						InformarResultados(precioAA,precioLATAM,km);
						banderaInformar = 1;
					}
				}
			}
			break;
		case 5:
			if(banderaKm == 1){
							if(banderaAerolineaArgentina == 1 || banderaLATAM == 1){
								if(banderaCalcular == 1 && banderaInformar == 1){
									CargaForzada(7090, 162965, 159339);
								}
							}
						}
			break;
		default:
			printf("Error, ingrese una opcion valida... (x < 6)\n");
			break;
		}

	}while(opcion != 6);
	return EXIT_SUCCESS;
}


