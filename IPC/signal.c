#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int varGlobal = 0;

void signalHandler(int sig){
	printf("Recibi señal %d\n", sig);
	varGlobal = 1;
}

int main(){
	signal(2, signalHandler);
	while(1){
		printf("Trabajando\n");
		if(varGlobal == 1){
			break;
		}
		sleep(1);
	}
	printf("Ya voy a terminar \n");
	return 0;
}