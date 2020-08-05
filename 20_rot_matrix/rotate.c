#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
