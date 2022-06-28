/*
 * menu.h
 *
 *  Created on: 1 abr. 2022
 *  Author: Alejandro Alberto Martín Rozas  - División H.
 *  Biblioteca de validaciones.
 *  Versión 1.0 del 10 de Mayo de 2022
 */

#ifndef MENU_H_
#define MENU_H_
// *************************************** YES/NO DEFINE **************************************
#define MENU_MINIMUN 1
// *************************************** YES/NO DEFINE **************************************
#define YES 1
#define NO 0

#include "input.h"

int menu_menu(char menuTitle[], char menuText[], char errorMessages[],int retries, int numberOptions);
int menu_confirm(char message[], char errorMessage[]);

#endif /* MENU_H_ */
