#include "dominion.h"
#include "dominion_helpers.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"


//RANDOM test for refactored Adventurer, so
//the amount of Treasure Cards you come across is 3 (instead of 2)
int main(int argc, char *argv[])
{
    
	struct gameState G;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	srand(1);
	int seed;
	int r;
	int testTotal = 1000;
	int count = 0;

	//Amount of time loops runs depends on "testTotal"
	//which is set above
	for(int i = 0; i < testTotal; i++)
	{
		//Game initialized with random value
		seed = rand();
		r = initializeGame(numPlayer, k, seed, &G);
		G.whoseTurn = 0;

		//Random values assigned to the deck count,
		//discard count, and hand count
		G.deckCount[0] = rand() % MAX_DECK;
		G.discardCount[0] = rand() % MAX_DECK;
		G.handCount[0] = rand() % MAX_HAND;


		//The hand total before card used 
		int preHandCount = G.handCount[0];
		//printf("%s%d\n", "The preHandCount is ",preHandCount);

		//The refactored ADVENTURER card used
		gainCard(adventurer, &G, 2, 0);
		playCard(preHandCount, 0, 0, 0, &G);

		//The hand total after card used
		int postHandCount = G.handCount[0];
		//printf("%s%d\n", "The postHandCount is ",postHandCount);


		//The assertion that keeps count of 
		//how many tests are successful
		if(preHandCount  + 3 == postHandCount)
		{
			count++;
		}
	} 
	printf("%s", "The TOTAL SUCCESSFUL TESTS IS ");
	printf("%d \n", count);


    return 0;
}


