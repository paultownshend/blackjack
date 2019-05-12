/* Contains main() and any desired helper functions to play the game as described in the instructions. Must not _define_ any of the 
 * card-related helper functions but must use thm at least as frequently as indicated below (hit means either player or dealer hit):
 * make_deck:1; shuffle:1; deal: 3+1/hit; append: 1+1/hit; total: 2+1/hit; destroy_deck: 1
 */
 /* 15 points */
#include "card.c"
#include <stdio.h>
#include <stdlib.h>


 int main(void) {
    card *head = make_deck();
    head = shuffle(shuffle(head));
    card *player;
    card *computer;
    int game = 1;
    player = deal(head);
    player->next = deal(head);
    computer = deal(head);
    char *response = "";
    int player_score = total(player);
    int hit = 0;
    printf("Enter H to hit or S to stand\n");
    scanf("%s", response);
    if (response == "H" || response == "h" || response == "hit") {
	    hit = 1;
    }
    while (hit) {
	    player = deal(head);
	    player_score += player->rank;
	    if (player_score > 21) {
		    printf("Lost!\n");
		    game = 0;
		    break;
	    }
	    player = player->next;
	    printf("Enter H to hit or S to stand\n");
	    scanf("%s", response);
	    if (response == "H" || response == "h" || response == "hit") {
            hit = 1;
            }
	    else {
		    break;
	    }
    }
    if (response == "S" || response == "s" || response == "stand") {
	    player_score = total(player);
    }
    return 0;
 }
