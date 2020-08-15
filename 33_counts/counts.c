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

void addNewValue(counts_t * c, const char * name){
  if(name != NULL){
    c->c = realloc(c->c, (((c->count_known)+1) * sizeof(*c->c)));
    c->c[c->count_known] = malloc(sizeof(*c->c[c->count_known]));
    //c->c[c->count_known]->count[0] = malloc(sizeof(int));
    c->c[c->count_known]->name = (char *)name;
    c->c[c->count_known]->count = 1;
    //(c->c[c->count_known]->count)++;
    (c->count_known)++;
    return;
  }
  else{
    (c->count_unknown)++;
    return;
  }
}

void addCount(counts_t * c, const char * name) {
  if(c->count_known == 0){
    addNewValue(c, name);
  }
  for(int i = 0; i < c->count_known; i++){
    if(c->c[i]->name == name){
      (c->c[i]->count)++;
      return;
    }
  }
  addNewValue(c, name);
}

void printCounts(counts_t * c, FILE * outFile) {
  for(int i = 0; i < c->count_known; i++){
    fprintf (outFile, "%s: %d", c->c[i]->name, c->c[i]->count);
    //printf ("%s: %zu", c->c[i]->name, c->c[i]->count);
    fprintf (outFile, "\n");
    //printf ("\n");
  }
  if(c->count_unknown != 0){
    fprintf (outFile, "<unknown> : %d", c->count_unknown);
    //printf ("<unknown> : %zu", c->count_unknown);
  }
}

void freeCounts(counts_t * c) {
  for(int i = 0; i < c->count_known; i++){
    free(c->c[i]);
  }
  free(c->c);
  free(c);
}
