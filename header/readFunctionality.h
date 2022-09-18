#ifndef READFUNCTIONALITY_H
#define READFUNCTIONALITY_H

#include <stdio.h>
#include <stdlib.h>
#include "global_definitions.h"
#include "IOFile.h"

void readFile(char*);
void RRNread(char*filepath, int RRN);
int readRegister(FILE *fp, PERSON* outPerson);
int readField(FILE* fp, int fieldFlag, PERSON* outPerson);

#endif