/*
 * eProduct.h
 *
 *  Created on: 30 abr. 2022
 *      Author: alejandro
 */

#ifndef EPRODUCT_H_
#define EPRODUCT_H_

#define PROD_NAME_LENGTH 25
#define ID_INIT_VALUE 1000

#define TECHNOLOGY 1 //tecno
#define HOME_AND_FURNITURE 2 //muebles
#define HOME_APPLIANCES 3 //electro
#define TOOLS 4 //herramientas
#define FASHION 5 //moda

#define TRUE 1
#define FALSE 2
#define NO_STOCK 3

#define RETRIES 3

#include <stdio.h>
#include <stdlib.h>

//ABM
typedef struct
{
	int id;
	int userId;
	int userPostalCode;
	short int isEmpty;
	//RELACIONES
	char productName[PROD_NAME_LENGTH];
	float price;
	short int category;
	int stock;
}eProduct;

int eProduct_getUniqueID(void);
int eProduct_init(eProduct eProductList[], int length);
void eProduct_printOne(eProduct toPrintStruc);
int eProduct_printAll(eProduct toPrintStruc[], int length, int status);
int eProduct_searchEmptyIndex(eProduct toSearchStruc[], int length);
int eProduct_searchIndexId(eProduct toSearchStruc[], int length);
int eProduct_searchId(eProduct toSearchStruc[], int length, int searchId);
int eProduct_countUsersProducts(eProduct toSearchStruc[], int length, int userId);
int eProduct_unregisterUsersProducts(eProduct toSearchStruc[], int length, int userId);
int eProduct_register(eProduct productList[]);
int eProduct_registerArray(eProduct toRegisterStruc[], int length);
int eProduct_unRegisterArray(eProduct toUnRegisterStruc[], int length);
eProduct eProduct_ModifyOne(eProduct toMofiedStruc);
int eProduct_ModifyArray(eProduct toMofiedStruc[], int length);
int eProduct_Sort(eProduct array[], int TAM, int criterio);
int eProduct_CategorySort(eProduct productList[], int TAM, int criterio);
int eProduct_StockSort(eProduct productList[], int TAM, int criterio);
void eProduct_ForceProducts(eProduct productList[]);

#endif /* EPRODUCT_H_ */
