#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * count = malloc(sizeof(*count));
  count->c = malloc(sizeof(*count->c));
  count->count_known = 0;
  count->count_unknown = 0;
  return count;
}

void addCount(counts_t * c, const char * name) {
  if(c->count_known == 0){
    if(name != NULL){
      c->c = realloc(c->c, (((c->count_known)+1) * sizeof(*c->c)));
      c->c[c->count_known] = malloc(sizeof(*c->c[c->count_known]));
      c->c[c->count_known]->name = (char *)name;
      c->c[c->count_known]->count = 0;
      (c->c[c->count_known]->count)++;
      (c->count_known)++;
      return;
    }
    else{
      (c->count_unknown)++;
      return;
    }
  }
  for(int i = 0; i < c->count_known; i++){
    if(c->c[i]->name == name){
      (c->c[i]->count)++;
      return;
    }
  }
  if(name != NULL){
    c->c = realloc(c->c, (((c->count_known)+1) * sizeof(*c->c)));
    c->c[c->count_known] = malloc(sizeof(*c->c[c->count_known]));
    c->c[c->count_known]->name = (char *)name;
    c->c[c->count_known]->count = 0;
    (c->c[c->count_known]->count)++;
    (c->count_known)++;
    return;
  }
  else{
    (c->count_unknown)++;
    return;
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  for(int i = 0; i < c->count_known; i++){
    fprintf (outFile, "%s: %zu\n", c->c[i]->name, c->c[i]->count);
  }
  if(c->count_unknown != 0){
    fprintf (outFile, "<unknown>: %zu\n", c->count_unknown);
  }
}

void freeCounts(counts_t * c) {
  for(int i = 0; i < c->count_known; i++){
    free(c->c[i]);
  }
  free(c->c);
  free(c);
}
