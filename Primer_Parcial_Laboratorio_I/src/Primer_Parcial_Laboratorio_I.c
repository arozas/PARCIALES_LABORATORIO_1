/*
 ============================================================================
 Name        : Primer_Parcial_Laboratorio_I.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : 0.0 del 13 de Mayo de 2022.
 División    : División H.
 Description : Pimer Parcial de Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 50
#define MAX_PRODUCTS 100
#define MAX_TRACKING 100

#include "uOperations.h"


int main(void)
{
	int mainMenu;
	int adminMenu;
	int userMenu;
	int userStatBuyMenu;
	int userSellMenu;

	eUser usersList[MAX_USERS];
	eProduct productList[MAX_PRODUCTS];
	eTracking trackingList[MAX_TRACKING];

	eUser_init(usersList, MAX_USERS);
	eProduct_init(productList, MAX_PRODUCTS);
	eTracking_init(trackingList, MAX_TRACKING);

	eUser userLoggedIn;

	do
	{
		mainMenu = menu_menu("***************************"
				"\n\t\t\t** 1er EXAMEN LAB 1 - 1H **"
				"\n\t\t\t***************************",
				"\n\n1) INGRESAR "
				"\n2) REGISTRARSE"
				"\n\n3) CARGA FORZADA DE DATOS"
				"\n\n3) SALIR", "ERROR, DEBE INGRESAR UNA OPCIÓN <1-4>:", 1, 4);
		switch(mainMenu)
		{
		case 1:
			switch(uOperations_Login(usersList,&userLoggedIn))
			{
			case 0:
				do{
					printf("\n\t\t\t\t\tID USUARIO LOGEADO: %s\n",userLoggedIn.email);
					adminMenu=menu_menu("***************************"
							"\n\t\t\t** 1er EXAMEN LAB 1 - 1H **"
							"\n\t\t\t********** ADMIN **********"
							"\n\t\t\t***************************",
							"\n\n1) LISTAR ESTADO DE TODOS LOS USUARIOS."
							"\n2) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA."
							"\n3) BAJA DE UN PRODUCTO."
							"\n4) BAJA DE UN USUARIO."
							"\n5) VER TRACKING GLOBAL"
							"\n6) FILTRAR POR NOMBRE DE PRODUCTO"
							"\n\n7) SALIR", "ERROR, DEBE INGRESAR UNA OPCIÓN <1-6>:", 1, 7);
					switch(adminMenu)
					{
					case 1:
						uOperations_printAllUsers(usersList, MAX_USERS, productList, MAX_PRODUCTS, FALSE);
						break;
					case 2:
						uOperations_printSortedProductList(productList, MAX_PRODUCTS, usersList, UP, MAX_USERS, FALSE);
						break;
					case 3:
						uOperations_unregisterProduct(productList, MAX_PRODUCTS, usersList, MAX_USERS, FALSE);
						break;
					case 4:
						uOperations_unregisterUser(usersList, MAX_USERS, productList, MAX_PRODUCTS);
						break;
					case 5:
						uOperations_updateTrackingStatus(trackingList, MAX_TRACKING);
						uOperations_printAllTrackings(trackingList, MAX_TRACKING, usersList, MAX_USERS, productList, MAX_PRODUCTS);
						break;
					case 6:
						uOperations_printSortedNameProductList(productList, MAX_PRODUCTS, usersList, MAX_USERS, UP);
						break;
					}
				}while(adminMenu<7);
				break;
			case 1:
				do
				{
					printf("\n\t\t\t\t\tID USUARIO LOGEADO: %s\n",userLoggedIn.email);
					userMenu=menu_menu("***************************"
							"\n\t\t\t** 1er EXAMEN LAB 1 - 1H **"
							"\n\t\t\t********* USUARIO *********"
							"\n\t\t\t***************************",
							"\n\n1) COMPRAR"
							"\n2) VENDER"
							"\n3) ESTADO DE COMPRAS"
							"\n4) ESTADO DE VENTAS"
							"\n\n5) SALIR", "ERROR, DEBE INGRESAR UNA OPCIÓN <1-5>:", 1, 5);
					switch(userMenu)
					{
					case 1:
						uOperations_buyProduct(productList, MAX_PRODUCTS, usersList, MAX_USERS, trackingList, MAX_TRACKING, userLoggedIn);
						break;
					case 2:
						do
						{
						userSellMenu=menu_menu(
								"***************************"
								"\n\t\t\t** 1er EXAMEN LAB 1 - 1H **"
								"\n\t\t\t******* MENU VENTAS *******"
								"\n\t\t\t***************************",
								"\n\n1) LISTAR NUEVO PRODUCTO"
								"\n2) REPONER STOCK"
								"\n\n3) SALIR", "ERROR, DEBE INGRESAR UNA OPCIÓN <1-3>:", 1, 3);
						switch(userSellMenu)
						{
						case 1:
							uOperations_sellProduct(productList, MAX_PRODUCTS, usersList,MAX_USERS, userLoggedIn);
							break;
						case 2:
							uOperations_modifiedStock(productList, MAX_PRODUCTS, usersList, MAX_USERS, userLoggedIn);
							break;
						}
						}while(userSellMenu<3);
						break;
					case 3:
						do
						{
							printf("\n\t\t\t\t\tID USUARIO LOGEADO: %s\n",userLoggedIn.email);
							userStatBuyMenu=menu_menu(
									"***************************"
									"\n\t\t\t** 1er EXAMEN LAB 1 - 1H **"
									"\n\t\t\t***** ESTADOS COMPRAS *****"
									"\n\t\t\t***************************",
									"\n\n1) ESTADO DE COMPRAS"
									"\n2) CANCELAR UNA COMPRA"
									"\n\n3) SALIR", "ERROR, DEBE INGRESAR UNA OPCIÓN <1-3>:", 1, 3);
							switch(userStatBuyMenu)
							{
							case 1:
								uOperations_updateTrackingStatus(trackingList, MAX_TRACKING);
								uOperations_printBuyedStatus(trackingList, MAX_TRACKING, usersList, MAX_USERS, productList, MAX_PRODUCTS, userLoggedIn);
								break;
							case 2:
								uOperations_updateTrackingStatus(trackingList, MAX_TRACKING);
								uOperations_printBuyedStatus(trackingList, MAX_TRACKING, usersList, MAX_USERS, productList, MAX_PRODUCTS, userLoggedIn);
								uOperations_cancelBuyed(productList, MAX_PRODUCTS, usersList, MAX_USERS, trackingList, MAX_TRACKING, userLoggedIn);
								break;
							}
						}while(userStatBuyMenu<3);
						break;
					case 4:
						uOperations_updateTrackingStatus(trackingList, MAX_TRACKING);
						uOperations_printSelledStatus(trackingList, MAX_TRACKING, usersList, MAX_USERS, productList, MAX_PRODUCTS, userLoggedIn);
						break;
					}
				}while(userMenu<5);
				break;
			}
			break;
			case 2:
				uOperations_RegisterUser(usersList, MAX_USERS);
				break;
			case 3:
				eUser_ForceUsers(usersList);
				eProduct_ForceProducts(productList);
				eTracking_ForceTrackings(trackingList);

				puts("¡CARGA FORZADA EXITOSA!");
				break;
		}
	}while(mainMenu<4);

	return EXIT_SUCCESS;
}
