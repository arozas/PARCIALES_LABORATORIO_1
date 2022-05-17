/*
 * eTracking.c
 *
 *  Created on: 30 abr. 2022
 *      Author: alejandro
 */
#include "eTracking.h"

#include "input.h"
#include "menu.h"


static int idAutoincremental = ID_INIT_VALUE;
int eTracking_getUniqueID()
{
	return idAutoincremental++;
}
int eTracking_init(eTracking eTrackingList[], int length)
{
	int rtn = -1;
	int i;

	if (eTrackingList != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				eTrackingList[i].isEmpty = TRUE;
			}
		}
	}
	return rtn;
}

void eTracking_printOne(eTracking toPrintStruc)
{
	printf(	"\n------------------------------------------------------------------------------------------|");
	printf(
			"\n%-6d%-6d%-15d%-15d",
			toPrintStruc.trackingId,
			toPrintStruc.productId,
			toPrintStruc.amount,
			toPrintStruc.distanceKM);
	//NEED TO BE COMPLETED WITH THE OTHERS ENTETY ATRIBUTES
}
int eTracking_printAll(eTracking toPrintStruc[], int length, int status)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				if (toPrintStruc[i].isEmpty == status)
				{
					eTracking_printOne(toPrintStruc[i]);
				}
			}
		}
	}
	return rtn;
}
int eTracking_searchEmptyIndex(eTracking toSearchStruc[], int length)
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
int eTracking_searchIndexId(eTracking toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;
	int searchId;

	if (toSearchStruc != NULL) {
		if (length > 0) {
			//ESTA OK

			//MUESTRO TODOS - Le muestro al usuario todos los dados de alta para que elija cual ID dar de baja
			eTracking_printAll(toSearchStruc, length, FALSE);

			//PEDIR UN ID
			input_getInt("INGRESE ID: ", 1 , ID_INIT_VALUE, ID_INIT_VALUE + length, "ERROR, VUELVA A INGRESAR ID:", &searchId);

			for (i = 0; i < length; i++) {
				if (toSearchStruc[i].isEmpty == FALSE) {
					if (toSearchStruc[i].trackingId == searchId) {
						flag = 1;
						rtn = i; //retorno index del ID que estoy buscando
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
int eTracking_searchId(eTracking toSearchStruc[], int length, int searchId)
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
					if (toSearchStruc[i].trackingId == searchId) {
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
int eTracking_register(eTracking *trackingList)
{
	int rtn=-1;
	//eTracking eTrackingBuffer;

	/* EXAMPLE*/
	//Need to declare all struct attributes and register
	//input_getStringletters("INGRESE DATO STRING:", 2, "ERROR", eTrackingBuffer.exampleChar, MAX_LENGHT_CHAR);
	//input_getInt("INGRESE DATO INT:", 2, 0, 1000, "ERROR", &eTrackingBuffer.exampleInt );
	//input_getFloat("INGRESE DATO FLOAT:", 2, 0, 1000, "ERROR", &eTrackingBuffer.exampleFloat);

	return rtn;
}

int eTracking_registerArray(eTracking toRegisterStruc[], int length)
{
	int rtn = -1;
	int emptyIndex;
	eTracking eTrackingBuffer;

	//VA A RETORNAR UN INDEX LIBRE SI ENCONTRO O -1 SI NO LO ENCONTRO.
	emptyIndex = eTracking_searchEmptyIndex(toRegisterStruc, length);

	if (toRegisterStruc != NULL) {
		if (length > 0) {
			if (emptyIndex >= 0) {
				//CARGO DATOS NO GENERICOS
				//eTrackingBuffer = eTracking_register();

				//SI ESTA TODO BIEN - LE DOY UN ID UNICO
				eTrackingBuffer.trackingId = eTracking_getUniqueID();
				//CAMBIO ESTADO A OCUPADO
				eTrackingBuffer.isEmpty = FALSE;
				if(menu_confirm("¿DESEA REALIZAR LA CARGA?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					//COPIA AUXILIAR EN ARRAY EN POSICION OBTENIDA LIBRE
					toRegisterStruc[emptyIndex] = eTrackingBuffer;
					rtn = emptyIndex;
				}
				else
				{	//CARGA CANCELADA.
					rtn= -5;
				}
			} else {
				// ARRAY LLENO
				rtn = -4;
			}
		} else {
			// LEN MAL DEFINIDO
			rtn = -3;
		}
	} else {
		// ARRAY NULO
		rtn = -2;
	}

	return rtn;
}
int eTracking_unRegisterArray(eTracking toUnRegisterStruc[], int length)
{
	int rtn = -1;
	int indexBaja;

	if (toUnRegisterStruc != NULL)
	{
		if (length > 0)
		{

			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			indexBaja = eTracking_searchIndexId(toUnRegisterStruc, length);
			if (indexBaja < 0)
			{
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -2;
			}
			else
			{
				eTracking_printOne(toUnRegisterStruc[indexBaja]);
				if(menu_confirm("¿DESEA REALIZAR LA BAJA?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					toUnRegisterStruc[indexBaja].isEmpty = TRUE;
					rtn=0;
				}
				else
				{	//SE CANCELÓ LA BAJA
					rtn=-5;
				}
			}

		} else {
			// LEN MAL DEFINIDO
			rtn = -3;
		}
	} else {
		// ARRAY NULO
		rtn = -4;
	}

	return rtn;
}
eTracking eTracking_ModifyOne(eTracking toMofiedStruc)
{
	int menu;
	do{
		menu = menu_menu("EJEMPLO MODIFICAR ENTIDAD",
				"\n\n1 - PROBAR MODIFICAR STRUCT CHAR."
				"\n2 - PROBAR MODIFICAR STRUCT INT."
				"\n3 - PROBAR MODIFICAR STRUCT FLOAT."
				"\n4 - DEJAR DE MODIFICAR.",
				"ERROR INGRESE UNA OPCIÓN <1-4>:", 2, 4);

		switch (menu)
		{
		case 1:
			//input_getStringletters("INGRESE DATO STRING", 2, "ERROR", toMofiedStruc.exampleChar, MAX_LENGHT_CHAR);
			break;
		case 2:
			//input_getInt("INGRESE DATO INT ", 2, 0, 100, "ERROR", &toMofiedStruc.exampleInt );
			break;
		case 3:
			//input_getFloat("INGRESE DATO FLOAT", 2, 0, 100, "ERROR", &toMofiedStruc.exampleFloat);
			break;
		}
	}while(menu<4);

	return toMofiedStruc;
}
int eTracking_ModifyArray(eTracking toMofiedStruc[], int length)
{
	int rtn = -1;
	int toModStrucIndex;
	eTracking eTrackingBuffer;

	if (toMofiedStruc != NULL)
	{
		if (length > 0)
		{
			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			toModStrucIndex = eTracking_searchIndexId(toMofiedStruc,
					length);
			if (toModStrucIndex < 0)
			{
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -2;
			}
			else
			{
				eTrackingBuffer = toMofiedStruc[toModStrucIndex];
				//MODIFICAR UN PRODUCTO
				eTrackingBuffer = eTracking_ModifyOne(eTrackingBuffer);
				if(menu_confirm("¿DESEA REALIZAR LA MODIFICACIÓN?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					toMofiedStruc[toModStrucIndex] = eTrackingBuffer;
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
int eTracking_Sort(eTracking array[], int TAM, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eTracking aux;

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
						if (array[i].trackingId > array[j].trackingId)
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
						if (array[i].trackingId < array[j].trackingId) {
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