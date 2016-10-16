\newpage

# Part 2

For part 2 I wrote a set of solutions which can be run with different repetitions and array
sizes on the command line. However, all recorded times for these three implementations are for
1 repetition with an array of 1000 * 1000

### Implementation 1

Run time: 1.1595 seconds

```
    |a|b|      |w|x|
a = |-+-|  b = |-+-|
    |c|d|      |y|z|
```

Given the above matrices we can see that to obtain their product we must access b in the pattern
w, y, x, z. Given the way this array is arranged in memory we know that this is not a viable
pattern for arrays which are too large to fit inside of cache.

### Implementation 2

Run time: 0.8021 seconds

### Implementation 3

Run time: 0.9479 secs

Unfortunately I was unable to make my blocking algorithm faster than transpose at all. Even 
when I experimented with prefetching (code not included). I glanced at the object file for 
matrix2 and saw that gcc is utilizing some of the SIMD instructions for vector processing.

This makes it hard for me to know how to further optimize my blocking algorithm.

To write it I looked online for other approaches, I found this paper by Ulrich Drepper 
[What Every Programmer Should Know About Memory](https://www.akkadia.org/drepper/cpumemory.pdf),
which was helpful but ultimately I wasnt able to get blocking producing the correct results 
with his method. 
I found this paper by Marcin Paprzycki 
[Matrix Multiplication](http://www.ibspan.waw.pl/~paprzyck/mp/cvr/education/papers/ESCCC_92.pdf)
which I used to experiment with swapping the ordering of `for i.. for j.. for k..` into k,i,j,
(ultimately this had better results than my blocking solution, yet worse than transpositon).

The final approach I used was based on this short piece 
[MEM:BLOCKING:Using Blocking to Increase Temporal Locality](http://csapp.cs.cmu.edu/2e/waside/waside-blocking.pdf)

A and C are broken into strides as long as how many elements fit into a cache line. B is split
into blocks which are square with the dimensions of A and C.
