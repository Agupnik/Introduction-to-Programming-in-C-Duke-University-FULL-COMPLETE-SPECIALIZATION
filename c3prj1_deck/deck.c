#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(size_t i = 0; i < (*hand).n_cards; i++){
  print_card(*hand->cards[i]);
  printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for(size_t i = 0; i < (*d).n_cards; i++){
    if((*d).cards[i]->value == c.value && (*d).cards[i]->suit == c.suit){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  if ((*d).n_cards > 1)
    {
      size_t i;
      for (i = 0; i < (*d).n_cards - 1; i++)
	{
	  size_t j = i + rand() / (RAND_MAX / ((*d).n_cards - i) + 1);
	  card_t * t = (*d).cards[j];
	  (*d).cards[j] = (*d).cards[i];
	  (*d).cards[i] = t;
	}
    }
}

void assert_full_deck(deck_t * d) {
  int x = 0;
  for(size_t i = 0; i < (*d).n_cards; i++){
    assert_card_valid(*d->cards[i]);
    for(size_t j = 0; j< (*d).n_cards; j++){
      if((*d).cards[i]->value == (*d).cards[j]->value && (*d).cards[i]->suit  == (*d).cards[j]->suit){
	x++;
      }
    }
    assert(x<=1);
    x=0;
  }
}
