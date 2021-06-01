#include "student.h"
#include <stdio.h>
#include <stdlib.h>
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
  char *atrubuto = argv[2];
  char *palabra = argv[3];
  FILE *forigen;
  forigen = fopen(filename,"rb");
  STUDENT newstudent;

    while(fread(&newstudent,sizeof(newstudent),1,forigen)){ 
        if(strcmp(atrubuto,"name")==0){
            if(strcmp(palabra,newstudent.name)==0){
                printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        }else if(strcmp(atrubuto,"lastname")==0){
            if(strcmp(palabra,newstudent.lastname)==0){
                printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        }else if(strcmp(atrubuto,"id") == 0){
            char* id = itoa(newstudent.id, 10);
            if(strcmp(palabra,id) == 0){
             printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        }else if(strcmp(atrubuto,"semestre")==0){
            char* semestre = itoa(newstudent.semestre,10);
            if(strcmp(palabra,semestre)==0){
                printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }    
        }
    }
    fclose(forigen);
} 