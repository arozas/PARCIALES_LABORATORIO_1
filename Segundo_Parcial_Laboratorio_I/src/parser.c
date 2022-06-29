/*
 ============================================================================
 Name        : parser.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Source file for Parser Library.
 ============================================================================
 */
#include "parser.h"

/// @fn int parser_SalonFromText(FILE*, LinkedList*)
/// @brief 				Parsea los datos los datos de los Salones desde el archivo salones.csv
///
/// @param pFile 		path al archivo.
/// @param pSalonList 	Puntero a la linkelist de salones
/// @return
/// 		Retorna 0 si la operacion se realizó con exito.
///			Retorna -1 si los punteros va a Null.
///			Retorna -2 si scaneo menos caracteres.
///			Retorna -3 si el nuevo salon va a Null.
int parser_SalonFromText(FILE* pFile , LinkedList* pSalonList)
{
	int rtn = -1;
	char buffer[4][128];
	Salon* pSalon;
	if(pFile != NULL && pSalonList !=NULL)
	{											  //id	    name      adress	type
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]) < 4)
			{
				printf("\nMENOS CARACTERES");
				rtn = -2;
				break;
			}
			else
			{
				pSalon = Salon_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				if(pSalon == NULL)
				{
					printf("\nSALON NULL");
					rtn = -3;
					break;
				}
				else
				{
					ll_add(pSalonList,(Salon*)pSalon);
					rtn = 0;
				}
			}
		}while(feof(pFile)==0);
	}
	return rtn;
}
/// @fn int parser_ArcadeFromText(FILE*, LinkedList*)
/// @brief 				Parsea los datos los datos de los Arcades desde el archivo arcade.csv
///
/// @param pFile 		path al archivo.
/// @param pArcadeList 	Puntero a la linkelist de Arcades
/// @return
/// 		Retorna 0 si la operacion se realizó con exito.
///			Retorna -1 si los punteros va a Null.
///			Retorna -2 si scaneo menos caracteres.
///			Retorna -3 si el nuevo salon va a Null.
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArcadeList)
{
	int rtn = -1;
	char buffer[7][128];
	Arcade* pArcade;
	if(pFile != NULL && pArcadeList !=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]) < 7)
			{
				printf("\nMENOS CARACTERES");
				rtn = -2;
				break;
			}
			else
			{
				pArcade = Arcade_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
				if(pArcade == NULL)
				{
					printf("\nARCADE NULL");
					rtn = -3;
					break;
				}
				else
				{
					ll_add(pArcadeList,(Arcade*)pArcade);
					rtn = 0;
				}
			}
		}while(feof(pFile)==0);
	}
	return rtn;
}
/// @fn int parser_JuegoFromText(FILE*, LinkedList*)
/// @brief 				Parsea los datos los datos de los juegos desde el archivo juegos.csv
///
/// @param pFile 		path al archivo.
/// @param pGameList 	Puntero a la linkelist de juegos.
/// @return
/// 		Retorna 0 si la operacion se realizó con exito.
///			Retorna -1 si los punteros va a Null.
///			Retorna -2 si scaneo menos caracteres.
///			Retorna -3 si el nuevo juego va a Null.
int parser_JuegoFromText(FILE* pFile , LinkedList* pGameList)
{
	int rtn = -1;
	char buffer[6][128];
	Juego* pGame;
	if(pFile != NULL && pGameList !=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]) < 4)
			{
				rtn = -2;
				break;
			}
			else
			{
				pGame = Juego_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				if(pGame == NULL)
				{
					rtn = -3;
					break;
				}
				else
				{
					ll_add(pGameList,(Juego*)pGame);
					rtn = 0;
				}
			}
		}while(feof(pFile)==0);
	}
	return rtn;
}
/// @fn int parser_SalonFromBinary(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pSalonList
/// @return
int parser_SalonFromBinary(FILE* pFile , LinkedList* pSalonList)
{
	int rtn = -1;
	if(pFile != NULL && pSalonList !=NULL)
	{
		do
		{
			Salon* this = Salon_new();
			if(this !=NULL)
			{
				if(fread(this,sizeof(Salon),1,pFile) != 1)
				{
					free(this);
					break;
				}
				else
				{
					if(ll_add(pSalonList,this) == 0)
					{
						rtn = 0;
					}
				}
			}
		}while(!feof(pFile));
	}
    return rtn;
}
/// @fn int parser_ArcadeFromBinary(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pArcadeList
/// @return
int parser_ArcadeFromBinary(FILE* pFile , LinkedList* pArcadeList)
{
	int rtn = -1;
	if(pFile != NULL && pArcadeList !=NULL)
	{
		do
		{
			Arcade* this = Arcade_new();
			if(this !=NULL)
			{
				if(fread(this,sizeof(Arcade),1,pFile) != 1)
				{
					free(this);
					break;
				}
				else
				{
					if(ll_add(pArcadeList,this) == 0)
					{
						rtn = 0;
					}
				}
			}
		}while(!feof(pFile));
	}
    return rtn;
}
/// @fn int parser_GameFromBinary(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pGameList
/// @return
int parser_GameFromBinary(FILE* pFile , LinkedList* pGameList)
{
	int rtn = -1;
	if(pFile != NULL && pGameList !=NULL)
	{
		do
		{
			Juego* this = Juego_new();
			if(this !=NULL)
			{
				if(fread(this,sizeof(Juego),1,pFile) != 1)
				{
					free(this);
					break;
				}
				else
				{
					if(ll_add(pGameList,this) == 0)
					{
						rtn = 0;
					}
				}
			}
		}while(!feof(pFile));
	}
    return rtn;
}
