#ifndef _USER_H
#define _USER_H
#define MAX 30
#define MAX1 35
#define FIRST 1
#define ZERO 0
#define ASCII_N 32
#define ASCII_Z 122
#define FILE_NAME "baza.txt"

typedef struct user{
   unsigned long phone_num;
   char name[MAX];
   char address[MAX1];
   char email[MAX1];
   struct user* next;
}user;

user add;
struct user* head;
int choice, marker,i,found;

#endif
