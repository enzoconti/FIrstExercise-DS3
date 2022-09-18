// this functionality writes to the file, record by record and field by field

#include "../header/writeFunctionality.h" 
#include "../header/IOFile.h" 


void writeFile(char* filepath, int nRegister){
    FILE* fp = fopen(filepath, "wb"); // tries to open a binary file for read
    //FUNCAO DE ERRO

    PERSON p;
    
    for(int i = 0; i < nRegister; i++){
        writeRegister(fp);
    }
    fwrite("\n", sizeof(char), 1, fp);
    binarioNaTela(filepath);
    fclose(fp);
}

void writeRegister(FILE *fp){

    char aux[100];
    int auxi;
    int tam;
    int lixo;
    
    scanf("%s", aux);
    tam = strlen(aux);
    if(tam > 51){
        fwrite(aux, sizeof(char), 51, fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    if(tam < 51){
        lixo = 51 - tam;
        fwrite(aux, sizeof(char), tam, fp);
        fwrite("\n", sizeof(char), 1, fp);
        fwrite("$", sizeof(char), lixo, fp);
    }
 
    scanf("%s", aux);
    tam = strlen(aux);
    if(tam > 51){
        fwrite(aux, sizeof(char), 51, fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    if(tam < 51){
        lixo = 51 - tam;
        fwrite(aux, sizeof(char), tam, fp);
        fwrite("\n", sizeof(char), 1, fp);
        fwrite("$", sizeof(char), lixo, fp);
    }

    scanf("%s", aux);
    tam = strlen(aux);
    if(tam > 81){
        fwrite(aux, sizeof(char), 81, fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    if(tam < 81){
        lixo = 81 - tam;
        fwrite(aux, sizeof(char), tam, fp);
        fwrite("\n", sizeof(char), 1, fp);
        fwrite("$", sizeof(char), lixo, fp);
    }

    scanf("%s", aux);
    tam = strlen(aux);
    if(tam > 51){
        fwrite(aux, sizeof(char), 51, fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    if(tam < 51){
        lixo = 51 - tam;
        fwrite(aux, sizeof(char), tam, fp);
        fwrite("\n", sizeof(char), 1, fp);
        fwrite("$", sizeof(char), lixo, fp);
    }

    scanf("%d", &auxi);
    fwrite(&auxi, sizeof(int), 1, fp);
    fwrite("\n", sizeof(char), 1, fp);
}
