#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  int len = strlen(str);
  if(len == 0){
    return;
  }
  int len_temp = strlen(str);
  char str_copy[len];
  strcpy(str_copy, str);
  for(int i = 0; i < len_temp; i++){
    str[i]=str_copy[len-1];
    len -= 1;
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
