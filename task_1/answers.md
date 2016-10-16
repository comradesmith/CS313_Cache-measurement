\newpage

# Part 1

### Processor details

Intel(R) Core(TM) i7-4770S CPU @ 3.10GHz

Level 1 Cache: 8192 KB
Level 2 Cache: 32	KB
Level 3 Cache: 1 	MB
*note, this is 1 MB per core, this CPU has 'smart cache' meaning that these L3 caches are
shared between 8 cores.*

### Results

|N          |size of a  |Case 1     |Case 2     |
|-----------|-----------|-----------|-----------|
|1024       |4   KB     |0.5859     |0.5859     |
|2048       |8   KB     |0.4883     |0.4883     |
|4096       |16  KB     |0.4395     |0.3906     |
|8192       |32  KB     |0.5371     |0.4883     |
|16384      |64  KB     |0.5005     |0.4883     |
|32768      |128 KB     |0.4150     |0.5493     |
|65536      |256 KB     |0.4211     |0.7904     |
|131072     |512 KB     |0.4272     |1.1200     |
|262144     |1   MB     |0.4173     |1.2718     |
|524288     |2   MB     |0.4227     |1.4080     |
|1048576    |4   MB     |0.4385     |2.0391     |
|2097152    |8   MB     |0.5009     |3.7135     |
|4194304    |16  MB     |0.5600     |6.4807     |
|8388608    |32  MB     |0.5815     |8.0140     |
|16777216   |64  MB     |0.6174     |9.1286     |
|33554432   |128 MB     |0.5167     |9.3303     |
|67108864   |256 MB     |0.5075     |9.2896     |
|134217728  |512 MB     |0.4942     |9.3978     |
|268435456  |1   GB     |0.5873     |9.7701     |

### Observations

**Linear**

The linear implementation behaved as expected, the time increased linearly and the time per
iteration remained constant. This implementation has a time complexity of O(N).

**Random**

While the size of the array a is less than the l2 cache for my 8 cores the access speeds are
similar to linear. During the 32kb - 256bk range we see increasing penalties as a is presumably
being stored mostly in the l2 caches of the various cores, with *smart cache* assisting. This 
leads to a region of linear increase in time per iteration until we rapidly reach the size 
ranges of the L3 caches.

The range between 1mb and 8mb is a range of incredibly sharp rise in time. As we go past the 
8mb point as diminishing portion of the data is able to be contained in cache of any kind, 
and once the majority is stored in ram we see a flatter increase in time per iteration.



