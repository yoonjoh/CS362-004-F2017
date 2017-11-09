#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"

#include <string.h>
#include <stdio.h>
#include "rngs.h"

//Tests the isGameOver function by exploring the results of various 
//values for Province and supply counts
void testIsGameOver()
{
	struct gameState G;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int r;

	r = initializeGame(numPlayer, k, seed, &G);

	//Test for baseline when nothing had been changed, thus
	//the Province count should be 8, and the game should NOT be over
	int endTest = isGameOver(&G);
	printf("%s", "isGameOver() when Province count is 8 since the game started; baseline test:");
	assertTest(endTest == 0);

	//Tests for when just Province count is 0 and 
	//the rest of the supply counts are 5
	for (int i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 5;
	}
	G.supplyCount[province] = 0;
	endTest = isGameOver(&G);
	printf("%s", "isGameOver() when Province count is 0, but all other supply counts are 5:");
	assertTest(endTest == 1);

	//Tests for when just Province count is intentionally error range value of -1 and 
	//the rest of the supply counts are 5
	G.supplyCount[province] = -1;
	printf("%s", "isGameOver() when Province count is -1, but all other supply counts are 5:");
	assertTest(endTest == 1);


	//Tests when just one supply count is zero, and
	//the rest are 5, including province count.
	G.supplyCount[7] = 0;
	G.supplyCount[province] = 5;
	endTest = isGameOver(&G);
	printf("%s", "isGameOver() when one supply count is 0, but all other supply counts are 5:");
	assertTest(endTest == 0);

	//Tests when just two supply counts are zero, and
	//the rest are 5, including province count.
	G.supplyCount[7] = 0;
	G.supplyCount[8] = 0;
	endTest = isGameOver(&G);
	printf("%s", "isGameOver() when two supply counts are 0, but all other supply counts are 5:");
	assertTest(endTest == 0);

	//Tests when just three supply counts are zero, and
	//the rest are 5, including province count.
	G.supplyCount[7] = 0;
	G.supplyCount[8] = 0;
	G.supplyCount[9] = 0;
	endTest = isGameOver(&G);
	printf("%s", "isGameOver() when three supply counts are 0, but all other supply counts are 5:");
	assertTest(endTest == 1);

}


int main(int argc, char *argv[])
{
    testIsGameOver();
    return 0;
}