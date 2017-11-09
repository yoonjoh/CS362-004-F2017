CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.c
	echo "Result for running dominion tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "randomtestcard2.c:" >> unittestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "randomtestadventurer.c:" >> unittestresults.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	gcc -o dominion dominion.c rngs.c randomtestcard1.c
	

clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 unittest2 unittest3 unittest4 randomtestcard1 randomtestcard2 randomtestadventurer *.gcda *.gcno *.gcov
