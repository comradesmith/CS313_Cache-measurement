OPT = -O1 				

default: cachetest1

cachestest1: cachetest1.o 
	gcc $(OPT) -o cachestest1.out cachestest1.o

cachestest1.o: cachestest1.c
	gcc $(OPT) -c cachestest1.c


clean:
	rm -f *.o
	rm -f cachestest1

