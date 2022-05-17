/*
 * eProduct.c
 *
 *  Created on: 30 abr. 2022
 *      Author: alejandro
 */
#include "eProduct.h"

#include "input.h"
#include "menu.h"

int eProduct_getUniqueID(void);
static int idAutoincremental = ID_INIT_VALUE;
int eProduct_getUniqueID()
{
	return idAutoincremental++;
}
int eProduct_init(eProduct eProductList[], int length)
{
	int rtn = -1;
	int i;

	if (eProductList != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				eProductList[i].isEmpty = TRUE;
			}
		}
	}
	return rtn;
}

void eProduct_printOne(eProduct toPrintStruc)
{
	printf(	"\n------------------------------------------------------------------------------------------|");
	printf(
			"\n%-6d%-25s$%-15.2f",
			toPrintStruc.id,
			toPrintStruc.productName,
			toPrintStruc.price);
	switch(toPrintStruc.category)
	{
	case TECHNOLOGY:
		printf("%-20s","TECNOLOGIA");
		break;
	case HOME_AND_FURNITURE:
		printf("%-20s","MUEBLES Y HOGAR");
		break;
	case HOME_APPLIANCES:
		printf("%-20s","ELECTRODOMESTICOS");
		break;
	case TOOLS:
		printf("%-20s","HERRAMIENTAS");

		break;
	case FASHION:
		printf("%-20s","MODA");
		break;
	}
	printf("%-8d", toPrintStruc.stock);
	printf("\n------------------------------------------------------------------------------------------|");
}
int eProduct_printAll(eProduct toPrintStruc[], int length, int status)
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
					eProduct_printOne(toPrintStruc[i]);
				}
			}
		}
	}
	return rtn;
}
int eProduct_searchEmptyIndex(eProduct toSearchStruc[], int length)
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
int eProduct_searchIndexId(eProduct toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;
	int searchId;

	if (toSearchStruc != NULL)
	{
		if (length > 0)
		{
			eProduct_printAll(toSearchStruc, length, FALSE);
			input_getInt("INGRESE ID: ", 1 , ID_INIT_VALUE, ID_INIT_VALUE + length, "ERROR, VUELVA A INGRESAR ID:", &searchId);

			for (i = 0; i < length; i++)
			{
				if (toSearchStruc[i].isEmpty == FALSE)
				{
					if (toSearchStruc[i].id == searchId)
					{
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
int eProduct_searchId(eProduct toSearchStruc[], int length, int searchId)
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
				if (toSearchStruc[i].isEmpty == FALSE || toSearchStruc[i].isEmpty == NO_STOCK )
				{
					if (toSearchStruc[i].id == searchId)
					{
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
int eProduct_countUsersProducts(eProduct toSearchStruc[], int length, int userId)
{
	int rtn = -1;
	int i;
	int productCount = 0;

	if (toSearchStruc != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (toSearchStruc[i].isEmpty == FALSE || toSearchStruc[i].isEmpty == NO_STOCK )
			{
				if (toSearchStruc[i].userId == userId)
				{
					productCount++;
				}
			}
		}
	}
	if(productCount>0)
	{
		rtn = productCount;
	}
	return rtn;
}
int eProduct_unregisterUsersProducts(eProduct toSearchStruc[], int length, int userId)
{
	int rtn = -1;
	int i;

	if (toSearchStruc != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (toSearchStruc[i].isEmpty == FALSE || toSearchStruc[i].isEmpty == NO_STOCK )
			{
				if (toSearchStruc[i].userId == userId)
				{
					toSearchStruc[i].isEmpty=TRUE;
					rtn = 0;
				}
			}
		}
	}

	return rtn;
}
int eProduct_register(eProduct *productList)
{
	int rtn=-1;
	int menuCategory;
	eProduct eProductBuffer;
	if(		input_getAlphaNumericString("INGRESE EL NOMBRE DEL PRODUCTO:", RETRIES, "ERROR, INGRESE UN NOMBRE VALIDO:", eProductBuffer.productName, PROD_NAME_LENGTH)== 0
			&& input_getFloat("INGRESE EL PRECIO DEL PRODUCTO:", RETRIES, 1, 999999,"ERROR, INGRESE UN PRECIO VALIDO:" , &eProductBuffer.price)==0)
	{
		menuCategory=menu_menu("ELIJA CATEGORIA:", "\n1 - TECNOLOGÍA"
				"\n2 - HOGAR Y MUEBLES"
				"\n3 - ELECTRODOMESTICOS"
				"\n4 - HERRAMIENTAS"
				"\n5 - MODA", "ERROR, DEBE INGRESAR UNA OPCIÓN <1-5>", RETRIES, 5);
		if(menuCategory>0)
		{
			switch(menuCategory)
			{
			case 1:
				eProductBuffer.category=TECHNOLOGY;
				break;
			case 2:
				eProductBuffer.category=HOME_AND_FURNITURE;
				break;
			case 3:
				eProductBuffer.category=HOME_APPLIANCES;
				break;
			case 4:
				eProductBuffer.category=TOOLS;
				break;
			case 5:
				eProductBuffer.category=FASHION;
				break;
			}
		}
		if(input_getInt("INGRESE LA CANTIDAD DEL PRODUCTO:", RETRIES, 0, 999, "ERROR, INGRESE UNA CANTIDAD VALIDA:", &eProductBuffer.stock)==0)
		{
			strncpy(productList->productName,eProductBuffer.productName,PROD_NAME_LENGTH);
			productList->price=eProductBuffer.price;
			productList->category= eProductBuffer.category;
			productList->stock= eProductBuffer.stock;
			rtn=0;
		}

	}

	return rtn;
}

int eProduct_registerproductList(eProduct toRegisterStruc[], int length)
{
	int rtn = -1;
	int emptyIndex;

	eProduct eProductBuffer;

	emptyIndex = eProduct_searchEmptyIndex(toRegisterStruc, length);

	if (toRegisterStruc != NULL)
	{
		if (length > 0)
		{
			if (emptyIndex >= 0)
			{
				if(eProduct_register(&eProductBuffer)==0)
				{
					eProductBuffer.id = eProduct_getUniqueID();
					eProductBuffer.isEmpty = FALSE;
					if(menu_confirm("¿DESEA REALIZAR LA CARGA?"
							"\nINGRESE RESPUESTA <S/N> :"
							, "ERROR, REINGRESE RESPUESTA:")==1)
					{
						//COPIA AUXILIAR EN productList EN POSICION OBTENIDA LIBRE
						toRegisterStruc[emptyIndex] = eProductBuffer;
						rtn = emptyIndex;
					}
					else
					{	//CARGA CANCELADA.
						rtn= -5;
					}
				}

			} else {
				// productList LLENO
				rtn = -4;
			}
		} else {
			// LEN MAL DEFINIDO
			rtn = -3;
		}
	} else {
		// productList NULO
		rtn = -2;
	}

	return rtn;
}
int eProduct_unRegisterproductList(eProduct toUnRegisterStruc[], int length)
{
	int rtn = -1;
	int indexBaja;

	if (toUnRegisterStruc != NULL)
	{
		if (length > 0)
		{

			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL productList
			indexBaja = eProduct_searchIndexId(toUnRegisterStruc, length);
			if (indexBaja < 0)
			{
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -2;
			}
			else
			{
				eProduct_printOne(toUnRegisterStruc[indexBaja]);
				if(menu_confirm("¿DESEA REALIZAR LA BAJA?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
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
		// productList NULO
		rtn = -4;
	}

	return rtn;
}
eProduct eProduct_ModifyOne(eProduct toMofiedStruc)
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
int eProduct_ModifyproductList(eProduct toMofiedStruc[], int length)
{
	int rtn = -1;
	int toModStrucIndex;
	eProduct eProductBuffer;

	if (toMofiedStruc != NULL)
	{
		if (length > 0)
		{
			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL productList
			toModStrucIndex = eProduct_searchIndexId(toMofiedStruc,
					length);
			if (toModStrucIndex < 0)
			{
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -2;
			}
			else
			{
				eProductBuffer = toMofiedStruc[toModStrucIndex];
				//MODIFICAR UN PRODUCTO
				eProductBuffer = eProduct_ModifyOne(eProductBuffer);
				if(menu_confirm("¿DESEA REALIZAR LA MODIFICACIÓN?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					toMofiedStruc[toModStrucIndex] = eProductBuffer;
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
		// productList NULO
		rtn = -4;
	}

	return rtn;
}
int eProduct_CategorySort(eProduct productList[], int TAM, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eProduct aux;

	if (productList != NULL && TAM > 0) {
		switch (criterio) {
		case 1:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j = i + 1; j < TAM; j++)
				{
					if (productList[i].isEmpty == FALSE
							&& productList[j].isEmpty == FALSE)
					{
						if(productList[i].category == productList[j].category)
						{
							if (strcmp(productList[i].productName,productList[j].productName)<0)
							{
								aux = productList[i];
								productList[i] = productList[j];
								productList[j] = aux;
							}
						}
						else
						{
							if(productList[i].category > productList[j].category)
							{
								aux = productList[i];
								productList[i] = productList[j];
								productList[j] = aux;
							}
						}
					}
				}
			}
			rtn = 1;
			break;
		case 2:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++)
				{
					if (productList[i].isEmpty == FALSE
							&& productList[j].isEmpty == FALSE)
					{
						if(productList[i].category == productList[j].category)
						{
							if (strcmp(productList[i].productName,productList[j].productName)>0)
							{
								aux = productList[i];
								productList[i] = productList[j];
								productList[j] = aux;
							}
						}
						else
						{
							if(productList[i].category > productList[j].category)
							{
								aux = productList[i];
								productList[i] = productList[j];
								productList[j] = aux;
							}
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
	return rtn;
}
int eProduct_StockSort(eProduct productList[], int TAM, int criterio)
{
	int rtn = -1;
	int i;
	int j;
	eProduct aux;

	if (productList != NULL && TAM > 0)
	{
		switch (criterio)
		{
		case 1:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j = i + 1; j < TAM; j++)
				{
					if (productList[i].isEmpty == FALSE
							&& productList[j].isEmpty == FALSE)
					{
						if(productList[i].stock > productList[j].stock)
						{
							aux = productList[i];
							productList[i] = productList[j];
							productList[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			break;
		case 2:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j = i + 1; j < TAM; j++)
				{
					if (productList[i].isEmpty == FALSE
							&& productList[j].isEmpty == FALSE)
					{
						if(productList[i].stock > productList[j].stock)
						{
							aux = productList[i];
							productList[i] = productList[j];
							productList[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			break;
		}
	}
	return rtn;
}
void eProduct_ForceProducts(eProduct productList[])
{
	eProduct userBuffer[6];

	userBuffer[0].id=1090;
	userBuffer[0].userId=1011;
	userBuffer[0].userPostalCode=0001;
	userBuffer[0].isEmpty=FALSE;
	strcpy(userBuffer[0].productName,"USB");
	userBuffer[0].price=100.50;
	userBuffer[0].category=TECHNOLOGY;
	userBuffer[0].stock=10;

	userBuffer[1].id=1091;
	userBuffer[1].userId=1012;
	userBuffer[1].userPostalCode=1001;
	userBuffer[1].isEmpty=FALSE;
	strcpy(userBuffer[1].productName,"CELULAR");
	userBuffer[1].price=29999.99;
	userBuffer[1].category=TECHNOLOGY;
	userBuffer[1].stock=3;

	userBuffer[2].id=1092;
	userBuffer[2].userId=1013;
	userBuffer[2].userPostalCode=3001;
	userBuffer[2].isEmpty=FALSE;
	strcpy(userBuffer[2].productName,"NOTEBOOK");
	userBuffer[2].price=5499.99;
	userBuffer[2].category=TECHNOLOGY;
	userBuffer[2].stock=1;

	userBuffer[3].id=1093;
	userBuffer[3].userId=1014;
	userBuffer[3].userPostalCode=5001;
	userBuffer[3].isEmpty=FALSE;
	strcpy(userBuffer[3].productName,"TALADRO");
	userBuffer[3].price=3000;
	userBuffer[3].category=TOOLS;
	userBuffer[3].stock=10;

	userBuffer[4].id=1094;
	userBuffer[4].userId=1015;
	userBuffer[4].userPostalCode=8001;
	userBuffer[4].isEmpty=FALSE;
	strcpy(userBuffer[4].productName,"MARTILLO");
	userBuffer[4].price=1500;
	userBuffer[4].category=TOOLS;
	userBuffer[4].stock=20;

	userBuffer[5].id=1095;
	userBuffer[5].userId=1015;
	userBuffer[5].userPostalCode=8001;
	userBuffer[5].isEmpty=FALSE;
	strcpy(userBuffer[5].productName,"SIERRA");
	userBuffer[5].price=150000;
	userBuffer[5].category=TOOLS;
	userBuffer[5].stock=2;

	productList[10]=userBuffer[0];
	productList[11]=userBuffer[1];
	productList[12]=userBuffer[2];
	productList[13]=userBuffer[3];
	productList[14]=userBuffer[4];
	productList[15]=userBuffer[5];
}
