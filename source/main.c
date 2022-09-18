#include <stdio.h>
#include <stdlib.h>
#include "../header/IOFile.h"
#include "../header/writeFunctionality.h"
#include "../header/readFunctionality.h"
#include "../header/global_definitions.h"

int main(){
    int funcao;
    int lugar;
    char *arquivo; // this will be a filepath
    int nRegister;

    scanf("%d", &funcao);
    arquivo = getFilepath();
    
    switch(funcao){
        case 1: // direciona para a funcao write
            scanf("%d", &nRegister);
            writeFile(arquivo, nRegister);
            break;

        case 2: // direciona para a funcao read
            readFile(arquivo);
            break;

        case 3: // direciona para a funcao readRRN
            scanf("%d", &lugar);
            RRNread(arquivo, lugar); // "lugar" means the RRN index
            break;
    }	
}