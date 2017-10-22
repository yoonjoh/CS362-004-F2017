#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"

#include <string.h>
#include <stdio.h>
#include "rngs.h"

//Tests the discardCard function by seeing if the
//playedCardCount increases/decreases (depending on trashFlag
//value), while the handCount always decreases
void testDiscardCard()
{
	struct gameState G;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int r;
	int test1, test2;

	r = initializeGame(numPlayer, k, seed, &G);
	//Just one card in the player's hands
	G.hand[1][0] = 7;
	G.handCount[1]++;


	//Tests if the playedCardCount increases by 1 and
	//if handCount decreases by 1, when trashFlag value is 0
	int before = G.playedCardCount;
	int oldHand = G.handCount[1];
	discardCard(0, 1, &G, 0);
	int after = G.playedCardCount;
	int newHand = G.handCount[1];
	//Tests playedCardCount increases by 1
	test1 = (before == after - 1);
	//Tests handCount decreases by 1
	test2 = (oldHand == newHand + 1);
	printf("%s", "discardCard() when trashFlag is 0:");
	assertTest(test1 && test2);


	//Tests if the playedCardCount stays the same and
	//if handCount decreases by 1, when trashFlag value is 1
	before = G.playedCardCount;
	oldHand = G.handCount[1];
	discardCard(0, 1, &G, 1);
	after = G.playedCardCount;
	newHand = G.handCount[1];
	//Tests playedCardCount stays the same
	test1 = (before == after);
	//Tests handCount decreases by 1
	test2 = (oldHand == newHand + 1);
	printf("%s", "discardCard() when trashFlag is 1:");
	assertTest(test1 && test2);


	//Tests for results when trashFlag value is not 
	//expected values of 0 or 1, i.e. when it is 2
	//Results: Acts identical to when trashFlag value is 1
	before = G.playedCardCount;
	oldHand = G.handCount[1];
	discardCard(0, 1, &G, 2);
	after = G.playedCardCount;
	newHand = G.handCount[1];
	//Tests playedCardCount stays the same
	test1 = (before == after);
	//Tests handCount decreases by 1
	test2 = (oldHand == newHand + 1);
	printf("%s", "discardCard() when trashFlag is 2:");
	assertTest(test1 && test2);
}


int main(int argc, char *argv[])
{
    testDiscardCard();
    return 0;
}