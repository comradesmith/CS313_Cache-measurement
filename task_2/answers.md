# Part 2

For part 2 I wrote a set of solutions which can be run with different repetitions and array
sizes on the command line. However, all recorded times for these three implementations are for
1 repetition with an array of 1000 * 1000

### Implementation 1

Run time: 1.1722 seconds

```
    |a|b|      |w|x|
a = |-+-|  b = |-+-|
    |c|d|      |y|z|
```

Given the above matrices we can see that to obtain their product we must access b in the pattern
w, y, x, z. Given the way this array is arranged in memory we know that this is not a viable
pattern for arrays which are too large to fit inside of cache.

### Implementation 2

Run time: 1.2125 seconds

### Implementation 3

Run time: 0.8376 secs


