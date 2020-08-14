#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

#define NUM_LOOKUPS 5

char * lookupValue(kvarray_t * pairs, const char * key) {
  for(int i = 0; i < pairs->size; i++){
    if(strcmp(pairs->pair[i]->key, key) == 0){
      return pairs->pair[i]->value;
    }
  }
  return NULL;
}

int main(void) {
  kvarray_t * array = readKVs("test.txt");
  printf("Printing all keys\n\n");
  printKVs(array);
  char *tests[NUM_LOOKUPS] = {"banana", "grapes", "cantaloupe", "lettuce", "orange"};
  for (int i = 0; i < NUM_LOOKUPS; i++) {
     printf("lookupValue('%s')=%s\n", tests[i], lookupValue(array,tests[i]));
  }
  freeKVs(array);
  return EXIT_SUCCESS;
}
