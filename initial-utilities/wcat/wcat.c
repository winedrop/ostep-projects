#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  if (argc < 2) {
        printf("Insufficient arguments. Usage: %s arg1 \n", argv[0]);
        return 1;
    }
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("cannot open file\n");
    exit(1);
  }
  char buffer[256];
  fgets(buffer, sizeof(buffer), fp);
  printf("%s", buffer);
  fclose(fp);
  return 0;
}
