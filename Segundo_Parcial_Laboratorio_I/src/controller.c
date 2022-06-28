/*
 ============================================================================
 Name        : Controller.h
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Source file for Controller libray.
 ============================================================================
 */
#include "controller.h"

//====================================================== MESAGGES ==============================================================================
void controller_msgErroMenu(void)
{
	printf("\nERROR, NO SELECCIONÓ UNA OPCIÓN DEL MENU VALIDA, VUELVA A INTENTARLO.\n");
}
//====================================================== LOAD FILES ==============================================================================
/// @fn int controller_loadSalon(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pSalonList
/// @return
int controller_loadSalon(char* path , LinkedList* pSalonList)
{
	int rtn = -1;
	FILE* pFile = NULL;
	if (access(path, F_OK) == 0)
	{
		pFile = fopen(path,"r");
		if(path != NULL && pSalonList != NULL)
		{
			if(pFile == NULL)
			{
				printf("\nNO SE PUDO ABRIR EL ARCHIVO DE SALONES");
			}
			else
			{
				if(ll_isEmpty(pSalonList) == 1)
				{

					if(parser_SalonFromText(pFile,pSalonList) == 0)
					{
						printf("\nSE CARGO EL ARCHIVO SALONES CON EXITO");
						rtn = 0;
					}
					else
					{
						printf("\nERROR DE PARSER");
					}
				}
			}
		}
		fclose(pFile);
	}
	else
	{
		printf("\nNO EXISTE EL ARCHIVO DE SALONES");
	}
	return rtn;
}
/// @fn int controller_loadArcade(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pArcadeList
/// @return
int controller_loadArcade(char* path , LinkedList* pArcadeList)
{
	int rtn = -1;
	FILE* pFile;
	if (access(path, F_OK) == 0)
	{
		pFile = fopen(path,"r");
		if(path != NULL && pArcadeList != NULL)
		{
			if(pFile == NULL )
			{
				printf("\nNO SE PUDO ABRIR EL ARCHIVO ARCADES");
			}
			else
			{
				if(ll_isEmpty(pArcadeList) == 1)
				{

					if(parser_ArcadeFromText(pFile,pArcadeList) == 0)
					{
						printf("\nSE CARGO EL ARCHIVO ARCADES CON EXITO");
						rtn = 0;
					}
					else
					{
						printf("\nERROR DE PARSER");
					}
				}
			}
		}
		fclose(pFile);
	}
	else
	{
		printf("\nNO EXISTE EL ARCHIVO DE ARCADES");
	}
	return rtn;
}
/// @fn int controller_loadGame(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pGameList
/// @return
int controller_loadGame(char* path , LinkedList* pGameList)
{
	int rtn = -1;
	FILE* pFile;
	if (access(path, F_OK) == 0)
	{
		pFile = fopen(path,"r");
		if(path != NULL && pGameList != NULL)
		{

			if(pFile == NULL )
			{
				printf("\nNO SE PUDO ABRIR EL ARCHIVO DE JUEGOS");
			}
			else
			{
				if(ll_isEmpty(pGameList) == 1)
				{

					if(parser_JuegoFromText(pFile,pGameList) == 0)
					{
						printf("\nSE CARGO EL ARCHIVO JUEGOS CON EXITO");
						rtn = 0;
					}
					else
					{
						printf("\nERROR DE PARSER");
					}
				}
			}
		}
		fclose(pFile);
	}
	else
	{
		printf("\nNO EXISTE EL ARCHIVO DE ARCADES");
	}
	return rtn;
}
//====================================================== ADD ==============================================================================
/// @fn int controller_addSalon(LinkedList*)
/// @brief
///
/// @param pSalonList
/// @return
int controller_addSalon(LinkedList* pSalonList)
{
	int rtn = -1;
	int lastID;
	Salon* pSalon;
	if (pSalonList != NULL)
	{
		lastID = controller_searchSalonLastId(pSalonList);
		pSalon = Salon_new();
		if(pSalon != NULL && lastID != -1)
		{
			if(Salon_setData(pSalon)==0 && pSalon != NULL)
			{
				lastID++;
				Salon_setId(pSalon, lastID);
				ll_add(pSalonList, pSalon);
				printf("\nSE HA CARGADO CON EXITO EL NUEVO SALON");
				printf(	"\n------------------------------------------------------------|");
				printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
				printf(	"\n------------------------------------------------------------|");
				controller_printSalon(pSalon);
				printf(	"\n------------------------------------------------------------|");
				rtn = 0;
			}
			else
			{
				printf("\nNO SE HA PODIDO CARGAR EL SALON");
			}
		}
	}

	return rtn;
}
/// @fn int controller_addArcade(LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @return
int controller_addArcade(LinkedList* pArcadeList, LinkedList* pSalonList, LinkedList* pGameList)
{
	int rtn = -1;
	int lastID;
	int salonIdBuffer;
	int gameIdBuffer;
	Arcade* pArcade;
	if (pArcadeList != NULL && pSalonList != NULL && pGameList != NULL)
	{
		if(ll_isEmpty(pSalonList) == 0  && ll_isEmpty(pSalonList) == 0)
		{
			lastID = controller_searchArcadeLastId(pArcadeList);
			pArcade = Arcade_new();
			if(pArcade != NULL && lastID != -1)
			{
				if(Arcade_setData(pArcade)==0 && pArcade != NULL)
				{
					controller_listSalon(pSalonList);
					printf("\nDEBE SELECCIONAR DONDE ESTÁ EL SALÓN DONDE ESTA EL ARCADE");
					if(input_getInt("INGRESE EL ID DEL SALÓN:", RETRIES, 1, 1000, "DEBE INGRESAR UN ID VALIDO:", &salonIdBuffer)==0)
					{
						controller_listGames(pGameList);
						printf("\nDEBE SELECCIONAR EL JUEGO INSTALADO EN EL ARCADE");
						if(input_getInt("INGRESE EL ID DEL JUEGO:", RETRIES, 1, 1000, "DEBE INGRESAR UN ID VALIDO:", &gameIdBuffer)==0)
						{
							lastID++;
							Arcade_setFKSalon(pArcade, salonIdBuffer);
							Arcade_setFKGame(pArcade, gameIdBuffer);
							Arcade_setId(pArcade, lastID);
							ll_add(pArcadeList, pArcade);
							printf("\nSE HA CARGADO CON EXITO EL NUEVO ARCADE");
							printf(	"\n----------------------------------------------------------------------------|");
							printf("\n%-6s%-10s%-15s%-15s%-15s%-15s","ID","SONIDO","JUGADORES","FICHAS MAX", "SALON", "JUEGO");
							controller_printArcade(pArcade, pSalonList, pGameList);
							printf(	"\n----------------------------------------------------------------------------|");
							rtn = 0;
						}
						else
						{
							printf("\nERROR EN LA CARGA DEL ID DEL JUEGO");
							printf("\nNO SE HA PODIDO CARGAR EL ARCADE");
						}
					}
					else
					{
						printf("\nERROR EN LA CARGA DEL ID DEL SALON");
						printf("\nNO SE HA PODIDO CARGAR EL ARCADE");
					}

				}
				else
				{
					printf("\nERROR EN LA CARGA DATOS DEL ARCADE");
					printf("\nNO SE HA PODIDO CARGAR EL ARCADE");
				}
			}
		}
		else
		{
			printf("\nNO SE PUEDE CARGAR ARCADES SI NO HAY SALONES Y JUEGOS CARGADOS");
			printf("\nCARGUE UN SALON Y UN JUEGO COMO MINIMO PARA CARGAR ARCADES");
		}
	}
	return rtn;
}
/// @fn int controller_addGame(LinkedList*)
/// @brief
///
/// @param pGameList
/// @return
int controller_addGame(LinkedList* pGameList)
{
	{
		int rtn = -1;
		int lastID;
		Juego* pGame;
		if (pGameList != NULL)
		{
			lastID = controller_searchGameLastId(pGameList);
			pGame = Juego_new();
			if(pGame != NULL && lastID != -1)
			{
				if(Juego_setData(pGame)==0 && pGame != NULL)
				{
					lastID++;
					Juego_setId(pGame, lastID);
					ll_add(pGameList, pGame);
					printf("\nSE HA CARGADO CON EXITO EL NUEVO JUEGO");
					printf(	"\n------------------------------------------------------------|");
					printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","EMPRESA","GENERO");
					controller_printGame(pGame);
					rtn = 0;
				}
				else
				{
					printf("\nNO SE HA PODIDO CARGAR EL JUEGO");
				}
			}
		}

		return rtn;
	}
}
//====================================================== END ADD ==============================================================================
//====================================================== EDIT ==============================================================================
/// @fn int controller_editArcade(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_editArcade(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int bufferId;
	int menu;
	int playersBuffer;
	int gameIDBuffer;
	Arcade* pArcade = NULL;
	Juego* pGame = NULL;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		controller_ListArcade(pArcadeList, pListSalon, pListGame);
		if(input_getIntNoRange("INGRESE EL ID DEL ARCADE a MODIFICAR:", RETRIES, "ERROR, INGRESE UN ID VALIDO:", &bufferId) == 0)
		{
			pArcade = controller_searchArcadeById(pArcadeList,bufferId);
			if(pArcade != NULL)
			{
				do{
					menu = menu_menu("ELIJA CAMPO A MODIFICAR",
							"\n1 - CANTIDAD DE JUGADORES"
							"\n2 - JUEGO DEL ARCADE"
							"\n3 - SALIR DE MODIFICAR ARCADE",
							"ERROR, INGRESE UNA OPCIÓN <1-3>:",
							RETRIES, 3);
					switch(menu)
					{
					case 1:
						if(input_getInt("INGRESE EL NUMERO DE JUGADORES:", RETRIES, 1, 4, "ERROR, INGRESE <1-4> JUGADORES:", &playersBuffer)==0)
						{
							printf("\nLA CANTIDAD DE JUGADORES INGRESADA ES: %d",playersBuffer);
							if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
							{
								Arcade_setPlayers(pArcade, playersBuffer);
								printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
							}
							else
							{
								printf("\nSE HA CANCELADO LA MODIFICACIÓN");
							}
						}
						else
						{
							printf("\nERROR EN LA MODIFICACIÓN, MODIFICACIÓN NO REALIZADA");
						}
						break;
					case 2:
						controller_listGames(pListGame);
						printf("\nDEBE SELECCIONAR EL JUEGO INSTALADO EN EL ARCADE");
						if(input_getInt("INGRESE EL ID DEL JUEGO:", RETRIES, 1, 1000, "DEBE INGRESAR UN ID VALIDO:", &gameIDBuffer)==0)
						{
							pGame = controller_searchGameById(pListGame, gameIDBuffer);
							if(pGame != NULL)
							{
								printf("\nEL NOMBRE DEL JUEGO SELECCIONADO ES:");
								printf(	"\n------------------------------------------------------------|");
								printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","EMPRESA","GENERO");
								controller_printGame(pGame);
								if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
								{
									Arcade_setFKGame(pArcade, gameIDBuffer);
									printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
								}
								else
								{
									printf("\nSE HA CANCELADO LA MODIFICACIÓN");
								}
							}
						}
						break;
					}
				}while(menu<3);
			}
		}
	}
	return rtn;
}
//====================================================== END EDIT ==============================================================================
//====================================================== SEARCH ID ==============================================================================
/// @fn int controller_searchSalonLastId(LinkedList*)
/// @brief
///
/// @param pSalonlist
/// @return
int controller_searchSalonLastId(LinkedList* pSalonlist)
{
	int rtn = -1;
	int listSize;
	int i;
	int bufferId;
	int maxId = 0000;
	Salon* pSalon;
	int flagMaxId = 0;
	if(pSalonlist != NULL)
	{
		if(ll_isEmpty(pSalonlist) == 0)
		{
			listSize=ll_len(pSalonlist);
			for (i = 0; i < listSize; i++)
			{
				pSalon = (Salon*)ll_get(pSalonlist, i);
				Salon_getId(pSalon,&bufferId);
				if(flagMaxId == 0 || bufferId > maxId)
				{
					maxId = bufferId;
					flagMaxId = 1;
					rtn = maxId;
				}
			}
		}
		else
		{
			printf("\nNO HAY SALONES CARGADADOS EN LA BASE DE DATOS");
			printf("\nSE EMPEZARÁ UNA NUEVA LISTA DE ID");
			rtn = maxId;
		}
	}
	return rtn;
}
/// @fn Salon controller_searchSalonById*(LinkedList*, int)
/// @brief
///
/// @param pListSalon
/// @param idSearch
/// @return
Salon* controller_searchSalonById(LinkedList* pListSalon,int idSearch)
{
	Salon* rtn = NULL;
	int sizeLinkedList;
	int i;
	int bufferID;
	Salon* pSalon;
	if(pListSalon != NULL)
	{
		if(ll_isEmpty(pListSalon) == 0)
		{
			sizeLinkedList=ll_len(pListSalon);
			for (i = 0; i < sizeLinkedList; i++)
			{
				pSalon = (Salon*)ll_get(pListSalon, i);
				Salon_getId(pSalon,&bufferID);
				if(bufferID == idSearch)
				{
					rtn = pSalon;
					break;
				}
			}//FIN FOR
			if(rtn != pSalon)
			{
				printf("\nNO SE ENCONTRÓ EL ID EN LA BASE DE DATOS");
			}
		}
		else
		{
			printf("\nNO HAY PASAJEROS EN LA BASE DE DATOS");
		}
	}

	return rtn;
}
/// @fn int controller_searchArcadeLastId(LinkedList*)
/// @brief
///
/// @param pArcadelist
/// @return
int controller_searchArcadeLastId(LinkedList* pArcadelist)
{
	int rtn = -1;
	int listSize;
	int i;
	int bufferId;
	int maxId = 0000;
	Arcade* pArcade;
	int flagMaxId = 0;
	if(pArcadelist != NULL)
	{
		if(ll_isEmpty(pArcadelist) == 0)
		{
			listSize=ll_len(pArcadelist);
			for (i = 0; i < listSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadelist, i);
				Arcade_getId(pArcade,&bufferId);
				if(flagMaxId == 0 || bufferId > maxId)
				{
					maxId = bufferId;
					flagMaxId = 1;
					rtn = maxId;
				}
			}
		}
		else
		{
			printf("\nNO HAY ARCADES CARGADADOS EN LA BASE DE DATOS");
			printf("\nSE EMPEZARÁ UNA NUEVA LISTA DE ID");
			rtn = maxId;
		}
	}
	return rtn;
}
/// @fn Arcade controller_searchArcadeById*(LinkedList*, int)
/// @brief
///
/// @param pListArcade
/// @param idSearch
/// @return
Arcade* controller_searchArcadeById(LinkedList* pListArcade,int idSearch)
{
	Arcade* rtn = NULL;
	int sizeLinkedList;
	int i;
	int bufferID;
	Arcade* pArcade;
	if(pListArcade != NULL)
	{
		if(ll_isEmpty(pListArcade) == 0)
		{
			sizeLinkedList=ll_len(pListArcade);
			for (i = 0; i < sizeLinkedList; i++)
			{
				pArcade = (Arcade*)ll_get(pListArcade, i);
				Arcade_getId(pArcade,&bufferID);
				if(bufferID == idSearch)
				{
					rtn = pArcade;
					break;
				}
			}//FIN FOR
			if(rtn != pArcade)
			{
				printf("\nNO SE ENCONTRÓ EL ID EN LA BASE DE DATOS");
			}
		}
		else
		{
			printf("\nNO HAY PASAJEROS EN LA BASE DE DATOS");
		}
	}

	return rtn;
}
/// @fn int controller_searchGameLastId(LinkedList*)
/// @brief
///
/// @param pGamelist
/// @return
int controller_searchGameLastId(LinkedList* pGamelist)
{
	int rtn = -1;
	int listSize;
	int i;
	int bufferId;
	int maxId = 0;
	Juego* pGame;
	int flagMaxId = 0;
	if(pGamelist != NULL)
	{
		if(ll_isEmpty(pGamelist) == 0)
		{
			listSize=ll_len(pGamelist);
			for (i = 0; i < listSize; i++)
			{
				pGame = (Juego*)ll_get(pGamelist, i);
				Juego_getId(pGame,&bufferId);
				if(flagMaxId == 0 || bufferId > maxId)
				{
					maxId = bufferId;
					flagMaxId = 1;
					rtn = maxId;
				}
			}
		}
		else
		{
			printf("\nNO HAY ARCADES CARGADADOS EN LA BASE DE DATOS");
			printf("\nSE EMPEZARÁ UNA NUEVA LISTA DE ID");
			rtn = maxId;
		}
	}
	return rtn;
}
/// @fn Juego controller_searchGameById*(LinkedList*, int)
/// @brief
///
/// @param pListGame
/// @param idSearch
/// @return
Juego* controller_searchGameById(LinkedList* pListGame,int idSearch)
{
	Juego* rtn = NULL;
	int sizeLinkedList;
	int i;
	int bufferID;
	Juego* pGame;
	if(pListGame != NULL)
	{
		if(ll_isEmpty(pListGame) == 0)
		{
			sizeLinkedList=ll_len(pListGame);
			for (i = 0; i < sizeLinkedList; i++)
			{
				pGame = (Juego*)ll_get(pListGame, i);
				Juego_getId(pGame,&bufferID);
				if(bufferID == idSearch)
				{
					rtn = pGame;
					break;
				}
			}//FIN FOR
			if(rtn != pGame)
			{
				printf("\nNO SE ENCONTRÓ EL ID EN LA BASE DE DATOS");
			}
		}
		else
		{
			printf("\nNO HAY JUEGOS EN LA BASE DE DATOS");
		}
	}
	return rtn;
}
//======================================================  END SEARCH ID ==============================================================================
//====================================================== PRINT ==============================================================================
/// @fn int controller_printSalon(Salon*)
/// @brief
///
/// @param this
/// @return
int controller_printSalon(Salon* this)
{
	int rtn = -1;
	int idBuffer;
	char nameBuffer[NAME_LENGTH];
	char adressBuffer[ADRESS_LENGTH];
	int typeBuffer;
	if(this != NULL)
	{
		Salon_getId(this, &idBuffer);
		Salon_getName(this, nameBuffer);
		Salon_getAdress(this, adressBuffer);
		Salon_getType(this, &typeBuffer);

		printf("\n%-6d%-20s%-20s",idBuffer,nameBuffer,adressBuffer);
		switch(typeBuffer)
		{
		case LOCAL:
			printf("%-20s","LOCAL");
			break;
		case SHOPPING:
			printf("%-20s","SHOPPING");
			break;
		}
		rtn = 0;
	}
	return rtn;
}
/// @fn int controller_listSalon(LinkedList*)
/// @brief
///
/// @param pSalonList
/// @return
int controller_listSalon(LinkedList* pSalonList)
{
	int rtn = -1;
	int i;
	int listSize;
	Salon* pSalon;
	if(pSalonList != NULL)
	{
		listSize = ll_len(pSalonList);
		if(listSize != -1)
		{		printf(
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                           SALONES"
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
		for (i = 0; i < listSize; i++)
		{
			pSalon = (Salon*)ll_get(pSalonList, i);
			if(pSalon != NULL)
			{
				printf(	"\n------------------------------------------------------------|");
				controller_printSalon(pSalon);
				rtn = 0;
			}
		}
		printf(	"\n------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
/// @fn int controller_ListArcadeBySalon(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @param salonId
/// @return
int controller_ListArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId)
{
	int rtn = -1;
	int i;
	int listSize;
	Arcade* pArcade;
	int FKsalonID;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		listSize = ll_len(pArcadeList);
		if(listSize != -1)
		{
			printf(
					"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
					"\n                                             ARCADES"
					"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
			printf("\n%-6s%-10s%-15s%-15s%-15s%-15s%-15s","ID","SONIDO","NACIONALIDAD","JUGADORES","FICHAS MAX", "SALON", "JUEGO");
			for (i = 0; i < listSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadeList, i);
				Arcade_getFKSalon(pArcade, &FKsalonID);
				if(pArcade != NULL && FKsalonID == salonId)
				{
					printf(	"\n------------------------------------------------------------------------------------------------|");
					controller_printArcade(pArcade, pListSalon, pListGame);
					rtn = 0;
				}
			}
			printf(	"\n------------------------------------------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
/// @fn int controller_printArcade(Arcade*, LinkedList*, LinkedList*)
/// @brief
///
/// @param this
/// @param pListSalon
/// @param pListGame
/// @return
int controller_printArcade(Arcade* this, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int idBuffer;
	int soundTypeBuffer;
	char nationalityBuffer[NATIONALITY_LENGTH];
	int playersBuffer;
	int coinBuffer;
	int FKsalonBuffer;
	int FKgameBuffer;
	char salonName[NAME_LENGTH];
	char gameName[NAME_LENGTH];
	Salon* salonBuffer;
	Juego* gameBuffer;
	if(this != NULL)
	{
		if(Arcade_getId(this, &idBuffer)==0 &&
				Arcade_getNationality(this, nationalityBuffer) == 0 &&
				Arcade_getSoundType(this, &soundTypeBuffer)== 0 &&
				Arcade_getPlayers(this, &playersBuffer) == 0 &&
				Arcade_getCoinCapacity(this, &coinBuffer) == 0 &&
				Arcade_getFKSalon(this, &FKsalonBuffer) == 0 &&
				Arcade_getFKGame(this, &FKgameBuffer) == 0)
		{
			salonBuffer = controller_searchSalonById(pListSalon, FKsalonBuffer);
			gameBuffer = controller_searchGameById(pListGame, FKgameBuffer);
			Salon_getName(salonBuffer, salonName);
			Juego_getName(gameBuffer, gameName);
			if(salonBuffer != NULL && gameBuffer != NULL)
			{
				printf("\n%-6d",idBuffer);
				switch(soundTypeBuffer)
				{
				case MONO:
					printf("%-10s","MONO");
					break;
				case STEREO:
					printf("%-10s","ESTEREO");
					break;
				}
				printf("%-15s%-15d%-15d",nationalityBuffer,playersBuffer,coinBuffer);
				printf("%-15s%-15s",salonName,gameName);
			}
		}
	}
	return rtn;
}
int controller_ListArcade(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int i;
	int listSize;
	Arcade* pArcade;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		listSize = ll_len(pArcadeList);
		if(listSize != -1)
		{
			printf(
					"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
					"\n                                             ARCADES"
					"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
			printf("\n%-6s%-10s%-15s%-15s%-15s%-15s%-15s","ID","SONIDO","NACIONALIDAD","JUGADORES","FICHAS MAX", "SALON", "JUEGO");
			for (i = 0; i < listSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadeList, i);
				if(pArcade != NULL)
				{
					printf(	"\n------------------------------------------------------------------------------------------------|");
					controller_printArcade(pArcade, pListSalon, pListGame);
					rtn = 0;
				}
			}
			printf(	"\n------------------------------------------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
/// @fn int Controller_listArcadeSortByGame(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief
///
/// @param pListSalon
/// @param pListArcade
/// @param pListGame
/// @param salonId
/// @return
int Controller_listArcadeSortByGame(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame)
{
	int rtn = 0;
	int i, j;
	LinkedList* gameList = NULL;
	gameList = ll_clone(pListGame);
	int gameListSize;
	LinkedList* arcadeList = NULL;
	arcadeList = ll_clone(pListArcade);
	int arcadeListSize;
	Juego* gameBuffer;
	int gameId;
	int genre;
	Arcade* pArcade;
	int arcadeGameID;
	int arcadeSound;
	if( gameList != NULL && ll_sort(gameList, Juego_sortByName, 1)==0)
	{
		gameListSize = ll_len(gameList);
		arcadeListSize  = ll_len(arcadeList);
		if(gameListSize != -1)
		{
			for (i = 0; i < gameListSize; i++)
			{
				gameBuffer = (Juego*)ll_get(pListGame, i);
				Juego_getId(gameBuffer, &gameId);
				Juego_getGenre(gameBuffer, &genre);
				for(j = 0; j < arcadeListSize; j++)
				{
					pArcade = (Arcade*)ll_get(pListArcade, j);
					Arcade_getFKGame(pArcade, &arcadeGameID);
					Arcade_getSoundType(pArcade, &arcadeSound);
					if(gameId==arcadeGameID && genre == PLATFORM && arcadeSound == MONO)
					{
						printf(	"\n------------------------------------------------------------------------------------------------|");
						controller_printArcade(pArcade, pListSalon, pListGame);
						printf(	"\n------------------------------------------------------------------------------------------------|");
						rtn = 0;
					}
				}
			}
		}
	}
	return rtn;
}
/// @fn int controller_printGame(Juego*)
/// @brief
///
/// @param this
/// @return
int controller_printGame(Juego* this)
{
	int rtn = -1;
	int idBuffer;
	char nameBuffer[NAME_LENGTH];
	char companyBuffer[COMPANY_LENGTH];
	int genreBuffer;
	if(this != NULL)
	{
		Juego_getId(this, &idBuffer);
		Juego_getName(this, nameBuffer);
		Juego_getCompany(this, companyBuffer);
		Juego_getGenre(this, &genreBuffer);

		printf(	"\n------------------------------------------------------------|");
		printf("\n%-6d%-20s%-20s",idBuffer,nameBuffer,companyBuffer);
		switch(genreBuffer)
		{
		case AVENTURE:
			printf("%-20s","AVENTURA");
			break;
		case BEATEMUP:
			printf("%-20s","BEAT'EM UP");
			break;
		case LABYRINTH:
			printf("%-20s","LABERINTO");
			break;
		case FIGHT:
			printf("%-20s","PELEA");
			break;
		case PLATFORM:
			printf("%-20s","PLATAFORMA");
			break;
		case SHOOTER:
			printf("%-20s","TIROS");
			break;
		}

		rtn = 0;
	}
	return rtn;
}
/// @fn int controller_listGames(LinkedList*)
/// @brief
///
/// @param pGamesList
/// @return
int controller_listGames(LinkedList* pGamesList)
{
	int rtn = -1;
	int i;
	int listSize;
	Juego* pGame;
	if(pGamesList != NULL)
	{
		listSize = ll_len(pGamesList);
		if(listSize != -1)
		{		printf(
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                           JUEGOS"
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","COMPAÑIA","GENERO");
		for (i = 0; i < listSize; i++)
		{
			pGame = (Juego*)ll_get(pGamesList, i);
			if(pGame != NULL)
			{
				controller_printGame(pGame);
				rtn = 0;
			}
		}//FIN FOR
		printf(	"\n------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
//======================================================  END PRINT ==============================================================================
//======================================================  SORT ==============================================================================
/// @fn int controller_sortSaloon(LinkedList*)
/// @brief
///
/// @param pListSalon
/// @return
int controller_sortSaloon(LinkedList* pListSalon)
{
	int rtn = -1;
	int orderCriteria[2]={-1,-1};
	int(*pToOrder)(void*,void*);
	if(pListSalon != NULL)
	{
		if(ll_isEmpty(pListSalon) == 0)
		{
			orderCriteria[0]=menu_menu("CRITERIO DE ORFENAMIENTO",
					"\n1 - IDS"
					"\n2 - NOMBRE"
					"\n3 - DIRECCIÓN"
					"\n4 - TIPO"
					, "ERROR, INGRESE UNA OPCIÓN <1-4>", RETRIES, 4);
			switch (orderCriteria[0])
			{
			case 1:
				pToOrder = Salon_sortById;
				break;
			case 2:
				pToOrder = Salon_sortByName;
				break;
			case 3:
				pToOrder = Salon_sortByAdress;
				break;
			case 4:
				pToOrder = Salon_sortByType;
				break;
			}
			if(orderCriteria[0]!=-1)
			{
				orderCriteria[1]=menu_menu("FORMA DE ORDENAMIENTO",
						"\n1 - DESCENDENTE"
						"\n2 - ASCENDENTE",
						"ERROR, INGRESE UNA OPCIÓN <1-2>", RETRIES, 2);
			}
			else
			{
				orderCriteria[1] = -1;
			}
			if(orderCriteria[1] != -1)
			{
				if(orderCriteria[1] == 1)
				{
					orderCriteria[1] = 0;
				}
				else
				{
					orderCriteria[1] = 1;
				}
				if(ll_sort(pListSalon,pToOrder,orderCriteria[1]) == 0)
				{
					printf("\nSE ORDENARON LOS SALONES SEGUN EL CRITERIO ELEGIDO.");
					rtn = 0;
				}
				else
				{
					printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
				}

			}
		}

	}else
	{
		printf("NO HAY SALONES CARGADOS");
	}
	return rtn;
}
/// @fn int controller_sortSaloonNoMenu(LinkedList*, int, int)
/// @brief
///
/// @param pListSalon
/// @param OrderFun
/// @param Order
/// @return
int controller_sortSaloonNoMenu(LinkedList* pListSalon, int OrderFun, int Order)
{
	int rtn = -1;
	int(*pToOrder)(void*,void*);
	if(pListSalon != NULL)
	{
		if(ll_isEmpty(pListSalon) == 0)
		{
			switch (OrderFun)
			{
			case 1:
				pToOrder = Salon_sortById;
				break;
			case 2:
				pToOrder = Salon_sortByName;
				break;
			case 3:
				pToOrder = Salon_sortByAdress;
				break;
			case 4:
				pToOrder = Salon_sortByType;
				break;
			default:
				printf("\nNO SE EXISTE ESA OPCION DE ORDENAMIENTO");
				break;
			}
			if(OrderFun < 5 && ll_sort(pListSalon,pToOrder,Order) == 0)
			{
				rtn = 0;
			}
			else
			{
				printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
			}

		}
	}
	else
	{
		printf("NO HAY SALONES CARGADOS");
	}
	return rtn;
}
/// @fn int controller_sortArcade(LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @return
int controller_sortArcade(LinkedList* pArcadeList)
{
	int rtn = -1;
	int orderCriteria[2]={-1,-1};
	int(*pToOrder)(void*,void*);
	if(pArcadeList != NULL)
	{
		if(ll_isEmpty(pArcadeList) == 0)
		{
			orderCriteria[0]=menu_menu("CRITERIO DE ORFENAMIENTO",
					"\n1 - IDS"
					"\n2 - NACIONALIDAD"
					"\n3 - SONIDO"
					"\n4 - PLAYERS"
					"\n5 - CAPACIDAD DE FICHAS"
					"\n6 - SALÓN"
					"\n7 - JUEGO"
					, "ERROR, INGRESE UNA OPCIÓN <1-7>", RETRIES, 7);
			switch (orderCriteria[0])
			{
			case 1:
				pToOrder = Arcade_sortById;
				break;
			case 2:
				pToOrder = Arcade_sortByNationality;
				break;
			case 3:
				pToOrder = Arcade_sortBySound;
				break;
			case 4:
				pToOrder = Arcade_sortByPlayers;
				break;
			case 5:
				pToOrder = Arcade_sortByCoin;
				break;
			case 6:
				pToOrder = Arcade_sortBySaloon;
				break;
			case 7:
				pToOrder = Arcade_sortByGame;
				break;
			}
			if(orderCriteria[0]!=-1)
			{
				orderCriteria[1]=menu_menu("FORMA DE ORDENAMIENTO",
						"\n1 - DESCENDENTE"
						"\n2 - ASCENDENTE",
						"ERROR, INGRESE UNA OPCIÓN <1-2>", RETRIES, 2);
			}
			else
			{
				orderCriteria[1] = -1;
			}
			if(orderCriteria[1] != -1)
			{
				if(orderCriteria[1] == 1)
				{
					orderCriteria[1] = 0;
				}
				else
				{
					orderCriteria[1] = 1;
				}
				if(ll_sort(pArcadeList,pToOrder,orderCriteria[1]) == 0)
				{
					printf("\nSE ORDENARON LOS ARCADES SEGUN EL CRITERIO ELEGIDO.");
					rtn = 0;
				}
				else
				{
					printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
				}

			}
		}

	}else
	{
		printf("NO HAY ARCADES CARGADOS");
	}
	return rtn;
}
/// @fn int controller_sortArcadeNoMenu(LinkedList*, int, int)
/// @brief
///
/// @param pArcadeList
/// @param OrderFun
/// @param Order
/// @return
int controller_sortArcadeNoMenu(LinkedList* pArcadeList, int OrderFun, int Order)
{
	int rtn = -1;
	int(*pToOrder)(void*,void*);
	if(pArcadeList != NULL)
	{
		if(ll_isEmpty(pArcadeList) == 0)
		{
			switch (OrderFun)
			{
			case 1:
				pToOrder = Arcade_sortById;
				break;
			case 2:
				pToOrder = Arcade_sortByNationality;
				break;
			case 3:
				pToOrder = Arcade_sortBySound;
				break;
			case 4:
				pToOrder = Arcade_sortByPlayers;
				break;
			case 5:
				pToOrder = Arcade_sortByCoin;
				break;
			case 6:
				pToOrder = Arcade_sortBySaloon;
				break;
			case 7:
				pToOrder = Arcade_sortByGame;
				break;
			default:
				printf("\nNO SE EXISTE ESA OPCION DE ORDENAMIENTO");
				break;
			}
			if(OrderFun < 8 && ll_sort(pArcadeList,pToOrder,Order) == 0)
			{
				rtn = 0;
			}
			else
			{
				printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
			}

		}
	}
	else
	{
		printf("NO HAY SALONES CARGADOS");
	}
	return rtn;
}
/// @fn int controller_sortGame(LinkedList*)
/// @brief
///
/// @param pGamesList
/// @return
int controller_sortGame(LinkedList* pGamesList)
{
	int rtn = -1;
	int orderCriteria[2]={-1,-1};
	int(*pToOrder)(void*,void*);
	if(pGamesList != NULL)
	{
		if(ll_isEmpty(pGamesList) == 0)
		{
			orderCriteria[0]=menu_menu("CRITERIO DE ORDENAMIENTO",
					"\n1 - IDS"
					"\n2 - NOMBRE"
					"\n3 - EMPRESA"
					"\n4 - GENERO"
					, "ERROR, INGRESE UNA OPCIÓN <1-4>", RETRIES, 4);
			switch (orderCriteria[0])
			{
			case 1:
				pToOrder = Juego_sortById;
				break;
			case 2:
				pToOrder = Juego_sortByName;
				break;
			case 3:
				pToOrder = Juego_sortByCompany;
				break;
			case 4:
				pToOrder = Juego_sortByGenre;
				break;
			}
			if(orderCriteria[0]!=-1)
			{
				orderCriteria[1]=menu_menu("FORMA DE ORDENAMIENTO",
						"\n1 - DESCENDENTE"
						"\n2 - ASCENDENTE",
						"ERROR, INGRESE UNA OPCIÓN <1-2>", RETRIES, 2);
			}
			else
			{
				orderCriteria[1] = -1;
			}
			if(orderCriteria[1] != -1)
			{
				if(orderCriteria[1] == 1)
				{
					orderCriteria[1] = 0;
				}
				else
				{
					orderCriteria[1] = 1;
				}
				if(ll_sort(pGamesList,pToOrder,orderCriteria[1]) == 0)
				{
					printf("\nSE ORDENARON LOS JUEGOS SEGUN EL CRITERIO ELEGIDO.");
					rtn = 0;
				}
				else
				{
					printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
				}

			}
		}

	}else
	{
		printf("NO HAY JUEGOS CARGADOS");
	}
	return rtn;
}
/// @fn int controller_sortGameNoMenu(LinkedList*, int, int)
/// @brief
///
/// @param pGamesList
/// @param OrderFun
/// @param Order
/// @return
int controller_sortGameNoMenu(LinkedList* pGamesList, int OrderFun, int Order)
{
	int rtn = -1;
	int(*pToOrder)(void*,void*);
	if(pGamesList != NULL)
	{
		if(ll_isEmpty(pGamesList) == 0)
		{
			switch (OrderFun)
			{
			case 1:
				pToOrder = Juego_sortById;
				break;
			case 2:
				pToOrder = Juego_sortByName;
				break;
			case 3:
				pToOrder = Juego_sortByCompany;
				break;
			case 4:
				pToOrder = Juego_sortByGenre;
				break;
			default:
				printf("\nNO SE EXISTE ESA OPCION DE ORDENAMIENTO");
				break;
			}
			if(OrderFun < 5 && ll_sort(pGamesList,pToOrder,Order) == 0)
			{
				rtn = 0;
			}
			else
			{
				printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
			}

		}
	}
	else
	{
		printf("NO HAY JUEGOS CARGADOS");
	}
	return rtn;
}
/// @fn int Controller_arcadeSortByGame(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
//====================================================== END SORT ==============================================================================
//====================================================== REMOVE ==============================================================================
int controller_removeSalon(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame)
{
	int rtn = -1;
	int bufferId;
	int passangerIndex;
	Salon* pSalon = NULL;
	int salonIdBuffer;
	if(pListSalon != NULL)
	{
		controller_listSalon(pListSalon);
		if(input_getIntNoRange("INGRESE EL ID DEL SALON A BORRAR:", RETRIES, "ERROR, INGRESE UN ID VALIDO:", &bufferId) == 0)
		{
			pSalon = controller_searchSalonById(pListSalon,bufferId);
			Salon_getId(pSalon, &salonIdBuffer);
			if(pSalon != NULL)
			{
				printf("\nESTE ES EL SALON A DAR DE BAJA:\n");
				printf(	"\n------------------------------------------------------------|");
				printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
				controller_printSalon(pSalon);
				printf(	"\n------------------------------------------------------------|\n");
				if(controller_countArcadeBySalon(pListArcade, pListSalon, pListGame, salonIdBuffer)>0)
				{
					printf("\nY CONTIENE LOS SIGUIENTES ARCADES:\n");
					controller_ListArcadeBySalon(pListArcade, pListSalon, pListGame, salonIdBuffer);
				}
				else
				{
					printf("\nEL SALON NO TIENE ARCADES");
				}
				if(menu_confirm("¿DESEA DAR DE BAJA EL SALON?\n<S/N>:", "ERROR, INGRESE <S/N>:"))
				{
					passangerIndex = ll_indexOf(pListSalon,pSalon);
					if(ll_remove(pListSalon,passangerIndex) == 0)
					{
						printf("\nSE DIÓ DE BAJA EL SIGUIENTE SALON Y TODOS SUS ARCADES:");
						printf(	"\n------------------------------------------------------------|");
						printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
						controller_printSalon(pSalon);
						printf(	"\n------------------------------------------------------------|");
						controller_removeArcadeBySalon(pListArcade, pListSalon, pListGame, salonIdBuffer);
						Salon_delete(pSalon);
						rtn = 0;
					}
				}
			}
		}
		if(rtn != 0)
		{
			printf("\nSE CANCELÓ LA BAJA DEL PASAJERO");
		}
	}
	return rtn;
}
/// @fn int controller_removeArcade(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_removeArcade(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int bufferId;
	Arcade* pArcade = NULL;
	if(pArcadeList != NULL)
	{
		controller_ListArcade(pArcadeList, pListSalon, pListGame);
		if(input_getIntNoRange("INGRESE EL ID DEL ARCADE:", RETRIES, "ERROR, INGRESE UN ID VALIDO:", &bufferId) == 0)
		{
			pArcade = controller_searchArcadeById(pArcadeList,bufferId);
			if(pArcade != NULL)
			{
				printf("\nESTE ES EL ARCADE A DAR DE BAJA:\n");
				printf("\n%-6s%-10s%-15s%-15s%-15s%-15s","ID","SONIDO","JUGADORES","FICHAS MAX", "SALON", "JUEGO");
				controller_printArcade(pArcade, pListSalon, pListGame);
				printf(	"\n----------------------------------------------------------------------------|");
				if(menu_confirm("¿DESEA DAR DE BAJA EL ARCADE?\n<S/N>:", "ERROR, INGRESE <S/N>:"))
				{
					if(controller_removeArcadeByID(pArcadeList, pListSalon, pListGame, bufferId)==0)
					{
						rtn = 0;
					}
					else
					{
						printf("\nERROR EN LA BAJA DEL ARCADE");
					}

				}
			}
		}
		if(rtn != 0)
		{
			printf("\nSE CANCELÓ LA BAJA DEL ARCADE");
		}
	}
	return rtn;
}
/// @fn int controller_removeArcadeByID(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @param bufferId
/// @return
int controller_removeArcadeByID(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int bufferId)
{
	int rtn = -1;
	int ArcadeIndex;
	Arcade* pArcade = NULL;
	if(pArcadeList != NULL)
	{
		pArcade = controller_searchArcadeById(pArcadeList,bufferId);
		if(pArcade != NULL)
		{
			ArcadeIndex = ll_indexOf(pArcadeList,pArcade);
			if(ll_remove(pArcadeList,ArcadeIndex) == 0)
			{
				printf("\nSE DIÓ DE BAJA EL SIGUIENTE ARCADE:");
				printf("\n%-6s%-10s%-15s%-15s%-15s%-15s","ID","SONIDO","JUGADORES","FICHAS MAX", "SALON", "JUEGO");
				printf(	"\n----------------------------------------------------------------------------|");
				controller_printArcade(pArcade, pListSalon, pListGame);
				printf(	"\n----------------------------------------------------------------------------|");
				Arcade_delete(pArcade);
				rtn = 0;
			}
		}
	}
	if(rtn != 0)
	{
		printf("\nSE CANCELÓ LA BAJA DEL PASAJERO");
	}
	return rtn;
}
/// @fn int controller_removeArcadeBySalon(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @param salonId
/// @return
int controller_removeArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId)
{
	int rtn = -1;
	int i;
	int ArcadeIndex;
	int listSize;
	Arcade* pArcade;
	int salonIdBuffer;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		listSize = ll_len(pArcadeList);
		if(listSize != -1)
		{
			for (i = 0; i < listSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadeList, i);
				Arcade_getFKSalon(pArcade, &salonIdBuffer);
				if(pArcade != NULL && salonIdBuffer == salonId)
				{
					ArcadeIndex = ll_indexOf(pArcadeList,pArcade);
					if(ll_remove(pArcadeList,ArcadeIndex) == 0)
					{
						Arcade_delete(pArcade);
						rtn = 0;
					}
				}
			}
		}
	}
	if(rtn !=0 )
	{
		printf("\nEL SALON NO TENIA ARCADES QUE DAR DE BAJA");
	}
	return rtn;
}
//======================================================  END REMOVE ==============================================================================
//====================================================== COUNT ==============================================================================
/// @fn int controller_countArcadeBySalon(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @param salonId
/// @return
int controller_countArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId)
{
	int rtn = -1;
	int i;
	int listSize;
	int arcadeCount=0;
	Arcade* pArcade;
	int salonIdBuffer;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		listSize = ll_len(pArcadeList);
		if(listSize != -1)
		{
			for (i = 0; i < listSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadeList, i);
				Arcade_getFKSalon(pArcade, &salonIdBuffer);
				if(pArcade != NULL && salonIdBuffer == salonId)
				{
					arcadeCount++;
					rtn = arcadeCount;

				}
			}
		}
	}
	return rtn;
}
/// @fn int controller_countGenreArcadeBySalon(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @param salonId
/// @return
int controller_countGenreArcadeBySalon(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame, int salonId)
{
	int rtn = -1;
	int i, j;
	int arcadeListSize;
	int gameListSize;
	int aventCount = 0;
	int mazeCount = 0;
	int platfCount =0;
	Arcade* pArcade = NULL;
	int arcadeGameIdBuffer;
	int arcadeSaloonIdBuffer;
	Juego* pGame = NULL;
	int gameIdBuffer;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		arcadeListSize = ll_len(pArcadeList);
		if(arcadeListSize != -1)
		{
			for (i = 0; i < arcadeListSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadeList, i);
				Arcade_getFKGame(pArcade, &arcadeGameIdBuffer);
				Arcade_getFKSalon(pArcade, &arcadeSaloonIdBuffer);
				if(pArcade != NULL && arcadeSaloonIdBuffer == salonId)
				{
					gameListSize = ll_len(pListGame);
					if(gameListSize != -1)
					{
						for (j = 0; j < gameListSize; j++)
						{
							pGame = (Juego*)ll_get(pListGame,j);
							Juego_getId(pGame, &gameIdBuffer);
							if(pGame != NULL && arcadeGameIdBuffer == gameIdBuffer)
							{
								switch(pGame->genre)
								{
								case AVENTURE:
									aventCount++;
									break;
								case LABYRINTH:
									mazeCount++;
									break;
								case PLATFORM:
									platfCount++;
									break;
								}

							}

						}
					}
				}
			}
		}
	}
	if(aventCount > 4 && mazeCount > 2 && platfCount > 3)
	{
		rtn = 0;
	}
	return rtn;
}
//======================================================  END COUNT ==============================================================================
//====================================================== REPORTS ==============================================================================
/// @fn int controller_listSalonFourPlusArcade(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_reportA(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int i;
	int listSize;
	int salonIdBuffer;
	Salon* pSalon;
	if(pListSalon != NULL)
	{
		listSize = ll_len(pListSalon);
		if(listSize != -1)
		{		printf(
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                 SALONES CON MÁS DE 4 ARCADES"
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
		for (i = 0; i < listSize; i++)
		{
			pSalon = (Salon*)ll_get(pListSalon, i);
			Salon_getId(pSalon, &salonIdBuffer);
			if(pSalon != NULL && (controller_countArcadeBySalon(pArcadeList, pListSalon, pListGame, salonIdBuffer)>4))
			{
				printf(	"\n------------------------------------------------------------|");
				controller_printSalon(pSalon);
				rtn = 0;
			}
		}
		printf(	"\n------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
/// @fn int controller_ListArcadeTwoPlayer(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_reportB(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int i;
	int listSize;
	Arcade* pArcade;
	int playersBuffer;
	int arcadeGameIDBuffer;
	Juego* pGame;
	int genreBuffer;
	if(pArcadeList != NULL && pListSalon != NULL && pListGame != NULL)
	{
		listSize = ll_len(pArcadeList);
		if(listSize != -1)
		{		printf(
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                         ARCADES PARA 3 JUGADORES Ó MÁS"
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf("\n%-6s%-10s%-15s%-15s%-15s%-15s%-20s","ID","SONIDO","JUGADORES","FICHAS MAX","SALON","JUEGO","GENERO");
		for (i = 0; i < listSize; i++)
		{
			pArcade = (Arcade*)ll_get(pArcadeList, i);
			Arcade_getPlayers(pArcade, &playersBuffer);
			Arcade_getFKGame(pArcade, &arcadeGameIDBuffer);
			if(pArcade != NULL && playersBuffer > 2)
			{
				pGame=controller_searchGameById(pListGame, arcadeGameIDBuffer);
				Juego_getGenre(pGame, &genreBuffer);
				printf(	"\n--------------------------------------------------------------------------------------|");
				controller_printArcade(pArcade, pListSalon, pListGame);
				switch(genreBuffer)
				{
				case AVENTURE:
					printf("%-20s","AVENTURA");
					break;
				case BEATEMUP:
					printf("%-20s","BEAT'EM UP");
					break;
				case LABYRINTH:
					printf("%-20s","LABERINTO");
					break;
				case FIGHT:
					printf("%-20s","PELEA");
					break;
				case PLATFORM:
					printf("%-20s","PLATAFORMA");
					break;
				case SHOOTER:
					printf("%-20s","TIROS");
					break;
				}
				rtn = 0;
			}
		}
		printf(	"\n--------------------------------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
/// @fn int controller_ListSalonReport(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pListSalon
/// @param pListArcade
/// @param pListGame
/// @return
int controller_reportC(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame)
{
	int rtn = -1;
	int bufferId;
	int arcadesCount;
	int salonIdBuffer;
	Salon* pSalon = NULL;
	if(pListSalon != NULL)
	{
		controller_listSalon(pListSalon);
		if(input_getIntNoRange("INGRESE EL ID DEL SALON A MOSTRAR:", RETRIES, "ERROR, INGRESE UN ID VALIDO:", &bufferId) == 0)
		{
			pSalon = controller_searchSalonById(pListSalon,bufferId);
			Salon_getId(pSalon, &salonIdBuffer);
			if(pSalon != NULL)
			{
				arcadesCount=controller_countArcadeBySalon(pListArcade, pListSalon, pListGame, salonIdBuffer);
				printf(	"\n----------------------------------------------------------------------------|");
				printf("\n%-6s%-20s%-20s%-20s%-6s","ID","NOMBRE","DIRECCIÓN","TIPO","ARCADES");
				printf(	"\n----------------------------------------------------------------------------|");
				controller_printSalon(pSalon);
				if(arcadesCount>0)
				{
					printf("%-6d",arcadesCount);
					printf(	"\n----------------------------------------------------------------------------|\n");
				}
				else
				{
					printf("%-6d",arcadesCount+1);
					printf(	"\n----------------------------------------------------------------------------|\n");
				}
			}
		}
	}
	return rtn;
}
/// @fn int controller_reportD(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_reportD(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int i;
	int listSize;
	int salonIdBuffer;
	Salon* pSalon;
	if(pListSalon != NULL)
	{
		listSize = ll_len(pListSalon);
		if(listSize != -1)
		{		printf(
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                     SALONES COMPLETOS"
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
		for (i = 0; i < listSize; i++)
		{
			pSalon = (Salon*)ll_get(pListSalon, i);
			Salon_getId(pSalon, &salonIdBuffer);
			if(pSalon != NULL && (controller_countGenreArcadeBySalon(pArcadeList, pListSalon, pListGame, salonIdBuffer)==0))
			{
				printf(	"\n------------------------------------------------------------|");
				controller_printSalon(pSalon);
				rtn = 0;
			}
		}
		printf(	"\n------------------------------------------------------------|\n");
		}
	}
	return rtn;
}
/// @fn int controller_reportE(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pListSalon
/// @param pListArcade
/// @param pListGame
/// @return
int controller_reportE(LinkedList* pListSalon, LinkedList* pListArcade, LinkedList* pListGame)
{
	int rtn = -1;
	int bufferId;
	int salonIdBuffer;
	Salon* pSalon = NULL;
	if(pListSalon != NULL)
	{
		controller_listSalon(pListSalon);
		printf("\nDEBE SELECCIONAR UN SALON PARA MOSTRAR SUS ARCADES:\n");
		if(input_getIntNoRange("INGRESE EL ID DEL SALON:", RETRIES, "ERROR, INGRESE UN ID VALIDO:", &bufferId) == 0)
		{
			pSalon = controller_searchSalonById(pListSalon,bufferId);
			Salon_getId(pSalon, &salonIdBuffer);
			if(pSalon != NULL)
			{
				printf("\nEL SALON CONTIENE LOS SIGUIENTES ARCADES:\n");
				controller_ListArcadeBySalon(pListArcade, pListSalon, pListGame, salonIdBuffer);
			}
			else
			{
				printf(	"\n----------------------------------------------------------------------------|\n");
				printf("\nEL SALON NO TIENE ARCADES\n");
			}
		}
	}
	return rtn;
}
/// @fn int controller_reportF(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_reportF(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = -1;
	int i;
	int listSize;
	int countArcades = 0;
	int maxArcades = 0;
	int flag = 0;
	int salonIdBuffer[2];
	Salon* pSalon = NULL;
	Salon* pSalonMaxA = NULL;
	LinkedList* LinkedBuffer;
	if(pListSalon != NULL)
	{
		listSize = ll_len(pListSalon);
		if(listSize != -1)
		{
			printf(
					"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
					"\n                 SALON CON MÁS ARCADES"
					"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
			printf("\n%-6s%-20s%-20s%-20s","ID","NOMBRE","DIRECCIÓN","TIPO");
			for (i = 0; i < listSize; i++)
			{
				pSalon = (Salon*)ll_get(pListSalon, i);
				Salon_getId(pSalon, &salonIdBuffer[0]);
				if(pSalon != NULL)
				{
					countArcades = controller_countArcadeBySalon(pArcadeList, pListSalon, pListGame, salonIdBuffer[0]);
					if(flag == 0)
					{
						maxArcades = countArcades;
						pSalonMaxA = pSalon;
						flag=1;
					}
					else
					{
						if(maxArcades<countArcades)
						{
							maxArcades = countArcades;
							pSalonMaxA = pSalon;
						}
					}
				}
			}
			Salon_getId(pSalonMaxA, &salonIdBuffer[1]);
			if(countArcades>0)
			{
				printf(	"\n------------------------------------------------------------|");
				controller_printSalon(pSalonMaxA);
				printf(	"\n------------------------------------------------------------|\n");
				printf("\nEL SALON CONTIENE LOS SIGUIENTES ARCADES");
				printf("\nORDENADOS POR ID DE FORMA ASCENDENTE:\n");
				LinkedBuffer = ll_clone(pArcadeList);
				if(controller_sortArcadeNoMenu(LinkedBuffer, 7, 0)==0)
				{
					controller_ListArcadeBySalon(LinkedBuffer, pListSalon, pListGame, salonIdBuffer[1]);
				}
				rtn = 0;

			}
			else
			{
				printf(	"\nNO HAY UN SALÓN CON ARCADES\n");
			}
		}
	}
	return rtn;
}
/// @fn int controller_reportG(LinkedList*, LinkedList*, LinkedList*)
/// @brief
///
/// @param pArcadeList
/// @param pListSalon
/// @param pListGame
/// @return
int controller_reportG(LinkedList* pArcadeList, LinkedList* pListSalon, LinkedList* pListGame)
{
	int rtn = 0;
	int i, j;
	LinkedList* gameList = NULL;
	gameList = ll_clone(pListGame);
	int gameListSize;
	LinkedList* arcadeList = NULL;
	arcadeList = ll_clone(pArcadeList);
	int arcadeListSize;
	Juego* gameBuffer;
	int gameId;
	int genre;
	Arcade* pArcade;
	int arcadeGameID;
	int arcadeSound;
	if( gameList != NULL &&  arcadeList !=NULL && ll_sort(gameList, Juego_sortByName, 0)==0)
	{
		gameListSize = ll_len(gameList);
		arcadeListSize  = ll_len(arcadeList);
		if(gameListSize != -1 && arcadeListSize != -1)
		{
			for (i = 0; i < arcadeListSize; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadeList, i);
				Arcade_getFKGame(pArcade, &arcadeGameID);
				Arcade_getSoundType(pArcade, &arcadeSound);
				for(j = 0; j < gameListSize; j++)
				{
					gameBuffer = (Juego*)ll_get(pListGame, j);
					Juego_getId(gameBuffer, &gameId);
					Juego_getGenre(gameBuffer, &genre);
					if(gameId==arcadeGameID && genre == PLATFORM && arcadeSound == MONO)
					{
						printf(	"\n------------------------------------------------------------------------------------------------|");
						controller_printArcade(pArcade, pListSalon, pListGame);
						printf(	"\n------------------------------------------------------------------------------------------------|");
						rtn = 0;
					}
				}
			}
		}
	}
	return rtn;
}
//======================================================  END REPORTS ==============================================================================
//====================================================== SAVE ==============================================================================
/// @fn int controller_saveSalon(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pSalonlist
/// @return
int controller_saveSalon(char* path , LinkedList* pSalonlist)
{
	int rtn = -1;
	FILE* pFile;
	int sizeList;
	int i;
	int bufferID;
	char bufferName[NAME_LENGTH];
	char bufferAdress[ADRESS_LENGTH];
	int bufferType;
	Salon* pSalon = NULL;
	if(path != NULL && pSalonlist!= NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"ID,NAME,ADRESS,TYPE\n");
			sizeList = ll_len(pSalonlist);
			for (i = 0; i < sizeList; i++)
			{
				pSalon = (Salon*)ll_get(pSalonlist, i);
				if(pSalon != NULL)
				{
					if(		(Salon_getId(pSalon,&bufferID)) != 0 ||
							(Salon_getName(pSalon,bufferName)) != 0 ||
							(Salon_getAdress(pSalon,bufferAdress)) != 0 ||
							(Salon_getType(pSalon,&bufferType)) != 0)
					{
						pSalon = NULL;
						free(pSalon);
						printf("\nERROR, NO SE PUEDEN GUARDAR DATOS EN EL ARCHIVO%s",path);
						break;
					}
					else
					{
						fprintf(pFile,"%d,%s,%s,%d,\n",bufferID,bufferName,bufferAdress,bufferType);
					}
				}
			}//FIN FOR
		}
		else
		{
			printf("\nNO SE PUEDE GRABAR EL ARICHIVO: %s",path);
		}
	}
	if(pSalon != NULL)
	{
		rtn = 0;
		printf("\nSE GRABO EL ARICHIVO CON EXITO");
	}
	fclose(pFile);
	return rtn;
}
/// @fn int controller_saveArcade(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pArcadelist
/// @return
int controller_saveArcade(char* path , LinkedList* pArcadelist)
{
	int rtn = -1;
	FILE* pFile;
	int sizeList;
	int i;
	int bufferID;
	char bufferNationality[NATIONALITY_LENGTH];
	int bufferSoundType;
	int bufferPlayers;
	int bufferCoins;
	int bufferIDSalon;
	int bufferIDGame;
	Arcade* pArcade = NULL;
	if(path != NULL && pArcadelist!= NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"ID,NATIONALITY,SOUND TYPE,PLAYERS,COIN CAP,SALON ID,GAME ID\n");
			sizeList = ll_len(pArcadelist);
			for (i = 0; i < sizeList; i++)
			{
				pArcade = (Arcade*)ll_get(pArcadelist, i);
				if(pArcade != NULL)
				{
					if(		Arcade_getId(pArcade,&bufferID) != 0 ||
							Arcade_getNationality(pArcade, bufferNationality) != 0 ||
							Arcade_getSoundType(pArcade,&bufferSoundType) != 0 ||
							Arcade_getPlayers(pArcade,&bufferPlayers) != 0 ||
							Arcade_getCoinCapacity(pArcade,&bufferCoins) != 0 ||
							Arcade_getFKSalon(pArcade, &bufferIDSalon) !=0 ||
							Arcade_getFKGame(pArcade, &bufferIDGame) !=0)
					{
						pArcade = NULL;
						free(pArcade);
						printf("\nERROR, NO SE PUEDEN GUARDAR DATOS EN EL ARCHIVO%s",path);
						break;
					}
					else
					{
						fprintf(pFile,"%d,%s,%d,%d,%d,%d,%d,\n",bufferID,bufferNationality,bufferSoundType,bufferPlayers,bufferCoins,bufferIDSalon,bufferIDGame);
					}
				}
			}
		}
		else
		{
			printf("\nNO SE PUEDE GRABAR EL ARICHIVO: %s",path);
		}
	}
	if(pArcade != NULL)
	{
		rtn = 0;
		printf("\nSE GRABO EL ARICHIVO CON EXITO");
	}
	fclose(pFile);
	return rtn;
}
/// @fn int controller_saveGame(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pGamelist
/// @return
int controller_saveGame(char* path , LinkedList* pGamelist)
{
	int rtn = -1;
	FILE* pFile;
	int sizeList;
	int i;
	int bufferID;
	char bufferName[NAME_LENGTH];
	char bufferCompany[COMPANY_LENGTH];
	int bufferGenre;
	Juego* pGame = NULL;
	if(path != NULL && pGamelist!= NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"ID,NAME,COMPANY,GENRE\n");
			sizeList = ll_len(pGamelist);
			for (i = 0; i < sizeList; i++)
			{
				pGame = (Juego*)ll_get(pGamelist, i);
				if(pGame != NULL)
				{
					if(		(Juego_getId(pGame,&bufferID)) != 0 ||
							(Juego_getName(pGame,bufferName)) != 0 ||
							(Juego_getCompany(pGame,bufferCompany)) != 0 ||
							(Juego_getGenre(pGame,&bufferGenre)) != 0)
					{
						pGame = NULL;
						free(pGame);
						printf("\nERROR, NO SE PUEDEN GUARDAR DATOS EN EL ARCHIVO%s",path);
						break;
					}
					else
					{
						fprintf(pFile,"%d,%s,%s,%d,\n",bufferID,bufferName,bufferCompany,bufferGenre);
					}
				}
			}
		}
		else
		{
			printf("\nNO SE PUEDE GRABAR EL ARICHIVO: %s",path);
		}
	}
	if(pGame != NULL)
	{
		rtn = 0;
		printf("\nSE GRABO EL ARICHIVO CON EXITO");
	}
	fclose(pFile);
	return rtn;
}
//======================================================  END SAVE ==============================================================================
