#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  if(n == 0){
    return 0;
  }
  int seq = 1;

  int seq_temp = 0;
  int num = array[0];
  for(size_t i = 1; i < n; i++){
    if(array[i] > num){
      seq++;
      num = array[i];
    }
    else if(array[i] < num){
      if(seq_temp <= seq){
	seq_temp = seq;
      }
      seq = 1;
      num = array[i];
    }
  }
  if(seq_temp >= seq){
    return seq_temp;
  }
  return seq;
}
