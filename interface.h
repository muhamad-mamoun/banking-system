/*
=============================================================================================================
Author       : Mamoun
Module       : Interface
File Name    : interface.h
Date Created : Oct 18, 2023
Description  : User-Interface Functions.
=============================================================================================================
*/


#ifndef INTERFACE_H_
#define INTERFACE_H_

/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "system.h"

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

void DisplayStartMenu(void);
void DisplayAdminLoginMenu(void);
void DisplayClientLoginMenu(void);
void DisplayAdminControlMenu(void);
void DisplayClientData(ClientData* client_data);
void DisplayAllClientsData(void);
void DisplayAddNewClientMenu(void);
void DisplayDeleteClientMenu(void);
void DisplayClientDatabaseMenu(void);
void MoveCursor(int x,int y);


#endif /* INTERFACE_H_ */
