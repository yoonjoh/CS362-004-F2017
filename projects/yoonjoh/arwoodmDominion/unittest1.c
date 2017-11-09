#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"

#include <string.h>
#include <stdio.h>
#include "rngs.h"

//Tests the gainCard function by altering the values of toFlag
//and keeps track of the supplyCount and Piles Count
void testGainCard()
{
	struct gameState G;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int r;
	int test1, test2;

	r = initializeGame(numPlayer, k, seed, &G);

	//Tests if the supplyCount decreases by 1 and
	//if discardCount increases by 1, by testing toFlag value as 0
	int before = supplyCount(7, &G);
	int oldDiscard = G.discardCount[1];
	gainCard(7, &G, 0, 1);
	int after = supplyCount(7, &G);
	int newDiscard = G.discardCount[1]; 

	//Tests supplyCount decreases by 1
	test1 = (before == after + 1);
	//Tests discardCount increases by 1
	test2 = (oldDiscard == newDiscard - 1);
	printf("%s", "gainCard() when toFlag set as 0:");
	assertTest(test1 && test2);


	//Tests if the supplyCount decreases by 1 and
	//if deckCount increases by 1, by testing toFlag value as 1
	before = supplyCount(7, &G);
	int oldDeck = G.deckCount[1];
	gainCard(7, &G, 1, 1);
	after = supplyCount(7, &G);
	int newDeck = G.deckCount[1]; 

	//Tests supplyCount decreases by 1
	test1 = (before == after + 1);
	//Tests deckCount increases by 1
	test2 = (oldDeck == newDeck - 1);
	printf("%s", "gainCard() when toFlag set as 1:");
	assertTest(test1 && test2);


	//Tests if the supplyCount decreases by 1 and
	//if handCount increases by 1, by testing toFlag value as 2
	before = supplyCount(7, &G);
	int oldHand = G.handCount[1];

	gainCard(7, &G, 2, 1);
	after = supplyCount(7, &G);
	int newHand = G.handCount[1]; 

	//Tests supplyCount decreases by 1
	test1 = (before == after + 1);
	//Tests handCount increases by 1
	test2 = (oldHand == newHand - 1);
	printf("%s", "gainCard() when toFlag set as 2:");
	assertTest(test1 && test2);


	//Intentionally tests Error when toFlag value is set outside
	//the valid range, i.e. testing toFlag value as 3
	//The result: supplyCount decreases, but none of the piles increases
	before = supplyCount(7, &G);
	/*oldDiscard = G.discardCount[1];
	oldDeck = G.deckCount[1];*/
	oldHand = G.handCount[1];
	gainCard(7, &G, 3, 1);
	after = supplyCount(7, &G);
	/*newDiscard = G.discardCount[1];
	newDeck = G.deckCount[1];*/
	newHand = G.handCount[1]; 

	//Tests Supply Count decreases by 1
	test1 = (before == after + 1);
	//Tests handCount increases by 1
	test2 = (oldHand == newHand - 1);
	printf("%s", "gainCard() when toFlag set as 3 for intentional error:");
	assertTest(test1 && test2);
}


int main(int argc, char *argv[])
{
    testGainCard();
    return 0;
}
