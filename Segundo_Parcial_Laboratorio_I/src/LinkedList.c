#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;
	this = (LinkedList*)malloc(sizeof(LinkedList));
	if(this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int rtn = -1;
	if(this != NULL)
	{
		rtn = this->size;
	}
	return rtn;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* actualNode = NULL;
	if(this != NULL && nodeIndex >= 0 && ll_len(this) > nodeIndex)
	{
		actualNode = this->pFirstNode;
		for (int i = 0;i < nodeIndex;  i++)
		{
			actualNode = actualNode->pNextNode;
		}
	}
	return actualNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int rtn = -1;
	Node* pNewNode = NULL;
	Node* pPreviousNode = NULL;

	pNewNode = (Node*)malloc(sizeof(Node));

	if(this != NULL && nodeIndex >= 0 && pNewNode != NULL)
	{
		//Como no se donde va estar el nuevo nodo.
		//¿Primera posició?¿Siguiente?¿última?
		//Por eso en el buffer salvo la referencia al index
		pNewNode->pElement = pElement;
		if(nodeIndex == 0)
		{
			pNewNode->pNextNode = this->pFirstNode;
			this->pFirstNode = pNewNode;
			rtn = 0;
		}
		else
		{
			//En caso que sea distinto a 0 el NODE INDEX
			//Itero con el get Node
			pPreviousNode = getNode(this, nodeIndex-1);
			if(pPreviousNode!= NULL)
			{
				pNewNode->pNextNode = pPreviousNode->pNextNode;
				pPreviousNode->pNextNode= pNewNode;
				rtn = 0;
			}
		}
		if(rtn == 0)
		{
			//Aumento el size....
			this->size++;
		}

	}
	return rtn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int rtn = -1;
	if(this != NULL)
	{	//Si no es nulo, hago un addNode, el index me los da el ll_Len
		rtn = addNode(this, ll_len(this), pElement);
	}
	return rtn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	//No se el tipo de dato del elemeno, asi que es lógio el uso de void.
	void* rtn = NULL;
	// genero el Buffer
	Node* bufferNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		//copio y valido el buffer
		bufferNode = getNode(this,index);
		if(bufferNode != NULL)
		{
			//retorno el elemento
			rtn = bufferNode->pElement;
		}
	}
	return rtn;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	//Copio y pego el get...
	int rtn = -1;
	Node* bufferNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		bufferNode = getNode(this,index);
		if(bufferNode != NULL)
		{
			//aplico la misma lógica de los setters y getters del passenger del tp3
			bufferNode->pElement = pElement;
			rtn = 0;
		}
	}
	return rtn;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	//replico y refactorizo addNode
	int rtn = -1;
	Node* bufferPreviousNode = NULL;
	Node* bufferNode = NULL;
	Node* bufferNextNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		bufferNode = getNode(this,index);
		if(bufferNode != NULL)
		{
			if(index == 0)
			{
				bufferPreviousNode = this->pFirstNode;
				bufferNextNode = bufferNode->pNextNode;
				this->pFirstNode = bufferNextNode;
				rtn = 0;
			}
			else
			{
				bufferPreviousNode = getNode(this, index-1);
				if(bufferPreviousNode!= NULL)
				{
					bufferPreviousNode->pNextNode= bufferNode->pNextNode;
					rtn = 0;
				}
			}
			if(rtn == 0)
			{
				//resto tamaño y libero buffer
				this->size--;
				free(bufferNode);
			}
		}
	}

	return rtn;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 * 						(-2) Error, el puntero del elemento es NULL o menor a 0.
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{	//retorno -1 si la lista
	int rtn = -1;
	int i;
	if(this != NULL)
	{
		for (i = 0; i< ll_len(this); i++)
		{
			if(ll_remove(this, i) != 0)
			{
				rtn = -2;
				break;
			}
			rtn = 0;
		}
	}
	return rtn;
}
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int rtn = -1;
	//valido, y uso función clear (validada)
	//ahi libero
	if(this != NULL && ll_clear(this) == 0)
	{
		free(this);
		rtn = 0;
	}
	return rtn;
}
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int rnt = -1;
	Node* bufferNode = NULL;
	if(this != NULL)
	{
		for(int i = 0;i<ll_len(this);i++)
		{
			//recorro la lista y en el bugger traigó el nodo segun el conteo
			bufferNode = getNode(this,i);
			//comparo con el parametro
			if(bufferNode != NULL && (bufferNode->pElement == pElement))
			{
				//retorno el conteo
				rnt = i;
				// rompo el for
				break;
			}
		}
	}
	return rnt;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int rtn = -1;
	if(this != NULL)
	{
		// si la lista es distinto a null no esta vacía
		rtn = 0;
		if(this->pFirstNode == NULL)
		{
			//Si el primer nodo es NULL, la lista esta vacía
			rtn = 1;
		}
	}
	return rtn;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int rtn = -1;
	if(this != NULL && index >= 0 && index <= ll_len(this))
	{
		if(addNode(this,index,pElement) == 0)
		{
			rtn = 0;
		}
	}
	return rtn;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* rtn = NULL;
	if(this != NULL && index >= 0 && index <ll_len(this))
	{
		rtn =ll_get(this,index);
		ll_remove(this,index);
	}
	return rtn;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList* this, void* pElement)
{
	int rtn = -1;
	if(this != NULL)
	{
		if(ll_indexOf(this, pElement) == -1)
		{
			rtn = 0;
		}
		else
		{
			rtn = 1;
		}
	}
	return rtn;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int rnt = -1;
	Node* bufferNode = NULL;
	if(this != NULL && this2 != NULL)
	{
		rnt = 1;
		for(int i = 0;i < ll_len(this2);i++)
		{
			bufferNode = getNode(this2, i);
			if(bufferNode != NULL && ll_contains(this,bufferNode->pElement) == 0)
			{
				rnt = 0;
				break;
			}
		}
	}
	return rnt;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray = NULL;
	if(this != NULL && from >= 0  && to > from && to <= ll_len(this))
	{
		cloneArray = ll_newLinkedList();
		if(cloneArray != NULL)
		{
			for(int i = 0; i < to; i++)
			{
				ll_add(cloneArray,ll_get(this,i));
			}
		}
	}
	return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;
	if(this != NULL)
	{
		cloneArray = ll_subList(this, 0, ll_len(this));
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int rtn =-1;
	int i;
	int j;
	void* bufferElementOne = NULL;
	void* bufferElementTwo = NULL;
	if(this != NULL && (order == 1 || order == 0) && pFunc != NULL)
	{
		for( i = 0; i < ll_len(this)-1; i++)
		{
			for( j = i+1;j<ll_len(this);j++)
			{
				bufferElementOne = ll_get(this,i);
				bufferElementTwo = ll_get(this,j);
				if((order == 1 && pFunc(bufferElementOne,bufferElementTwo) > 0)
						||(order == 0 && pFunc(bufferElementOne,bufferElementTwo) < 0))
				{
					ll_set(this,i,bufferElementTwo);
					ll_set(this,j,bufferElementOne);
				}
			}
			rtn = 0;
		}
	}
	return rtn;
}
/// @fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
/// @brief filtra los elemetos que cumplen determinado criterio en una linkedlist;
///
/// @param this
/// @param pFunc
/// @return
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	void* pElement=NULL;
	int sizeLinkedList;
	LinkedList* filteredLinkedList=NULL;
	if(this!=NULL && pFunc!=NULL)
	{
		filteredLinkedList = ll_newLinkedList();

		if(filteredLinkedList!=NULL)
		{
			sizeLinkedList = ll_len(this);
			for(int i = 0; i<sizeLinkedList; i++)
			{

				pElement=ll_get(this, i);
				if(pFunc(pElement)== 1)
				{
					ll_add(filteredLinkedList, pElement);
				}
			}
		}
	}
	return filteredLinkedList;
}

