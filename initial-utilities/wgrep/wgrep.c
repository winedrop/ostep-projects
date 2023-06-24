#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


// preprocess for failure function
void computeLPS(char* pattern, int* lps){
  int patternLength = strlen(pattern);
  int len = 0; // Length of the previous longest prefix suffix
  int i = 1;

  lps[0] = 0; // lps[0] is always 0

  while (i < patternLength) {
    if (pattern[i] == pattern[len]) {// if prefix is a suffix
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
	// Try to find a shorter prefix that matches
	len = lps[len - 1];
      } else {
	lps[i] = 0;
	i++;
      }
    }
  }
}

// aabb
// 01
//

int searchPattern(const char* text,char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    int lps[patternLen]; // Create the lps array

    computeLPS(pattern, lps); // Preprocess the pattern

    int i = 0; // Index for the text
    int j = 0; // Index for the pattern

    while (i < textLen) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == patternLen) {
            return i - j; // Match found at index i-j
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Update j based on lps array
            } else {
                i++;
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]){
  //argv[0] is the ./wgrep
  //argv[1] is the string to search for
  //argv[2+] are the files to search through(can be 0 files)

  //handle use syntax
  if(argc < 2){
    printf("wgrep: searchterm [file ...]");
    exit(1);
  }
  
  char *searchTerm = argv[1];
  size_t termSize = strlen(searchTerm);
  int *patternLPS = malloc(termSize);
  computeLPS(searchTerm, patternLPS);
  for(int i = 0; i < termSize; i++){
    printf("%d", patternLPS[i]);
  }

  if(argc == 2){
    // take input from standard input

    
  }
  
  // else has correct arguments
  char *buf = NULL;
  size_t bufSize = 0;
  ssize_t bytesRead = 0;
  for(int i = 2; i < argc; i++){
    FILE *fp = fopen(argv[i], "r");
    // getline allocates data dynamically for &buf
    while ( (bytesRead = getline(&buf, &bufSize, fp)) != -1 ){
      // do the pattern search here
      printf("line #: %s", buf);
      // print if pattern matches
      if(searchPattern(buf, searchTerm) >= 0){
	//print the line with match
	printf("%s", buf);
      }else{
	// not found, do nothing
      }
    }
    

    
    if (fclose(fp) != 0){
      printf("error during file close");
      exit(0);
    }
  }

  free(patternLPS);
  free(buf);
  
  
}
