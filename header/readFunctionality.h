#ifndef READFUNCTIONALITY_H
#define READFUNCTIONALITY_H

#include <stdio.h>
#include <stdlib.h>
#include "../header/global_definitions.h"

void readFile(char*);
int readRegister(FILE *fp, PERSON* outPerson);
int readField(FILE* fp, int fieldFlag, PERSON* outPerson);

#endif