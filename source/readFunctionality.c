// this functionality reads the entire file, register per register and field per field

#include "../header/readFunctionality.h"


void readFile(char* filepath){
    FILE* fp = fopen(filepath, "rb"); // tries to open a binary file for read
    if(fp == NULL){
        printErrorFileOpening(); // print error if unsuceeded
        //printf("Error");
        return;
    }

    int countRegisters=0;
    PERSON tempPerson;

    while( readRegister(fp, &tempPerson) != 0){ // this reads a Register from fp and puts its data into tempPerson
        printPerson(tempPerson);     
        //printf("First Name:%s\nLast Name:%s\nemail:%s\nnationality:%s\nage:%d", tempPerson.FirstName, tempPerson.LastName, tempPerson.email, tempPerson.nationality, tempPerson.age);                           
        countRegisters++;
    }

    fclose(fp);

    return ;

}

// this will read an entire register and put it into the outPerson instance
int readRegister(FILE *fp, PERSON* outPerson){

    //printf("readRegister has been called\n");

    int countFieldsSize = 0, buff=0, fieldFlag = 0; // the fieldFlag indicates which f the 5 possible fields we are reading - to know its size and where to put it onto PERSON struct

    while(countFieldsSize < REGISTER_SIZE){
        //printf("starting the readRegister loop with countFieldsSize=%d and fielFlag=%d\n", countFieldsSize, fieldFlag);
        buff = readField(fp, fieldFlag, outPerson);

        if(buff == 0){ // this indicates the file has ended
            return 0;
        }else{
            countFieldsSize+=buff; // we accumulate the non-zero buffer to know how much of the register we have already read
        }

        fieldFlag = (fieldFlag + 1)%5; // this makes the fieldFlag loop through 0 -> 1 -> 2 -> 3 -> 4 -> 0 ...
        //printf("leaving the readRegister loop with countFieldsSize=%d and fieldFlag=%d\n", countFieldsSize, fieldFlag);
    }

    return 1; // if the register has ended and the file still not, we return 1 to indicate to readFile that it can read another register
}

// this function will read one of the 5 possible fields according to the fieldFlag and puts it onto a field of outPerson
int readField(FILE* fp, int fieldFlag, PERSON* outPerson){

    //printf("\n\nreadField has been called with fieldFlag:%d\n", fieldFlag);
    
    int outSizeCounter=0;
    int nullFlag=1; // this flag will indicate when fread fails(meaning the file has ended)

    switch(fieldFlag){
        case 0: // FirstName field
            //printf("switch case has entered case 0\n");
            nullFlag = fread(&(outPerson->FirstName),FIRSTNAME_SIZE,1,fp);
            //printf("fread is done for First name, returning nullFlag:%d\tFName:%s\n", nullFlag, outPerson->FirstName);
            outSizeCounter = FIRSTNAME_SIZE;
            break;

        case 1: // LastName Field
            //printf("switch case has entered case 1\n");
            nullFlag = fread(&(outPerson->LastName),LASTNAME_SIZE,1,fp);
            //printf("fread is done for Last name, returning nullFlag:%d\tLName:%s\n", nullFlag, outPerson->LastName);
            outSizeCounter = LASTNAME_SIZE;
            break;

        case 2: // email Field
            //printf("switch case has entered case 2\n");
            nullFlag = fread(&(outPerson->email), EMAIL_SIZE,1,fp);
            //printf("fread is done for email, returning nullFlag:%d\temail:%s\n", nullFlag, outPerson->email);
            outSizeCounter = EMAIL_SIZE;
            break;

        case 3: // nationality Field
            //printf("switch case has entered case 3\n");
            nullFlag = fread(&(outPerson->nationality), NATIONALITY_SIZE,1,fp);
            //printf("fread is done for nationality, returning nullFlag:%d\tNationality:%s\n", nullFlag, outPerson->nationality);
            outSizeCounter = NATIONALITY_SIZE;
            break;

        case 4: // age Field
            //printf("switch case has entered case 4\n");
            nullFlag = fread(&(outPerson->age), sizeof(int), 1, fp);
            //printf("fread is done for age, returning nullFlag:%d\tage:%d\n", nullFlag, outPerson->age);
            outSizeCounter = sizeof(int);
            break;
    }

    //printf("switch case ended, current nullFlag:%d\n", nullFlag);
    if(nullFlag == 0) return 0; // this indicates that the file has ended
    //printf("leaving readField with outSizeCounter:%d\n\n",outSizeCounter);

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

    if(fseek != 0){
        printErrorSeek();
        return;
    }

    
    readRegister(fp, &personRegister);

    printPerson(personRegister);

    fclose(fp);

    return ;
}