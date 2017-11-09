#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"

#include <string.h>
#include <stdio.h>
#include "rngs.h"

//Tests the fullDeckCount function by altering the values of 
//deck count, hand count, and discard count
void testFullDeckCount()
{
	struct gameState G;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int r;

	r = initializeGame(numPlayer, k, seed, &G);

	//Baseline test for Player 1 when nothing hand happened yet
	//or in otherwords, deck, hand, and discard counts are all 0
	int total = fullDeckCount(1, 7, &G);
	printf("%s", "fullDeckCount() when all counts are 0 and nothing has happened:");
	assertTest(total == 0);

	//Tests for when deckCount is 0, and the rest is 5.
	G.handCount[1] = 5;
	G.discardCount[1] = 5;
	total = fullDeckCount(1, 7, &G);
	printf("%s", "fullDeckCount() when deckCount is 0, and the rest is 5:");
	assertTest(total == 10);

	//Tests for when handCount is 0, and the rest is 5.
	G.handCount[1] = 0;
	G.deckCount[1] = 5;
	total = fullDeckCount(1, 7, &G);
	printf("%s", "fullDeckCount() when handCount is 0, and the rest is 5:");
	assertTest(total == 10);

	//Tests for when discardCount is 0, and the rest is 5.
	G.discardCount[1] = 0;
	G.handCount[1] = 5;
	total = fullDeckCount(1, 7, &G);
	printf("%s", "fullDeckCount() when discardCount is 0, and the rest is 5:");
	assertTest(total == 10);
}


int main(int argc, char *argv[])
{
    testFullDeckCount();
    return 0;
}