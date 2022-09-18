#ifndef IOFILE_H
#define IOFILE_H

#include <stdio.h>
#include <stdlib.h>
#include "global_definitions.h"


char* getFilepath();
void printPerson(PERSON p);
void printErrorFileOpening();
void printErrorSeek();
void readline(char* string);
void binarioNaTela(char *nomeArquivoBinario);
//int writeRegister(PERSON pp);

#endif