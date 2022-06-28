/*
 ============================================================================
 Name        : Juego.h
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Header file for Juego entity.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"

#ifndef JUEGOS_H_
#define JUEGOS_H_
// *************************************** STRING LENGTH **************************************
#define NAME_LENGTH 50
#define	COMPANY_LENGTH 50
// **************************************** GAMES GENRE ***************************************
#define AVENTURE 1
#define BEATEMUP 2
#define LABYRINTH 3
#define FIGHT 4
#define PLATFORM 5
#define SHOOTER 6

#define RETRIES 3

typedef struct
{
	int id;
	char name[NAME_LENGTH];
	char company[COMPANY_LENGTH];
	int genre;
}Juego;

Juego* Juego_new();
Juego* Juego_newParametros(char* pId,char* pName,char*pCompany,char* pGenre);

void Juego_delete(Juego* this);

int Juego_setId(Juego* this, int pId);
int Juego_getId(Juego* this,int* pId);

int Juego_setName(Juego* this,char* pName);
int Juego_getName(Juego* this,char* pName);

int Juego_setCompany(Juego* this,char* pCompany);
int Juego_getCompany(Juego* this,char* pCompany);

int Juego_setGenre(Juego* this, int pGenre);
int Juego_getGenre(Juego* this,int* pGenre);

int Juego_setData(Juego* this);

int Juego_sortById(void* pElementOne,void* pElementTwo);
int Juego_sortByName(void* pElementOne,void* pElementTwo);
int Juego_sortByCompany(void* pElementOne,void* pElementTwo);
int Juego_sortByGenre(void* pElementOne,void* pElementTwo);

#endif /* JUEGOS_H_ */
