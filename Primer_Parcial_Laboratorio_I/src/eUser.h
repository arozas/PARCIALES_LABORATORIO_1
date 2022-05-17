/*
 * eUser.h
 *
 *  Created on: 13 Mayo de 2022
 *  Author: Alejandro Alberto Martín Rozas
 *  Biblioteca de datos de la entidad eUser.
 *  Versión 0.0 del 13 de Mayo de 2022
 */

#ifndef _H_
#define _H_
//*************************************************   LENGTH DEFINES  *************************************************
#define MAIL_LENGTH 30
#define PASSWORD_LENGTH 10
#define RETRIES 3
#define ADRESS_LENGTH 50
//**************************************************   USER DEFINES   **************************************************
#define ADMIN 0
#define USER 1

#define TRUE 1
#define FALSE 2
#define ID_INIT_VALUE 1000

//*************************************************  INCLUDES  *************************************************
#include <stdio.h>
#include <stdlib.h>

//*************************************************   ENTITY   *************************************************

typedef struct
{
	int id;
	short int isEmpty;

	short int type;
	char email[MAIL_LENGTH];
	char password[PASSWORD_LENGTH];
	char adress[ADRESS_LENGTH];
	int postalCode;
	int buyedProducts;
	int selledProducts;
	float currentMoney;
	float spent;
	float won;

}eUser;

//************************************************* PROTOTYPES *************************************************
int eUser_getUniqueID(void);
int eUser_init(eUser eUserList[], int length);
void eUser_printOne(eUser toPrintStruc);
int eUser_printAll(eUser toPrintStruc[], int length, int status);
int eUser_searchEmptyIndex(eUser toSearchStruc[], int length);
int eUser_searchIndexId(eUser toSearchStruc[], int length);
int eUser_searchId(eUser toSearchStruc[], int length, int searchId);
int eUser_searchEmail(eUser toSearchStruc[], int length, char mailInput[]);
int eUser_create(eUser *userList);
int eUser_unRegisterArray(eUser toUnRegisterStruc[], int length);
eUser eUser_ModifyOne(eUser toMofiedStruc);
int eUser_ModifyArray(eUser toMofiedStruc[], int length);
int eUser_Sort(eUser array[], int TAM, int criterio);
void eUser_ForceUsers(eUser userList[]);

#endif /* _H_ */
