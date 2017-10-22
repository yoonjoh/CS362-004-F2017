#include <stdio.h>


int assertTest(int test)
{
	if (test == 1)
	{
		printf("%s\n", "TEST SUCCESSFULLY COMPLETED");
	}

	else
	{
		printf("%s\n", "TEST FAILED");
	}

	return 0;
}