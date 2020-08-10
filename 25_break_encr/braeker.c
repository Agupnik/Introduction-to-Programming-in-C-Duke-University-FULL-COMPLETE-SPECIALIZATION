#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int most_common(FILE * f)
{
  char frequency[26];
  int ch = 0;

  for (ch = 0; ch < 26; ch++)
    frequency[ch] = 0;

  while(1){
    ch = fgetc(f);
    if (isalpha(ch)){
    if (ch == EOF) break;

    if ('a' <= ch && ch  <= 'z')
      frequency[ch - 'a']++;
    else if ('A' <= ch && ch <= 'Z')
      frequency[ch - 'A']++;}
  }

  int maxCount = 0;
  int maxChar = 0;
  for (int i = 0; i <= 26; ++i)
    {
      if (frequency[i] > maxCount)
	{
	  maxCount = frequency[i];
	  maxChar = i;
	}
    }
  return maxChar + 'A';
}

int dencrypt(FILE * f) {
  int let;
  let = most_common(f);
  if(let == 'e'){
    return 0;
  }
  if(let > 'e'){
    return ((let%25)-1);
  }
  if(let < 'e'){
    if(let%25 == 0){
      return 25;
    }
    return (let%25);

  }
  return 0;
}
      

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int key = dencrypt(f);
  fprintf( stdout, "%d\n", key);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
