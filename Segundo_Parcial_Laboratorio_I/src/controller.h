/*
 ============================================================================
 Name        : Controller.h
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Header file for Controller libray.
 ============================================================================
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "Arcade.h"
#include "Salon.h"
#include "Juego.h"
#include "LinkedList.h"
#include "parser.h"
#include "menu.h"
#include "input.h"
#include "operations.h"

void controller_msgErroMenu(void);
//LOAD
int controller_loadSalon(char* path , LinkedList* pSalonList);
int controller_loadArcade(char* path , LinkedList* pArcadeList);
int controller_loadGame(char* path , LinkedList* pGameList);

int controller_loadSalonFromBinary(char* path , LinkedList* pSalonList);
int controller_loadArcadeFromBinary(char* path , LinkedList* pArcadeList);
int controller_loadGameFromBinary(char* path , LinkedList* pGameList);
//ADD
int controller_addSalon(LinkedList* pSalonList);
int controller_addArcade(LinkedList* pArcadeList, LinkedList* pSalonList, LinkedList* pGameList);
int controller_addGame(LinkedList* pGameList);
//EDIT
int controller_editArcade(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
//SEARCH
int controller_searchSalonLastId(LinkedList* pSalonlist);
Salon* controller_searchSalonById(LinkedList* pListSalon,int idSearch);
int controller_searchArcadeLastId(LinkedList* pArcadelist);
Arcade* controller_searchArcadeById(LinkedList* pListArcade,int idSearch);
int controller_searchGameLastId(LinkedList* pGamelist);
Juego* controller_searchGameById(LinkedList* pListGame,int idSearch);
//PRINT
int controller_printSalon(Salon* This);
int controller_listSalon(LinkedList* pSalonList);
int controller_ListArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId);
int controller_printArcade(Arcade* this, LinkedList* pListSalon, LinkedList* pListGame);
int controller_ListArcade(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
int Controller_listArcadeSortByGame(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame);
int controller_printGame(Juego* this);
int controller_listGames(LinkedList* pGamesList);
//SORT
int controller_sortSaloon(LinkedList* pListSalon);
int controller_sortSaloonNoMenu(LinkedList* pListSalon, int OrderFun, int Order);
int controller_sortArcade(LinkedList* pArcadeList);
int controller_sortArcadeNoMenu(LinkedList* pArcadeList, int OrderFun, int Order);
int controller_sortGame(LinkedList* pGamesList);
int controller_sortGameNoMenu(LinkedList* pGamesList, int OrderFun, int Order);
//REMOVE
int controller_removeSalon(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame);
int controller_removeArcade(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
int controller_removeArcadeByID(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int bufferId);
int controller_removeArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int SalonId);
//COUNT
int controller_countArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId);
int controller_countGenreArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId);
//REPORTS
int controller_reportA(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
int controller_reportB(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
int controller_reportC(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame);
int controller_reportD(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
int controller_reportE(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame);
int controller_reportF(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
int controller_reportG(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
//FILTER
LinkedList* controller_filterArcadeBySound(LinkedList* pArcadeList);
int controller_listFilteredArcadeList(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame);
//SAVE
int controller_saveSalon(char* path , LinkedList* pSalonlist);
int controller_saveArcade(char* path , LinkedList* pArcadelist);
int controller_saveGame(char* path , LinkedList* pGamelist);

int controller_savesSalonAsBinary(char* path , LinkedList* pSalonlist);
int controller_savesArcadeAsBinary(char* path , LinkedList* pArcadelist);
int controller_savesGameAsBinary(char* path , LinkedList* pGamelist);

#endif /* CONTROLLER_H_ */
