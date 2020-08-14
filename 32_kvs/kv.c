#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char* splitLine(char* line) {
  char* value = strchr(line, '=');
  *value = '\0';
  value++;
  value[strlen(value) - 1] = '\0';
  return value;
}

kvarray_t * readKVs(const char * fname) {
  FILE * f = fopen(fname, "r");
  kvarray_t * kvarray = malloc(sizeof(*kvarray));
  kvarray->pair = malloc(sizeof(*kvarray->pair));
  kvarray->size = 0;
  char * line = NULL;
  size_t sz = 0;
  int count = 1;
  int elem = 0;
  while(getline(&line, &sz, f) != -1){
    if(line[0] == '\n'){
      continue;
    }
    kvarray->pair = realloc(kvarray->pair, ((elem+1) * sizeof(*kvarray->pair)));
    kvarray->pair[elem] = malloc(sizeof(*kvarray->pair[elem]));
    kvarray->pair[elem]->value = splitLine(line);
    kvarray->pair[elem]->key = line;
    elem++;
    line = NULL;

  }
  kvarray->size = elem;
  free(line);
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  for(int i = 0; i < pairs->size; i++){
    free(pairs->pair[i]->key);
    free(pairs->pair[i]);
  }
  free(pairs->pair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for(int i = 0; i < pairs->size; i++){
    printf("key = '%s' value = '%s'\n", pairs->pair[i]->key, pairs->pair[i]->value);
  }
}


