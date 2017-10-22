#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"

#include <string.h>
#include <stdio.h>
#include "rngs.h"


int adventurerCard (struct gameState *state);
int smithyCard(struct gameState *state, int handPos);
int mineCard(struct gameState *state, int handPos, int choice1, int choice2);
int remodelCard(struct gameState *state, int handPos, int choice1, int choice2);

//Tests the Smithy Card by counting the hand count before and after and comparing
void testSmithy()
{
	struct gameState G, testG;
	int numPlayer = 2;
	int thisPlayer = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int r;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	r = initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	int oldTotal = testG.handCount[thisPlayer];
	
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	int newTotal = testG.handCount[thisPlayer];

	printf("%s", "smithyCard() with intentional bug, results should say test failed:");
	assertTest(oldTotal + 9 == newTotal);
}


int main(int argc, char *argv[])
{
    testSmithy();
    return 0;
}