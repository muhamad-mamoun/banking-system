/*
=============================================================================================================
Author       : Mamoun
Module       : System
File Name    : system.h
Date Created : Oct 18, 2023
Description  : All the banking system function.
=============================================================================================================
*/


#ifndef SYSTEM_H_
#define SYSTEM_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
	char user_name[20];
	char password[20];
}AdminData;

typedef struct admin
{
	AdminData admin_data;
	struct admin* next;
}AdminType;

typedef struct
{
	char user_name[20];
	char password[20];
	float salary;
	float taxes;
	float credit;
	int id;
}ClientData;

typedef struct client
{
	ClientData client_data;
	struct client* next;
}ClientType;

typedef enum
{
	WRONG,RIGHT
}UserDataStateType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

void InitClientsDatabase(void);
UserDataStateType CheckAdminData(AdminData* admin_data);
UserDataStateType CheckClientData(ClientData* entered_client_data);
ClientData* FindClientAccount(char* user_name);
UserDataStateType CheckPassword(const char* entered_password, const char* client_password);
void CreateNewAccount(ClientData* new_client_data);
void DeleteAccount(int client_id);


#endif /* SYSTEM_H_ */
