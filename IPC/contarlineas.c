#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

// 0 = stddin
// 1 = stdout

int main(){
    char minC;
    char mayC;
    int contador = 0;
    while(read(0,&minC,1)){
        mayC =toupper(minC);
        write(1,&mayC,1);
        if( minC == '\n'){
            contador++;
        }
    }
    printf ("\nSaltos de linea: %d\n",contador);

    return 0;
}