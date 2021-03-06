/*
 * eRecaudacion.h
 *
 *  Created on: 13 may. 2021
 *      Author: eduar
 */

#ifndef ERECAUDACION_H_
#define ERECAUDACION_H_
#define TEXT_SIZE 20
//#include "eContribuyente.h"

typedef struct {
	int idTipo;
	char descripcion[TEXT_SIZE];
	int isEmpty;
} eDescripTipoRecaudacion;

typedef struct {
	int idEstado;
	char descripcion[TEXT_SIZE];
	int isEmpty;
} eEstado;

typedef struct {
	int idRecaudacion;
	int idContribuyente;
	eDescripTipoRecaudacion idTipo;
	eEstado idEstado;
	int mes;
	float importe;
	int isEmpty;
} eRecaudacion;


void eRecaudacion_Inicializar(eRecaudacion array[], int TAM);
int buscarRecaudacion(eRecaudacion array[], int tam, int id);
int mostrarUnaRecaudacion(eRecaudacion array[], int tam);
int mostrarRecaudaciones(eRecaudacion array[], int id, int tam);
void listarUnaRecaudacion(eRecaudacion array);
void listarUnaRecaudacionPorId(eRecaudacion array);
int buscarLibre2(eRecaudacion array[], int *posicion2, int tam);
int altaRecaudacion(eRecaudacion array[], int posicion2, int *contadorId2);
int bajaRecaudacion(eRecaudacion array[], int tam, int id);
int buscarPorIdRecaudacion(eRecaudacion array[], int tam, int id);
int mostrarPorIdRecaudacion(eRecaudacion array[], int tam);
void cambiarEstadoRefinanciar(eRecaudacion array[], int tam, int idRecaudacion);
void cambiarEstadoSaldar(eRecaudacion array[], int tam, int idRecaudacion);
int buscarPorIdTipo(eRecaudacion array[], int tam, int id);
int mostrarRecaudacionPorIdTipo(eRecaudacion array[], int tam);

//void listarUnaRecaudacion2(eRecaudacion array, eContribuyente array2);
//int mostrarRecaudacionesSaldadas(eRecaudacion array[], int tam);

#endif /* ERECAUDACION_H_ */
