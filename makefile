OPT = -O1 				

default: cachetest1 cachetest2

cachestest1: cachetest1.o 
	gcc $(OPT) -o cachetest1.out cachetest1.o

cachetest2: cachetest2.o
	gcc $(OPT) -o cachetest2.out cachetest2.o

cachestest1.o: cachestest1.c
	gcc $(OPT) -c cachetest1.c

cachetest2.o: cachetest2.c
	gcc $(OPT) -c cachetest2.c

clean:
	rm -f *.o
	rm -f cachetest1.out
	rm -f cachetest2.out

