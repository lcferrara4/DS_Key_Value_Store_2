Project 04 - Key-Value Store II
===============================

This [project] implements a variety of [map] backends for a basic [key-value
store].

[project]:          https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project04.html
[map]:              https://en.wikipedia.org/wiki/Associative_array
[key-value store]:  https://en.wikipedia.org/wiki/Key-value_database

1. Complexities of map backends:
	
	* Unordered: 
	Insert: Best = O(1), Average = O(1), Worst = O(1)
	Search: Best = O(1), Average = O(n), Worst = O(n)

	* Chained:
	Insert: Best = O(1), Average = O(n), Worst = O(n)
	Search: Best = O(1), Average = O(n), Worst = O(n)

	* Open:
	Insert: Best = O(1), Average = O(log(n)), Worst = O(n)
	Search: Best = O(1), Average = O(log(n)), Worst = O(n)

2. map\_bench:

| BACKEND              | NITEMS     | INSERT     | SEARCH     |
|----------------------|------------|------------|------------|
|             unsorted |          1 |     0.0000 |     0.0000 |
|               sorted |          1 |     0.0000 |     0.0000 |
|                  bst |          1 |     0.0000 |     0.0000 |
|               rbtree |          1 |     0.0000 |     0.0000 |
|                treap |          1 |     0.0000 |     0.0000 |
|            unordered |          1 |     0.0000 |     0.0000 |
|        chained-0.500 |          1 |     0.0000 |     0.0000 |
|        chained-0.750 |          1 |     0.0000 |     0.0000 |
|        chained-1.000 |          1 |     0.0000 |     0.0000 |
|        chained-5.000 |          1 |     0.0000 |     0.0000 |
|        chained-10.00 |          1 |     0.0000 |     0.0000 |
|        chained-100.0 |          1 |     0.0000 |     0.0000 |
|             open-0.5 |          1 |     0.0000 |     0.0000 |
|             open-0.6 |          1 |     0.0000 |     0.0000 |
|             open-0.7 |          1 |     0.0000 |     0.0000 |
|             open-0.8 |          1 |     0.0000 |     0.0000 |
|             open-0.9 |          1 |     0.0000 |     0.0000 |
|             open-1.0 |          1 |     0.0000 |     0.0000 |
|             unsorted |         10 |     0.0000 |     0.0000 |
|               sorted |         10 |     0.0000 |     0.0000 |
|                  bst |         10 |     0.0000 |     0.0000 |
|               rbtree |         10 |     0.0000 |     0.0000 |
|                treap |         10 |     0.0000 |     0.0000 |
|            unordered |         10 |     0.0000 |     0.0000 |
|        chained-0.500 |         10 |     0.0000 |     0.0000 |
|        chained-0.750 |         10 |     0.0000 |     0.0000 |
|        chained-1.000 |         10 |     0.0000 |     0.0000 |
|        chained-5.000 |         10 |     0.0000 |     0.0000 |
|        chained-10.00 |         10 |     0.0000 |     0.0000 |
|        chained-100.0 |         10 |     0.0000 |     0.0000 |
|             open-0.5 |         10 |     0.0000 |     0.0000 |
|             open-0.6 |         10 |     0.0000 |     0.0000 |
|             open-0.7 |         10 |     0.0000 |     0.0000 |
|             open-0.8 |         10 |     0.0000 |     0.0000 |
|             open-0.9 |         10 |     0.0000 |     0.0000 |
|             open-1.0 |         10 |     0.0000 |     0.0000 |
|             unsorted |        100 |     0.0002 |     0.0002 |
|               sorted |        100 |     0.0002 |     0.0000 |
|                  bst |        100 |     0.0001 |     0.0000 |
|               rbtree |        100 |     0.0001 |     0.0000 |
|                treap |        100 |     0.0001 |     0.0000 |
|            unordered |        100 |     0.0001 |     0.0000 |
|        chained-0.500 |        100 |     0.0001 |     0.0000 |
|        chained-0.750 |        100 |     0.0001 |     0.0000 |
|        chained-1.000 |        100 |     0.0001 |     0.0000 |
|        chained-5.000 |        100 |     0.0001 |     0.0000 |
|        chained-10.00 |        100 |     0.0001 |     0.0000 |
|        chained-100.0 |        100 |     0.0001 |     0.0000 |
|             open-0.5 |        100 |     0.0000 |     0.0000 |
|             open-0.6 |        100 |     0.0000 |     0.0000 |
|             open-0.7 |        100 |     0.0000 |     0.0000 |
|             open-0.8 |        100 |     0.0000 |     0.0000 |
|             open-0.9 |        100 |     0.0000 |     0.0000 |
|             open-1.0 |        100 |     0.0000 |     0.0000 |
|             unsorted |       1000 |     0.0123 |     0.0121 |
|               sorted |       1000 |     0.0154 |     0.0006 |
|                  bst |       1000 |     0.0005 |     0.0005 |
|               rbtree |       1000 |     0.0008 |     0.0005 |
|                treap |       1000 |     0.0006 |     0.0005 |
|            unordered |       1000 |     0.0005 |     0.0003 |
|        chained-0.500 |       1000 |     0.0007 |     0.0003 |
|        chained-0.750 |       1000 |     0.0009 |     0.0003 |
|        chained-1.000 |       1000 |     0.0005 |     0.0003 |
|        chained-5.000 |       1000 |     0.0005 |     0.0003 |
|        chained-10.00 |       1000 |     0.0005 |     0.0003 |
|        chained-100.0 |       1000 |     0.0005 |     0.0003 |
|             open-0.5 |       1000 |     0.0004 |     0.0003 |
|             open-0.6 |       1000 |     0.0004 |     0.0003 |
|             open-0.7 |       1000 |     0.0005 |     0.0002 |
|             open-0.8 |       1000 |     0.0005 |     0.0002 |
|             open-0.9 |       1000 |     0.0006 |     0.0003 |
|             open-1.0 |       1000 |     0.0008 |     0.0007 |
|             unsorted |      10000 |     1.1880 |     1.2000 |
|               sorted |      10000 |     1.5607 |     0.0073 |
|                  bst |      10000 |     0.0061 |     0.0059 |
|               rbtree |      10000 |     0.0099 |     0.0059 |
|                treap |      10000 |     0.0069 |     0.0057 |
|            unordered |      10000 |     0.0045 |     0.0030 |
|        chained-0.500 |      10000 |     0.0128 |     0.0028 |
|        chained-0.750 |      10000 |     0.0104 |     0.0028 |
|        chained-1.000 |      10000 |     0.0122 |     0.0028 |
|        chained-5.000 |      10000 |     0.0089 |     0.0034 |
|        chained-10.00 |      10000 |     0.0068 |     0.0036 |
|        chained-100.0 |      10000 |     0.0069 |     0.0036 |
|             open-0.5 |      10000 |     0.0061 |     0.0022 |
|             open-0.6 |      10000 |     0.0066 |     0.0022 |
|             open-0.7 |      10000 |     0.0052 |     0.0026 |
|             open-0.8 |      10000 |     0.0056 |     0.0024 |
|             open-0.9 |      10000 |     0.0072 |     0.0024 |
|             open-1.0 |      10000 |     0.0245 |     0.0024 |
|             unsorted |     100000 |        inf |        inf |
|               sorted |     100000 |        inf |        inf |
|                  bst |     100000 |     0.0683 |     0.0683 |
|               rbtree |     100000 |     0.1112 |     0.0718 |
|                treap |     100000 |     0.0803 |     0.0723 |
|            unordered |     100000 |     0.0507 |     0.0361 |
|        chained-0.500 |     100000 |     0.1463 |     0.0426 |
|        chained-0.750 |     100000 |     0.1885 |     0.0492 |
|        chained-1.000 |     100000 |     0.1334 |     0.0441 |
|        chained-5.000 |     100000 |     0.1691 |     0.0508 |
|        chained-10.00 |     100000 |     0.1812 |     0.0552 |
|        chained-100.0 |     100000 |     0.1109 |     0.0619 |
|             open-0.5 |     100000 |     0.0589 |     0.0247 |
|             open-0.6 |     100000 |     0.0637 |     0.0249 |
|             open-0.7 |     100000 |     0.0688 |     0.0253 |
|             open-0.8 |     100000 |     0.0575 |     0.0299 |
|             open-0.9 |     100000 |     0.0715 |     0.0296 |
|             open-1.0 |     100000 |     0.6994 |     0.0298 |
|             unsorted |    1000000 |        inf |        inf |
|               sorted |    1000000 |        inf |        inf |
|                  bst |    1000000 |     0.8359 |     0.7873 |
|               rbtree |    1000000 |     1.3052 |     0.8390 |
|                treap |    1000000 |     0.9814 |     0.8373 |
|            unordered |    1000000 |     0.6551 |     0.5111 |
|        chained-0.500 |    1000000 |     1.5739 |     0.5667 |
|        chained-0.750 |    1000000 |     2.0437 |     0.5169 |
|        chained-1.000 |    1000000 |     1.5648 |     0.5209 |
|        chained-5.000 |    1000000 |     2.1598 |     0.6825 |
|        chained-10.00 |    1000000 |     2.3305 |     0.7849 |
|        chained-100.0 |    1000000 |     3.4870 |     1.0099 |
|             open-0.5 |    1000000 |     0.7918 |     0.3476 |
|             open-0.6 |    1000000 |     0.7762 |     0.3499 |
|             open-0.7 |    1000000 |     0.8789 |     0.3500 |
|             open-0.8 |    1000000 |     1.0441 |     0.3515 |
|             open-0.9 |    1000000 |     1.5140 |     0.3510 |
|             open-1.0 |    1000000 |    33.2990 |     1.4274 |
|             unsorted |   10000000 |        inf |        inf |
|               sorted |   10000000 |        inf |        inf |
|                  bst |   10000000 |     9.3875 |     9.2954 |
|               rbtree |   10000000 |    14.6810 |     9.7553 |
|                treap |   10000000 |    10.0640 |    10.2470 |
|            unordered |   10000000 |     9.1063 |     5.3702 |
|        chained-0.500 |   10000000 |    23.1980 |     5.3952 |
|        chained-0.750 |   10000000 |    18.8790 |     5.2926 |
|        chained-1.000 |   10000000 |    23.0340 |     5.5527 |
|        chained-5.000 |   10000000 |    20.9280 |     7.5628 |
|        chained-10.00 |   10000000 |    23.1560 |     8.5264 |
|        chained-100.0 |   10000000 |    38.1510 |    13.4530 |
|             open-0.5 |   10000000 |    10.0810 |     3.3071 |
|             open-0.6 |   10000000 |     8.0291 |     4.0538 |
|             open-0.7 |   10000000 |     9.4615 |     4.1696 |
|             open-0.8 |   10000000 |    11.2160 |     4.2335 |
|             open-0.9 |   10000000 |    16.1610 |     4.9198 |
|             open-1.0 |   10000000 |        inf |        inf |

3. frequencies:

| Backend    | Text            | File Size | Elapsed Time  | Memory          |
|------------|-----------------|-----------|---------------|-----------------|
| UNSORTED   | beowulf         | 21189     | 0.059990s     | 1.328125 Mbytes |
| SORTED     | beowulf         | 21189     | 0.035993s     | 1.324219 Mbytes |
| BST        | beowulf         | 21189     | 0.008998s     | 1.343750 Mbytes |
| RBTree     | beowulf         | 21189     | 0.008997s     | 1.363281 Mbytes |
| Treap      | beowulf         | 21189     | 0.008998s     | 1.363281 Mbytes |
| Unordered  | beowulf         | 21189     | 0.007998s     | 1.386719 Mbytes |
| Chained    | beowulf         | 21189     | 0.007997s     | 1.414062 Mbytes |
| Open       | beowulf         | 21189     | 0.029994s     | 1.347656 Mbytes |
| UNSORTED   | peterpan        | 22260     | 0.065989s     | 1.332031 Mbytes |
| SORTED     | peterpan        | 22260     | 0.038993s     | 1.328125 Mbytes |
| BST        | peterpan        | 22260     | 0.008997s     | 1.343750 Mbytes |
| RBTree     | peterpan        | 22260     | 0.009998s     | 1.367188 Mbytes |
| Treap      | peterpan        | 22260     | 0.008998s     | 1.367188 Mbytes |
| Unordered  | peterpan        | 22260     | 0.007997s     | 1.386719 Mbytes |
| Chained    | peterpan        | 22260     | 0.007998s     | 1.417969 Mbytes |
| Open       | peterpan        | 22260     | 0.032994s     | 1.367188 Mbytes |
| UNSORTED   | junglebook      | 23057     | 0.066988s     | 1.332031 Mbytes |
| SORTED     | junglebook      | 23057     | 0.038993s     | 1.328125 Mbytes |
| BST        | junglebook      | 23057     | 0.008997s     | 1.347656 Mbytes |
| RBTree     | junglebook      | 23057     | 0.009997s     | 1.367188 Mbytes |
| Treap      | junglebook      | 23057     | 0.008997s     | 1.367188 Mbytes |
| Unordered  | junglebook      | 23057     | 0.007998s     | 1.382812 Mbytes |
| Chained    | junglebook      | 23057     | 0.007998s     | 1.417969 Mbytes |
| Open       | junglebook      | 23057     | 0.033994s     | 1.378906 Mbytes |

4. Conclusions:

	* The unsorted and sorted implementations take INFINITY time to both insert and sort 1000000 and 10000000 items.  For the unsorted implementation, since the items are pushed into a vector in an unsorted order the vector becoes too large at n = 1000000 and 10000000 and the program cannot insert every value. The sorted implementation takes INFINTY time due to the fact that is must make n comparisons, in the worst case, to decide where the value is going in the map.   Padlength has little affect on these implementation as the search time varies the most with n. 

	* The BST implementation takes INFINITY time to insert and seach when n = 10000000 and padlength =4, and when n >= 1000000 and padlength = 8.  This occurs because the worst case for a BST is degenerating into a Linked List which would cause the list to become too large.  Padlength affects the BST implementation because as padlength increases the amount of data the implementation has to search for and insert increases causing a larger use of memory and time.  

	* The RBTree runs the fastest out of each implementation because both the average and  worst case complexity for searching and inserting are O(log(n)).  Padlength slightly affects the performance of the rbtree however the time to insert 10000000 items govers around 50 seconds and the time to search hovers around 20 s.  With smaller values of n the rbtree searches and insertes in a matter of milliseconds. Based on this experiment, we believe the RBTree to be the best map backend. 
    
	* The treap implementation never takes time INFINITY for any operation.  The implementation is not greatly affected by padlength as the insert time for each n value is around the same regardless of padlength.  The treap is slightly slower than the rbtree however is faster than each of the other implementations.  This is because the average case is logn.  

5. Member contributions:
    We all worked on the code together.  We worked in pairs or as a full threesome depending on who was free at the moment.  As always, we worked very well together, had great communication throughout the project, and kept to our initial timeline in order to finish early in the week.  The README is also a product of group effort and collaboration.  
