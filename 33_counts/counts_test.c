#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

#define NUM_TESTS 12
int main(void) {
  char * testData[24] = {"apple", "banana", NULL,"apple",
				"frog","sword","bear",NULL,
				"frog","apple", "zebra", "knight", "apple", "banana", NULL,"apple",
				"frog","sword","bear",NULL,
				"frog","apple", "zebra", "knight"};
  FILE * f = fopen("test.txt", "w");
  
  counts_t * testCounts= createCounts();
  for(int i =0; i < 24; i++) {
    addCount(testCounts,testData[i]);
  }
  printCounts(testCounts, f);
  fclose(f);
  freeCounts(testCounts);
  return EXIT_SUCCESS;
}
