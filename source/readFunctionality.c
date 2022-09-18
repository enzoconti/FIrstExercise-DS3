// this functionality reads the entire file, register per register and field per field

#include "../header/readFunctionality.h"


void readFile(char* filepath){
    FILE* fp = fopen(filepath, "rb"); // tries to open a binary file for read
    if(fp == NULL){
        printErrorFileOpening(); // print error if unsuceeded
        return;
    }

    int countRegisters=0;
    PERSON tempPerson;

    while( readRegister(fp, &tempPerson) != 0){ // this reads a Register from fp and puts its data into tempPerson
        printPerson(tempPerson);                     
        countRegisters++;
    }

    fclose(fp);

    return ;

}

// this will read an entire register and put it into the outPerson instance
// isso lerá um registro inteiro e o colocará na instância outPerson
int readRegister(FILE *fp, PERSON* outPerson){

    int countFieldsSize = 0, buff=0, fieldFlag = 0; // the fieldFlag indicates which f the 5 possible fields we are reading - to know its size and where to put it onto PERSON struct
    //o fieldFlag indica quais dos 5 campos possíveis estamos lendo - para saber seu tamanho e onde colocá-lo na estrutura PERSON

    while(countFieldsSize < REGISTER_SIZE){
        buff = readField(fp, fieldFlag, outPerson);

        if(buff == 0){ // this indicates the file has ended
            //isso indica que o arquivo terminou
            return 0;
        }else{
            countFieldsSize+=buff; // we accumulate the non-zero buffer to know how much of the register we have already read
        }//acumulamos o buffer diferente de zero para saber quanto do registrador já lemos

        fieldFlag = (fieldFlag + 1)%5; // this makes the fieldFlag loop through 0 -> 1 -> 2 -> 3 -> 4 -> 0 ...
        //isso faz com que o fieldFlag passe por 0 -> 1 -> 2 -> 3 -> 4 -> 0 ...
    }

    return 1; // if the register has ended and the file still not, we return 1 to indicate to readFile that it can read another register
    //se o registro terminou e o arquivo ainda não, retornamos 1 para indicar ao readFile que ele pode ler outro registro
}

// this function will read one of the 5 possible fields according to the fieldFlag and puts it onto a field of outPerson
int readField(FILE* fp, int fieldFlag, PERSON* outPerson){
    
    int outSizeCounter=0;
    int nullFlag=1; // this flag will indicate when fread fails(meaning the file has ended)
    switch(fieldFlag){
        case 0: // FirstName field
            nullFlag = fread(&(outPerson->FirstName),FIRSTNAME_SIZE,1,fp);
            outSizeCounter = FIRSTNAME_SIZE;
            break;

        case 1: // LastName Field
            nullFlag = fread(&(outPerson->LastName),LASTNAME_SIZE,1,fp);
            outSizeCounter = LASTNAME_SIZE;
            break;

        case 2: // email Field
            nullFlag = fread(&(outPerson->email), EMAIL_SIZE,1,fp);
            outSizeCounter = EMAIL_SIZE;
            break;

        case 3: // nationality Field
            nullFlag = fread(&(outPerson->nationality), NATIONALITY_SIZE,1,fp);
            outSizeCounter = NATIONALITY_SIZE;
            break;

        case 4: // age Field
            nullFlag = fread(&(outPerson->age), sizeof(int), 1, fp);
            outSizeCounter = sizeof(int);
            break;
    }

    if(nullFlag == 0) return 0; // this indicates that the file has ended

    return outSizeCounter;
}

void RRNread(char* filepath, int RRN){
    int byte_offset = RRN * REGISTER_SIZE, fseekFlag=0; // this calculates the byte_offset to find the RRNth register
    PERSON personRegister;


    FILE* fp = fopen(filepath, "rb"); // tries to open a binary file for read
    if(fp == NULL){
        printErrorFileOpening(); // print error if unsuceeded
        //printf("Error");
        return;
    }

    fseekFlag = fseek(fp, byte_offset, SEEK_SET); // this sets the file pointer to the desired position to read the register

    if(fseekFlag != 0){
        printErrorSeek();
        return;
    }

    
    readRegister(fp, &personRegister);

    printPerson(personRegister);

    fclose(fp);

    return ;
}