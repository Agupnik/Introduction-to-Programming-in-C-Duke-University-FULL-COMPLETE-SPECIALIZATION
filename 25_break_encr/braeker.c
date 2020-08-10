#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find_max(FILE * f){
  int array[255] = {0};
  int c;
  while ((c = fgetc(f)) != EOF){
    if (isalpha(c)){
      array[c]++;
    }
  }
  int max = 0;
  int let = 0;
  for(int i = 0; i < 255; i++){
    if(array[i] > max){
      max = array[i];
      let = i;
    }
  }
  return let;
}

int dencrypt(FILE * f) {
  int let = find_max(f);
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
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int key = dencrypt(f);
  fprintf( stdout, "%d\n", key);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
