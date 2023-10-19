/*
=============================================================================================================
Author       : Mamoun
Module       : Interface
File Name    : interface.c
Date Created : Oct 18, 2023
Description  : User-Interface Functions.
=============================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include <stdio.h>
#include <windows.h>
#include "interface.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

extern ClientType* ptr2HeadClient;

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

void DisplayStartMenu(void)
{
	system("cls");
	MoveCursor(0,0);
	printf("Welcome To M-Bank.\n\n");
	printf("[1]. Admin Login.\n");
	printf("[2]. Client Login.\n\n");
	printf("Please enter your choice: ");
	fflush(stdout);
}

void DisplayAdminLoginMenu(void)
{
	system("cls");
	MoveCursor(0,0);
	printf("Admin Login.\n\n");
	printf("User-name: \n");
	printf("Password: \n");
	fflush(stdout);
}

void DisplayClientLoginMenu(void)
{
	system("cls");
	MoveCursor(0,0);
	printf("Client Login.\n\n");
	printf("User-name: \n");
	printf("Password: \n");
	fflush(stdout);
}

void DisplayAdminControlMenu(void)
{
	system("cls");
	MoveCursor(0,0);
	printf("Admin Menu.\n\n");
	printf("[1]. View Clients Database.\n");
	printf("[2]. Add New Client.\n");
	printf("[3]. Delete Client.\n\n");
	printf("Please enter your choice: ");
	fflush(stdout);
}

void DisplayClientData(ClientData* client_data)
{
	system("cls");
	MoveCursor(0,0);
	printf("Welcome, %s.\n\n",client_data->user_name);
	printf("Account Credit: %.2f\n",client_data->credit);
	printf("Salary: %.2f\n",client_data->salary);
	printf("Taxes: %.2f\n",client_data->taxes);
	fflush(stdout);
}

void DisplayAllClientsData(void)
{
	system("cls");
	MoveCursor(0,0);
}

void DisplayAddNewClientMenu(void)
{
	system("cls");
	MoveCursor(0,0);
	printf("Add New Client.\n\n");
	printf("User-name: \n");
	printf("Password: \n");
	printf("Credit: \n");
	printf("Salary: \n");
	printf("Taxes: \n");
	printf("ID: \n");
	fflush(stdout);
}

void DisplayDeleteClientMenu(void)
{
	system("cls");
	MoveCursor(0,0);
	printf("Delete Client.\n\n");
	printf("Enter Client ID: ");
	fflush(stdout);
}

void DisplayClientDatabaseMenu(void)
{
	ClientType* current_client = ptr2HeadClient;

	system("cls");
	MoveCursor(0,0);
	printf("Clients Database.\n\n");
	printf("Client Name          Client ID          Credit          Salary          Taxes\n");
	for(char counter = 0; current_client != NULL; counter++)
	{
		printf("[%d].",(counter+1));
		MoveCursor(5,(counter+3));
		printf("%s\n",current_client->client_data.user_name);
		MoveCursor(21,(counter+3));
		printf("%d\n",current_client->client_data.id);
		MoveCursor(40,(counter+3));
		printf("%.2f\n",current_client->client_data.credit);
		MoveCursor(56,(counter+3));
		printf("%.2f\n",current_client->client_data.salary);
		MoveCursor(72,(counter+3));
		printf("%.2f\n",current_client->client_data.taxes);
		current_client = current_client->next;
	}
}

void MoveCursor(int x,int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
