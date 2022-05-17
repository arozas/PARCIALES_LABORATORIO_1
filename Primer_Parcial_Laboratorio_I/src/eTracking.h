/*
 * eTracking.h
 *
 *  Created on: 30 abr. 2022
 *      Author: alejandro
 */

#ifndef ETRACKING_H_
#define ETRACKING_H_
#define MAX_LENGHT_CHAR 30
#define ID_INIT_VALUE 1000

#define TRUE 1
#define FALSE 2

#define IN_DEPOSIT 1
#define TRAVELLING 2
#define DELIVERED 3
#define CANCELLED 4

#include <stdio.h>
#include <stdlib.h>

//ABM
typedef struct
{
	int trackingId;
	int productId;
	int userId;
	int buyerId;
	short int isEmpty;

	int amount;
	float priceCost;
	int distanceKM;
	long int arrivalTime;
	short int status;
}eTracking;

int eTracking_getUniqueID(void);
int eTracking_init(eTracking eTrackingList[], int length);
void eTracking_printOne(eTracking toPrintStruc);
int eTracking_printAll(eTracking toPrintStruc[], int length, int status);
int eTracking_searchEmptyIndex(eTracking toSearchStruc[], int length);
int eTracking_searchIndexId(eTracking toSearchStruc[], int length);
int eTracking_searchId(eTracking toSearchStruc[], int length, int searchId);
int eTracking_register(eTracking *trackingList);
int eTracking_registerArray(eTracking toRegisterStruc[], int length);
int eTracking_unRegisterArray(eTracking toUnRegisterStruc[], int length);
eTracking eTracking_ModifyOne(eTracking toMofiedStruc);
int eTracking_ModifyArray(eTracking toMofiedStruc[], int length);
int eTracking_Sort(eTracking array[], int TAM, int criterio);

#endif /* ETRACKING_H_ */
