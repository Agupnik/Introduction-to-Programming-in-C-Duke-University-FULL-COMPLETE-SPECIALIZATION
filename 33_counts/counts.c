#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
#define MYSTRDUP(str,lit) strcpy(str = malloc(strlen(lit)+1), lit)

counts_t * createCounts(void) {
  counts_t * count = malloc(sizeof(*count));
  count->c = malloc(sizeof(*count->c));
  count->count_known = 0;
  count->count_unknown = 0;
  return count;
}


void addNewValue(counts_t * c, const char * name){
  int value = c->count_known;
  if(name != NULL){
    c->c = realloc(c->c, (((value)+1) * sizeof(*c->c)));
    c->c[value] = malloc(sizeof(*c->c[value]));
    //c->c[value]->name = malloc(sizeof(strlen(name)*2));
    //c->c[value]->name = name;
    //strcpy((char*)c->c[value]->name, name);
    MYSTRDUP(c->c[value]->name, name);
    c->c[value]->count = 1;
    value++;
    c->count_known = value;
    return;
  }
  else{
    (c->count_unknown)++;
    return;
  }
}

void addCount(counts_t * c, const char * name) {
  if(name == NULL){
    addNewValue(c, name);
    return;
  }
  for(int i = 0; i < c->count_known; i++){
    char * x = (char*)c->c[i]->name;
    if(strcmp(x, name) == 0){
      (c->c[i]->count)++;
      return;
    }
  }
  addNewValue(c, name);
  return;
}

void printCounts(counts_t * c, FILE * outFile) {
  if(outFile == NULL){
    return;
  }
  for(int i = 0; i < c->count_known; i++){
    fprintf (outFile, "%s: %d\n", c->c[i]->name, c->c[i]->count);
  }
  if(c->count_unknown != 0){
    fprintf (outFile, "<unknown> : %d\n", c->count_unknown);
  }
}

void freeCounts(counts_t * c) {
  for(int i = 0; i < c->count_known; i++){
    free(c->c[i]->name);
    free(c->c[i]);
  }
  free(c->c);
  free(c);
}
