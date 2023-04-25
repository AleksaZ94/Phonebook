#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "user.h"
#include "secondary_functions.h"

void reading_data()
{
    FILE* f;
    f = fopen(FILE_NAME, "r");
    if(f == NULL)
    {
        printf("Error with reading the file!");
        exit(EXIT_FAILURE);
    }
    while(fscanf(f,"%s %lu %s %s", add.name, &add.phone_num, add.address, add.email) != EOF)
    {
       if(head == NULL)
       {
        user* temp = (user*)malloc(sizeof(user));
        strcpy(temp->name,add.name);
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
       printf("Name: ");
       fflush(stdin);
       gets(temp->name);
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
       printf("Name: ");
       fflush(stdin);
       gets(temp->name);
       printf("Phone number: ");
       scanf("%lu", &temp->phone_num);
       printf("Address: ");
       scanf("%s", temp->address);
       printf("Email address: ");
       scanf("%s", temp->email);
       temp2->next = temp;
       temp->next = NULL;
    }
    printf("You have successfully added a user\n");
    update_the_list();
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
          printf("Name: %s\nPhone number: %lu\nAddress: %s\nEmail: %s\n\n",
                 temp->name, temp->phone_num, temp->address, temp->email);
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
