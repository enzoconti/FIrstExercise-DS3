#ifndef GLOBALDEFINITIONS_H
#define GLOBALDEFINITIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REGISTER_SIZE 238
#define FIRSTNAME_SIZE 51
#define LASTNAME_SIZE 51
#define EMAIL_SIZE 81
#define NATIONALITY_SIZE 51

typedef struct pessoa{
    char FirstName[FIRSTNAME_SIZE];
    char LastName[LASTNAME_SIZE];
    char email[EMAIL_SIZE];
    char nationality[NATIONALITY_SIZE];
    int age;
}PERSON;

#endif

