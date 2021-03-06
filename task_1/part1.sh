#!/bin/sh

# usage: part1.sh $repetitions $x $y
# where 2 to the power of x through y are the values of array size to test.

if [ $# -ne 3 ]
	then echo not enough args
	exit 1;
fi

m=$1
start=$2
end=$3

make clean >> /dev/null
make >> /dev/null
rm -f part1.data >> /dev/null

echo "Part1 test with M of" $m >> part1.data

for i in `seq $start $end`;
do
	x=$(echo 2^$i | bc)
	echo "n=" $x >> part1.data 
	./cachetest1.out --repetitions $m --array_size $x | grep time >> part1.data
	./cachetest2.out --repetitions $m --array_size $x | grep time >> part1.data

done

make clean >> /dev/null
