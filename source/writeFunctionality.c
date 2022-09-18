// this functionality writes to the file, record by record and field by field

#include "../header/writeFunctionality.h" 


void writeFile(char* filepath, int nRegister){
    FILE* fp = fopen(filepath, "wb"); // tries to open a binary file for read
    //FUNCAO DE ERRO

    PERSON p;
    
    for(int i = 0; i < nRegister; i++){
        writeRegister(fp);
    }
    binarioNaTela(filepath);
    fclose(fp);
}

void writeRegister(FILE *fp){

    char aux[100];
    int auxi;
    //int tam;
    //int lixo;
    scanf("%s", aux);
    //tam = strlen(aux);
    //if(tam > 51){
        fwrite(aux, sizeof(char), 51, fp);
    //}
    /*if(tam < 51){
        lixo = 51 - tam;
        fwrite(aux, sizeof(char), tam, fp);
        fwrite("$", sizeof(char), lixo, fp);
    }*/
 
    scanf("%s", aux);
    fwrite(aux, sizeof(char), 51, fp);
    
    scanf("%s", aux);
    fwrite(aux, sizeof(char), 81, fp);
    
    scanf("%s", aux);
    fwrite(aux, sizeof(char), 51, fp);
    
    scanf("%d", &auxi);
    fwrite(&auxi, sizeof(int), 1, fp);
}
