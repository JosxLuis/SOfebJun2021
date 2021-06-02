#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv) {
  char  *dirName = argv[1];
  DIR * dir = opendir(dirName);
  struct dirent * dirContent;
  while( dirContent = readdir(dir)) {
    printf("file %s y esta %lu \n",dirContent->d_name,dirContent->d_ino);
  }
  closedir(dir);
  return 0;
}