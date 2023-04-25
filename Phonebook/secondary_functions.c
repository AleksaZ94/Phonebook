#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "user.h"
#include "main_functions.h"
#include "secondary_functions.h"

void exit_or_menu()
{
    printf("Enter 1 to go in main menu or 0 do exit the app: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        system("cls");
        menu();
    }
    else if(choice == 0)
    {
        system("cls");
        exit_app();
    }
    else
    {
        menu();
    }
}

void exit_app()
{
   printf("Thank's for using the app!\n");
   exit(0);
}

void update_the_list()
{
    user* temp = head;
    FILE* f;
    f = fopen(FILE_NAME,"w");
    if(f == NULL)
    {
        printf("Error with opening %s", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    while(temp != NULL)
    {
        fprintf(f,"%s %lu %s %s\n", temp->name, temp->phone_num, temp->address, temp->email);
        temp = temp->next;
    }
    fclose(f);
}
