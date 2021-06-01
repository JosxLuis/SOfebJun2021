#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* itoa(int val, int base){
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}


int main(int argc, char **argv) {
  char *filename = argv[1];
  char *atributo = argv[2];
  char *palabra = argv[3];
  char *nuevoValor = argv[4];

  FILE *forigen;
  forigen = fopen(filename,"r+b");
  STUDENT newstudent;

  while(fread(&newstudent,sizeof(newstudent),1,forigen)){
    if(strcmp(atributo,"name")==0){
        if(strcmp(palabra, newstudent.name) == 0){
            strcpy(newstudent.name, nuevoValor);
            fseek(forigen,-1 * sizeof(newstudent),SEEK_CUR);
            fwrite(&newstudent,sizeof(newstudent),1,forigen);
            fread(&newstudent,sizeof(newstudent),1,forigen);
        }
    }
    if(strcmp(atributo,"lastname")==0){
        if(strcmp(palabra, newstudent.lastname) == 0){
            strcpy(newstudent.lastname, nuevoValor);
            fseek(forigen,-1 * sizeof(newstudent),SEEK_CUR);
            fwrite(&newstudent,sizeof(newstudent),1,forigen);
            fread(&newstudent,sizeof(newstudent),1,forigen);
        }
    }
    if(strcmp(atributo,"id")==0){
        char* id = itoa(newstudent.id, 10);
        if(strcmp(palabra, id) == 0){
            newstudent.id = atoi(nuevoValor);
            fseek(forigen,-1 * sizeof(newstudent),SEEK_CUR);
            fwrite(&newstudent,sizeof(newstudent),1,forigen);
            fread(&newstudent,sizeof(newstudent),1,forigen);
        }
    }
    if(strcmp(atributo,"semestre")==0){
        char* semestre = itoa(newstudent.semestre, 10);
        if(strcmp(palabra, semestre) == 0){
            newstudent.semestre = atoi(nuevoValor);
            fseek(forigen,-1 * sizeof(newstudent),SEEK_CUR);
            fwrite(&newstudent,sizeof(newstudent),1,forigen);
            fread(&newstudent,sizeof(newstudent),1,forigen);
        }
    }
  }
    fclose(forigen);
} 