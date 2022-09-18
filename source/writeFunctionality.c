// this functionality writes to the file, record by record and field by field

#include "../header/writeFunctionality.h" 
//NÃO TERIA QUE INCLUIR O IOFile.h E global_definitions.h TAMBÉM???

void writeFile(char* filepath){
    //AQUI EU SEI QUE TENHO QUE MUDAR A FORMA COM QUE ABRE O ARQUIVO...
    FILE* fp = fopen(filepath, "wb"); //VER DEPOIS // tries to open a binary file for read
    /*o wb nao permite que o arquivo seja lido, apenas que escreva nele*/
    //O ERRO, OU AVISO TEM QUE VIR QUANDO O ARQUIVO NAO FOR NULL DESSA VEZ?
    //SE O ARQUIVO JA CONTER REGISTROS, EU VOU PODER ADICIONAR MAIS??
    
    //O ERRO VAI ACONTECER CASO O ARQUIVO NAO EXISTA
    /*if(fp == NULL){ //ACHO QUE ISSO NAO VAI MAIS SER NECESSARIO
        //VER QUAL O ERRO QUE TEM QUE MOSTRAR
        printErrorFileOpening(); // print error if unsuceeded
        //printf("Error");
        return;
    }*/


    //para escrever vou usar o fwrite(buffer,sizeof, numero, ponteiro)
    //fwrite(/*buffer = o arquivo*/,/*sizeof = tamanho de cada elemento*/, /*numero = numero de elementos a serem lidos*/,/*ponteiro = ponteiro retomado do fopen*/);
    PERSON p;
    int a = 0;
    while(a == 0/*quando FirstName for igual a \n*/){ //fazer uma funcao para ver o firstname?
        fwrite(p.FirstName, sizeof(char), 51, fp); //tirei o & do PERSON
        fwrite(p.LastName, sizeof(char), 51, fp);
        fwrite(p.email, sizeof(char), 81, fp);
        fwrite(p.nationality, sizeof(char), 51, fp);
        fwrite(p.age, sizeof(int), 1, fp);
        if(strcmp(p.FirstName, "\n")){
            //break;
            a = 1;
        }
    }

    //EU VOU TER QUE CONTAR O REGISTRO PARA INSERIR?
    //int countRegisters=0; //contador de registro
    //EU VOU TER QUE ADICIONAR AS COISAS NESSA STRUCT
    //PERSON tempPerson; //var do tipo PERSON - PERSON eh uma struc

    //while(readRegister(fp, &tempPerson) != 0){ // this reads a Register from fp and puts its data into tempPerson
        //printPerson(tempPerson); //funcao o IOFile     
        //printf("First Name:%s\nLast Name:%s\nemail:%s\nnationality:%s\nage:%d", tempPerson.FirstName, tempPerson.LastName, tempPerson.email, tempPerson.nationality, tempPerson.age);                           
        //countRegisters++;


    //}

    fclose(fp);

    return ;

}