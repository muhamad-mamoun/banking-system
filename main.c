/*
=============================================================================================================
Author       : Mamoun
Project      : Banking System
File Name    : main.c
Date Created : Oct 18, 2023
=============================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "system.h"
#include "interface.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

void (*ptr2menuFunction)(void) = NULL;
ClientData g_selected_client_data;

/*=====================================================================================================================
                                      < Private Functions Prototypes >
=====================================================================================================================*/

void StartMenu(void);
void AdminLoginMenu(void);
void ClientLoginMenu(void);
void AdminControlMenu(void);
void ClientsDatabaseMenu(void);
void AddNewClientMenu(void);
void DeleteClientMenu(void);
void ClientDataMenu(void);

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

int main(void)
{
	InitClientsDatabase();
	ptr2menuFunction = StartMenu;
	while(1)
	{
		ptr2menuFunction();
	}
}

void StartMenu(void)
{
	char user_input;
	DisplayStartMenu();
	scanf(" %c",&user_input);

	switch(user_input)
	{
	case '1':
		ptr2menuFunction = AdminLoginMenu;
		break;
	case '2':
		ptr2menuFunction = ClientLoginMenu;
		break;
	default :
		ptr2menuFunction = StartMenu;
		break;
	}
}

void AdminLoginMenu(void)
{
	AdminData entered_admin_data;
	DisplayAdminLoginMenu();

	fflush(stdin);
	MoveCursor(11,2);
	gets(entered_admin_data.user_name);
	fflush(stdin);
	MoveCursor(10,3);
	gets(entered_admin_data.password);

	UserDataStateType admin_data_state = CheckAdminData(&entered_admin_data);
	if(admin_data_state == RIGHT)
	{
		ptr2menuFunction = AdminControlMenu;
	}
	else
	{
		ptr2menuFunction = StartMenu;
	}
}

void ClientLoginMenu(void)
{
	DisplayClientLoginMenu();

	fflush(stdin);
	MoveCursor(11,2);
	gets(g_selected_client_data.user_name);
	fflush(stdin);
	MoveCursor(10,3);
	gets(g_selected_client_data.password);

	UserDataStateType client_data_state = CheckClientData(&g_selected_client_data);
	if(client_data_state == RIGHT)
	{
		ptr2menuFunction = ClientDataMenu;
	}
	else
	{
		ptr2menuFunction = StartMenu;
	}
}

void AdminControlMenu(void)
{
	char user_input = '\0';
	DisplayAdminControlMenu();

	fflush(stdin);
	scanf(" %c",&user_input);

	switch(user_input)
	{
	case '1':
		ptr2menuFunction = ClientsDatabaseMenu;
		break;
	case '2':
		ptr2menuFunction = AddNewClientMenu;
		break;
	case '3':
		ptr2menuFunction = DeleteClientMenu;
		break;
	default :
		ptr2menuFunction = AdminControlMenu;
		break;
	}
}

void ClientsDatabaseMenu(void)
{
	DisplayClientDatabaseMenu();

	char user_input = '\0';
	printf("\n\nEnter 'E' To Exit: ");
	scanf(" %c",&user_input);
	if(user_input == 'E' || user_input == 'e')
	{
		ptr2menuFunction = AdminControlMenu;
	}
	else
	{
		/* Do Nothing. */
	}
}

void AddNewClientMenu(void)
{
	ClientData new_client_data;
	DisplayAddNewClientMenu();

	fflush(stdin);
	MoveCursor(11,2);
	gets(new_client_data.user_name);

	fflush(stdin);
	MoveCursor(10,3);
	gets(new_client_data.password);

	fflush(stdin);
	MoveCursor(8,4);
	scanf("%f",&new_client_data.credit);

	fflush(stdin);
	MoveCursor(8,5);
	scanf("%f",&new_client_data.salary);

	fflush(stdin);
	MoveCursor(7,6);
	scanf("%f",&new_client_data.taxes);

	fflush(stdin);
	MoveCursor(4,7);
	scanf("%d",&new_client_data.id);

	CreateNewAccount(&new_client_data);
	printf("\nAccount created successfully.");


	char user_input = '\0';
	printf("\nEnter 'E' To Exit: ");
	scanf(" %c",&user_input);
	if(user_input == 'E' || user_input == 'e')
	{
		ptr2menuFunction = AdminControlMenu;
	}
	else
	{
		/* Do Nothing. */
	}
}

void DeleteClientMenu(void)
{
	int client_id = 0;
	DisplayDeleteClientMenu();

	scanf("%d",&client_id);
	DeleteAccount(client_id);

	char user_input = '\0';
	printf("\nEnter 'E' To Exit: ");
	scanf(" %c",&user_input);
	if(user_input == 'E' || user_input == 'e')
	{
		ptr2menuFunction = AdminControlMenu;
	}
	else
	{
		/* Do Nothing. */
	}
}

void ClientDataMenu(void)
{
	DisplayClientData(&g_selected_client_data);

	char user_input = '\0';
	printf("\nEnter 'E' To Exit: ");
	scanf(" %c",&user_input);
	if(user_input == 'E' || user_input == 'e')
	{
		ptr2menuFunction = StartMenu;
	}
	else
	{
		/* Do Nothing. */
	}
}
