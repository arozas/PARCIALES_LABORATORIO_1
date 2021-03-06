/*
 * uReport.c
 *
 *  Created on: 15 may. 2022
 *      Author: alejandro
 */

#include "uOperations.h"

static void  uOperations_loginMsg(void);
/// @fn void uOperations_loginMsg()
/// @brief print a the header of the login screen.
///
static void uOperations_loginMsg()
{
	printf("\n\t\t\t***************************"
			"\n\t\t\t** 1er EXAMEN LAB 1 - 1H **"
			"\n\t\t\t***************************"
			"\n\t\t\t********** LOGIN **********"
			"\n\t\t\t***************************\n\n");
}
/// @fn void uOperations_printOneUser(eUser, eProduct[], int)
/// @brief print one user data.
///
/// @param toPrintStruc the user array.
/// @param productList the product array.
/// @param productLength the product array length.
void uOperations_printOneUser(eUser toPrintStruc, eProduct productList[], int productLength)
{
	int listedProducts;

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
	listedProducts = eProduct_countUsersProducts(productList, productLength, toPrintStruc.id);
	if(listedProducts>0)
	{
		printf("%-10d",listedProducts);
	}
	else
	{
		listedProducts=0;
		printf("%-10d",listedProducts);
	}
	printf("%-10d",toPrintStruc.buyedProducts);
	printf("%-10d",toPrintStruc.selledProducts);
	printf("$%-12.2f",toPrintStruc.currentMoney);
	printf("$%-12.2f",toPrintStruc.spent);
	printf("$%-12.2f",toPrintStruc.won);
	printf(	"\n--------------------------------------------------------------------------------------------------------------------------------------|");
}
/// @fn int uOperations_printAllUsers(eUser[], int, eProduct[], int, int)
/// @brief print all users data.
///
/// @param toPrintStruc the user array.
/// @param length the length of the user array.
/// @param productList the product array.
/// @param productLength the product array length.
/// @param status the status of the users to print.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_printAllUsers(eUser toPrintStruc[], int length, eProduct productList[], int productLength, int status)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL)
	{
		if (length > 0)
		{
			printf(	"\n======================================================================================================================================|");
			printf("\n%-6s%-30s%-10s%-10s%-10s%-10s%-10s%-12s%-12s%-12s","ID", "EMAIL", "ESTADO", "Km","PRODUCTOS","COMPRADO","VENDIDO","DINERO","GASTADO","GANADO");
			printf(	"\n======================================================================================================================================|");
			for (i = 0; i < length; i++)
			{
				if (toPrintStruc[i].isEmpty == status)
				{
					uOperations_printOneUser(toPrintStruc[i], productList, productLength);
				}
			}
			printf(	"\n======================================================================================================================================|\n");
			rtn=0;
		}
	}
	return rtn;
}
/// @fn int uOpertions_RegisterUser(eUser*, int)
/// @brief register an user thats not an admin.
///
/// @param userList	users array.
/// @param length users array length.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_RegisterUser(eUser userList[], int length)
{
	int rtn =-1;
	int rtnEmail;
	int emptyIndex;
	eUser eUserBuffer;

	input_getEmail("INGRESE SU EMAIL:", RETRIES, "ERROR, INGRESE UN EMAIL VALIDO:", eUserBuffer.email, MAIL_LENGTH);
	rtnEmail=eUser_searchEmail(userList, MAIL_LENGTH, eUserBuffer.email);
	if( rtnEmail==-2)
	{
		emptyIndex = eUser_searchEmptyIndex(userList, length);
		printf("\n index vacio: %d",emptyIndex);
		if (userList != NULL)
		{
			if (length > 0)
			{
				if (emptyIndex >= 0)
				{
					if(eUser_create(&eUserBuffer)==0)
					{
						eUserBuffer.id = eUser_getUniqueID();
						eUserBuffer.isEmpty = FALSE;
						if(menu_confirm("??DESEA REALIZAR LA REGISTRACI??N?"
								"\nINGRESE RESPUESTA <S/N> :"
								, "ERROR, REINGRESE RESPUESTA:")==1)
						{
							userList[emptyIndex] = eUserBuffer;
							rtn = emptyIndex;
						}
						else
						{	//CARGA CANCELADA.
							rtn= -5;
						}
					}
					else
					{
						//error de carga
						rtn=-6;
					}
				}
				else
				{
					// ARRAY LLENO
					rtn = -4;
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
			rtn = -2;
		}

	}
	else
	{
		puts("ESTE MAIL YA ESTA REGISTRADO");
	}

	return rtn;
}
/// @fn int uOperations_unregisterUser(eUser[], int, eProduct[], int)
/// @brief unregister an user and all his products from the system.
///
/// @param userList the users array.
/// @param length the users length.
/// @param productList the products array.
/// @param productLength the products array length.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_unregisterUser(eUser userList[], int length, eProduct productList[], int productLength)
{
	int rtn = -1;
	int indexBaja;
	if (userList != NULL && length > 0)
	{
		indexBaja = eUser_searchIndexId(userList, length);
		if (indexBaja < 0)
		{
			puts("NO SE ENCONTRO USUARIO CON ESE ID");
		}
		else
		{
			eUser_printOne(userList[indexBaja]);
			if(menu_confirm("??DESEA REALIZAR LA BAJA?"
					"\nSE DARAN DE BAJA LOS PRODUCTOS LISTADO EN VENTA"
					"\n\nINGRESE RESPUESTA <S/N> :"
					, "ERROR, REINGRESE RESPUESTA:")==1)
			{
				userList[indexBaja].isEmpty=TRUE;
				eProduct_unregisterUsersProducts(productList, productLength, userList[indexBaja].id);
				rtn=0;
			}
			else
			{
				puts("??BAJA CANCELADA!");
			}
		}

	}

	return rtn;
}
/// @fn int uOperations_Login(eUser*, eUser*)
/// @brief The login function, its save the logged users in the parametres.
///
/// @param usersList the users array.
/// @param userLoggedIn pointer to var to save user logged in.
/// @return return -1 if error, rtn user type if ok.
int uOperations_Login(eUser *usersList, eUser *userLoggedIn)
{
	int rtn = -1 ;
	char bufferEmail[MAIL_LENGTH];
	char bufferPassword[PASSWORD_LENGTH];
	int rtnEmail;

	uOperations_loginMsg();

	if( input_getEmail("POR FAVOR INGRESE SU MAIL:", RETRIES, "ERROR, INGRESE UN MAIL VALIDO:", bufferEmail, MAIL_LENGTH)==0)
	{
		rtnEmail=eUser_searchEmail(usersList, MAIL_LENGTH, bufferEmail);
		if( rtnEmail>=0)
		{
			input_getAlphaNumericString("INGRESE SU PASSWORD", RETRIES, "ERROR, INGRESO MAL EL PASSWORD", bufferPassword, PASSWORD_LENGTH);
			if(strcmp(usersList[rtnEmail].password,bufferPassword)==0)
			{
				rtn=usersList[rtnEmail].type;
				*userLoggedIn=usersList[rtnEmail];
			}
			else
			{
				puts("LA CONTRASE??A INCORRECTA");
			}
		}
		else
		{
			puts("NO PODEMOS ENCONTRAR UNA CUENTA CON ESA DIRECCI??N DE EMAIL");
		}
	}
	return rtn;
}
/// @fn void uOperations_printOneProduct(eProduct, eUser[], int)
/// @brief print one product and all its data and some relation informations.
///
/// @param toPrintStruc the product array.
/// @param userList the users array.
/// @param userListLength the users array length.
void uOperations_printOneProduct(eProduct toPrintStruc, eUser userList[], int userListLength)
{
	int userIndex;

	printf(	"\n-------------------------------------------------------------------------------------------------------------------------|");
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

	userIndex=eUser_searchId(userList, userListLength, toPrintStruc.userId);

	printf("%-25s", userList[userIndex].email);
	printf("%-10d", userList[userIndex].id);

	if(userList[userIndex].postalCode>8000)
	{
		printf("%-10s", "150km");
	}
	else
	{
		if(userList[userIndex].postalCode>5000)
		{
			printf("%-10s", "80km");
		}
		else
		{
			if(userList[userIndex].postalCode>3000)
			{
				printf("%-10s", "50km");
			}
			else
			{
				if(userList[userIndex].postalCode>1000)
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

	printf(	"\n-------------------------------------------------------------------------------------------------------------------------|");
}
/// @fn int uOperations_printAllProducts(eProduct[], int, eUser[], int, int)
/// @brief print all products of a determinate state.
///
/// @param toPrintStruc the products array.
/// @param length the products array length.
/// @param userList the users array.
/// @param userListLength the users array length.
/// @param status the status of the products to print.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_printAllProducts(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, int status)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL && userList != NULL)
	{
		if (length > 0 && userListLength> 0)
		{
			printf("\n=========================================================================================================================|");
			printf("\n%-6s%-25s%-15s %-20s%-8s%-25s%-10s%-10s", "ID","PRODUCTO","PRECIO","CATEGORIA","STOCK","VENDEDOR","ID","DISTANCIA");
			printf("\n=========================================================================================================================|");
			rtn=0;
			for (i = 0; i < length; i++)
			{
				if (toPrintStruc[i].isEmpty == status)
				{
					uOperations_printOneProduct(toPrintStruc[i], userList, userListLength);
				}
			}
			printf("\n=========================================================================================================================|");
			rtn=0;
		}
	}
	return rtn;
}
/// @fn int uOperations_printSortedProductList(eProduct[], int, eUser[], int, int, int)
/// @brief Print a sorted product list per categories.
///
/// @param toPrintStruc the product array to print.
/// @param length	the product arrar length.
/// @param userList the users array.
/// @param userListLength the users array length.
/// @param order the order of sorting, 1 for up or 2 down.
/// @param status the status of the products to print.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_printSortedProductList(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, int order, int status)
{
	int rtn =-1;
	int i;
	int productCount = 0;

	eProduct toSortProductList[length];

	for (i = 0; i < length; i++)
	{
		if (toPrintStruc[i].isEmpty == status)
		{
			productCount++;
		}
	}
	if(productCount>0)
	{
		for ( i = 0; i < length; ++i)
		{
			toSortProductList[i] = toPrintStruc[i];
		}
		eProduct_CategorySort(toSortProductList, length, order);
		uOperations_printAllProducts(toSortProductList, length, userList, userListLength, status);
		rtn = 0;
	}
	else
	{
		puts("NO HAY PRODUCTOS PARA MOSTRAR");
	}
	return rtn;

}
/// @fn int uOperations_printAllProducts(eProduct[], int, eUser[], int, int)
/// @brief print all products with a determined name.
///
/// @param toPrintStruc the products array.
/// @param length the products array length.
/// @param userList the users array.
/// @param userListLength the users array length.
/// @param status the status of the products to print.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_printAllNameProducts(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, char productName[])
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL && userList != NULL)
	{
		if (length > 0 && userListLength> 0)
		{
			printf("\n=========================================================================================================================|");
			printf("\n%-6s%-25s%-15s %-20s%-8s%-25s%-10s%-10s", "ID","PRODUCTO","PRECIO","CATEGORIA","STOCK","VENDEDOR","ID","DISTANCIA");
			printf("\n=========================================================================================================================|");
			rtn=0;
			for (i = 0; i < length; i++)
			{
				if (strcmp(toPrintStruc[i].productName,productName)==0)
				{
					uOperations_printOneProduct(toPrintStruc[i], userList, userListLength);
				}
			}
			printf("\n=========================================================================================================================|");
			rtn=0;
		}
	}
	return rtn;
}
/// @fn int uOperations_printSortedProductList(eProduct[], int, eUser[], int, int, int)
/// @brief Print a sorted product list per stock and a determined name.
///
/// @param toPrintStruc the product array to print.
/// @param length	the product arrar length.
/// @param userList the users array.
/// @param userListLength the users array length.
/// @param order the order of sorting, 1 for up or 2 down.
/// @param status the status of the products to print.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_printSortedNameProductList(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, int order)
{
	int rtn =-1;
	int i;
	int productCount = 0;
	int rtnGet;
	char productName[25];


	eProduct toSortProductList[length];

	for (i = 0; i < length; i++)
	{
		if (toPrintStruc[i].isEmpty == FALSE || toPrintStruc[i].isEmpty == NO_STOCK)
		{
			productCount++;
		}
	}

	if(productCount>0)
	{
		rtnGet = input_getStringletters("INGRESE EL NOMBRE DEL PRODUCTO A MOSTRAR:", RETRIES, "ERROR", productName, sizeof(productName));
		if(rtnGet==0)
		{
			for ( i = 0; i < length; ++i)
			{
				toSortProductList[i] = toPrintStruc[i];
			}
			eProduct_StockSort(toSortProductList, length, order);
			uOperations_printAllNameProducts(toSortProductList, length, userList, userListLength, productName);
			rtn = 0;
		}
		else
		{
			puts("ERROR, MAL INGRESADO EL NOMBRE");
		}
	}
	else
	{
		puts("NO HAY PRODUCTOS PARA MOSTRAR");
	}
	return rtn;

}
/// @fn int uOperations_printAllProducts(eProduct[], int, eUser[], int, int)
/// @brief print all products of a determinate state.
///
/// @param toPrintStruc the products array.
/// @param length the products array length.
/// @param userList the users array.
/// @param userListLength the users array length.
/// @return return -1 if error, rtn 0 if ok.
int uOperations_printAllUserProducts(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, eUser loggedUser)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL && userList != NULL)
	{
		if (length > 0 && userListLength> 0)
		{
			printf("\n=========================================================================================================================|");
			printf("\n%-6s%-25s%-15s %-20s%-8s%-25s%-10s%-10s", "ID","PRODUCTO","PRECIO","CATEGORIA","STOCK","VENDEDOR","ID","DISTANCIA");
			printf("\n=========================================================================================================================|");
			rtn=0;
			for (i = 0; i < length; i++)
			{
				if (toPrintStruc[i].userId == loggedUser.id)
				{
					uOperations_printOneProduct(toPrintStruc[i], userList, userListLength);
				}
			}
			printf("\n=========================================================================================================================|");
			rtn=0;
		}
	}
	return rtn;
}
/// @fn int uOperations_modifiedStock(eProduct[], int, eUser[], int, eUser)
/// @brief Modifies the stock of selected product.
///
/// @param productList The products array.
/// @param productLength The products array length.
/// @param userList The users array.
/// @param userListLength The users arrays length.
/// @param loggedUser The user logged in.
/// @return returns -1 if error, rtn 0 if ok.
int uOperations_modifiedStock(eProduct productList[], int productLength, eUser userList[], int userListLength, eUser loggedUser)
{
	int rtn = -1;
	int indexStock;
	int productId;
	int rtnGeIn;

	eProduct eProductBuffer;

	int stockAdd;

	if (productList != NULL && userList != NULL)
	{
		if (productLength > 0 && userListLength> 0)
		{
			uOperations_printAllUserProducts(productList, productLength, userList, userListLength, loggedUser);
			input_getInt("INGRESE EL ID DEL PRODUCTO A MODIFICAR STOCK:", RETRIES, 1000, 2000, "ERROR, REINGRESE EL ID:", &productId);
			indexStock=eProduct_searchId(productList, productLength, productId);
			eProductBuffer=productList[indexStock];

			if (indexStock < 0)
			{
				puts("NO HAY PRODUCTO CON ESE ID");
			}
			else
			{
				rtnGeIn=input_getInt("INGRESE LA CANTIDAD DE STOCK A AUMENTAR O RESTAR:", RETRIES, -300, 300, "ERROR, REINGRESE LA CANTIDAD DE STOCK A AUMENTAR O RESTAR:", &stockAdd);

				if(rtnGeIn==0)
				{
					if((eProductBuffer.stock+stockAdd)>=0)
					{
						eProductBuffer.stock=eProductBuffer.stock+stockAdd;

						uOperations_printOneProduct(eProductBuffer, userList, userListLength);

						if(menu_confirm("??CONFIRMA LA MODIFICACI??N DE STOCK?"
								"\nINGRESE RESPUESTA <S/N> :"
								, "ERROR, REINGRESE RESPUESTA:")==1)
						{
							productList[indexStock].stock=eProductBuffer.stock;

							if(productList[indexStock].stock==0)
							{
								productList[indexStock].isEmpty=NO_STOCK;
							}

							rtn=0;
						}
						else
						{
							puts("??BAJA CANCELADA!");
						}
					}
					else
					{
						puts("??ERROR DE CARGA!??NO PUEDE TENER MENOS DE 0 PRODUCTOS!");
					}
				}
				else
				{
					puts("??ERROR DE CARGA!??BAJA CANCELADA!");
				}
			}
		}
	}
	return rtn;
}
/// @fn int uOperations_unregisterProduct(eProduct[], int, eUser[], int, int)
/// @brief  Unregister a product.
///
/// @param productList the product array.
/// @param productLength the product list length.
/// @param userList
/// @param userListLength
/// @param status
/// @return
int uOperations_unregisterProduct(eProduct productList[], int productLength, eUser userList[], int userListLength, int status)
{
	int rtn = -1;
	int productId;
	int indexBaja;

	if (productList != NULL && productLength > 0)
	{
		uOperations_printSortedProductList(productList, productLength, userList, userListLength, UP , status);
		input_getInt("INGRESE EL ID DEL PRODUCTO A DAR DE BAJA:", RETRIES, 1000, 2000, "ERROR, REINGRESE EL ID:", &productId);
		indexBaja=eProduct_searchId(productList, productLength, productId);

		if (indexBaja < 0)
		{
			puts("NO HAY PRODUCTO CON ESE ID");
		}
		else
		{
			uOperations_printOneProduct(productList[indexBaja], userList, userListLength);

			if(menu_confirm("??DESEA REALIZAR LA BAJA?"
					"\nINGRESE RESPUESTA <S/N> :"
					, "ERROR, REINGRESE RESPUESTA:")==1)
			{
				productList[indexBaja].isEmpty=TRUE;
				rtn=0;
			}
			else
			{
				puts("??BAJA CANCELADA!");
			}
		}
	}

	return rtn;
}
void uOperations_printOneTracking(eTracking toPrintStruc, eUser userList[], int userListLength, eProduct productList[], int productLength)
{
	int sellerIndex;
	int buyerIndex;
	int productIndex;
	printf(	"\n-------------------------------------------------------------------------------------------------------------------------------------------------|");
	printf(		//id //idproducto //cantidad //
			"\n%-6d%-6d",//-25 -25
			toPrintStruc.trackingId,
			toPrintStruc.productId);
	productIndex=eProduct_searchId(productList, productLength, toPrintStruc.productId);
	printf("%-25s", productList[productIndex].productName);
	sellerIndex=eUser_searchId(userList, userListLength, toPrintStruc.userId);
	printf("%-25s", userList[sellerIndex].email);
	buyerIndex=eUser_searchId(userList, userListLength, toPrintStruc.buyerId);
	printf("%-25s", userList[buyerIndex].email);
	printf("%-10d",toPrintStruc.amount);
	printf("%-8d",toPrintStruc.distanceKM);
	switch(toPrintStruc.status)
	{
	case IN_DEPOSIT:
		printf("%-15s", "EN DEPOSITO");
		break;
	case TRAVELLING:
		printf("%-15s", "EN VIAJE");
		break;
	case DELIVERED:
		printf("%-15s", "ENTREGADO");
		break;
	case CANCELLED:
		printf("%-15s", "CANCELADO");
		break;
	}
	printf("%-20s", ctime(&toPrintStruc.arrivalTime));
	printf(	"-------------------------------------------------------------------------------------------------------------------------------------------------|");
	//NEED TO BE COMPLETED WITH THE OTHERS ENTETY ATRIBUTES
}
int uOperations_printAllTrackings(eTracking toPrintStruc[],int trackingLength, eUser userList[], int userListLength, eProduct productList[], int productLength)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL)
	{
		if (trackingLength > 0)
		{
			rtn=0;
			printf(	"\n=================================================================================================================================================|");
			printf("\n%-6s%-6s%-25s%-25s%-25s%-10s%-8s%-15s%-20s", "ID","P.ID","PRODUCTO","VENDEDOR","COMPRADOR","CANTIDAD","KM","ESTADO","LLEGA EL:");
			printf(	"\n=================================================================================================================================================|");
			for (i = 0; i < trackingLength; i++)
			{
				if (toPrintStruc[i].isEmpty == FALSE)
				{
					uOperations_printOneTracking(toPrintStruc[i], userList, userListLength, productList, productLength);
				}
			}
		}
	}
	return rtn;
}
int uOperations_updateTrackingStatus(eTracking trackingList[],int trackingLength)
{
	int rtn = -1;
	int i;
	long int currentTime;
	currentTime=myTime_current();
	if(trackingList!=NULL && trackingLength>0)
	{
		for (i = 0; i < trackingLength; i++)
		{
			if(trackingList[i].isEmpty == FALSE
					&& trackingList[i].status != CANCELLED)
			{
				if(trackingList[i].arrivalTime>currentTime)
				{
					trackingList[i].status=TRAVELLING;
				}
				else
				{
					if(trackingList[i].arrivalTime<currentTime)
					{
						trackingList[i].status=DELIVERED;
					}
				}
				rtn=0;
			}
		}
	}


	return rtn;
}
/// @fn int uOperations_updateUserBalance(eTracking[], int, eUser[], int)
/// @brief INCOMPLETA
///
/// @param trackingList
/// @param trackingLength
/// @param userList
/// @param userListLength
/// @return
int uOperations_updateUserBalance(eTracking trackingList[],int trackingLength, eUser userList[], int userListLength)
{
	int rtn = -1;
	int i;
	long int currentTime;
	currentTime=myTime_current();
	if(trackingList!=NULL && trackingLength>0)
	{
		for (i = 0; i < trackingLength; i++)
		{
			if(trackingList[i].isEmpty == FALSE
					&& trackingList[i].status != CANCELLED)
			{
				if(trackingList[i].arrivalTime>currentTime)
				{
					trackingList[i].status=TRAVELLING;
				}
				else
				{
					if(trackingList[i].arrivalTime<currentTime)
					{
						trackingList[i].status=DELIVERED;
					}
				}
				rtn=0;
			}
		}
	}


	return rtn;
}
int uOperations_printBuyedStatus(eTracking toPrintStruc[],int trackingLength, eUser userList[], int userListLength, eProduct productList[], int productLength, eUser loggedUser)
{
	int rtn = -1;
	int i;
	int productCount = 0;

	if (toPrintStruc != NULL)
	{
		if (trackingLength > 0)
		{
			for (i = 0; i < trackingLength; i++)
			{
				if (toPrintStruc[i].buyerId == loggedUser.id)
				{
					productCount++;
				}
			}
			if(productCount>0)
			{
				printf(	"\n=================================================================================================================================================|");
				printf("\n%-6s%-6s%-25s%-25s%-25s%-10s%-8s%-15s%-20s", "ID","P.ID","PRODUCTO","VENDEDOR","COMPRADOR","CANTIDAD","KM","ESTADO","LLEGA EL:");
				printf(	"\n=================================================================================================================================================|");
				for (i = 0; i < trackingLength; i++)
				{
					if (toPrintStruc[i].userId == loggedUser.id)
					{
						uOperations_printOneTracking(toPrintStruc[i], userList, userListLength, productList, productLength);
					}
				}
				rtn=0;
			}
			else
			{
				puts("??NO TIENE PRODUCTOS COMPRADOS PARA LISTAR!");
			}
		}
	}
	return rtn;
}
int uOperations_printSelledStatus(eTracking toPrintStruc[],int trackingLength, eUser userList[], int userListLength, eProduct productList[], int productLength, eUser loggedUser)
{
	int rtn = -1;
	int i;
	int productCount=0;

	if (toPrintStruc != NULL)
	{
		if (trackingLength > 0)
		{
			for (i = 0; i < trackingLength; i++)
			{
				if (toPrintStruc[i].userId == loggedUser.id)
				{
					productCount++;
				}
			}
			if(productCount>0)
			{
				printf(	"\n=================================================================================================================================================|");
				printf("\n%-6s%-6s%-25s%-25s%-25s%-10s%-8s%-15s%-20s", "ID","P.ID","PRODUCTO","VENDEDOR","COMPRADOR","CANTIDAD","KM","ESTADO","LLEGA EL:");
				printf(	"\n=================================================================================================================================================|");
				for (i = 0; i < trackingLength; i++)
				{
					if (toPrintStruc[i].userId == loggedUser.id)
					{
						uOperations_printOneTracking(toPrintStruc[i], userList, userListLength, productList, productLength);
					}
				}
				rtn=0;
			}
			else
			{
				puts("??NO TIENE PRODUCTOS VENDIDOS!");
			}
		}
	}
	return rtn;
}
int uOperations_sellProduct(eProduct productList[], int productLength, eUser userList[], int userLength, eUser userLoggedin)
{
	int rtn = -1;
	int emptyIndex;

	eProduct eProductBuffer;

	emptyIndex = eProduct_searchEmptyIndex(productList, productLength);

	if (productList != NULL && userList != NULL)
	{
		if (productLength > 0)
		{
			if (emptyIndex >= 0)
			{
				if(eProduct_register(&eProductBuffer)==0)
				{
					eProductBuffer.id = eProduct_getUniqueID();
					eProductBuffer.isEmpty = FALSE;
					if(menu_confirm("??DESEA PONER EL PRODUCTO EN VENTA?"
							"\nINGRESE RESPUESTA <S/N> :"
							, "ERROR, REINGRESE RESPUESTA:")==1)
					{
						productList[emptyIndex] = eProductBuffer;
						productList[emptyIndex].userId=userLoggedin.id;
						productList[emptyIndex].userPostalCode=userLoggedin.postalCode;
						rtn = emptyIndex;
					}
					else
					{	//CARGA CANCELADA.
						rtn= -5;
					}
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
int uOperations_buyProduct(eProduct productList[], int productLength, eUser usersList[], int usersLength, eTracking trackingList[], int trackingLength, eUser userLoggedin)
{
	int rtn = 1;
	int productId;
	int trackingEmptyIndex;
	int toBuyIndex;
	int toBuyAmount;
	float finalPrice;
	int userLoggedIndex;
	int sellerIndex;
	double distInSec;

	eTracking eTrackingBuffer;

	uOperations_printSortedProductList(productList, productLength, usersList, usersLength,UP, FALSE);
	input_getInt("INGRESE EL ID DEL PRODUCTO A COMPRAR:", RETRIES, 1000, 2000, "ERROR INGRESE EL ID NUEVAMENTE:", &productId);
	toBuyIndex=eProduct_searchId(productList, productLength, productId);
	if(toBuyIndex<0)
	{
		printf("\nNO EXISTE PRODUCTO CON ESE ID");
	}
	else
	{
		trackingEmptyIndex=eTracking_searchEmptyIndex(trackingList, trackingLength);
		userLoggedIndex=eUser_searchId(usersList, usersLength, userLoggedin.id);
		sellerIndex=eUser_searchId(usersList, usersLength, productList[toBuyIndex].userId);
		if(productList[toBuyIndex].userId!=userLoggedin.id)
		{
			if (trackingList != NULL)
			{
				if (trackingLength > 0)
				{
					if (trackingEmptyIndex >= 0)
					{
						//CARGO DATOS NO GENERICOS
						//eTrackingBuffer = eTracking_register();
						input_getInt("INGRESE LA CANTIDAD A COMPRAR:", RETRIES, 1, productList[toBuyIndex].stock, "ERROR, INGRESE LA CANTIDAD A COMPRAR", &toBuyAmount);
						//SI ESTA TODO BIEN - LE DOY UN ID UNICO
						eTrackingBuffer.trackingId = eTracking_getUniqueID();
						eTrackingBuffer.productId=productList[toBuyIndex].id;
						eTrackingBuffer.userId=productList[toBuyIndex].userId;
						eTrackingBuffer.buyerId=userLoggedin.id;
						eTrackingBuffer.isEmpty = FALSE;
						eTrackingBuffer.amount=toBuyAmount;
						finalPrice=toBuyAmount*productList[toBuyIndex].price;
						eTrackingBuffer.priceCost=finalPrice;

						if(usersList[sellerIndex].postalCode>8000)
						{
							eTrackingBuffer.distanceKM=150;
						}
						else
						{
							if(usersList[sellerIndex].postalCode>5000)
							{
								eTrackingBuffer.distanceKM=80;
							}
							else
							{
								if(usersList[sellerIndex].postalCode>3000)
								{
									eTrackingBuffer.distanceKM=50;
								}
								else
								{
									if(usersList[sellerIndex].postalCode>1000)
									{
										eTrackingBuffer.distanceKM=30;
									}
									else
									{
										eTrackingBuffer.distanceKM=20;
									}
								}
							}
						}
						distInSec=(eTrackingBuffer.distanceKM/10)*20;
						eTrackingBuffer.arrivalTime=myTime_add(distInSec);
						eTrackingBuffer.status=IN_DEPOSIT;
						printf( "\n=================================================================================================================================================|");
						printf("\n%-6s%-6s%-25s%-25s%-25s%-10s%-8s%-15s%-20s", "ID","P.ID","PRODUCTO","VENDEDOR","COMPRADOR","CANTIDAD","KM","ESTADO","LLEGA EL:");
						printf( "\n=================================================================================================================================================|");
						uOperations_printOneTracking(eTrackingBuffer, usersList, usersLength, productList, productLength);
						printf("\n\nTOTAL A PAGAR: $%.2f\n",finalPrice);
						printf("\n\nUSTED TIENE: $%.2f\n",userLoggedin.currentMoney);
						if(menu_confirm("??DESEA REALIZAR LA COMPRA?"
								"\nINGRESE RESPUESTA <S/N> :"
								, "ERROR, REINGRESE RESPUESTA:")==1)
						{
							if(finalPrice>userLoggedin.currentMoney)
							{
								puts("NO TIENE FONDOS PARA LA OPERACI??N");
							}
							else
							{
								usersList[userLoggedIndex].currentMoney=usersList[userLoggedIndex].currentMoney-finalPrice;
								usersList[userLoggedIndex].spent=usersList[userLoggedIndex].spent+finalPrice;
								usersList[userLoggedIndex].buyedProducts=usersList[userLoggedIndex].buyedProducts+toBuyAmount;
								usersList[sellerIndex].won=usersList[sellerIndex].won+finalPrice;
								usersList[sellerIndex].selledProducts=usersList[sellerIndex].selledProducts+toBuyAmount;
								productList[toBuyIndex].stock=productList[toBuyIndex].stock-toBuyAmount;
								if(productList[toBuyIndex].stock==0)
								{
									productList[toBuyIndex].isEmpty=NO_STOCK;
								}
								trackingList[trackingEmptyIndex] = eTrackingBuffer;
								rtn = trackingEmptyIndex;
							}

						}
						else
						{
							puts("COMPRA CANCELADA");
						}
					}
					else
					{
						puts("LISTA DE COMPRAS LLENAS");
					}
				}
			}
		}
		else
		{
			puts("NO PUEDE COMPRAR SUS PROPIOS PRODUCTOS");
		}
	}
	return rtn;
}
int uOperations_cancelBuyed(eProduct productList[], int productLength, eUser usersList[], int usersLength, eTracking trackingList[], int trackingLength, eUser userLoggedin)
{
	int rtn =-1;

	int i;
	int productCount=0;

	int trackigId;
	int trackingIndex;

	int productId;
	int sellerId;

	int buyedProductIndex;
	int buyerIndex;
	int sellerIndex;

	eTracking eTrackingBuffer;

	if (trackingList != NULL && trackingLength > 0)
	{
		for (i = 0; i < trackingLength; i++)
		{
			if (trackingList[i].buyerId == userLoggedin.id)
			{
				productCount++;
			}
		}
	}
	if(productCount>0)
	{
		input_getInt("INGRESE EL ID DE LA COMPRA A CANCELAR:", RETRIES, 1000, 2000, "ERROR, REINGRESE EL ID:", &trackigId);
		trackingIndex = eTracking_searchId(trackingList, trackingLength, trackigId);
		if(trackingIndex<0)
		{
			printf("\nNO EXISTE COMPRA CON ESE ID");
		}
		else
		{
			if(trackingList[trackingIndex].status==CANCELLED)
			{
				printf("\n??LA COMPRA YA ESTA CANCELADA!");
			}
			else
			{
				eTrackingBuffer=trackingList[trackingIndex];
				eTrackingBuffer.status = CANCELLED;

				productId=eTrackingBuffer.productId;
				buyedProductIndex=eProduct_searchId(productList, productLength, productId);

				sellerId=productList[buyedProductIndex].userId;
				sellerIndex=eUser_searchId(usersList, usersLength, sellerId);

				buyerIndex=eUser_searchId(usersList, usersLength, userLoggedin.id);

				printf("\nID VENDEDOR:%d", sellerId);
				printf("\nINDEX VENDEDOR:%d", sellerIndex);

				printf("\nID PRODUCTO:%d", productId);
				printf("\nINDEX VENDEDOR:%d", buyedProductIndex);

				uOperations_printOneTracking(eTrackingBuffer, usersList, usersLength, productList, productLength);
				if(menu_confirm("??ESTA SEGURO DE CANCELAR LA COMPRA?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE RESPUESTA:")==1)
				{
					//ACTUALIZO EL ESTADO DEL USUARIO, GASTOS Y COMPRAS
					usersList[buyerIndex].currentMoney=usersList[buyerIndex].currentMoney+eTrackingBuffer.priceCost;
					usersList[buyerIndex].spent=usersList[buyerIndex].spent-eTrackingBuffer.priceCost;
					usersList[buyerIndex].buyedProducts=usersList[buyerIndex].buyedProducts-eTrackingBuffer.amount;

					//ACTUALIZO EL ESTADO DEL VENDEDOR, VENDIDO Y GANADO
					usersList[sellerIndex].won=usersList[sellerIndex].won-eTrackingBuffer.priceCost;
					usersList[sellerIndex].selledProducts=usersList[sellerIndex].selledProducts-eTrackingBuffer.amount;

					//ACTUALIZO EL ESTADO DEL PRODUCTO, STOCK
					productList[buyedProductIndex].stock=productList[buyedProductIndex].stock+eTrackingBuffer.amount;

					if(productList[buyedProductIndex].stock>0)
					{
						productList[buyedProductIndex].isEmpty=FALSE;
					}

					trackingList[trackingIndex] = eTrackingBuffer;
					rtn = trackingIndex;
				}
				else
				{
					puts("COMPRA NO CANCELADA");
				}
			}
		}
	}
	else
	{
		puts("NO TIENE PRODUCTOS COMPRADOS PARA CANCELAR");
	}
	return rtn;
}
