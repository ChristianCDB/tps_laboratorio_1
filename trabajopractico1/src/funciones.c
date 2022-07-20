#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>



void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int IngresarKm(int* pRetorno){
	int retorno = -1;
	int km;

	printf("Ingrese los kilometros:\n");
	scanf("%d", &km);
	if(pRetorno != NULL && km > 0){
		*pRetorno = km;
		retorno = 1;
	}

	return retorno;
}
int IngresoPrecioAA(int* pRetorno){
	int retorno = -1;
	int precio;

	printf("Ingrese el precio del vuelo de Aerolineas Argentinas\n");
	scanf("%d", &precio);

	if(pRetorno != NULL && precio > 0){
		*pRetorno = precio;
		retorno = 1;
	}

	return retorno;
}

int IngresoPrecioLATAM(int* pRetorno){
	int retorno = -1;
	int precio;

	printf("Ingrese el precio del vuelo de LATAM\n");
	scanf("%d", &precio);

	if(pRetorno != NULL && precio > 0){
		*pRetorno = precio;
		retorno = 1;
	}

	return retorno;
}

int CalcularTodosLosCostos(int banderaAerolineaArgentina, int banderaLATAM, int precioAA, int precioLATAM, int km){
	int retornoAA = -1;
	int retornoLATAM = -1;
	int retornoFuncion = -1;
	float retornoDebitoAA;
	float resultadoDebitoAA;
	float retornoCreditoAA;
	float resultadoCreditoAA;
	float retornoBitcoinAA;
	float resultadoBitcoinAA;
	float retornoUnitarioAA;
	float resultadoUnitarioAA;

	float retornoDebitoLATAM;
	float resultadoDebitoLATAM;
	float retornoCreditoLATAM;
	float resultadoCreditoLATAM;
	float retornoBitcoinLATAM;
	float resultadoBitcoinLATAM;
	float retornoUnitarioLATAM;
	float resultadoUnitarioLATAM;

	float retornoDiferenciaPrecios;
	float resultadoDiferenciaPrecios;

	if(banderaAerolineaArgentina == 1){
		retornoDebitoAA = CalcularDebitoAA(&resultadoDebitoAA, precioAA);
		retornoCreditoAA = CalcularCreditoAerolineas(&resultadoCreditoAA, precioAA);
		retornoBitcoinAA = CalcularBitcoinAerolineas(&resultadoBitcoinAA, precioAA);
		retornoUnitarioAA = CalcularPrecioUnitarioAerolineas(&resultadoUnitarioAA, precioAA, km);
		if(retornoDebitoAA == 1 || retornoCreditoAA == 1 || retornoBitcoinAA == 1 || retornoUnitarioAA == 1){
			retornoAA = 1;
		} else {
			retornoAA = -1;
		}
	}

	if(banderaLATAM == 1){
		retornoDebitoLATAM = CalcularDebitoLATAM(&resultadoDebitoLATAM, precioLATAM);
		retornoCreditoLATAM = CalcularCreditoLATAM(&resultadoCreditoLATAM, precioLATAM);
		retornoBitcoinLATAM = CalcularBitcoinLATAM(&resultadoBitcoinLATAM, precioLATAM);
		retornoUnitarioLATAM = CalcularUnitarioLATAM(&resultadoUnitarioLATAM, precioLATAM, km);
		if(retornoDebitoLATAM == 1 || retornoCreditoLATAM == 1 || retornoBitcoinLATAM == 1 || retornoUnitarioLATAM == 1){
			retornoLATAM = 1;
		} else {
			retornoLATAM = -1;
		}
	}

	retornoDiferenciaPrecios = CalcularDiferenciaPrecios(&resultadoDiferenciaPrecios, precioAA, precioLATAM);

	if(retornoAA == 1 || retornoLATAM == 1 || retornoDiferenciaPrecios == 1){
		retornoFuncion = 1;
	}

	return retornoFuncion;
}

float CalcularDebitoAA(float*pResultado, int precio){
	float retorno = -1;

	float resultadoAerolineasDebito;
	int descuento = 10;

	if(pResultado != NULL && precio > 0){
		resultadoAerolineasDebito = precio - (precio * descuento)/ 100;
		*pResultado = resultadoAerolineasDebito;
		retorno = 1;
	}

	return retorno;
}

float CalcularCreditoAerolineas(float* pResultado, int precio){
	float retorno = -1;
	int interes = 25;
	float resultadoAerolineasCredito;

	if(pResultado != NULL && precio > 0){
		resultadoAerolineasCredito = precio + (precio * interes)/ 100;
		*pResultado = resultadoAerolineasCredito;
		retorno = 1;
	}

	return retorno;

}

float CalcularBitcoinAerolineas(float* pResultado,int precio){
	float retorno = -1;
	float resultadoAerolineasBitcoin;
	float valorBtc = 4606954.55;

	if(pResultado != NULL && precio > 0){
		resultadoAerolineasBitcoin = (float)precio / valorBtc;
		*pResultado = resultadoAerolineasBitcoin;
		retorno = 1;
	}

	return retorno;
}

float CalcularPrecioUnitarioAerolineas(float* pResultado,int precio, int km){
	float retorno = -1;
	float resultadoPrecioUnitarioAA;

	if(pResultado != NULL && precio > 0){
		resultadoPrecioUnitarioAA = (float)precio / km;
		*pResultado = resultadoPrecioUnitarioAA;
		retorno = 1;
	}


	return retorno;
}

float CalcularDebitoLATAM(float* pResultado, int precioLATAM){
	float retorno = -1;
	float resultadoLatamDebito;
	int descuento;
	descuento = 10;

	if(pResultado != NULL && precioLATAM > 0){
		resultadoLatamDebito = precioLATAM - (precioLATAM * descuento)/ 100;
		*pResultado = resultadoLatamDebito;
		retorno = 1;
	}

	return resultadoLatamDebito;


	return retorno;
}

float CalcularCreditoLATAM(float* pResultado, int precioLATAM){
	float retorno = -1;
	float resultadoLatamCredito;
	int interes = 25;

	if(pResultado != NULL && precioLATAM > 0){
		resultadoLatamCredito = precioLATAM + (precioLATAM * interes)/ 100;
		*pResultado = resultadoLatamCredito;
		retorno = 1;
	}


	return retorno;
}

float CalcularBitcoinLATAM(float* pResultado,int precioLATAM){
	float retorno = -1;
	float valorBtc = 4606954.55;
	float resultadoLatamBitcoin;

	if(pResultado != NULL && precioLATAM > 0){
		resultadoLatamBitcoin = (float)precioLATAM / valorBtc;
		*pResultado = resultadoLatamBitcoin;
		retorno = 1;
	}

	return retorno;
}

float CalcularUnitarioLATAM(float* pResultado,int precioLATAM, int km){
	float retorno = -1;
	float resultadoUnitarioLATAM;

	if(pResultado != NULL && precioLATAM > 0){
		resultadoUnitarioLATAM = (float)precioLATAM / km;
		*pResultado = resultadoUnitarioLATAM;
		retorno = 1;
	}

	return retorno;
}

float CalcularDiferenciaPrecios(float* pResultado,int precioAA,int precioLATAM){
	float retorno = -1;
	float resultadoDiferenciaPrecios;


	if(pResultado != NULL  && precioAA > 0 && precioLATAM > 0){
		resultadoDiferenciaPrecios = precioAA - precioLATAM;
		*pResultado = resultadoDiferenciaPrecios;
		retorno = 1;
	}

	return retorno;
}

void InformarResultados(int precioAA, int precioLATAM, int km){
	float resultadoDebitoAA;
	float resultadoCreditoAA;
	float resultadoBitcoinAA;
	float resultadoUnitarioAA;
	float resultadoDebitoLATAM;
	float resultadoCreditoLATAM;
	float resultadoBitcoinLATAM;
	float resultadoUnitarioLATAM;
	float resultadoDiferencia;

	CalcularDebitoAA(&resultadoDebitoAA, precioAA);
	CalcularCreditoAerolineas(&resultadoCreditoAA, precioAA);
	CalcularBitcoinAerolineas(&resultadoBitcoinAA, precioAA);
	CalcularPrecioUnitarioAerolineas(&resultadoUnitarioAA, precioAA, km);
	CalcularDebitoLATAM(&resultadoDebitoLATAM, precioLATAM);
	CalcularCreditoLATAM(&resultadoCreditoLATAM, precioLATAM);
	CalcularBitcoinLATAM(&resultadoBitcoinLATAM, precioLATAM);
	CalcularUnitarioLATAM(&resultadoUnitarioLATAM, precioLATAM, km);
	CalcularDiferenciaPrecios(&resultadoDiferencia, precioAA, precioLATAM);

	printf("--------------------------------- \n");
	printf(" - - - -  P R E C I O S - - - - - \n");
	printf("--------------------------------- \n");
	printf("Latam:\n");
	printf("a) Precio con tarjeta de débito: %.2f\n", resultadoDebitoLATAM);
	printf("b) Precio con tarjeta de crédito: %.2f\n", resultadoCreditoLATAM);
	printf("c) Precio pagando con bitcoin : %.2f\n", resultadoBitcoinLATAM);
	printf("d) Precio unitario: %.2f\n", resultadoUnitarioLATAM);
	printf("Aerolineas:\n");
	printf("a) Precio con tarjeta de débito: %.2f\n", resultadoDebitoAA);
	printf("b) Precio con tarjeta de crédito: %.2f\n", resultadoCreditoAA);
	printf("c) Precio pagando con bitcoin : %.2f\n", resultadoBitcoinAA);
	printf("d) Precio unitario: %.2f\n", resultadoUnitarioAA);
	printf("La diferencia de precio es : %.2f\n", resultadoDiferencia);
	printf("--------------------------------- \n");
	printf(" - - - -  P R E C I O S - - - - - \n");
	printf("--------------------------------- \n");
}

void CargaForzada(float km, float precioAerolineas, float precioLatam){
	float debitoAerolineas;
	float retornoDebitoAerolineas;
	float creditoAerolineas;
	float retornoCreditoAerolineas;
	float bitcoinAerolineas;
	float retornoBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float retornoUnitarioAerolineas;

	float debitoLatam;
	float retornoDebitoLatam;
	float creditoLatam;
	float retornoCreditoLatam;
	float bitcoinLatam;
	float retornoBitcoinLatam;
	float precioUnitarioLatam;
	float retornoUnitarioLatam;

	float diferenciaDePrecios;
	float retornoDiferenciaDePrecios;

	retornoDebitoAerolineas = CalcularDebitoAA(&debitoAerolineas, precioAerolineas);
	retornoCreditoAerolineas = CalcularCreditoAerolineas(&creditoAerolineas, precioAerolineas);
	retornoBitcoinAerolineas = CalcularBitcoinAerolineas(&bitcoinAerolineas, precioAerolineas);
	retornoUnitarioAerolineas = CalcularPrecioUnitarioAerolineas(&precioUnitarioAerolineas,precioAerolineas,km );

	retornoDebitoLatam = CalcularDebitoLATAM(&debitoLatam, precioLatam);
	retornoCreditoLatam = CalcularCreditoLATAM(&creditoLatam, precioLatam);
	retornoBitcoinLatam = CalcularBitcoinLATAM(&bitcoinLatam,precioLatam);
	retornoUnitarioLatam = CalcularUnitarioLATAM(&precioUnitarioLatam, precioLatam, km );

	retornoDiferenciaDePrecios = CalcularDiferenciaPrecios(&diferenciaDePrecios, precioAerolineas, precioLatam);

	printf("-------------------CARGA FORZADA----------------------------------  \n\n");
	printf("Aerolineas: %.2f \n", precioAerolineas);
	printf("a) Precio con tarjeta de débito: %.2f \n", debitoAerolineas);
	printf("b) Precio con tarjeta de crédito: %.2f \n", creditoAerolineas);
	printf("c) Precio pagando con bitcoin : %.2f \n", bitcoinAerolineas);
	printf("d) Precio unitario: %.2f \n", precioUnitarioAerolineas);
	printf("\n\n");
	printf("Latam: %.2f/n", precioLatam);
	printf("a) Precio con tarjeta de débito: %.2f \n", debitoLatam);
	printf("b) Precio con tarjeta de crédito: %.2f \n", creditoLatam);
	printf("c) Precio pagando con bitcoin : %.2f \n", bitcoinLatam);
	printf("d) Precio unitario: %.2f \n", precioUnitarioLatam);
	printf("La diferencia de precio es : %.2f \n", diferenciaDePrecios);
	printf("-------------------CARGA FORZADA----------------------------------  \n\n");


}
