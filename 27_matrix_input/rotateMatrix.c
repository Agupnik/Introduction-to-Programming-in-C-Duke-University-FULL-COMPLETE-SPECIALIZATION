#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

void rotate(char matrix[10][10]){
  char matrix2[10][10];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      matrix2[i][j] = matrix[i][j];
    }
  }
  int max = 9;
  int min = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      matrix[i][j] = matrix2[max][min];
      max--;
    }
    max = 9;
    min++;
  }
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "No File\n");
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  char matrix[10][10];
  int c;
  int ten_chars = 0;
  int start_pos = 0;
  int elemsum = 0;
  if ((c = fgetc(f)) == EOF) {
    fprintf(stderr, "Invalid char\n");
    return EXIT_FAILURE;
  }
  rewind(f);
  while ((c = fgetc(f)) != EOF) {
    if (c < 10 || (c > 10 && c < 32) || c > 255) {
      fprintf(stderr, "Invalid char\n");
      return EXIT_FAILURE;
    }
    else if (c == 10 && ten_chars < 9) {
      fprintf(stderr, "Invalid matrix\n");
      return EXIT_FAILURE;
    }
    else if (c == 10 && ten_chars == 10) {
      start_pos++;
      ten_chars = 0;
      elemsum += 10;
      continue;
    }
    else if(c != 10){
      assert(elemsum <= 100);
      matrix[start_pos][ten_chars] = c;
      ten_chars++;
    }
    //printf("%d\n", start_pos);
  }
  //printf("%d\n", elemsum);
  //printf("%d\n", start_pos);
  if (start_pos != 10) {
    fprintf(stderr, "Invalid matrix\n");
    return EXIT_FAILURE;
  }
  rotate(matrix);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
	}
     printf("\n");
  }
  //printf("\n");
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
