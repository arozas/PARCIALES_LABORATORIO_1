/*
 ============================================================================
 Name        : Salon.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Source file for Salon entity.
 ============================================================================
 */
#include "Salon.h"

//====================================================== MEMORY HANDLING ==============================================================================

/// @fn Salon Salon_new*()
/// @brief
///
/// @return
Salon* Salon_new()
{
	Salon* memoryPointer = NULL;
	memoryPointer = (Salon*) malloc(sizeof(Salon));
	return memoryPointer;
}
/// @fn Salon Salon_newParametros*(char*, char*, char*, char*)
/// @brief
///
/// @param idStr
/// @param nameStr
/// @param adressStr
/// @param typeStr
/// @return
Salon* Salon_newParametros(char* idStr,char* nameStr,char*adressStr,char* typeStr)
{
	Salon* newSalon = Salon_new();
	if(idStr != NULL
			&& nameStr != NULL
			&& adressStr != NULL
			&& typeStr != NULL
			&& newSalon != NULL)
	{
		if(Salon_setId(newSalon, atoi(idStr)) != 0
				||Salon_setName(newSalon, nameStr)  != 0
				||Salon_setAdress(newSalon, adressStr)  != 0
				||Salon_setType(newSalon, atoi(typeStr))  != 0)
		{
			Salon_delete(newSalon);
			newSalon = NULL;
		}
	}

	return newSalon;
}
/// @fn void Salon_delete(Salon*)
/// @brief
///
/// @param this
void Salon_delete(Salon* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
//====================================================== SETTER && GETTERS ==============================================================================
/// @fn int Salon_setId(Salon*, int)
/// @brief
///
/// @param this
/// @param id
/// @return
int Salon_setId(Salon* this,int id)
{
	int rtn = -1;
	if(this != NULL && id > 0)
	{
		rtn = 0;
		this->id =id;
	}
	return rtn;
}
/// @fn int Salon_getIdChar(Salon*, char*)
/// @brief
///
/// @param this
/// @param id
/// @return
int Salon_getId(Salon* this,int* id)
{
	int rtn =-1;
	if(this != NULL &&  id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Salon_setName(Salon*, char*)
/// @brief
///
/// @param this
/// @param pName
/// @return
int Salon_setName(Salon* this,char* pName)
{
	int rtn = -1;
	if(this != NULL && pName != NULL)
	{
		strcpy(this->name,pName);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Salon_getName(Salon*, char*)
/// @brief
///
/// @param this
/// @param pName
/// @return
int Salon_getName(Salon* this,char* pName)
{
	int rtn = -1;
	if(this != NULL &&  pName != NULL)
	{
		strcpy(pName,this->name);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Salon_setAdress(Salon*, char*)
/// @brief
///
/// @param this
/// @param pAdress
/// @return
int Salon_setAdress(Salon* this,char* pAdress)
{
	int rtn = -1;
	if(this != NULL && pAdress != NULL)
	{
		strcpy(this->adress,pAdress);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Salon_getAdress(Salon*, char*)
/// @brief
///
/// @param this
/// @param pAdress
/// @return
int Salon_getAdress(Salon* this,char* pAdress)
{
	int rtn = -1;
	if(this != NULL &&  pAdress != NULL)
	{
		strcpy(pAdress,this->adress);
		rtn = 0;
	}
	return rtn;
}
/// @fn int Salon_setTypeInt(Salon*, short int)
/// @brief
///
/// @param this
/// @param pType
/// @return
int Salon_setType(Salon* this,int pType)
{
	int rtn = -1;
	if(this != NULL && pType >-1)
	{
		rtn = 0;
		this->type =pType;
	}
	return rtn;
}
/// @fn int Salon_getType(Salon*, short int*)
/// @brief
///
/// @param this
/// @param pType
/// @return
int Salon_getType(Salon* this,int* pType)
{
	int rtn =-1;
	if(this != NULL &&  pType != NULL)
	{
		*pType = this->type;
		rtn = 0;
	}
	return rtn;
}
/// @fn int Salon_setData(Salon*)
/// @brief
///
/// @param this
/// @return
int Salon_setData(Salon* this)
{
	int rtn = -1;
	Salon salonBuffer;
	int salonTypeMenu;
	if (this !=NULL)
	{
		printf("\n\t\t\tCARGA DE SALÓN\t\t\t");
		if(input_getStringletters("INGRESE EL NOMBRE DEL SALÓN:", RETRIES, "ERROR. INGRESE UN NOMBRE VALIDO", salonBuffer.name, NAME_LENGTH)==0
				&&input_getAlphaNumericString("INGRESE LA DIRECCIÓN DEL SALON:", RETRIES, "ERROR INGRESE UNA DIRECCIÓN VALIDA", salonBuffer.adress, ADRESS_LENGTH)==0)
		{
			salonTypeMenu = menu_menu("ELIJA EL TIPO DE SALÓN",
					"\n1 - LOCAL"
					"\n2 - SHOPPING",
					"ERROR ELIJA UNA OPCIÓN <1-2>:"
					, RETRIES, 2);
			if(salonTypeMenu!=-1)
			{
				switch (salonTypeMenu)
				{
				case LOCAL:
					salonBuffer.type=LOCAL;
					break;
				case SHOPPING:
					salonBuffer.type=SHOPPING;
					break;
				}
				if(Salon_setName(this, salonBuffer.name) !=0)
				{
					puts("ERROR DE SET NAME");
				}
				else
				{

					if(Salon_setAdress(this, salonBuffer.adress)!=0)
					{
						puts("ERROR DE SET ADRESS");
					}
					else
					{

						if(Salon_setType(this, salonBuffer.type)!=0)
						{

							puts("ERROR DE SET TYPE");
							this = NULL;
						}
						else
						{
							rtn = 0;
						}
					}
				}
			}
		}
	}
	return rtn;
}
//====================================================== END SETTER && GETTERS ==============================================================================
//====================================================== SORT ==============================================================================
/// @fn int Salon_sortById(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Salon_sortById(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Salon* salonBuffer[2];
	int bufferIdOne;
	int bufferIdTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		salonBuffer[0]=(Salon*)pElementOne;
		salonBuffer[1]=(Salon*)pElementTwo;
		if(!Salon_getId(salonBuffer[0],&bufferIdOne)
				&& !Salon_getId(salonBuffer[1],&bufferIdTwo))
		{
			if(bufferIdOne > bufferIdTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferIdOne <bufferIdTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
/// @fn int Salon_sortByName(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Salon_sortByName(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Salon* salonBuffer[2];
	char bufferNameOne[NAME_LENGTH];
	char bufferNameTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		salonBuffer[0] = (Salon*) pElementOne;
		salonBuffer[1] = (Salon*) pElementTwo;
		if(!Salon_getName(salonBuffer[0], bufferNameOne) &&
				!Salon_getName(salonBuffer[1], bufferNameTwo))
		{
			if(strncmp(bufferNameOne,bufferNameTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferNameOne,bufferNameTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
/// @fn int Salon_sortByAdress(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Salon_sortByAdress(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Salon* salonBuffer[2];
	char bufferNameOne[ADRESS_LENGTH];
	char bufferNameTwo[ADRESS_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		salonBuffer[0] = (Salon*) pElementOne;
		salonBuffer[1] = (Salon*) pElementTwo;
		if(!Salon_getAdress(salonBuffer[0], bufferNameOne) &&
				!Salon_getAdress(salonBuffer[1], bufferNameTwo))
		{
			if(strncmp(bufferNameOne,bufferNameTwo,ADRESS_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferNameOne,bufferNameTwo,ADRESS_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
/// @fn int Salon_sortByType(void*, void*)
/// @brief
///
/// @param pElementOne
/// @param pElementTwo
/// @return
int Salon_sortByType(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Salon* salonBuffer[2];
	int bufferIdOne;
	int bufferIdTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		salonBuffer[0]=(Salon*)pElementOne;
		salonBuffer[1]=(Salon*)pElementTwo;
		if(!Salon_getType(salonBuffer[0],&bufferIdOne)
				&& !Salon_getType(salonBuffer[1],&bufferIdTwo))
		{
			if(bufferIdOne > bufferIdTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferIdOne <bufferIdTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
//====================================================== END SORT ==============================================================================

