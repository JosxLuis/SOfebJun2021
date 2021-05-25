#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argvnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;
    int size = 0;
    
    FILE *foriginal, *fdestino;
    foriginal = fopen(original, "rb");
    fdestino = fopen(destino, "wb");
    char* linea;

   
    while(fread(&buffer,sizeof(char),1,foriginal)){
        size += 1;
        if(buffer == '\n'){
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char));
            fread(linea,sizeof(char),size,foriginal);
            if(strstr(linea,"hola") == NULL){
                fwrite(linea,sizeof(char),size,fdestino);
            }
            size = 0;
        }        
    }
     if(!fread(&buffer,sizeof(char),1,foriginal)){
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char)); 
            fread(linea,sizeof(char),size,foriginal);
            if(strstr(linea,"hola") == NULL){
                fwrite(linea,sizeof(char),size,fdestino);
            }
        }

    fclose(foriginal);
    fclose(fdestino);

    return 0;

}