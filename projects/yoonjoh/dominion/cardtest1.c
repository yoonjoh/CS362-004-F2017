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
//Tests the Adventurer Card which has an intentional bug where it loops until 8 treasure cards
//are acquired, which is impossible at the start of the game since there are only 7 copper
void testAdventurer()
{
	struct gameState G;
	int numPlayer = 2;
	int thisPlayer = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int r;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	r = initializeGame(numPlayer, k, seed, &G);

	int oldTotal = G.handCount[thisPlayer];
	
	cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
	int newTotal = G.handCount[thisPlayer];

	printf("%s", "adventurerCard() with intentional bug, results should say test failed:");
	assertTest(oldTotal + 8 == newTotal);

}


int main(int argc, char *argv[])
{
    testAdventurer();
    return 0;
}