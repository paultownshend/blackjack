/* 40 points */
/* Define all card/deck related functions as follows:
 * make_deck: generates a new list of 52 unique cards with ranks 1-13 and suits CDHS. Returns a pointer to the head of the list.
 *            Note: you must use malloc to create all 52 cards.
 * destroy_deck: consumes a pointer to a card. Free memory for all cards in the list.
 * shuffle: consumes a pointer to a card (expected to be the head of a list of cards). Returns a pointer to a card (the possibly new head).
 *          Randomly re-orders the cards in the list. Note; this function has been provided for you.
 * deal: consumes a pointer to a card (expected to be the head of a list of cards). Finds the last card in the list, prints its values, removes it
 *       from the list, and returns it (pointer to card).
 * total: consumes a pointer to card. Returns the sum of the values in the list headed by the given card (note: 10,11,12, and 13 all value as 10).
 * show: consumes a pointer to card. Prints the rank and suit of all cards in the list (this may be one card) on one line. For example:
 *       11H 9S 3D 1C 1S
*/
#include "card.h"
#include <stdlib.h>
#include <stdio.h>



card *make_deck(card *iCard) {
    char suits[] = {'C', 'D', 'H', 'S'};
    card *current = iCard;
    for (int i = 1; i < 14; i++) {
        for (int s = 0; s < 4; s++) {
	   if (i == iCard->rank && suits[s] == iCard->suit) {
		continue;
	   }
	   while (current->next != NULL) {
		   current = current->next;
	   }
           current->next = malloc(sizeof(card));
	   current->next->rank = i;
	   current->next->suit = suits[s];
	}
    }
}

void show(card *deck) {
	card *current = deck;
	while (current != NULL) {
		printf("%c %i\n", current->suit, current->rank);
		current = current->next;
	}
}

void destroy_deck(card *deck) {
	card *current = deck;
	while((current != NULL) {
		deck = deck->next;
		free(current);
	}
}

/* counts the number of cards in the list headed by "deck" */
int count_deck(card *deck) {
    int count=0;
    /* No initialization required. When "deck" is NULL (zero), it's at the end. Otherwise, move to the
    next card and increment the count. No body of the for loop! */
    for(;deck;deck=deck->next,count++);
    return count;
}

/* Emulates a "riffle shuffle" of "deck". */
card *shuffle(card *deck) {
    int size = count_deck(deck);
    card *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    card *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    card *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        card *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}

int main(void) {

	card *c;
	c = malloc(sizeof(card));
	c->rank = 5;
	c->suit = 'H';
	printf("suit = %c\nrank = %i\n", c->suit, 8);
	make_deck(c);
	card *c1 = c->next;
	printf("suit of next card = %c\nrank of next card = %i\n", c1->suit, c1->rank);
        printf("%i\n", count_deck(c));
	show(c);
}
