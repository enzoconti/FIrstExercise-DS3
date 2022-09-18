// this functionality writes to the file, record by record and field by field

#include "../header/writeFunctionality.h" 

// This function writes onto a file for WRITE Functionality
void writeFile(char* filepath, int nRegister){
    FILE* fp = fopen(filepath, "wb"); // tries to open a binary file for write
    if(fp == NULL){
        printErrorFileOpening();
    }

    PERSON tempPerson;

    // inputs each of the n registers and writes them onto a file
        for(int i = 0; i < nRegister; i++){
        inputPerson(&tempPerson);
        writeRegister(fp,&tempPerson);
    }
    
    fclose(fp);
    binarioNaTela(filepath);
    
}

void writeRegister(FILE *fp, PERSON*p){
    // simply writes the 5 different field options
    for(int i=0;i<5;i++){
        writeField(fp,p,i);
    }
}

void writeField(FILE *fp, PERSON*p,int fieldFlag){
    int trashSize;
    switch(fieldFlag){ // swtich casing similar to readField
        case 0: // FirstName field
            fwrite(p->FirstName,sizeof(char),strlen(p->FirstName) + 1,fp); // writes the string + \0
            trashSize = FIRSTNAME_SIZE - strlen(p->FirstName) - 1; // the rest of the fixed size register gets trash
            break;                                                  // the other cases are similar, changing only the sizes and fields
        case 1: // LastName Field
            fwrite(p->LastName,sizeof(char),strlen(p->LastName) + 1,fp);
            trashSize = LASTNAME_SIZE - strlen(p->LastName) - 1;
            break;

        case 2: // email Field
            fwrite(p->email,sizeof(char),strlen(p->email) + 1,fp);
            trashSize = EMAIL_SIZE - strlen(p->email) - 1;
            break;

        case 3: // nationality Field
            fwrite(p->nationality,sizeof(char),strlen(p->nationality) + 1,fp);
            trashSize = NATIONALITY_SIZE - strlen(p->nationality) - 1;
            break;

        case 4: // age Field
            fwrite(&p->age,sizeof(int),1,fp);
            trashSize=0;
            break;
    }

    // creating the trash for the file, filling it with $
    char trash[trashSize];
        for(int i=0;i<trashSize;i++){
            trash[i] = '$';
        }
    // printing the trash as $
    if(fieldFlag != 4){
        fwrite(trash,trashSize,1,fp);
    }
}
