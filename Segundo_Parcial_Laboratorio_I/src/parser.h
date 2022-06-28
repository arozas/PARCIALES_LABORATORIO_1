/*
 ============================================================================
 Name        : parser.h
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Header file for Parser Library.
 ============================================================================
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>

#include "Arcade.h"
#include "LinkedList.h"
#include "Salon.h"
#include "Juego.h"

int parser_SalonFromText(FILE* pFile , LinkedList* pSalonList);
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArcadeList);
int parser_JuegoFromText(FILE* pFile , LinkedList* pGameList);

int parser_SalonFromBinary(FILE* pFile , LinkedList* pSalonList);
int parser_ArcadeFromBinary(FILE* pFile , LinkedList* pArcadeList);
int parser_GameFromBinary(FILE* pFile , LinkedList* pGameList);

#endif /* PARSER_H_ */
