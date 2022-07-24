#ifndef ARRAYPASSENGERS_H_
#define ARRAYPASSENGERS_H_

typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}sPassenger;

typedef struct{
	int id;
	char nombre[51];
}sTypePassenger;

typedef struct{
	int id;
	char nombre[51];
}sStatusFlight;

int initPassengers(sPassenger lista[], int len);
sPassenger addPassenger();
int findEmptySpace(sPassenger lista[], int len);
int loadInList(sPassenger lista[], int len);
int idGenerico();
void ShowTypePassenger();
void validateTypePassenger(int* idTypePassenger, sTypePassenger tiposDePasajeros[], int len);
int findPassengerById(sPassenger lista[], int len,int id);
void removePassenger(sPassenger lista[], int len);
int printPassenger(sPassenger lista[], int len);
int findFullPassengers(sPassenger lista[], int len);
int findTypePassenger(sPassenger lista);
int findStatusFlight(sPassenger lista);
void ShowOnePassenger(sPassenger unPasajero, sTypePassenger tipoPasajero, sStatusFlight estadoVuelo);
void ShowPassengerData(sPassenger unPasajero);
char removeConfirmation(char mensaje[]);
void modifyPassenger(sPassenger lista[], int len);
void inform(sPassenger lista[], int len);
void OrdenarListaAlfabeticamente(sPassenger lista[], int len, int opcion);
void AlfabeticamenteAscendente(sPassenger lista[],int len);
void AlfabeticamenteDescendente(sPassenger lista[],int len);
void PromediosPrecios(sPassenger lista[],int len);
void OrdenarPorCodigoDeVuelo(sPassenger lista[], int len, int opcion);
void codigoDeVueloAscendente(sPassenger lista[], int len);
void codigoDeVueloDescendente(sPassenger lista[], int len);
void harcodear(sPassenger lista[],int len);

#endif /* ARRAYPASSENGERS_H_ */
