#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);
int main()
{
  if(power(0, 0) != 1){
    return EXIT_FAILURE;
  }
  if(power(1, 0) != 1){
    return EXIT_FAILURE;
  }
  if(power(0, 3) != 0){
    return EXIT_FAILURE;
  }
  if(power(2, 4) != 16){
    return EXIT_FAILURE;
  }
  if(power(3.14, 3.8) != 27){
    return EXIT_FAILURE;
  }
  if(power(5, 0) != 1){
    return EXIT_FAILURE;
  }
  if(power(1, 0) != 1){
    return EXIT_FAILURE;
  }
  if(power(6, 1) != 6){
    return EXIT_FAILURE;
  }
  if(power(6, 1) != 6){
    return EXIT_FAILURE;
  }
  if(power('a', 'b') != 1993115841){
    return EXIT_FAILURE;
  }
  if(power(-2, 4) != 16){
    return EXIT_FAILURE;
  }
  if(power(-2, 3) != -8){
    return EXIT_FAILURE;
  }
  if(power(2, -4) != 0){
    return EXIT_FAILURE;
  }
  if(power(-2, -4) != 0){
    return EXIT_FAILURE;
  }
  printf("Success!\n");
  return EXIT_SUCCESS;
}
