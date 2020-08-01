#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);
int main(void) {
  int mark[] = {1,2,1,3,5,7,2,4,6,9};
  int mark2[] = {0,1,0,0,0,0,0,0,0,0};
  int mark3[] = {0,1,0,1,0,1,0,1,0,1};
  int mark4[] = {1,2,3,4,5,6,7,8,9,10};
  int mark5[] = {1,1,3,1,5,1,7,1,9,1};
  int mark6[] = {0,0,0,0,0,0,0,0,0,0};
  int mark7[] = {0,0,0,0,0,0,0,0,-1,0,1,2,3};
  int mark8[] = {};
  int mark9[] = {1};
  if(maxSeq(mark, 10) != 4){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark2, 10) != 2){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark3, 10) != 2){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark4, 10) != 10){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark5, 10) != 2){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark6, 10) != 1){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark7, 13) != 5){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark8, 0) != 0){
    return EXIT_FAILURE;
  }
  if(maxSeq(mark9, 1) != 1){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
