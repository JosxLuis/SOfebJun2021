// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf(1, "Practica 2 sh\n");
    pid = fork();
    if(pid < 0){
      printf(1, "init: fork failed\n");
      exit();
    }
    if(pid == 0){
	  // 1) Cuando cambio SH, por ls = imprime los directorios en un buqule infinito por el for que tenemos
	  // 2) nohayprograma, entra en un buqule infinito, imprimiendo los mensajes de "init: starting sh", "init: exec sh failed" y "fail", eso quiere decir que falla, hace el init de nuevo y vuelve a fallar
      exec("nohayprograma", argv);
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
