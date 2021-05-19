#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argnum, char **argv){
    char *oldpath = argv[1];
    char *newpath = argv[2];
    struct stat sb;
    if(stat(oldpath,&sb)==-1){
        printf("Error en el archivo\n");
        return -1;
    }

    struct stat sbn;
    if(stat(newpath,&sbn)==-1){
        link(oldpath,newpath);
        unlink(oldpath);
    }

    if(S_ISREG(sbn.st_mode)){
        printf("Archivo 2 ya existe \n");
        return -1;
    }

    if(S_ISDIR(sbn.st_mode)){
        char newdir[100];
        strcpy(newdir, newpath);
        strcat(newdir, "/");
        strcat(newdir,oldpath);
        printf("%s \n",newdir);
        link(oldpath,newdir);
        unlink(oldpath);
    }

    return 0;
}
