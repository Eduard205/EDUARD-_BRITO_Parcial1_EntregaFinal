/*
 * eContribuyente.c
 *
 *  Created on: 13 may. 2021
 *      Author: eduar
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eContribuyente.h"
#include "eRecaudacion.h"

void eContribuyente_Inicializar(eContribuyente array[], int TAM) {
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = 1;
			array[i].idContribuyente = 0;
			strcpy(array[i].nombre, " ");
			strcpy(array[i].apellido, " ");
			strcpy(array[i].cuil, " ");
		}
	}
	return;
}

int buscarLibre(eContribuyente array[], int *posicion, int tam) {

	int rtn = -1;
	if (array != NULL && posicion != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (array[i].isEmpty == 1) {
				*posicion = i;
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int altaContribuyente(eContribuyente array[], int posicion, int *contadorId) {

	array[posicion].idContribuyente = *contadorId;

	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(array[posicion].nombre);

	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(array[posicion].apellido);

	printf("Ingrese CUIL: ");
	fflush(stdin);
	gets(array[posicion].cuil);

	array[posicion].isEmpty = 0;

	printf("\nAlta efectuada\n");
	printf("Id Contribuyente: %d\n", array[posicion].idContribuyente);
	printf("Nombre: %s\n", array[posicion].nombre);
	printf("Apellido: %s\n", array[posicion].apellido);
	printf("CUIL: %s\n", array[posicion].cuil);

	return 0;
}

int buscarContribuyente(eContribuyente array[], int tam, int id) {
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

eContribuyente modificarUnContribuyente(eContribuyente array) {

	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(array.nombre);

	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(array.apellido);

	printf("Ingrese CUIL: ");
	gets(array.cuil);

	eContribuyente arrayAux = array;

	return arrayAux;
}

int modificarContribuyente(eContribuyente array[], int tam) {

	int rtn = 0;
	int posicion;
	int idContribuyente;
	eContribuyente arrayAux;

	printf("Ingrese el id del contribuyente a modificar: ");
	scanf("%d", &idContribuyente);
	while (idContribuyente < 1000 || idContribuyente > 1050) {
		printf("Error. Ingrese un Id de contribuyente entre (1000-1050): ");
		scanf("%d", &idContribuyente);
	}

	while (buscarContribuyente(array, tam, idContribuyente) == -1) {
		printf("No existe el id ingresado, reingrese id del contribuyente: ");
		scanf("%d", &idContribuyente);
	}

	posicion = buscarContribuyente(array, tam, idContribuyente);

	arrayAux = modificarUnContribuyente(array[posicion]);

	array[posicion] = arrayAux;

	rtn = 1;
	if (rtn == 1) {
		printf("Se modifico los datos del contribuyente\n");
		printf("Nuevo Nombre: %s\n", array[posicion].nombre);
		printf("Nuevo Apellido: %s\n", array[posicion].apellido);
		printf("Nuevo CUIL: %s\n", array[posicion].cuil);
	}

	return rtn;
}

int bajaContribuyente(eContribuyente array[], int tam, int id) {

	int rtn = 0;
	int posicion;

	while (buscarContribuyente(array, tam, id) == -1) {
		printf("No existe el id ingresado, reingrese id del contribuyente: ");
		scanf("%d", &id);
	}

	posicion = buscarContribuyente(array, tam, id);

	array[posicion].isEmpty = -1;

	rtn = 1;

	if (rtn == 1) {
		printf("Se elimino al contribuyente y sus recaudaciones con el id %d\n",
				array[posicion].idContribuyente);
		printf("Nombre: %s\n", array[posicion].nombre);
		printf("Apellido: %s\n", array[posicion].apellido);
		printf("CUIL: %s\n", array[posicion].cuil);
	}

	return rtn;
}

void mostrarUnContribuyente(eContribuyente array) {

	printf("%5d%10s%10s%7s\n", array.idContribuyente, array.nombre,
			array.apellido, array.cuil);

	return;
}

void listarUnContribuyente(eContribuyente array, eRecaudacion array2) {

	printf("%13d%10s%10s%15s%11d%13s%13s%7d%13.2f\n", array.idContribuyente,
			array.nombre, array.apellido, array.cuil, array2.idRecaudacion,
			array2.idTipo.descripcion, array2.idEstado.descripcion, array2.mes,
			array2.importe);

	return;
}

int mostrarContribuyentes(eContribuyente array[], eRecaudacion array2[],
		int tam) {
	int i;
	int rtn = 0;

	printf("\n\t> LISTADO DE CONTRIBUYENTES\n");
	printf("%13s%9s%10s%10s%17s%11s%11s%8s%12s\n", "IdCONTRIBUYENTE", "NOMBRE", "APELLIDO", "CUIL", "IdRECAUDACION", "TIPO", "ESTADO", "MES", "IMPORTE");

	if (array != NULL && array2 != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].isEmpty == 0 && array2[i].isEmpty == 0) {
				listarUnContribuyente(array[i], array2[i]);
				rtn++;
			}
		}
	}
	return rtn;
}
