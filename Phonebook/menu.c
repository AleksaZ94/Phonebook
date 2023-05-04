#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "user.h"
#include "main_functions.h"
#include "secondary_functions.h"

void menu()
{
   while(1)
   {
    printf("\n\t\tMAIN MENU\n");
    printf("\t=======================\n");
    printf("\t[1] Add a new Contact\n\t[2] List all Contacts\n\t[3] Search for contact"
          "\n\t[4] Edit a Contact\n\t[5] Delete a Contact\n\t[0] Exit\n");
    printf("\t=======================\n");
    printf("Enter a your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
     case 1:
        system("cls");
        add_user();
        break;
     case 2:
        system("cls");
        list_of_users();
        break;
     case 3:
        system("cls");
        search_for_contact();
        break;
     case 4:
        system("cls");
        edit_contact();
        break;
     case 5:
        system("cls");
        delete_contact();
        break;
     default:
        system("cls");
        printf("Wrong input!\n");
        exit_app();
        break;
    }
   }
}
