CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out 

unittestresults.out:  randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.c
	echo "Result for running dominion tests:" > unittestresults.out
	
	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> unittestresults.out
	gcov randomtestcard1.c >> unittestresults.out
	
	echo "randomtestcard2.c:" >> unittestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "randomtestcard2.c:" >> unittestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> unittestresults.out
	gcov randomtestcard2.c >> unittestresults.out
	
	echo "randomtestadventurer.c:" >> unittestresults.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "randomtestadventurer.c:" >> unittestresults.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> unittestresults.out
	gcov randomtestadventurer.c >> unittestresults.out

	gcc -o dominion dominion.c rngs.c randomtestcard1.c



	


clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out randomtestcard1 randomtestcard2 randomtestadventurer dominion *.gcda *.gcno *.gcov
