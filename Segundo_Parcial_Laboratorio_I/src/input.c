/*
 * input.c
 *
 *  Created on: 1 abr. 2022
 *      Author: Alejandro Alberto Martín Rozas
 *      Biblioteca de funciones de entrada.
 *      Versión 0.4 del 14 de abril de 2022
 */
#include "input.h"
#include "menu.h"

//********************************************************************  STATICS FUNCTIONS  ********************************************************************
static int itsInteger(char aPossibleInteger[], int length);
static int itsFloat(char aPossibleFloat[], int length);
static int itsLetters(char aPossibleFloat[], int length);
static int itsAlphaNumeric(char aPossibleAlpha[], int length);
static int myGets(char aUserInputs[], int length);
static int getInt(int *pAuxNumber);
static int getFloat(float *pAuxNumber);

//********************************************************************     VALIDATIONS     ********************************************************************

static int itsInteger(char aPossibleInteger[], int length)
{
	/// @fn int itsInteger(char[], int)
	/// @brief checks that a number is an integer within the established range.
	///
	/// @param aPossibleInteger Array with the string to be verified.
	/// @param length Integer defines the length of the array to be verified.
	/// @return returns 0 if the string is an integer, returns -1 if it cannot validate, returns - 2 if it is not an integer.

	int rtn = -1;
	int i = 0;

	if(aPossibleInteger != NULL && length > 0)
	{
		rtn = 0;
		if (aPossibleInteger[0] == '-' || aPossibleInteger[0] == '+' )
		{
			i = 1;
		}
		while(aPossibleInteger[i] != '\0')
		{
			if(aPossibleInteger[i] < '0' || aPossibleInteger[i] > '9' )
			{
				rtn = -2;
				break;
			}
			i++;
		}
	}
	return rtn;
}
static int itsFloat(char aPossibleFloat[], int length)
{
	/// @fn int itsFloat(char[], int)
	/// @brief checks that a number is a Float within the established range.
	///
	/// @param aPossibleFloat Array with the string to be verified.
	/// @param length defines the length of the array to be verified.
	/// @return returns 0 if the string is a float, returns -1 if it cannot validate, returns - 2 if it is not a float.

	int rtn = -1;
	int dotCount = 0;
	int i = 0;


	if(aPossibleFloat != NULL && length > 0)
	{
		rtn = 0;
		if (aPossibleFloat[0] =='-' || aPossibleFloat[0]=='+')
		{
			i = 1;
		}
		while(aPossibleFloat[i] != '\0')
		{
			if (aPossibleFloat[i]== '.' && dotCount == 0)
			{
				dotCount++;
				i++;
				continue;
			}
			if(aPossibleFloat[i] < '0' || aPossibleFloat[i] > '9' )
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}

static int itsLetters(char aPossibleLetter[], int length)
{
	/// @fn int itsLetters(char[], int)
	/// @brief Checks that an input is a letter within the established range.
	///
	/// @param aPossibleLetter Array with the string to be verified.
	/// @param length Defines the length of the array to be verified.
	/// @return returns 0 if the string is a letter, returns -1 if it cannot validate, returns - 2 if it is not a letter.

	int rtn = -1;
	int i = 0;
	if(aPossibleLetter != NULL && length > 0)
	{
		rtn = 0;
		while(aPossibleLetter[i] != '\0')
		{
			if((aPossibleLetter[i] != ' ')
					&& (aPossibleLetter[i] < 'a' || aPossibleLetter[i] > 'z')
					&& (aPossibleLetter[i] < 'A' || aPossibleLetter[i] > 'Z'))
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}

static int itsAlphaNumeric(char aPossibleAlpha[], int length)
{
	/// @fn int itsAlphaNumeric(char[], int)
	/// @brief Checks that an input is Alphanumeric within the established range.
	///
	/// @param aPossibleAlpha Array with the string to be verified.
	/// @param length Defines the length of the array to be verified.
	/// @return returns 0 if the string is a letter, returns -1 if it cannot validate, returns - 2 if it is not a letter.

	int rtn = -1;
	int i = 0;
	if(aPossibleAlpha != NULL && length > 0)
	{
		rtn = 0;
		while(aPossibleAlpha[i] != '\0')
		{
			if((aPossibleAlpha[i] != ' ')
					&& (aPossibleAlpha[i] < 'a' || aPossibleAlpha[i] > 'z')
					&& (aPossibleAlpha[i] < 'A' || aPossibleAlpha[i] > 'Z')
					&& (aPossibleAlpha[i] < '0' || aPossibleAlpha[i] > '9'))
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}
//********************************************************************   END VALIDATIONS    ********************************************************************
//********************************************************************     VALIDATIONS NO STATICS   ********************************************************************
/// @fn int itsInteger(char[], int)
/// @brief checks that a number is an integer within the established range.
///
/// @param aPossibleInteger Array with the string to be verified.
/// @param length Integer defines the length of the array to be verified.
/// @return returns 0 if the string is an integer, returns -1 if it cannot validate, returns - 2 if it is not an integer.
int input_itsInteger(char aPossibleInteger[], int length)
{
	int rtn = -1;
	int i = 0;

	if(aPossibleInteger != NULL && length > 0)
	{
		rtn = 0;
		if (aPossibleInteger[0] == '-' || aPossibleInteger[0] == '+' )
		{
			i = 1;
		}
		while(aPossibleInteger[i] != '\0')
		{
			if(aPossibleInteger[i] < '0' || aPossibleInteger[i] > '9' )
			{
				rtn = -2;
				break;
			}
			i++;
		}
	}
	return rtn;
}
/// @fn int itsFloat(char[], int)
/// @brief checks that a number is a Float within the established range.
///
/// @param aPossibleFloat Array with the string to be verified.
/// @param length defines the length of the array to be verified.
/// @return returns 0 if the string is a float, returns -1 if it cannot validate, returns - 2 if it is not a float.
int input_itsFloat(char aPossibleFloat[], int length)
{
	int rtn = -1;
	int dotCount = 0;
	int i = 0;


	if(aPossibleFloat != NULL && length > 0)
	{
		rtn = 0;
		if (aPossibleFloat[0] =='-' || aPossibleFloat[0]=='+')
		{
			i = 1;
		}
		while(aPossibleFloat[i] != '\0')
		{
			if (aPossibleFloat[i]== '.' && dotCount == 0)
			{
				dotCount++;
				i++;
				continue;
			}
			if(aPossibleFloat[i] < '0' || aPossibleFloat[i] > '9' )
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}
/// @fn int itsLetters(char[], int)
/// @brief Checks that an input is a letter within the established range.
///
/// @param aPossibleLetter Array with the string to be verified.
/// @param length Defines the length of the array to be verified.
/// @return returns 0 if the string is a letter, returns -1 if it cannot validate, returns - 2 if it is not a letter.
int input_itsLetters(char aPossibleLetter[], int length)
{
	int rtn = -1;
	int i = 0;
	if(aPossibleLetter != NULL && length > 0)
	{
		rtn = 0;
		while(aPossibleLetter[i] != '\0')
		{
			if((aPossibleLetter[i] != ' ')
					&& (aPossibleLetter[i] < 'a' || aPossibleLetter[i] > 'z')
					&& (aPossibleLetter[i] < 'A' || aPossibleLetter[i] > 'Z'))
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}
/// @fn int itsAlphaNumeric(char[], int)
/// @brief Checks that an input is Alphanumeric within the established range.
///
/// @param aPossibleAlpha Array with the string to be verified.
/// @param length Defines the length of the array to be verified.
/// @return returns 0 if the string is a letter, returns -1 if it cannot validate, returns - 2 if it is not a letter.
int input_itsAlphaNumeric(char aPossibleAlpha[], int length)
{
	int rtn = -1;
	int i = 0;
	if(aPossibleAlpha != NULL && length > 0)
	{
		rtn = 0;
		while(aPossibleAlpha[i] != '\0')
		{
			if((aPossibleAlpha[i] != ' ')
					&& (aPossibleAlpha[i] < 'a' || aPossibleAlpha[i] > 'z')
					&& (aPossibleAlpha[i] < 'A' || aPossibleAlpha[i] > 'Z')
					&& (aPossibleAlpha[i] < '0' || aPossibleAlpha[i] > '9'))
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}
/// @fn int itsAll(char[], int)
/// @brief Checks that an input is ASCII within the established range.
///
/// @param aPossibleAlpha Array with the string to be verified.
/// @param length Defines the length of the array to be verified.
/// @return returns 0 if the string is a letter, returns -1 if it cannot validate, returns - 2 if it is not a letter.
int input_itsAll(char aPossibleAlpha[], int length)
{
	int rtn = -1;
	int i = 0;
	if(aPossibleAlpha != NULL && length > 0)
	{
		rtn = 0;
		while(aPossibleAlpha[i] != '\0')
		{
			if((aPossibleAlpha[1] != ' ')
					&& (aPossibleAlpha[i] < 'a' || aPossibleAlpha[i] > 'z')
					&& (aPossibleAlpha[i] < 'A' || aPossibleAlpha[i] > 'Z')
					&& (aPossibleAlpha[i] < '0' || aPossibleAlpha[i] > '9')
					&& (aPossibleAlpha[i] < 32 || aPossibleAlpha[i] > 46))
			{
				rtn = -2; //ERROR FUERA DE RANGO
				break;
			}
			i++;
		}
	}
	return rtn;
}
//********************************************************************   END VALIDATIONS NO STATICS    ********************************************************************
static int myGets(char aUserInputs[], int length)
{
	/// @brief Get the user inputs from the stdin buffer.
	///
	/// @param aUserInputs Array with the string to be verified.
	/// @param length Defines the length of the array to be verified.
	/// @return returns 0 if ok, returns -1 if error.

	int rtn=-1;
	char auxArray[length];
	if(aUserInputs!=NULL && length > 0)
	{
		__fpurge(stdin);
		if(fgets(auxArray, sizeof(auxArray), stdin) != NULL)
		{
			if(auxArray[strnlen(auxArray, sizeof(auxArray))-1] == '\n')
			{
				auxArray[strnlen(auxArray, sizeof(auxArray))-1] = '\0';
			}
			if(strnlen(auxArray,sizeof(auxArray))<=length)
			{
				strncpy(aUserInputs,auxArray,length);
				rtn=0;
			}
		}
	}
	return rtn;

}
static int getInt(int* pAuxNumber)
{
	/// @brief Function that takes a data entered by a user and validates that it is an integer.
	///
	/// @param pAuxNumber Memory pointer that returns the entered integer.
	/// @return Returns 0 if ok, returns -1 if error.
	int rtn = -1;
	char auxNumber[12];
	if(pAuxNumber!= NULL)
	{
		if( myGets(auxNumber, 12) == 0 && itsInteger(auxNumber, sizeof(auxNumber)) == 0)
		{
			*pAuxNumber=atoi(auxNumber);
			rtn=0;
		}
	}
	return rtn;
}
static int getFloat(float *pAuxNumber)
{
	/// @brief Function that takes a data entered by a user and validates that it is a float.
	///
	/// @param pAuxNumber Memory pointer that returns the entered float.
	/// @return Returns 0 if ok, returns -1 if error
	int rtn = -1;
	char auxNumber[53];
	if( myGets(auxNumber, sizeof(auxNumber)) == 0 && itsFloat(auxNumber, sizeof(auxNumber)) == 0)
	{
		*pAuxNumber=atof(auxNumber);
		rtn=0;
	}
	return rtn;
}
//********************************************************************   END STATICS    ********************************************************************
/// @fn int input_getNumber(char[], int, int, int, char[], int*)
/// @brief 					Esta función solicita al usuario el ingreso de un entero validando el ingreso,
/// 						si no se encuentra entre los parametros vuelve a pedir el ingreso.
/// @param mensaje 			Es el mensaje que se le muestra al usuario para solicitar el numero.
/// @param reintentos 		Es la cantidad de reintentos que tendrá el usuario en el caso de que el dato ingresado no cumpla con los parametros.
/// @param minimo			Es el valor mínimo que puede ingresar el usuario.
/// @param maximo			Es el valor máximo que puede ingresar el usuario.
/// @param mensajeError		Es el mensaje de error que muestra la función si no pasó la validación el ingreso por el usuario.
/// @param pNumeroingresado	Es el puntero donde se guarda el valor ingresado por el usuario.
/// @return					El retorno devolvera -1 por si hay un error, 0 en el caso que la función no haya tenido errores.
int input_getIntNoRange(char mensaje[], int reintentos, char mensajeError[], int aNumeroingresado[])
{
	int rtn = -1;
	int auxiliarInt;
	int retornoGetInt;
	//
	if(mensaje != NULL
			&& mensajeError != NULL
			&& aNumeroingresado != NULL)
	{
		printf("\n\n%s", mensaje);
		retornoGetInt = getInt(&auxiliarInt);
		do
		{
			if(retornoGetInt == 0)
			{
				*aNumeroingresado = auxiliarInt;
				rtn = 0;
				break;
			}
			printf("\n\n%s", mensajeError);
			retornoGetInt = getInt(&auxiliarInt);
			reintentos--;
		}while(reintentos>=0);
	}
	return rtn;
}
/// @fn int input_getInt(char[], int, int, int, char[], int[])
/// @brief
///
/// @param mensaje
/// @param reintentos
/// @param minimo
/// @param maximo
/// @param mensajeError
/// @param aNumeroingresado
/// @return
int input_getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int aNumeroingresado[])
{
	int rtn = -1; //ERROR GETINT O FUERA DE RANGO
	int auxiliarInt; //buffer
	int retornoGetInt;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL
			&& minimo < maximo
			&& mensajeError != NULL
			&& aNumeroingresado != NULL)
	{
		printf("\n\n%s", mensaje);
		retornoGetInt = getInt(&auxiliarInt);
		do
		{
			if(retornoGetInt == 0 && auxiliarInt <= maximo && auxiliarInt >= minimo)
			{
				*aNumeroingresado = auxiliarInt;
				rtn = 0;
				break;
			}
			printf("\n\n%s", mensajeError);
			retornoGetInt = getInt(&auxiliarInt);
			reintentos--;
		}while(reintentos>=0);
	}
	return rtn;
}
/// @fn int input_getFloat(char[], int, int, int, char[], float*)
/// @brief 					Esta función solicita al usuario el ingreso de un decimal validando el ingreso,
/// 						si no se encuentra entre los parametros vuelve a pedir el ingreso.
/// @param mensaje 			Es el mensaje que se le muestra al usuario para solicitar el numero.
/// @param reintentos 		Es la cantidad de reintentos que tendrá el usuario en el caso de que el dato ingresado no cumpla con los parametros.
/// @param minimo			Es el valor mínimo que puede ingresar el usuario.
/// @param maximo			Es el valor máximo que puede ingresar el usuario.
/// @param mensajeError		Es el mensaje de error que muestra la función si no pasó la validación el ingreso por el usuario.
/// @param pNumeroingresado	Es el puntero donde se guarda el valor ingresado por el usuario.
/// @return					El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int input_getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado)
{
	int rtn = -1;
	float auxiliarFloat;
	int retornoGetFloat;
	if(mensaje != NULL
			&& minimo < maximo
			&& mensajeError != NULL
			&& pNumeroingresado != NULL)
	{
		printf("\n\n%s", mensaje);
		retornoGetFloat = getFloat(&auxiliarFloat);
		do
		{
			if (retornoGetFloat == 0 && auxiliarFloat <= maximo && auxiliarFloat >= minimo)
			{
				*pNumeroingresado = auxiliarFloat;
				rtn = 0;
				break;
			}
			printf("\n\n%s", mensajeError);
			retornoGetFloat = getFloat(&auxiliarFloat);
			reintentos--;
		}while(reintentos>=0);
	}
	return rtn;
}
/// @fn int input_getStringletters(char[], int, char[], char[], int)
/// @brief
///
/// @pre
/// @post
/// @param mensaje
/// @param reintentos
/// @param mensajeError
/// @param aStringIngresado
/// @param length
/// @return
int input_getStringletters(char mensaje[], int reintentos, char mensajeError[], char aStringIngresado[], int length)
{
	int rtn = -1;
	char aAuxString[length];
	int retornoGetString;
	if(mensaje != NULL
			&& mensajeError != NULL
			&& aStringIngresado != NULL
			&& length > 0)
	{
		printf("\n\n%s", mensaje);
		__fpurge(stdin);
		retornoGetString = myGets(aAuxString, sizeof(aAuxString));
		do
		{
			if (retornoGetString == 0 && strlen(aAuxString) <= length && itsLetters(aAuxString, sizeof(aAuxString)) == 0)
			{
				__fpurge(stdin);
				strncpy(aStringIngresado,aAuxString,strnlen(aAuxString,sizeof(aAuxString))+1);
				rtn = 0;
				break;
			}
			printf("\n\n%s", mensajeError);
			__fpurge(stdin);
			retornoGetString = myGets(aAuxString, sizeof(aAuxString));;
			reintentos--;

		}while(reintentos>=0);
	}
	return rtn;
}
/// @fn int input_getAlphaNumericString(char[], int, char[], char[], int)
/// @brief
///
/// @pre
/// @post
/// @param mensaje
/// @param reintentos
/// @param mensajeError
/// @param aStringIngresado
/// @param length
/// @return
int input_getAlphaNumericString(char mensaje[], int reintentos, char mensajeError[], char* aStringIngresado, int length)
{
	int rtn = -1; //ERROR getfloat O FUERA DE RANGO
	char aAuxString[length]; //buffer
	int retornoGetString;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL
			&& mensajeError != NULL
			&& aStringIngresado != NULL
			&& length > 0)
	{
		printf("\n\n%s", mensaje);
		__fpurge(stdin);
		retornoGetString = myGets(aAuxString, sizeof(aAuxString));
		do
		{
			if (retornoGetString == 0 && strlen(aAuxString) <= length && itsAlphaNumeric(aAuxString, sizeof(aAuxString)) == 0)
			{
				strncpy(aStringIngresado,aAuxString,strlen(aAuxString)+1);
				rtn = 0;
				break;
			}
			printf("\n\n%s", mensajeError);
			__fpurge(stdin);
			retornoGetString = myGets(aAuxString, sizeof(aAuxString));;
			reintentos--;
		}while(reintentos>=0);
	}
	return rtn;
}
/// @fn int input_getChar(char[], int, char, char, char[], char*)
/// @brief						Esta función solicita al usuario el ingreso de un carácter validando el ingreso,
///								si no se encuentra entre los parametros vuelve a pedir el ingreso.
/// @param mensaje				Es el mensaje que se le muestra al usuario para solicitar el carácter.
/// @param reintentos			Es la cantidad de reintentos que tendrá el usuario en el caso de que el dato ingresado no cumpla con los parametros.
/// @param minimo				Es el valor mínimo (ASCII) que puede ingresar el usuario.
/// @param maximo				Es el valor máximo (ASCII) que puede ingresar el usuario.
/// @param mensajeError			Es el mensaje de error que muestra la función si no pasó la validación el ingreso por el usuario.
/// @param pCaracteringresado	Es el puntero donde se guarda el valor ingresado por el usuario.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int input_getChar(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], char *pCaracteringresado)
{
	int rtn = -1;
	char auxiliarChar; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL
			&& minimo < maximo
			&& mensajeError != NULL
			&& pCaracteringresado != NULL
			&& reintentos >= 0)
	{
		printf("\n\n%s", mensaje);
		retornoScanf = scanf("%c", &auxiliarChar);
		do
		{
			if (retornoScanf == 1 && auxiliarChar <= maximo && auxiliarChar >= minimo)
			{
				*pCaracteringresado = auxiliarChar;
				rtn = 0;
				break;
			}
			printf("\n\n%s", mensajeError);
			__fpurge(stdin);
			retornoScanf = scanf("%c", &auxiliarChar);
			reintentos--;
		}while(reintentos>=0);
	}
	return rtn;
}
/// @fn int input_setFileName(char*, int)
/// @brief
///
/// @param path
/// @param lengNombre
/// @return
int input_setFileName(char* path,int lengNombre)
{
	{
		int ret = -1;
		int fileType;
		if(	input_getAlphaNumericString("NOMBRE DEL ARCHIVO:", 3, "ERROR. INGRESE UN NOMBRE VALIDO:", path, lengNombre) == 0)
		{
			strcat(path,".");
			fileType=menu_menu("ELIJA LA EXTENSIÓN DEL ARCHIVO",
					"\n1 - EXTENSION .CSV"
					"\n1 - EXTENSION .BIN"
					"\n1 - EXTENSION .TXT",
					"ERROR, INGRESE OPCIÓN <1-3>:",
					3,
					3);
			switch (fileType)
			{
			case 1:
				strcat(path,"csv");
				ret = 0;
				break;
			case 2:
				strcat(path,"bin");
				ret = 0;
				break;
			case 3:
				strcat(path,"txt");
				ret = 0;
				break;
			default:
				printf("\n¡ERROR! "
						"\nVERIFIQUE QUE ESTA SELECCIONANDO "
						"\nUNA OPCIÓN DEL MENU");
				break;
			}
		}
		return ret;
	}
}

