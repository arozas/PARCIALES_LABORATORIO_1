/*
 ============================================================================
 Name        : Salon.h
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Header file for Salon entity.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"

#ifndef SALON_H_
#define SALON_H_
// *************************************** STRING LENGTH **************************************
#define NAME_LENGTH 50
#define	ADRESS_LENGTH 50
// **************************************** SALON TYPES ***************************************
#define LOCAL 1
#define SHOPPING 2

#define RETRIES 3

typedef struct
{
	int id;
	char name[NAME_LENGTH];
	char adress[ADRESS_LENGTH];
	int type;

}Salon;

Salon* Salon_new();
Salon* Salon_newParametros(char* idStr,char* nameStr,char*adressStr,char* typeStr);

void Salon_delete(Salon* this);

int Salon_setId(Salon* this,int id);
int Salon_getId(Salon* this,int* id);


int Salon_setName(Salon* this,char* pName);
int Salon_getName(Salon* this,char* pName);

int Salon_setAdress(Salon* this,char* pAdress);
int Salon_getAdress(Salon* this,char* pAdress);

int Salon_setType(Salon* this, int pType);
int Salon_getType(Salon* this, int* pType);

int Salon_setData(Salon* this);

int Salon_sortById(void* pElementOne,void* pElementTwo);
int Salon_sortByName(void* pElementOne,void* pElementTwo);
int Salon_sortByAdress(void* pElementOne,void* pElementTwo);
int Salon_sortByType(void* pElementOne,void* pElementTwo);

#endif /* SALON_H_ */
