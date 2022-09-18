#include "../header/IOFile.h"

// this gets the filepath of a file
char* getFilepath(){
    char* filepath;
    filepath = malloc(50 *sizeof(char));

    scanf("%s", filepath);

    filepath = realloc(filepath, (strlen(filepath) + 1) * sizeof(char));

    return filepath;
}

// this simply prints a person register for functionalities read and readRRN
void printPerson(PERSON p){
    printf("Firstname: %s\n", p.FirstName);
    printf("Lastname: %s\n", p.LastName);
    printf("Email: %s\n", p.email);
    printf("Nationality: %s\n", p.nationality);
    printf("Age: %d\n\n", p.age);
}

void printErrorFileOpening(){
    printf("Falha no processamento do arquivo\n");
}

void printErrorSeek(){
    printf("Não foi possível ler o arquivo\n");
}

//given functions

void readline(char* string){
    char c = 0;

    do{
        c = (char) getchar();

    } while(c == '\n' || c == '\r');

    int i = 0;

    do{
        string[i] = c;
        i++;
        c = getchar();
    } while(c != '\n' && c != '\r');

    string[i]  = '\0';
}

void binarioNaTela(char *nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}

// this input is for write functionality and simply inputs 4 strings via readline and age via scanf
void inputPerson(PERSON *p){
    readline(p->FirstName);
    readline(p->LastName);
    readline(p->email);
    readline(p->nationality);
    scanf("%d", &p->age);
}

