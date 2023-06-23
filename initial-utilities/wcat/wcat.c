#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  if (argc < 2) {
        return 0;
    }
  for(int i = 1; i < argc; i++){
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
     
      exit(1);
    }
    //keep reading until reading end of file
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)){
      printf("%s", buffer);
    } 

    
    if (fclose(fp) != 0){
      printf("error during file close");
      exit(0);
    }
  }
  return 0;
}
