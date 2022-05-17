/*
 * eUser.c
 *
 *  Created on: 30 abr. 2022
 *      Author: alejandro
 */
#include "eUser.h"

#include "input.h"
#include "menu.h"

int eUser_getUniqueID(void);
static int idAutoincremental = ID_INIT_VALUE;
int eUser_getUniqueID()
{
	return idAutoincremental++;
}
int eUser_init(eUser eUserList[], int length)
{
	int rtn = -1;
	int i;

	if (eUserList != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				eUserList[i].isEmpty = TRUE;
				eUserList[i].buyedProducts= 0;
				eUserList[i].selledProducts = 0;
				eUserList[i].currentMoney = 0;
				eUserList[i].spent = 0;
				eUserList[i].won = 0;
			}
		}
	}
	return rtn;
}

void eUser_printOne(eUser toPrintStruc)
{
	printf(	"\n--------------------------------------------------------------------------------------------------------------------------------------|");
	printf( //id //email
			"\n%-6d%-30s",
			toPrintStruc.id,
			toPrintStruc.email);
	switch(toPrintStruc.isEmpty)
	{
	case 1:		//Estado
		printf("%-10s", "VACIO");
		break;
	case 2:
		printf("%-10s", "CARGADO");
		break;
	}
	//distancia
	if(toPrintStruc.postalCode>8000)
	{
		printf("%-10s", "150km");
	}
	else
	{
		if(toPrintStruc.postalCode>5000)
		{
			printf("%-10s", "80km");
		}
		else
		{
			if(toPrintStruc.postalCode>3000)
			{
				printf("%-10s", "50km");
			}
			else
			{
				if(toPrintStruc.postalCode>1000)
				{
					printf("%-10s", "30km");
				}
				else
				{
					printf("%-10s", "20km");

				}
			}
		}
	}
	printf("%-10d",toPrintStruc.buyedProducts);
	printf("%-10d",toPrintStruc.selledProducts);
	printf("$%-12.2f",toPrintStruc.currentMoney);
	printf("$%-12.2f",toPrintStruc.spent);
	printf("$%-12.2f",toPrintStruc.won);
	printf(	"\n--------------------------------------------------------------------------------------------------------------------------------------|");
}
int eUser_printAll(eUser toPrintStruc[], int length, int status)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL)
	{
		if (length > 0)
		{
			printf(	"\n======================================================================================================================================|");
			printf("\n%-6s%-30s%-10s%-10s%-10s%-10s%-12s%-12s%-12s","ID", "EMAIL", "ESTADO", "Km","COMPRADO","VENDIDO","DINERO","GASTADO","GANADO");
			printf(	"\n======================================================================================================================================|");
			for (i = 0; i < length; i++)
			{
				if (toPrintStruc[i].isEmpty == status)
				{
					eUser_printOne(toPrintStruc[i]);
				}
			}
			printf(	"\n======================================================================================================================================|\n");
			rtn=0;
		}
	}
	return rtn;
}
int eUser_searchEmptyIndex(eUser toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;

	if (toSearchStruc != NULL) {
		if (length > 0) {
			//ESTA OK
			for (i = 0; i < length; i++) {
				if (toSearchStruc[i].isEmpty == TRUE)
				{
					flag = 1;
					rtn = i;
					break;
				}
			}

			if (flag == 0)
			{
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}
int eUser_searchIndexId(eUser toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;
	int searchId;

	if (toSearchStruc != NULL)
	{
		if (length > 0)
		{
			eUser_printAll(toSearchStruc, length, FALSE);
			input_getInt("INGRESE ID: ", 1 , ID_INIT_VALUE, ID_INIT_VALUE + length, "ERROR, VUELVA A INGRESAR ID:", &searchId);

			for (i = 0; i < length; i++) {
				if (toSearchStruc[i].isEmpty == FALSE) {
					if (toSearchStruc[i].id == searchId) {
						flag = 1;
						rtn = i;
						break;
					}
				}
			}

			if (flag == 0) {
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}
int eUser_searchId(eUser toSearchStruc[], int length, int searchId)
{
	int rtn = -1;
	int flag = 0;
	int i;

	if (toSearchStruc != NULL)
	{
		if (length > 0)
		{
			for (i = 0; i < length; i++) {
				if (toSearchStruc[i].isEmpty == FALSE) {
					if (toSearchStruc[i].id == searchId) {
						flag = 1;
						rtn = i;
						break;
					}
				}
			}

			if (flag == 0) {
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}
int eUser_searchEmail(eUser toSearchStruc[], int length, char mailInput[])
{
	int rtn = -1;
	int flag = 0;
	int i;

	if (toSearchStruc != NULL)
	{
		if (length > 0)
		{
			for (i = 0; i < length; i++)
			{
				if (toSearchStruc[i].isEmpty == FALSE)
				{
					if (strcmp(toSearchStruc[i].email,mailInput)==0)
					{
						flag = 1;
						rtn = i;
						break;
					}
				}
			}
			if (flag == 0)
			{
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}
int eUser_create(eUser *userList)
{

	int rtn=-1;
	eUser eUserBuffer;
	if(	input_getAlphaNumericString("INGRESE EN PASSWORD:", RETRIES, "ERROR, INGRESE EN PASSWORD VALIDO:", eUserBuffer.password, PASSWORD_LENGTH) == 0
			&& input_getAlphaNumericString("INGRESE SU DIRECCIÓN:", RETRIES, "ERROR, INGRESE UNA DIRECCIÓN VALIDO:", eUserBuffer.adress, ADRESS_LENGTH) == 0
			&& input_getInt("INGRESE SU CODIGO POSTAL:", RETRIES, 1, 9999,"ERROR, INGRESE UN CODIGO POSTAL VALIDO:" , &eUserBuffer.postalCode)==0)
	{
		switch(menu_confirm("COMO NUEVO USUARIO LE REGALAMOS $100.000 PESOS PARA SUS PRIMERAS COMPRAS."
				"\n¿DESEA ACREDITARLOS?"
				"\nINGRESE RESPUESTA <S/N>:", "ERROR, INGRESE <S/N>:"))
		{
		case 0:
			userList->currentMoney=0;
			printf("\nRECUERDE QUE DEBERÁ HACER UNA VENTA PARA ACREDITAR DINERO EN SU CUENTA");
			break;
		case 1:
			userList->currentMoney=100000;
			printf("\n¡SE HAN ACREDITADO $100.000 PESOS EN SU CUENTA!");
			break;
		}
		strncpy(userList->password,eUserBuffer.password,PASSWORD_LENGTH);
		strncpy(userList->adress,eUserBuffer.adress,ADRESS_LENGTH);
		userList->postalCode=eUserBuffer.postalCode;
		userList->buyedProducts=0;
		userList->selledProducts=0;
		userList->type= USER;

		rtn=0;
	}

	return rtn;
}
int eUser_unRegisterArray(eUser toUnRegisterStruc[], int length)
{
	int rtn = -1;
	int indexBaja;

	if (toUnRegisterStruc != NULL)
	{
		if (length > 0)
		{
			indexBaja = eUser_searchIndexId(toUnRegisterStruc, length);
			if (indexBaja < 0)
			{
				rtn = -2;
			}
			else
			{
				eUser_printOne(toUnRegisterStruc[indexBaja]);
				if(menu_confirm("¿DESEA REALIZAR LA BAJA?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					rtn=0;
				}
				else
				{
					rtn=-5;
				}
			}

		}
		else
		{
			rtn = -3;
		}
	}
	else
	{
		rtn = -4;
	}

	return rtn;
}
eUser eUser_ModifyOne(eUser toMofiedStruc)
{
	int menu;
	do{
		menu = menu_menu("SELECCIONE QUE MODIFICAR",
				"\n\n1 - MODIFICAR E-MAIL."
				"\n2 - MODIFICAR PASSWORD."
				"\n3 - MODIFICAR DIRECCIÓN."
				"\n4 - MODIFICAR CODIGO POSTAL.",
				"ERROR INGRESE UNA OPCIÓN <1-4>:", 2, 4);

		switch (menu)
		{
		case 1:
			input_getEmail("INGRESE SU EMAIL:", RETRIES, "ERROR, INGRESE UN EMAIL VALIDO:", toMofiedStruc.email, MAIL_LENGTH);
			break;
		case 2:
			input_getAlphaNumericString("INGRESE EL APELLIDO DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN APELLIDO VALIDO:", toMofiedStruc.password, PASSWORD_LENGTH);
			break;
		case 3:
			input_getAlphaNumericString("INGRESE EL APELLIDO DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN APELLIDO VALIDO:", toMofiedStruc.adress, ADRESS_LENGTH);
			break;
		case 4:
			input_getInt("INGRESE SU CODIGO POSTAL:", RETRIES, 1, 9999,"ERROR, INGRESE UN CODIGO POSTAL VALIDO:" , &toMofiedStruc.postalCode);
			break;
		}
	}while(menu<4);

	return toMofiedStruc;
}
int eUser_ModifyArray(eUser toMofiedStruc[], int length)
{
	int rtn = -1;
	int toModStrucIndex;
	eUser eUserBuffer;

	if (toMofiedStruc != NULL)
	{
		if (length > 0)
		{
			toModStrucIndex = eUser_searchIndexId(toMofiedStruc,
					length);
			if (toModStrucIndex < 0)
			{
				rtn = -2;
			}
			else
			{
				eUserBuffer = toMofiedStruc[toModStrucIndex];
				eUserBuffer = eUser_ModifyOne(eUserBuffer);
				if(menu_confirm("¿DESEA REALIZAR LA MODIFICACIÓN?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					toMofiedStruc[toModStrucIndex] = eUserBuffer;
					rtn=0;
				}
				else
				{	//CANCELO LA MODIFICACIÓN.
					rtn=-5;
				}

			}

		}
		else
		{
			// LEN MAL DEFINIDO
			rtn = -3;
		}
	}
	else
	{
		// ARRAY NULO
		rtn = -4;
	}

	return rtn;
}
int eUser_Sort(eUser array[], int TAM, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eUser aux;

	/* EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE  1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  2 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	 */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case 1:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j = i + 1; j < TAM; j++)
				{
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == FALSE
							&& array[j].isEmpty == FALSE)
					{
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id > array[j].id)
						{
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 2:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == FALSE
							&& array[j].isEmpty == FALSE) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id < array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}
/// @fn void eUser_ForceUsers(eUser[])
/// @brief Function that forces the loading of data in the arrays to be able to do tests.
///
/// @param userList Array with the list of users.
void eUser_ForceUsers(eUser userList[])
{
	eUser userBuffer[6];


	userBuffer[0].id=1010;
	userBuffer[0].isEmpty=FALSE;
	userBuffer[0].type=ADMIN;
	strcpy(userBuffer[0].email,"alejandro.rozas@gmail.com");
	strcpy(userBuffer[0].password,"prueba123");
	strcpy(userBuffer[0].adress,"Dirección 1234, Partido, Ciudad, País.");
	userBuffer[0].postalCode=9999;
	userBuffer[0].buyedProducts= 0;
	userBuffer[0].selledProducts = 0;
	userBuffer[0].currentMoney = 0;
	userBuffer[0].spent = 0;
	userBuffer[0].won = 0;

	userBuffer[1].id=1011;
	userBuffer[1].isEmpty=FALSE;
	userBuffer[1].type=USER;
	strcpy(userBuffer[1].email,"usuario1@gmail.com");
	strcpy(userBuffer[1].password,"prueba123");
	strcpy(userBuffer[1].adress,"Dirección 1234, Partido, Ciudad, País.");
	userBuffer[1].postalCode=0001;
	userBuffer[1].buyedProducts= 0;
	userBuffer[1].selledProducts = 0;
	userBuffer[1].currentMoney = 300000;
	userBuffer[1].spent = 0;
	userBuffer[1].won = 0;

	userBuffer[2].id=1012;
	userBuffer[2].isEmpty=FALSE;
	userBuffer[2].type=USER;
	strcpy(userBuffer[2].email,"usuario2@gmail.com");
	strcpy(userBuffer[2].password,"prueba123");
	strcpy(userBuffer[2].adress,"Dirección 1234, Partido, Ciudad, País.");
	userBuffer[2].postalCode=1001;
	userBuffer[2].buyedProducts= 0;
	userBuffer[2].selledProducts = 0;
	userBuffer[2].currentMoney = 300000;
	userBuffer[2].spent = 0;
	userBuffer[2].won = 0;

	userBuffer[3].id=1013;
	userBuffer[3].isEmpty=FALSE;
	userBuffer[3].type=USER;
	strcpy(userBuffer[3].email,"usuario3@gmail.com");
	strcpy(userBuffer[3].password,"prueba123");
	strcpy(userBuffer[3].adress,"Dirección 1234, Partido, Ciudad, País.");
	userBuffer[3].postalCode=3001;
	userBuffer[3].buyedProducts= 0;
	userBuffer[3].selledProducts = 0;
	userBuffer[3].currentMoney = 300000;
	userBuffer[3].spent = 0;
	userBuffer[3].won = 0;

	userBuffer[4].id=1014;
	userBuffer[4].isEmpty=FALSE;
	userBuffer[4].type=USER;
	strcpy(userBuffer[4].email,"usuario4@gmail.com");
	strcpy(userBuffer[4].password,"prueba123");
	strcpy(userBuffer[4].adress,"Dirección 1234, Partido, Ciudad, País.");
	userBuffer[4].postalCode=5001;
	userBuffer[4].buyedProducts= 0;
	userBuffer[4].selledProducts = 0;
	userBuffer[4].currentMoney = 300000;
	userBuffer[4].spent = 0;
	userBuffer[4].won = 0;

	userBuffer[5].id=1015;
	userBuffer[5].isEmpty=FALSE;
	userBuffer[5].type=USER;
	strcpy(userBuffer[5].email,"usuario5@gmail.com");
	strcpy(userBuffer[5].password,"prueba123");
	strcpy(userBuffer[5].adress,"Dirección 1234, Partido, Ciudad, País.");
	userBuffer[5].postalCode=8001;
	userBuffer[5].buyedProducts= 0;
	userBuffer[5].selledProducts = 0;
	userBuffer[5].currentMoney = 300000;
	userBuffer[5].spent = 0;
	userBuffer[5].won = 0;

	userList[10]=userBuffer[0];
	userList[11]=userBuffer[1];
	userList[12]=userBuffer[2];
	userList[13]=userBuffer[3];
	userList[14]=userBuffer[4];
	userList[15]=userBuffer[5];
}
