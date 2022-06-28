/*
 ============================================================================
 Name        : Juego.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Source file for Juego entity.
 ============================================================================
 */

#include "Juego.h"

//====================================================== MEMORY HANDLING ==============================================================================
/// @fn Juego Juego_new*()
/// @brief
///
/// @returnpGenre
Juego* Juego_new()
{
	Juego* memoryPointer = NULL;
	memoryPointer = (Juego*) malloc(sizeof(Juego));
	return memoryPointer;
}
/// @fn Juego Juego_newParametros*(char*, char*, char*, char*)
/// @brief
///
/// @param pId
/// @param pName
/// @param pCompany
/// @param pGenre
/// @return
Juego* Juego_newParametros(char* pId,char* pName,char*pCompany,char* pGenre)
{
	Juego* newGame = Juego_new();
	if(pId != NULL
			&& pName != NULL
			&& pCompany != NULL
			&& pGenre != NULL
			&& newGame != NULL)
	{
		if(Juego_setId(newGame, atoi(pId)) != 0
				||Juego_setName(newGame, pName)  != 0
				||Juego_setCompany(newGame, pCompany)  != 0
				||Juego_setGenre(newGame, atoi(pGenre))  != 0)
		{
			Juego_delete(newGame);
			newGame = NULL;
		}
	}
	return newGame;
}
/// @fn void Juego_delete(Juego*)
/// @brief
///
/// @param this
void Juego_delete(Juego* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
//====================================================== SETTER && GETTERS ==============================================================================
/// @fn int Juego_setId(Juego*, int)
/// @brief
///
/// @param this
/// @param pId
/// @return
int Juego_setId(Juego* this, int pId)
{
	int rtn = -1;
	if(this != NULL && pId > 0)
	{
		rtn = 0;
		this->id =pId;
	}
	return rtn;
}
/// @fn int Juego_getId(Juego*, int*)
/// @brief
///
/// @param this
/// @param pId
/// @return
int Juego_getId(Juego* this,int* pId)
{
	int rtn =-1;
	if(this != NULL &&  pId != NULL)
	{
		*pId = this->id;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Juego_setNameStr(Juego*, char*)
/// @brief
///
/// @param this
/// @param pName
/// @return
int Juego_setName(Juego* this,char* pName)
{
	int rtn = -1;
	if(this != NULL && pName != NULL)
	{
		strcpy(this->name,pName);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Juego_getName(Juego*, char*)
/// @brief
///
/// @param this
/// @param pName
/// @return
int Juego_getName(Juego* this,char* pName)
{
	int rtn = -1;
	if(this != NULL &&  pName != NULL)
	{
		strcpy(pName,this->name);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Juego_setCompanyStr(Juego*, char*)
/// @brief
///
/// @param this
/// @param pCompany
/// @return
int Juego_setCompany(Juego* this,char* pCompany)
{
	int rtn = -1;
	if(this != NULL && pCompany != NULL)
	{
		strcpy(this->company,pCompany);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Juego_getCompany(Juego*, char*)
/// @brief
///
/// @param this
/// @param pCompany
/// @return
int Juego_getCompany(Juego* this,char* pCompany)
{
	int rtn = -1;
	if(this != NULL &&  pCompany != NULL)
	{
		strcpy(pCompany,this->company);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Juego_setGenre(Juego*, int)
/// @brief
///
/// @param this
/// @param pGenre
/// @return
int Juego_setGenre(Juego* this, int pGenre)
{
	int rtn = -1;
	if(this != NULL && pGenre > 0)
	{
		rtn = 0;
		this->genre =pGenre;
	}
	return rtn;
}
/// @fn int Juego_getGenre(Juego*, int*)
/// @brief
///
/// @param this
/// @param pGenre
/// @return
int Juego_getGenre(Juego* this,int* pGenre)
{
	int rtn =-1;
	if(this != NULL &&  pGenre != NULL)
	{
		*pGenre = this->genre;
		rtn = 0;
	}
	return rtn;
}

int Juego_setData(Juego* this)
{
	int rtn = -1;
	Juego gameBuffer;
	int genreMenu;
	if(this != NULL)
	{
		printf("\n\t\t\tCARGA DE JUEGO\t\t\t");
		if(input_getAlphaNumericString("INGRESE EL NOMBRE DEL JUEGO:", RETRIES, "ERROR. INGRESE UN NOMBRE VALIDO", gameBuffer.name, NAME_LENGTH) == 0
				&& input_getAlphaNumericString("INGRESE EL NOMBRE DE LA DESARROLADORA:", RETRIES, "ERROR. INGRESE UN NOMBRE VALIDO", gameBuffer.company, COMPANY_LENGTH) ==0)
		{
			genreMenu = menu_menu("ELIJA EL GENERO DE JUEGO",
					"\n1 - AVENTURA"
					"\n2 - BEAT'EM UP"
					"\n3 - LABERINTO"
					"\n4 - PELEA"
					"\n5 - PLATAFORMA"
					"\n6 - TIROS",
					"ERROR ELIJA UNA OPCIÓN <1-6>:"
					, RETRIES, 6);
			if(genreMenu!=-1)
			{
				switch (genreMenu)
				{
				case AVENTURE:
					gameBuffer.genre=AVENTURE;
					break;
				case BEATEMUP:
					gameBuffer.genre=BEATEMUP;
					break;
				case LABYRINTH:
					gameBuffer.genre=LABYRINTH;
					break;
				case FIGHT:
					gameBuffer.genre=FIGHT;
					break;
				case PLATFORM:
					gameBuffer.genre=PLATFORM;
					break;
				case SHOOTER:
					gameBuffer.genre=SHOOTER;
					break;
				}
				if(Juego_setName(this, gameBuffer.name) != 0
						|| Juego_setCompany(this, gameBuffer.company) != 0
						|| Juego_setGenre(this, gameBuffer.genre)!= 0)
				{
					this = NULL;
				}
				else
				{
					rtn = 0;
				}
			}
		}
	}

	return rtn;
}
//====================================================== END SETTER && GETTERS ==============================================================================
//====================================================== SORT ==============================================================================
/// @fn int Juego_sortById(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Juego_sortById(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Juego* gameBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		gameBuffer[0]=(Juego*)pElementOne;
		gameBuffer[1]=(Juego*)pElementTwo;
		if(!Juego_getId(gameBuffer[0],&bufferElemenOne)
				&& !Juego_getId(gameBuffer[1],&bufferElemenTwo))
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
/// @fn int Juego_sortByName(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Juego_sortByName(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Juego* gameBuffer[2];
	char bufferElementOne[NAME_LENGTH];
	char bufferElemenTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		gameBuffer[0] = (Juego*) pElementOne;
		gameBuffer[1] = (Juego*) pElementTwo;
		if(!Juego_getName(gameBuffer[0], bufferElementOne) &&
				!Juego_getName(gameBuffer[1], bufferElemenTwo))
		{
			if(strncmp(bufferElementOne,bufferElemenTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferElementOne,bufferElemenTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
/// @fn int Juego_sortByCompany(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Juego_sortByCompany(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Juego* gameBuffer[2];
	char bufferElementOne[NAME_LENGTH];
	char bufferElemenTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		gameBuffer[0] = (Juego*) pElementOne;
		gameBuffer[1] = (Juego*) pElementTwo;
		if(!Juego_getCompany(gameBuffer[0], bufferElementOne) &&
				!Juego_getCompany(gameBuffer[1], bufferElemenTwo))
		{
			if(strncmp(bufferElementOne,bufferElemenTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferElementOne,bufferElemenTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
/// @fn int Juego_sortByGenre(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Juego_sortByGenre(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Juego* gameBuffer[2];
	int bufferElemenOne;
	int bufferElemenTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		gameBuffer[0]=(Juego*)pElementOne;
		gameBuffer[1]=(Juego*)pElementTwo;
		if(!Juego_getGenre(gameBuffer[0],&bufferElemenOne)
				&& !Juego_getGenre(gameBuffer[1],&bufferElemenTwo))
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


