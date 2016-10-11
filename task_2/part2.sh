#!/bin/bash

# usage: part2.sh $repetitions $n

if [ $# -ne 2 ]
	then echo "usage: part2.sh $repetitions $n"
	exit 1;
fi

m=$1
n=$2

make clean >> /dev/null
make >> /dev/null
rm -f part2.data >> /dev/null

echo "Part2 test with m, n of :" $m $n >> part2.data


echo "martix1" `./matrix1.out --repetitions $m --n $n` >> part2.data
echo "matrix2" `./matrix2.out --repetitions $m --n $n` >> part2.data
echo "matrix3" `./matrix3.out --repetitions $m --n $n` >> part2.data
