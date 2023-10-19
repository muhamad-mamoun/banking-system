/*
=============================================================================================================
Author       : Mamoun
Module       : System
File Name    : system.c
Date Created : Oct 18, 2023
Description  : All the banking system functions.
=============================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

AdminType g_admin = {{"admin","admin"},NULL};
AdminType* ptr2HeadAdmin = &g_admin;
ClientType* ptr2HeadClient = NULL;

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

void InitClientsDatabase(void)
{
	char names[10][20] = {"Name 1","Name 2","Name 3","Name 4","Name 5","Name 6","Name 7","Name 8","Name 9","Name 10"};
	for(int counter = 0; counter < 10; counter++)
	{
		ClientData new_client_data = {"","",10000+(counter * 100),100+(counter * 11),100000+(counter * 101),(15230 + counter)};
		strcpy(new_client_data.user_name,names[counter]);
		strcpy(new_client_data.password,names[counter]);
		CreateNewAccount(&new_client_data);
	}
}

UserDataStateType CheckAdminData(AdminData* admin_data)
{
	UserDataStateType data_state = WRONG;

	if(strcmp(admin_data->user_name,g_admin.admin_data.user_name) == 0)
	{
		if(strcmp(admin_data->password,g_admin.admin_data.password) == 0)
		{
			data_state = RIGHT;
		}
	}
	else
	{
		/* Do Nothing. */
	}

	return data_state;
}

UserDataStateType CheckClientData(ClientData* entered_client_data)
{
	UserDataStateType data_state = WRONG;

	ClientData* ptr2client = FindClientAccount(entered_client_data->user_name);

	if(ptr2client != NULL)
	{
		UserDataStateType password_state = WRONG;
		password_state = CheckPassword(entered_client_data->password,ptr2client->password);

		if(password_state == RIGHT)
		{
			data_state = RIGHT;
			*entered_client_data = *ptr2client;
		}
		else
		{
			/* Do Nothing. */
		}
	}
	else
	{
		/* Do Nothing. */
	}

	return data_state;
}

ClientData* FindClientAccount(char* user_name)
{
	ClientData* target_client_record = NULL;

	if(ptr2HeadClient != NULL)
	{
		ClientType* current_record = ptr2HeadClient;
		while(current_record != NULL)
		{
			if(strcmp(current_record->client_data.user_name,user_name) == 0)
			{
				target_client_record = &current_record->client_data;
				break;
			}

			current_record = current_record->next;
		}
	}

	return target_client_record;
}

UserDataStateType CheckPassword(const char* entered_password, const char* client_password)
{
	UserDataStateType password_state = RIGHT;
	char counter = 0;

	for(; (*(entered_password + counter) != '\0') && (*(client_password + counter) != '\0'); counter++)
	{
		if(*(entered_password + counter) != *(client_password + counter))
		{
			password_state = WRONG;
			break;
		}
	}

	if(*(entered_password + counter) != *(client_password + counter))
	{
		password_state = WRONG;
	}

	return password_state;
}

void CreateNewAccount(ClientData* new_client_data)
{
	ClientType* new_client = (ClientType*)(calloc(1,sizeof(ClientType)));

	if(new_client != NULL)
	{
		new_client->client_data = *new_client_data;

		if(ptr2HeadClient != NULL)
		{
			new_client->next = ptr2HeadClient;
		}
		else
		{
			new_client->next = NULL;
		}

		ptr2HeadClient = new_client;
	}
	else
	{
		printf("ERROR!\n");
	}
}

void DeleteAccount(int client_id)
{
	if(ptr2HeadClient != NULL)
	{
		ClientType* current_record = ptr2HeadClient;
		while(current_record->next != NULL)
		{
			if(current_record->next->client_data.id == client_id)
			{
				ClientType* freed_record = current_record->next;
				current_record->next = current_record->next->next;
				free(freed_record);
				printf("\nAccount successfully deleted.");
				return;
			}

			current_record = current_record->next;
		}
		printf("Invalid ID!");
	}
	else
	{
		printf("No accounts to be deleted!");
	}
}
