#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  if(n == 0){
    return 0;
  }
  size_t seq = 1;
  size_t seq_temp = 0;
  int num = array[0];
  for(size_t i = 1; i < n; i++){
    if(array[i] > array[i-1]){
      seq++;
    }
    else{
      if(seq_temp < seq){
	seq_temp = seq;
      }
      seq = 1;
    }
  }
  if(seq_temp > seq){
    return seq_temp;
  }
  return seq;
}
