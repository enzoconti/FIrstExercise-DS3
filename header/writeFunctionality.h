#ifndef WRITEFUNCTIONALITY_H
#define WRITEFUNCTIONALITY_H

#include <stdio.h>
#include <stdlib.h>
#include "global_definitions.h"
#include "IOFile.h"

void writeFile(char*, int nRegister);
void writeField(FILE *fp, PERSON*,int fieldFlag);
void writeRegister(FILE *fp, PERSON*);

#endif