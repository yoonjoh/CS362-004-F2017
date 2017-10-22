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

//Tests the Mine Card by counting the money count before and after and comparing
void testMine()
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

	//Counts the total money before using mine
	int money = 0;
	for(int i = 0; i < G.handCount[thisPlayer]; i++)
	{
		if (G.hand[thisPlayer][i] == 4)
		{
			money++;
		}
		if (G.hand[thisPlayer][i] == silver)
		{
			money = money + 2;
		}
		if (G.hand[thisPlayer][i] == gold)
		{
			money = money + 3;
		}
	}

	cardEffect(mine, choice1, choice2, choice3, &G, handpos, &bonus);

	//Counts the total money after using mine
	int newMoney = 0;
	for(int i = 0; i < G.handCount[thisPlayer]; i++)
	{
		if (G.hand[thisPlayer][i] == 4)
		{
			newMoney++;
		}
		if (G.hand[thisPlayer][i] == silver)
		{
			newMoney = newMoney + 2;
		}
		if (G.hand[thisPlayer][i] == gold)
		{
			newMoney = newMoney + 3;
		}
	}
	printf("%s", "mineCard() with intentional bug, results should say successful:");
	assertTest(money != newMoney);
}


int main(int argc, char *argv[])
{
    testMine();
    return 0;
}