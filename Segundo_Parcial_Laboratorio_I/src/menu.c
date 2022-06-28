/*
 * menu.c
 *
 *  Created on: 1 abr. 2022
 *  Author: Alejandro Alberto Martín Rozas  - División H.
 *  Biblioteca de validaciones.
 *  Versión 1.0 del 10 de Mayo de 2022
 */

#include "menu.h"
#include "input.h"

/// @fn int menu_menu(char[], char[], char[], int, int)
/// @brief Print a menu with options.
///
/// @param menuTitle String with the menu title.
/// @param menuText String with the menu options.
/// @param errorMessages String with error message.
/// @param retries Retries.
/// @param numberOptions Number of menu options.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - Option entered by the user  if Ok.
int menu_menu(char menuTitle[], char menuText[], char errorMessages[],int retries, int numberOptions)
{
	int rtn = -1;
	int getIntValid;
	int option;

	if(menuTitle != NULL
			&& menuText != NULL
			&& retries > 0
			&& numberOptions > 0)
	{
		printf("\n\t\t\t%s", menuTitle);
		printf("%s", menuText);
		getIntValid=input_getInt("INGRESE UNA OPCIÓN:", retries, MENU_MINIMUN, numberOptions, errorMessages, &option);
		if(getIntValid!=-1)
		{
			rtn=option;
		}
	}
	return rtn;
}
/// @fn int menu_confirm(char[], char[])
/// @brief Confirmation function, ask a yes or no question.
///
/// @param message String with message or question.
/// @param errorMessage String with error message.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - return 1 for yes 0 for no if Ok.
int menu_confirm(char message[], char errorMessage[])
{
	int rtn = -1;
	char buffer;
	int rtnGetChar;

	if(message != NULL && errorMessage != NULL)
	{
		__fpurge(stdin);
		rtnGetChar=input_getChar(message, 3, 'N', 'S', errorMessage, &buffer);

		if (rtnGetChar==0)
		{
			if(buffer == 'S')
			{
				rtn = YES;
			}
			else
			{
				if (buffer == 'N')
				{
					rtn = NO;
				}
			}
		}

	}
	return rtn;
}


