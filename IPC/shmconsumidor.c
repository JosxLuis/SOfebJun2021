#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

typedef struct m {
    char status;
    int data[4];
} MyData;


int main(){
    MyData *datos;
    int key = 27;
    int shmId = shmget(key,sizeof(MyData), IPC_CREAT | 0666);
    datos = (MyData *)shmat(shmId, NULL, 0);
     while(datos->status != 'r'){
        sleep(1);
    }
    printf("Los datos son: %d %d %d %d \n",
            datos->data[0],
            datos->data[1],
            datos->data[2],
            datos->data[3]);
    datos->status = 't';
    return 0;
}
