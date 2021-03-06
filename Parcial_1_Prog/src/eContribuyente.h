/*
 * eContribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: eduar
 */
#ifndef ECONTRIBUYENTE_H_
#define ECONTRIBUYENTE_H_
#include "eRecaudacion.h"

typedef struct {
	int idContribuyente;
	char nombre[15];
	char apellido[15];
	char cuil[12];
	int isEmpty;
} eContribuyente;

void eContribuyente_Inicializar(eContribuyente array[], int TAM);
int buscarLibre(eContribuyente array[], int *posicion, int tam);
int altaContribuyente(eContribuyente array[], int posicion, int *contadorId);
int buscarContribuyente(eContribuyente array[], int tam, int id);
eContribuyente modificarUnContribuyente(eContribuyente array);
int modificarContribuyente(eContribuyente array[], int tam);
int bajaContribuyente(eContribuyente array[], int tam, int id);
void mostrarUnContribuyente(eContribuyente array);
void listarUnContribuyente(eContribuyente array, eRecaudacion array2);
int mostrarContribuyentes(eContribuyente array[], eRecaudacion array2[], int tam);

#endif /* ECONTRIBUYENTE_H_ */
