#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "user.h"
#include "secondary_functions.h"
#define CONTACT "Enter the name of the contact: "
#define CHANGES "Changes are saved!\n"

void reading_data()
{
    FILE* f;
    f = fopen(FILE_NAME, "a+");
    if(f == NULL)
    {
        printf("Error with reading the file!");
        exit(EXIT_FAILURE);
    }
    while(fscanf(f,"%s %s %lu %s %s", add.name, add.surname, &add.phone_num, add.address, add.email) != EOF)
    {
       if(head == NULL)
       {
        user* temp = (user*)malloc(sizeof(user));
        strcpy(temp->name,add.name);
        strcpy(temp->surname,add.surname);
        temp->phone_num = add.phone_num;
        strcpy(temp->address,add.address);
        strcpy(temp->email,add.email);
        head = temp;
        temp->next = NULL;
       }
       else
       {
        user* temp2 = head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        user* temp = (user*)malloc(sizeof(user));
        strcpy(temp->name,add.name);
        strcpy(temp->surname,add.surname);
        temp->phone_num = add.phone_num;
        strcpy(temp->address,add.address);
        strcpy(temp->email,add.email);
        temp->next = NULL;
        temp2->next = temp;
       }
    }
  fclose(f);
}
void add_user()
{
    printf("\t\n\t*** Add user ***\n");
    user* temp = (user*)malloc(sizeof(user));
    if(head == NULL)
    {
       printf("First Name: ");
       scanf("%s", temp->name);
       printf("Last Name: ");
       scanf("%s", temp->surname);
       printf("Phone number: ");
       scanf("%lu", &temp->phone_num);
       printf("Address: ");
       scanf("%s", temp->address);
       printf("Email address: ");
       scanf("%s", temp->email);
       head = temp;
       temp->next = NULL;
    }
    else
    {
        user* temp2 = head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
       printf("First Name: ");
       scanf("%s", temp->name);
       printf("Last Name: ");
       scanf("%s", temp->surname);
       printf("Phone number: ");
       scanf("%lu", &temp->phone_num);
       printf("Address: ");
       scanf("%s", temp->address);
       printf("Email address: ");
       scanf("%s", temp->email);
       head = temp;
       temp->next = NULL;
    }
    printf("You have successfully added a user\n");
    update_the_list();
    function_chooser = THREE;
    exit_or_menu();
}
void list_of_users()
{
    for(i = 97; i <= ASCII_Z; i++)
    {
     marker = ZERO;
     user* temp = head;
     found = 0;
     while(temp != NULL)
     {
        marker = FIRST;
        if(temp->name[0] == i || temp->name[0] == i - ASCII_N)
        {
          printf("First Name: %s\nLast Name: %s\nPhone number: %lu\nAddress: %s\nEmail: %s\n\n",
                 temp->name, temp->surname, temp->phone_num, temp->address, temp->email);
          found++;
        }
        temp = temp->next;
     }
     if(found != 0)
     {
        printf("====================(%c)(%d)\n", i - ASCII_N,found);
        getch();
     }
    }

    if(marker == ZERO)
    {
        printf("List is empty!\n");
    }
    exit_or_menu();
}

void search_for_contact()
{
   printf("\n\t*** CONTACT SEARCH ***\n");
   printf("Enter the name of the user: ");
   scanf("%s", user_name);
   user* temp = head;
   marker = ZERO;
   found = ZERO;
   while(temp != NULL)
   {
       if(strcmp(temp->name, user_name) == 0)
       {
           marker = FIRST;
           found++;
           system("cls");
           printf("\n====== Search result for %s =======\n", user_name);
           printf("Name: %s\nPhone number: %lu\nAddress: %s\nEmail: %s\n\n",
                 temp->name, temp->surname, temp->phone_num, temp->address, temp->email);
       }
       temp = temp->next;
   }
   if(marker == FIRST)
   {
     printf("%d match(s) found\n", found);
     function_chooser = ZERO;
     try_again();
   }
   else
   {
       printf("\n====== Search result for %s =======\n", user_name);
       printf("======================\n");
       printf("Not match found!\n");
       try_again();
   }
}

void edit_contact()
{
    printf("\t\xBc\xBc\xBc Edit Contact \xBc\xBc\xBc\n\t====================\n\n");
    printf("\t%s", CONTACT);
    scanf("%s", user_name);
    user* temp = head;
    marker = ZERO;
    while(temp != ZERO)
    {
        if(strcmp(temp->name, user_name) == ZERO)
        {
            marker = FIRST;
            printf("Editing '%s'\n", user_name);
            printf("Name: ");
            scanf("%s", add.name);
            strcpy(temp->name,add.name);
            printf("Last Name: ");
            scanf("%s", add.surname);
            strcpy(temp->surname,add.surname);
            printf("Phone number: ");
            scanf("%lu", &add.phone_num);
            temp->phone_num = add.phone_num;
            printf("Address: ");
            scanf("%s", add.address);
            strcpy(temp->address, add.address);
            printf("Email address: ");
            scanf("%s", add.email);
            strcpy(temp->email,add.email);
        }
        temp = temp->next;
    }
    if(marker == FIRST)
    {
        printf("%s", CHANGES);
        update_the_list();
        exit_or_menu();
    }
    else
    {
       printf("\n====== Search result for %s =======\n", user_name);
       printf("======================\n");
       printf("Not match found!\n");
       function_chooser = FIRST;
       try_again();
    }
}

void delete_contact()
{
    printf("\t\xBc\xBc\xBc Delete Contact \xBc\xBc\xBc\n\t====================\n\n");
    printf("\t%s", CONTACT);
    scanf("%s", user_name);
    user* temp = head;
    user* temp2;
    user* temp3;
    marker = ZERO;
    while(temp != ZERO)
    {
        if(strcmp(temp->name,user_name) == 0)
        {
            marker = FIRST;
            if(temp == head)
            {
                head = temp->next;
                temp2 = temp;
                free(temp2);
            }
            else
            {
                temp3 = temp;
                temp2->next = temp->next;
                temp = temp->next;
                if(temp->next == ZERO)
                {
                    free(temp3);
                    break;
                }
                free(temp3);
            }
        }
        else
        {
          temp2 = temp;
          temp = temp->next;
        }
    }
   if(marker == FIRST)
    {
        printf("%s", CHANGES);
        update_the_list();
        exit_or_menu();
    }
    else
    {
       printf("\n====== Search result for %s =======\n", user_name);
       printf("======================\n");
       printf("Not match found!\n");
       function_chooser = TWO;
       try_again();
    }
}
