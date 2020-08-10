#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int dencrypt(FILE * f, FILE * f2) {
  int commonn = 0;
  int c;
  int c2;
  int let;
  while ((c = fgetc(f)) != EOF) {
    int common = 0;
    while((c2 = fgetc(f2)) != EOF){
      if (isalpha(c) && isalpha(c2)) {
	c = tolower(c);
	c2 = tolower(c2);
	if(c == c2){
	  common++;
	}
      }
    }
    if(commonn < common){
      commonn = common;
      let = c;
    }
    common = 0;
    rewind(f2);
  }
  if(let == 'e'){
    return 0;
  }
  if(let > 'e'){
    return ((let%25)-1);
  }
  if(let < 'e'){
    if(let%25 == 0){
      return 25;
    }
    return (let%25);

  }
  return 0;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  FILE * f2 = fopen(argv[1], "r");
  if (f == NULL || f2 == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int key = dencrypt(f, f2);
  fprintf( stdout, "%d\n", key);
  if (fclose(f) != 0 || fclose(f2) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
