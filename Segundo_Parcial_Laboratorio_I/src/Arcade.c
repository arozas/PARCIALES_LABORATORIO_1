/*
 ============================================================================
 Name        : Arcade.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Source file for Arcade entity.
 ============================================================================
 */
#include "Arcade.h"

//====================================================== MEMORY HANDLING ==============================================================================
/// @fn Arcade Arcade_new*()
/// @brief
///
/// @return
Arcade* Arcade_new()
{
	Arcade* memoryPointer = NULL;
	memoryPointer = (Arcade*) malloc(sizeof(Arcade));
	return memoryPointer;
}
/// @fn Arcade Arcade_newParametros*(char*, char*, char*, char*, char*, char*)
/// @brief
///
/// @param pId
/// @param pSoundType
/// @param pPlayer
/// @param pCoinCapacity
/// @param pFKArcade
/// @param pFKGame
/// @return
Arcade* Arcade_newParametros(char* pId, char* pNationality, char* pSoundType,char*pPlayer,char* pCoinCapacity, char* pFKSalon, char* pFKGame)
{
	Arcade* newArcade = Arcade_new();
	if(pId != NULL
			&& pSoundType != NULL
			&& pPlayer != NULL
			&& pCoinCapacity != NULL
			&& pFKSalon != NULL
			&& pFKGame != NULL
			&& newArcade != NULL)
	{
		if(Arcade_setId(newArcade, atoi(pId)) !=0
				|| Arcade_setNationality(newArcade, pNationality) !=0
				|| Arcade_setSoundType(newArcade, atoi(pSoundType)) !=0
				|| Arcade_setPlayers(newArcade, atoi(pPlayer)) !=0
				|| Arcade_setCoinCapacity(newArcade, atoi(pCoinCapacity))!=0
				|| Arcade_setFKSalon(newArcade, atoi(pFKSalon))!=0
				|| Arcade_setFKGame(newArcade, atoi(pFKGame))!=0)
		{
			Arcade_delete(newArcade);
			newArcade = NULL;
		}
	}
	return newArcade;
}
/// @fn void Arcade_delete(Arcade*)
/// @brief
///
/// @param this
void Arcade_delete(Arcade* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
//====================================================== SETTER && GETTERS ==============================================================================
/// @fn int Arcade_setId(Arcade*, int)
/// @brief
///
/// @param this
/// @param id
/// @return
int Arcade_setId(Arcade* this,int id)
{
	int rtn = -1;
	if(this != NULL && id > 0)
	{
		rtn = 0;
		this->id =id;
	}
	return rtn;
}
/// @fn int Arcade_getIdChar(Arcade*, char*)
/// @brief
///
/// @param this
/// @param id
/// @return
int Arcade_getId(Arcade* this,int* id)
{
	int rtn =-1;
	if(this != NULL &&  id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_setNationality(Arcade*, char*)
/// @brief
///
/// @param this
/// @param pNationality
/// @return
int Arcade_setNationality(Arcade* this, char* pNationality)
{
	int rtn = -1;
	if(this != NULL && pNationality != NULL)
	{
		strcpy(this->nationality,pNationality);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_getNationality(Arcade*, char*)
/// @brief
///
/// @param this
/// @param pNationality
/// @return
int Arcade_getNationality(Arcade* this, char* pNationality)
{
	int rtn = -1;
	if(this != NULL &&  pNationality != NULL)
	{
		strcpy(pNationality,this->nationality);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_setSoundType(Arcade*, int)
/// @brief
///
/// @param this
/// @param pSoundType
/// @return
int Arcade_setSoundType(Arcade* this, int pSoundType)
{
	int rtn = -1;
	if(this != NULL && pSoundType > 0)
	{
		rtn = 0;
		this->soundType =pSoundType;
	}
	return rtn;
}
/// @fn int Arcade_getSoundType(Arcade*, int*)
/// @brief
///
/// @param this
/// @param pSoundType
/// @return
int Arcade_getSoundType(Arcade* this, int* pSoundType)
{
	int rtn =-1;
	if(this != NULL &&  pSoundType != NULL)
	{
		*pSoundType = this->soundType;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_setPlayers(Arcade*, int)
/// @brief
///
/// @param this
/// @param pPlayers
/// @return
int Arcade_setPlayers(Arcade* this, int pPlayers)
{
	int rtn = -1;
	if(this != NULL && pPlayers > 0)
	{
		rtn = 0;
		this->players = pPlayers;
	}
	return rtn;
}
/// @fn int Arcade_getPlayers(Arcade*, int*)
/// @brief
///
/// @param this
/// @param pPlayers
/// @return
int Arcade_getPlayers(Arcade* this, int* pPlayers)
{
	int rtn =-1;
	if(this != NULL &&  pPlayers != NULL)
	{
		*pPlayers = this->players;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_setCoinCapacity(Arcade*, int)
/// @brief
///
/// @param this
/// @param pCoinCapacity
/// @return
int Arcade_setCoinCapacity(Arcade* this, int pCoinCapacity)
{
	int rtn = -1;
	if(this != NULL && pCoinCapacity > 0)
	{
		rtn = 0;
		this->coinCapacity =pCoinCapacity;
	}
	return rtn;
}
/// @fn int Arcade_getCoinCapacityStr(Arcade*, int*)
/// @brief
///
/// @param this
/// @param pCoinCapacity
/// @return
int Arcade_getCoinCapacity(Arcade* this, int* pCoinCapacity)
{
	int rtn =-1;
	if(this != NULL &&  pCoinCapacity != NULL)
	{
		*pCoinCapacity = this->coinCapacity;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_setFKSalon(Arcade*, int)
/// @brief
///
/// @param this
/// @param pFKSalon
/// @return
int Arcade_setFKSalon(Arcade* this, int pFKSalon)
{
	int rtn = -1;
	if(this != NULL && pFKSalon > 0)
	{
		rtn = 0;
		this->FKSalon =pFKSalon;
	}
	return rtn;
}
/// @fn int Arcade_getFKSalon(Arcade*, int*)
/// @brief
///
/// @param this
/// @param pFKSalon
/// @return
int Arcade_getFKSalon(Arcade* this, int* pFKSalon)
{
	int rtn =-1;
	if(this != NULL &&  pFKSalon != NULL)
	{
		*pFKSalon = this->FKSalon;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Arcade_setFKGame(Arcade*, int)
/// @brief
///
/// @param this
/// @param pFKGame
/// @return
int Arcade_setFKGame(Arcade* this, int pFKGame)
{
	int rtn = -1;
	if(this != NULL && pFKGame > 0)
	{
		rtn = 0;
		this->FKGame =pFKGame;
	}
	return rtn;
}
/// @fn int Arcade_getFKGame(Arcade*, int*)
/// @brief
///
/// @param this
/// @param pFKGame
/// @return
int Arcade_getFKGame(Arcade* this, int* pFKGame)
{
	int rtn =-1;
	if(this != NULL &&  pFKGame != NULL)
	{
		*pFKGame = this->FKGame;
		rtn = 0;
	}
	return rtn;
}

int Arcade_setData(Arcade* this)
{
	int rtn = -1;
	Arcade arcadeBuffer;
	int arcadeMenu = 0;
	if(this !=NULL)
	{
		printf("\n\t\t\tCARGA DE ARCADE\t\t\t");
		arcadeMenu= menu_menu("TIPO DE SONIDO",
				"\n1 - MONO"
				"\n2 - ESTEREO",
				"ERROR ELIJA UNA OPCIÓN <1-2>:"
				,RETRIES, 2);
		if(arcadeMenu!=-1)
		{
			switch (arcadeMenu)
			{
			case MONO:
				arcadeBuffer.soundType=MONO;
				break;
			case STEREO:
				arcadeBuffer.soundType=STEREO;
				break;
			}
		}
		if(input_getStringletters("INGRESE LA NACIONALIDAD DEL ARCADE:", RETRIES, "ERROR, INTENTE DE NUEVO:", arcadeBuffer.nationality, NATIONALITY_LENGTH) == 0
				&& input_getInt("INGRESE EL NUMERO DE JUGADORES:", RETRIES, 1, 4, "ERROR, INGRESE <1-4> JUGADORES:", &arcadeBuffer.players)==0
				&& input_getInt("INGRESE EL NUMERO DE FICHAS:", RETRIES, 1000, 4000, "ERROR, INGRESE <1000 - 4000> FICHAS:", &arcadeBuffer.coinCapacity)==0)
		{
			if(Arcade_setNationality(this, arcadeBuffer.nationality) !=0
					|| Arcade_setSoundType(this, arcadeBuffer.soundType) !=0
					|| Arcade_setPlayers(this, arcadeBuffer.players) !=0
					|| Arcade_setCoinCapacity(this, arcadeBuffer.coinCapacity) !=0)
			{
				Arcade_delete(&arcadeBuffer);
				this = NULL;
			}
			else
			{
				rtn = 0;
			}
		}
	}
	return rtn;
}
//====================================================== END SETTER && GETTERS ==============================================================================
//====================================================== SORT ==============================================================================
/// @fn int Arcade_sortById(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortById(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* ArcadeBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		ArcadeBuffer[0]=(Arcade*)pElementOne;
		ArcadeBuffer[1]=(Arcade*)pElementTwo;
		if(!Arcade_getId(ArcadeBuffer[0],&bufferElemenOne)
				&& !Arcade_getId(ArcadeBuffer[1],&bufferElemenTwo))
		{
			if(bufferElemenOne > bufferElemenTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferElemenOne <bufferElemenTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
/// @fn int Arcade_sortByNationality(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortByNationality(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* arcadeBuffer[2];
	char bufferElementOne[NATIONALITY_LENGTH];
	char bufferElemenTwo[NATIONALITY_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		arcadeBuffer[0] = (Arcade*) pElementOne;
		arcadeBuffer[1] = (Arcade*) pElementTwo;
		if(!Arcade_getNationality(arcadeBuffer[0], bufferElementOne) &&
				!Arcade_getNationality(arcadeBuffer[1], bufferElemenTwo))
		{
			if(strncmp(bufferElementOne,bufferElemenTwo,NATIONALITY_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferElementOne,bufferElemenTwo,NATIONALITY_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
/// @fn int Arcade_sortBySound(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortBySound(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* ArcadeBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		ArcadeBuffer[0]=(Arcade*)pElementOne;
		ArcadeBuffer[1]=(Arcade*)pElementTwo;
		if(!Arcade_getSoundType(ArcadeBuffer[0],&bufferElemenOne)
				&& !Arcade_getSoundType(ArcadeBuffer[1],&bufferElemenTwo))
		{
			if(bufferElemenOne > bufferElemenTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferElemenOne <bufferElemenTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
/// @fn int Arcade_sortByPlayers(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortByPlayers(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* ArcadeBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		ArcadeBuffer[0]=(Arcade*)pElementOne;
		ArcadeBuffer[1]=(Arcade*)pElementTwo;
		if(!Arcade_getPlayers(ArcadeBuffer[0],&bufferElemenOne)
				&& !Arcade_getPlayers(ArcadeBuffer[1],&bufferElemenTwo))
		{
			if(bufferElemenOne > bufferElemenTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferElemenOne <bufferElemenTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
/// @fn int Arcade_sortByCoin(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortByCoin(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* ArcadeBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		ArcadeBuffer[0]=(Arcade*)pElementOne;
		ArcadeBuffer[1]=(Arcade*)pElementTwo;
		if(!Arcade_getCoinCapacity(ArcadeBuffer[0],&bufferElemenOne)
				&& !Arcade_getCoinCapacity(ArcadeBuffer[1],&bufferElemenTwo))
		{
			if(bufferElemenOne > bufferElemenTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferElemenOne <bufferElemenTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
/// @fn int Arcade_sortBySaloon(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortBySaloon(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* ArcadeBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		ArcadeBuffer[0]=(Arcade*)pElementOne;
		ArcadeBuffer[1]=(Arcade*)pElementTwo;
		if(!Arcade_getFKSalon(ArcadeBuffer[0],&bufferElemenOne)
				&& !Arcade_getFKSalon(ArcadeBuffer[1],&bufferElemenTwo))
		{
			if(bufferElemenOne > bufferElemenTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferElemenOne <bufferElemenTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
/// @fn int Arcade_sortByGame(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Arcade_sortByGame(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Arcade* ArcadeBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		ArcadeBuffer[0]=(Arcade*)pElementOne;
		ArcadeBuffer[1]=(Arcade*)pElementTwo;
		if(!Arcade_getFKGame(ArcadeBuffer[0],&bufferElemenOne)
				&& !Arcade_getFKGame(ArcadeBuffer[1],&bufferElemenTwo))
		{
			if(bufferElemenOne > bufferElemenTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferElemenOne <bufferElemenTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
//====================================================== END SORT ==============================================================================
