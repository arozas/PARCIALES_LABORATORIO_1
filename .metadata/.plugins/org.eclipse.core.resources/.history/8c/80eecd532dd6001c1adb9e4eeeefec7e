/*
 * uReports.h
 *
 *  Created on: 15 may. 2022
 *      Author: alejandro
 */

#ifndef UOPERATIONS_H_
#define UOPERATIONS_H_

#define UP 1
#define DOWN 2

#include "eProduct.h"
#include "eTracking.h"
#include "eUser.h"
#include "menu.h"
#include "input.h"
#include "operations.h"
#include "myTime.h"

int uOperations_RegisterUser(eUser *userList, int length);
int uOperations_unregisterUser(eUser userList[], int length, eProduct productList[], int productLength);
int uOperations_Login(eUser *usersList, eUser *userLoggedIn);
void uOperations_printOneUser(eUser toPrintStruc, eProduct productList[], int productLength);
int uOperations_printAllUsers(eUser toPrintStruc[], int length, eProduct productList[], int productLength, int status);
void uOperations_printOneProduct(eProduct toPrintStruc, eUser userList[], int userListLength);
int uOperations_printAllProducts(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, int status);
int uOperations_printSortedProductList(eProduct toPrintStruc[], int length, eUser userList[], int userListLength, int order, int status);
int uOperations_unregisterProduct(eProduct productList[], int productLength, eUser userList[], int userListLength, int status);
void uOperations_printOneTracking(eTracking toPrintStruc, eUser userList[], int userListLength, eProduct productList[], int productLength);
int uOperations_printAllTrackings(eTracking toPrintStruc[],int trackingLength, eUser userList[], int userListLength, eProduct productList[], int productLength);
int uOperations_updateTrackingStatus(eTracking trackingList[],int trackingLength);
int uOperations_updateUserBalance(eTracking trackingList[],int trackingLength, eUser userList[], int userListLength);
int uOperations_printBuyedStatus(eTracking toPrintStruc[],int trackingLength, eUser userList[], int userListLength, eProduct productList[], int productLength, eUser loggedUser);
int uOperations_printSelledStatus(eTracking toPrintStruc[],int trackingLength, eUser userList[], int userListLength, eProduct productList[], int productLength, eUser loggedUser);
int uOperations_sellProduct(eProduct productList[], int productLength, eUser userList[], int userLength, eUser userLoggedin);
int uOperations_buyProduct(eProduct productList[], int productLength, eUser usersList[], int usersLength, eTracking trackingList[], int trackingLength, eUser userLoggedin);
int uOperations_cancelBuyed(eProduct productList[], int productLength, eUser usersList[], int usersLength, eTracking trackingList[], int trackingLength, eUser userLoggedin);

#endif /* UOPERATIONS_H_ */
