#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

#define NUM_TESTS 12

int main(void) {
  char * testData[5] = {"car", "car", "car", "car", "car"};
  counts_t * testCounts= createCounts();
  for(int i =0; i < 5; i++) {
    addCount(testCounts,testData[i]);
  }
  printCounts(testCounts, stdout);
  freeCounts(testCounts);
  return EXIT_SUCCESS;
}
