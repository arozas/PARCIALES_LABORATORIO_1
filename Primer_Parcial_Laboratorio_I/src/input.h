/*
 * Input.h
 *
 *  Created on: 1 abr. 2022
 *      Author: Alejandro Alberto Martín Rozas
 *      Biblioteca de funciones de entrada.
 *      Versión 0.4 del 14 de abril de 2022
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

int input_getIntNoRange(char mensaje[], int reintentos, char mensajeError[], int aNumeroingresado[]);
int input_getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroingresado);
int input_getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado);
int input_getChar(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], char *pCaracteringresado);
int input_getString(char mensaje[], int reintentos, char mensajeError[], char aStringIngresado[], int lenght);
int input_getStringletters(char mensaje[], int reintentos, char mensajeError[], char aStringIngresado[], int lenght);
int input_getAlphaNumericString(char mensaje[], int reintentos, char mensajeError[], char aStringIngresado[], int lenght);
int input_getEmail(char mensaje[], int reintentos, char mensajeError[], char aStringIngresado[], int length);

#endif /* INPUT_H_ */
