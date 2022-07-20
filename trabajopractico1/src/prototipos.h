#ifndef PROTOTIPOS_H_
#define PROTOTIPOS_H_
void clear();
//PUNTO 1
int IngresarKm(int* pRetorno);
//PUNTO 2
int IngresoPrecioAA(int* pRetorno);
int IngresoPrecioLATAM(int* pRetorno);
//PUNTO 3
int CalcularTodosLosCostos(int banderaAerolineaArgentina, int banderaLATAM, int precioAA, int precioLATAM, int km);
float CalcularDebitoAA(float*pResultado, int precio);
float CalcularCreditoAerolineas(float* resultadoCreditoAA,int precioAA);
float CalcularBitcoinAerolineas(float* resultadoBitcoinAA,int precioAA);
float CalcularPrecioUnitarioAerolineas(float* resultadoUnitarioAA,int precioAA, int km);
float CalcularDebitoLATAM(float* pResultado, int precioLATAM);
float CalcularCreditoLATAM(float* pResultado, int precioLATAM);
float CalcularBitcoinLATAM(float* resultadoBitcoinLATAM,int precioLATAM);
float CalcularUnitarioLATAM(float* resultadoUnitarioLATAM,int precioLATAM, int km);
float CalcularDiferenciaPrecios(float* resultadoDiferenciaPrecios,int precioAA,int precioLATAM);
//PUNTO 4
void InformarResultados( int precioAA, int precioLATAM, int km);
//PUNTO 5
void CargaForzada(float km, float precioAerolineas, float precioLatam);

#endif /* PROTOTIPOS_H_ */
