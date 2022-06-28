/*
 ============================================================================
 Name        : Arcade.h
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Header file for Arcade entity.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"

#ifndef ARCADE_H_
#define ARCADE_H_

#define MONO 1
#define STEREO 2

#define NATIONALITY_LENGTH 25

#define RETRIES 3

typedef struct
{
	int id;
	char nationality[NATIONALITY_LENGTH];
	int soundType;
	int players;
	int coinCapacity;
	int FKSalon;
	int FKGame;

}Arcade;

Arcade* Arcade_new();
Arcade* Arcade_newParametros(char* pId,char* pNationality,char* pSoundType,char*pPlayer,char* pCoinCapacity, char* pFKSalon, char* pFKGame);

void Arcade_delete(Arcade* this);

int Arcade_setId(Arcade* this, int id);
int Arcade_getId(Arcade* this,int* id);

int Arcade_setNationality(Arcade* this, char* pNationality);
int Arcade_getNationality(Arcade* this, char* pNationality);

int Arcade_setSoundType(Arcade* this, int pSoundType);
int Arcade_getSoundType(Arcade* this, int* pSoundType);

int Arcade_setPlayers(Arcade* this, int pPlayers);
int Arcade_getPlayers(Arcade* this, int* pPlayers);

int Arcade_setCoinCapacity(Arcade* this, int pCoinCapacity);
int Arcade_getCoinCapacity(Arcade* this, int* pCoinCapacity);

int Arcade_setFKSalon(Arcade* this, int pFKSalon);
int Arcade_getFKSalon(Arcade* this, int* pFKSalon);

int Arcade_setFKGame(Arcade* this, int pFKGame);
int Arcade_getFKGame(Arcade* this, int* pFKGame);

int Arcade_setData(Arcade* this);

int Arcade_sortById(void* pElementOne,void* pElementTwo);
int Arcade_sortByNationality(void* pElementOne,void* pElementTwo);
int Arcade_sortBySound(void* pElementOne,void* pElementTwo);
int Arcade_sortByPlayers(void* pElementOne,void* pElementTwo);
int Arcade_sortByCoin(void* pElementOne,void* pElementTwo);
int Arcade_sortBySaloon(void* pElementOne,void* pElementTwo);
int Arcade_sortByGame(void* pElementOne,void* pElementTwo);

#endif /* ARCADE_H_ */
