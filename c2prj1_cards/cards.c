#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  bool assr = true;
  if(c.value < 2 || c.value > VALUE_ACE){
    assr = false; 
  }
  if(c.suit < 0 || c.suit > 3){
    assr = false;
  }
  assert(assr);
}

const char * ranking_to_string(hand_ranking_t r) {
  const char *v = "0";
  switch(r){
  case 0:
    v = "STRAIGHT_FLUSH";
    break;
  case 1:
    v = "FOUR_OF_A_KIND";
    break;
  case 2:
    v = "FULL_HOUSE";
    break;
  case 3:
    v = "FLUSH";
    break;
  case 4:
    v = "STRAIGHT";
    break;
  case 5:
    v = "THREE_OF_A_KIND";
    break;
  case 6:
    v = "TWO_PAIR";
    break;
  case 7:
    v = "PAIR";
    break;
  case 8:
    v = "NOTHING";
    break;
  default:
    break;
  }
  
  return v;
}

char value_letter(card_t c) {
  char ret = '0';
  switch (c.value)
    {
    case 2:
      ret = '2';
      break;
    case 3:
      ret = '3';
      break;
    case 4:
      ret = '4';
      break;
    case 5:
      ret = '5';
      break;
    case 6:
      ret = '6';
      break;
    case 7:
      ret = '7';
      break;
    case 8:
      ret = '8';
      break;
    case 9:
      ret = '9';
      break;
    case 10:
      ret = '0';
      break;
    case 11:
      ret = 'J';
      break;
    case 12:
      ret = 'Q';
      break;
    case 13:
      ret = 'K';
      break;
    case 14:
      ret = 'A';
      break;
    default:
      break;
    }
  return ret;
}


char suit_letter(card_t c) {
  char ret = '0';
  switch (c.suit)
    {
    case SPADES:
      ret = 's';
      break;
    case HEARTS:
      ret = 'h';
      break;
    case DIAMONDS:
      ret = 'd';
      break;
    case CLUBS:
      ret = 'c';
      break;
    default:
      break;
    }
  return ret;
  
}

void print_card(card_t c) {
  char value_let = value_letter(c);
  char suit_let = suit_letter(c);
  printf("%c%c", value_let, suit_let);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch (value_let)
    {
    case '2':
      temp.value = 2;
      break;
    case '3':
      temp.value = 3;
      break;
    case '4':
      temp.value = 4;
      break;
    case '5':
      temp.value = 5;
      break;
    case '6':
      temp.value = 6;
      break;
    case '7':
      temp.value = 7;
      break;
    case '8':
      temp.value = 8;
      break;
    case '9':
      temp.value = 9;
      break;
    case '0':
      temp.value = 10;
      break;
    case 'J':
      temp.value = 11;
      break;
    case 'Q':
      temp.value = 12;;
      break;
    case 'K':
      temp.value = 13;
      break;
    case 'A':
      temp.value = 14;
      break;
    default:
      printf("Error! Invalid VALUE!");
      assert(false);
      break;
    }
  switch (suit_let)
    {
    case 's':
      temp.suit = SPADES;
      break;
    case 'h':
      temp.suit = HEARTS;
      break;
    case 'd':
      temp.suit = DIAMONDS;
      break;
    case 'c':
      temp.suit = CLUBS;
      break;
    default:
      printf("Error! Invalid SUIT!");
      assert(false);
      break;
    }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  bool assr = true;
  if(c < 0 || c > 51){
    assr = false;
  }
  assert(assr);
  if(c >= 0 || c <= 12)
    {
      temp.suit = CLUBS;
    }
  if (c >= 13 || c <= 25)
    {
      temp.suit = DIAMONDS;
    }
  if (c >= 26 || c <= 38)
    {
      temp.suit = HEARTS;
    }
  if (c >= 39 || c <= 51)
    {
      temp.suit = SPADES;
    }
  int oneFifTwo = c + 1;
  bool eq = false;
  while(eq == false){
    if(oneFifTwo <= 13){
      eq = true;
      continue;
    }
    else{
      oneFifTwo -= 13;
    }
  }
  int zeroFifOne = oneFifTwo - 1;
  int card = 2;
  if(zeroFifOne != 0){
    for(int i = 1; i <= zeroFifOne; i++){
      card++;
    }   
  }
  temp.value = card;
  return temp;
}
