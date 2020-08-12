#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  
  char ** lines = NULL;
  char * curr = NULL;
  size_t sz = 0; //might be bug
  size_t j = 0;

  if(argc == 1){
    while(getline(&curr, &sz, stdin) >= 0){
      lines = realloc(lines, (j+1) * sizeof(*lines));
      lines[j] = curr;
      curr = NULL;
      j++;
    }
    free(curr);
    sortData(lines, j);
    for(size_t j2 = 0; j2 < j; j2++){
      printf("%s", lines[j2]);
      free(lines[j2]);
    }
    free(lines);
  }
  if(argc > 1){
    for(int i = 1; i < argc; i++){
      FILE* f = fopen(argv[i], "r");
      if (f == NULL) {
	perror("Could not open file");
	return EXIT_FAILURE;
      }
      while(getline(&curr, &sz, f) >= 0){
	lines = realloc(lines, (j+1) * sizeof(*lines));
	lines[j] = curr;
	curr = NULL;
	j++;
      }
      free(curr);
      sortData(lines, j);
      for(size_t j2 = 0; j2 < j; j2++){
	printf("%s", lines[j2]);
	free(lines[j2]);
      }
      free(lines);
      if (fclose(f) != 0) {
	perror("Failed to close the input file!");
	return EXIT_FAILURE;
      }
      j = 0;
      sz = 0;
      curr = NULL;
      lines = NULL;
    }
  }
  return EXIT_SUCCESS;
}
