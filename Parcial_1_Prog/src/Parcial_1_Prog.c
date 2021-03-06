/*
 ============================================================================
 Name        : Parcial_1_Prog.c
 Author      : Eduard Brito Hernandez - Divisi?n: 1-E
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eRecaudacion.h"
#include "eContribuyente.h"
#define TAM_ARRAY 50

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	char resp = 's';
	eContribuyente listaContribuyentes[TAM_ARRAY];
	eRecaudacion listaRecaudaciones[TAM_ARRAY];
	int posicion;
	int posicion2;
	int contadorId = 1000;
	int contadorId2 = 100;
	int flagOpcion1 = 0;
	int flagOpcion4 = 0;
	int idContribuyente;
	int idRecaudacion;

	eContribuyente_Inicializar(listaContribuyentes, TAM_ARRAY);
	eRecaudacion_Inicializar(listaRecaudaciones, TAM_ARRAY);

	do {
		printf("\nIngrese una opcion del menu:"
				"\n1-Alta de contribuyente"
				"\n2-Modificar datos del contribuyente"
				"\n3-Baja de contribuyente"
				"\n4-Recaudacion"
				"\n5-Refinanciar Recaudacion"
				"\n6-Saldar Recaudacion"
				"\n7-Imprimir Contribuyente"
				"\n8-Imprimir Recaudacion"
				"\n9-Informes"
				"\n10-Salir\n");
		scanf("%d", &opcion);

		while (opcion < 1 || opcion > 10) {
			printf(
					"Ingreso una opci?n invalida, las opciones disponibles son (1, 2, 3, 4, 5, 6, 7, 8, 9): ");
			scanf("%d", &opcion);
		}

		switch (opcion) {

		case 1:
			if (buscarLibre(listaContribuyentes, &posicion, TAM_ARRAY) != -1) {
				altaContribuyente(listaContribuyentes, posicion, &contadorId);
				contadorId++;
				flagOpcion1 = 1;
			} else {
				printf(
						"No se proceso el alta del contribuyente, ingrese nuevamente a la opci?n 1");
			}
			break;

		case 2:
			if (flagOpcion1 == 1) {
				modificarContribuyente(listaContribuyentes, TAM_ARRAY);
			} else {
				printf(
						"No ha dado de alta contribuyentes, ingrese a la opci?n 1");
			}

			break;

		case 3:
			if (flagOpcion1 == 1) {

				mostrarUnaRecaudacion(listaRecaudaciones, TAM_ARRAY);
				printf(
						"Si esta seguro de eliminar el contribuyente reingrese el id: ");
				scanf("%d", &idContribuyente);

				while (idContribuyente < 1000 || idContribuyente > 1050) {
					printf(
							"Error. Ingrese un Id de contribuyente entre (1000-1050): ");
					scanf("%d", &idContribuyente);
				}
				bajaRecaudacion(listaRecaudaciones, TAM_ARRAY, idContribuyente);
				bajaContribuyente(listaContribuyentes, TAM_ARRAY,
						idContribuyente);
			} else {
				printf(
						"No ha dado de alta contribuyentes, ingrese a la opci?n 1");
			}
			break;

		case 4:
			if (flagOpcion1 == 1) {

				if (buscarLibre2(listaRecaudaciones, &posicion2, TAM_ARRAY)
						!= -1) {

					altaRecaudacion(listaRecaudaciones, posicion2,
							&contadorId2);
					contadorId2++;
					flagOpcion4 = 1;
				}

				else {
					printf(
							"No hay espacio en memoria para ingresar mas recaudaciones\n");
				}
			}

			else {
				printf(
						"No ha dado de alta contribuyentes, ingrese a la opci?n 1");
			}

			break;

		case 5:
			if (flagOpcion4 == 1) {
				mostrarPorIdRecaudacion(listaRecaudaciones, TAM_ARRAY);
				printf(
						"Si esta seguro de refinanciar la recaudacion reingrese el id: ");
				scanf("%d", &idRecaudacion);

				while (idRecaudacion < 100 || idRecaudacion > 150) {
					printf(
							"Error. Ingrese un Id de recaudacion entre (100-150): ");
					scanf("%d", &idRecaudacion);
				}
				cambiarEstadoRefinanciar(listaRecaudaciones, TAM_ARRAY,
						idRecaudacion);
				printf("La recaudacion fue refinanciada");

			} else {
				printf(
						"No ha dado de alta recaudaciones, ingrese a la opci?n 4");
			}
			break;

		case 6:
			if (flagOpcion4 == 1) {
				mostrarPorIdRecaudacion(listaRecaudaciones, TAM_ARRAY);
				printf(
						"Si esta seguro de saldar la recaudacion reingrese el id: ");
				scanf("%d", &idRecaudacion);

				while (idRecaudacion < 100 || idRecaudacion > 150) {
					printf(
							"Error. Ingrese un Id de recaudacion entre (100-150): ");
					scanf("%d", &idRecaudacion);
				}
				cambiarEstadoSaldar(listaRecaudaciones, TAM_ARRAY,
						idRecaudacion);
				printf("La recaudacion fue saldada");
			} else {
				printf(
						"No ha dado de alta recaudaciones, ingrese a la opci?n 4");
			}
			break;

		case 7:
			if (flagOpcion1 == 1) {
				mostrarContribuyentes(listaContribuyentes, listaRecaudaciones,
						TAM_ARRAY);
			} else {
				printf(
						"No ha dado de alta contribuyentes, ingrese a la opci?n 1");
			}

			break;

		case 9:
			if (flagOpcion4 == 1) {
				mostrarRecaudacionPorIdTipo(listaRecaudaciones, TAM_ARRAY);
			} else {
				printf(
						"No ha dado de alta recaudaciones, ingrese a la opci?n 4");
			}

			break;

		case 10:
			printf("A salido del programa");
			resp = !'s';
			break;

		}
	} while (resp == 's');

	return EXIT_SUCCESS;
}
