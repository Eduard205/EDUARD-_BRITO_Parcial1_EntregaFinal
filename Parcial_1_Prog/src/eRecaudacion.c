/*
 * eRecaudacion.c
 *
 *  Created on: 13 may. 2021
 *      Author: eduar
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eRecaudacion.h"
#include "eContribuyente.h"

void eRecaudacion_Inicializar(eRecaudacion array[], int TAM) {
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = 1;
			array[i].idRecaudacion = 0;
			array[i].idContribuyente = 0;
			array[i].mes = 0;
			array[i].importe = 0;
			array[i].isEmpty = 1;
			array[i].idTipo.idTipo = 0;
			strcpy(array[i].idTipo.descripcion, " ");
			array[i].idTipo.isEmpty = 1;
			array[i].idEstado.idEstado = 0;
			strcpy(array[i].idEstado.descripcion, " ");
			array[i].idEstado.isEmpty = 1;

		}
	}
	return;
}

int buscarRecaudacion(eRecaudacion array[], int tam, int id) {
	int rtn = -1;
	int i;

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].idContribuyente == id && array[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int buscarPorIdRecaudacion(eRecaudacion array[], int tam, int id) {
	int rtn = -1;
	int i;

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].idRecaudacion == id && array[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

void listarUnaRecaudacionPorId(eRecaudacion array) {
	printf("%15s%15s%7s%10s%13s\n", "IdCONTRIBUYENTE", "IdRECAUDACION", "MES",
			"TIPO", "IMPORTE");
	printf("%10d%10d%15d%13s%12.2f\n", array.idContribuyente,
			array.idRecaudacion, array.mes, array.idTipo.descripcion,
			array.importe);

	return;
}

int mostrarPorIdRecaudacion(eRecaudacion array[], int tam) {

	int rtn = 0;
	int idRecaudacion;
	int posicion;

	printf("Ingrese el id de recaudacion: ");
	scanf("%d", &idRecaudacion);
	while (idRecaudacion < 100 || idRecaudacion > 150) {
		printf("Error. Ingrese un Id de recaudacion entre (100-150): ");
		scanf("%d", &idRecaudacion);
	}

	while (buscarPorIdRecaudacion(array, tam, idRecaudacion) == -1) {
		printf("No existe el id ingresado, reingrese id de recaudacion: ");
		scanf("%d", &idRecaudacion);
	}

	posicion = buscarPorIdRecaudacion(array, tam, idRecaudacion);
	listarUnaRecaudacionPorId(array[posicion]);

	rtn = 1;
	return rtn;
}

void cambiarEstadoRefinanciar(eRecaudacion array[], int tam, int idRecaudacion) {

	int posicion;

	while (buscarPorIdRecaudacion(array, tam, idRecaudacion) == -1) {
		printf("No existe el id ingresado, reingrese id de recaudacion: ");
		scanf("%d", &idRecaudacion);
	}
	posicion = buscarPorIdRecaudacion(array, tam, idRecaudacion);

	array[posicion].idEstado.idEstado = 1;
	strcpy(array[posicion].idEstado.descripcion, "Refinanciar");
	array[posicion].idEstado.isEmpty = 0;

	return;
}

void cambiarEstadoSaldar(eRecaudacion array[], int tam, int idRecaudacion) {

	int posicion;

	while (buscarPorIdRecaudacion(array, tam, idRecaudacion) == -1) {
		printf("No existe el id ingresado, reingrese id de recaudacion: ");
		scanf("%d", &idRecaudacion);
	}
	posicion = buscarPorIdRecaudacion(array, tam, idRecaudacion);

	array[posicion].idEstado.idEstado = 2;
	strcpy(array[posicion].idEstado.descripcion, "Saldar");
	array[posicion].idEstado.isEmpty = 0;

	return;
}


int mostrarUnaRecaudacion(eRecaudacion array[], int tam) {

	int rtn = 0;
	int idContribuyente;

	printf("Ingrese el id del contribuyente: ");
	scanf("%d", &idContribuyente);
	while (idContribuyente < 1000 || idContribuyente > 1050) {
		printf("Error. Ingrese un Id de contribuyente entre (1000-1050): ");
		scanf("%d", &idContribuyente);
	}

	while (buscarRecaudacion(array, tam, idContribuyente) == -1) {
		printf("No existe el id ingresado, reingrese id del contribuyente: ");
		scanf("%d", &idContribuyente);
	}

	mostrarRecaudaciones(array, idContribuyente, tam);

	rtn = 1;
	return rtn;
}

void listarUnaRecaudacion(eRecaudacion array) {

	printf("%10d%10d%15d%13s%12.2f\n", array.idContribuyente,
			array.idRecaudacion, array.mes, array.idTipo.descripcion,
			array.importe);

	return;
}

int mostrarRecaudaciones(eRecaudacion array[], int id, int tam) {
	int i;
	int rtn = 0;

	printf("\n\t> LISTADO DE RECAUDACIONES\n");
	printf("%15s%15s%7s%10s%13s\n", "IdCONTRIBUYENTE", "IdRECAUDACION", "MES",
			"TIPO", "IMPORTE");

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].idContribuyente == id && array[i].isEmpty == 0) {
				listarUnaRecaudacion(array[i]);
				rtn++;
			}
		}

	}
	return rtn;
}

int buscarLibre2(eRecaudacion array[], int *posicion2, int tam) {

	int rtn = -1;
	if (array != NULL && posicion2 != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (array[i].isEmpty == 1) {
				*posicion2 = i;
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int bajaRecaudacion(eRecaudacion array[], int tam, int id) {
	int rtn = 0;
	int i;
	int posicion;

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			posicion = buscarRecaudacion(array, tam, id);

			array[posicion].isEmpty = -1;
			rtn = 1;
		}
	}
	return rtn;
}

int altaRecaudacion(eRecaudacion array[], int posicion2, int *contadorId2) {

	array[posicion2].idRecaudacion = *contadorId2;

	printf("Ingrese Id del contribuyente: ");
	scanf("%d", &array[posicion2].idContribuyente);

	printf("Ingrese mes: ");
	scanf("%d", &array[posicion2].mes);

	printf("Ingrese tipo (1-ARBA, 2-IIBB, 3-GANANCIAS): ");
	scanf("%d", &array[posicion2].idTipo.idTipo);

	switch (array[posicion2].idTipo.idTipo) {

	case 1:
		strcpy(array[posicion2].idTipo.descripcion, "ARBA");
		array[posicion2].idTipo.isEmpty = 0;
		break;
	case 2:
		strcpy(array[posicion2].idTipo.descripcion, "IIBB");
		array[posicion2].idTipo.isEmpty = 0;
		break;
	case 3:
		strcpy(array[posicion2].idTipo.descripcion, "GANANCIAS");
		array[posicion2].idTipo.isEmpty = 0;
		break;
	}

	printf("Ingrese importe: ");
	scanf("%f", &array[posicion2].importe);

	array[posicion2].isEmpty = 0;

	printf("\nAlta efectuada\n");
	printf("Id Recaudacion: %d\n", array[posicion2].idRecaudacion);
	printf("Id Contribuyente: %d\n", array[posicion2].idContribuyente);
	printf("Mes: %d\n", array[posicion2].mes);
	printf("Tipo: %d-%s\n", array[posicion2].idTipo.idTipo,
			array[posicion2].idTipo.descripcion);
	printf("Importe: %.2f\n", array[posicion2].importe);

	return 0;
}

int buscarPorIdTipo(eRecaudacion array[], int tam, int id) {
	int rtn = -1;
	int i;

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].idTipo.idTipo == id && array[i].idTipo.isEmpty == 0) {
				rtn = i;
				//break;
			}
		}
	}
	return rtn;
}

int mostrarRecaudacionPorIdTipo(eRecaudacion array[], int tam) {

	int rtn = 0;
	int idTipo;
	int posicion;

	printf("Ingrese el id del tipo (1-ARBA, 2-IIBB, 3-GANANCIAS): ");
	scanf("%d", &idTipo);
	while (idTipo < 1 || idTipo > 3) {
		printf("Error. Ingrese un Id de tipo entre (1-3): ");
		scanf("%d", &idTipo);
	}

	while (buscarPorIdTipo(array, tam, idTipo) == -1) {
		printf("No existe el id ingresado, reingrese id de tipo: ");
		scanf("%d", &idTipo);
	}


	posicion = buscarPorIdTipo(array, tam, idTipo);
	listarUnaRecaudacionPorId(array[posicion]);


	rtn = 1;
	return rtn;
}



/*
void listarUnaRecaudacion2(eRecaudacion array, eContribuyente array2) {

	printf("%10d%10d%15d%13s%12.2f%13s%13s%13s\n", array.idContribuyente,
			array.idRecaudacion, array.mes, array.idTipo.descripcion,
			array.importe, array.idEstado.descripcion, array2.cuil, array2.nombre);

	return;
}

int mostrarRecaudacionesSaldadas(eRecaudacion array[], int tam) {
	int i;
	int rtn = 0;


	printf("\n\t> LISTADO DE RECAUDACIONES\n");
	printf("%15s%15s%7s%10s%13s%13s%13s%13s\n", "IdCONTRIBUYENTE", "IdRECAUDACION", "MES",
			"TIPO", "IMPORTE", "ESTADO", "CUIL", "NOMBRE");

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].idEstado.idEstado == 2 && array[i].idEstado.isEmpty == 0) {
				listarUnaRecaudacion2(array[i]);
				rtn++;
			}
		}

	}
	return rtn;
}
*/
