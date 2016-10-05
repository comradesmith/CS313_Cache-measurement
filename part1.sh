#!/bin/sh

m=8192

make clean
make
rm -f *.data

echo "Part1 test with M of" $m >> part1.data

for i in `seq 10 20`;
do
	x=$(echo 2^$i | bc)
	echo "n=" $x >> part1.data 
	./cachetest1.out --repetitions $m --array_size $x | grep time >> part1.data
	./cachetest2.out --repetitions $m --array_size $x | grep time >> part1.data

done

make clean
