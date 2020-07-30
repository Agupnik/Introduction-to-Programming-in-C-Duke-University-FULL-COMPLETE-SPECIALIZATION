#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    card_t c;
    c.value = 14;

    c.suit = 2;
    //char m  = value_letter(c);
    //char z = suit_letter(c);
    //assert_card_valid(c);
    print_card(c);
  return 0;
}
