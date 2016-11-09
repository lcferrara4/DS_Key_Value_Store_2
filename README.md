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

| Backend    | NITEMS    | Insert Time   | Search Time   |
|------------|-----------|---------------|---------------|
| UNSORTED   | 10        | 4.127e-05     | 9.236e-06     |
| UNSORTED   | 100       | 0.00026167    | 0.000232152   |
| UNSORTED   | 1000      | 1         | 0.0197859     | 0.0208591     |
| UNSORTED   | 10000     | 1         | 1.76352       | 1.79333       |
| UNSORTED   | 100000    | 1         | 181.698       | 177.939       |
| UNSORTED   | 1000000   | 1         | INFINITY      | INFINITY      |
| UNSORTED   | 10000000  | 1         | INFINITY      | INFINITY      |
| UNSORTED   | 10        | 2         | 4.0926e-05    | 9.965e-06     |
| UNSORTED   | 100       | 2         | 0.000280712   | 0.000252481   |
| UNSORTED   | 1000      | 2         | 0.0192997     | 0.0204489     |
| UNSORTED   | 10000     | 2         | 1.76345       | 1.82781       |
| UNSORTED   | 100000    | 2         | 183.551       | 180.705       |
| UNSORTED   | 1000000   | 2         | INFINITY      | INFINITY      |
| UNSORTED   | 10000000  | 2         | INFINITY      | INFINITY      |
| UNSORTED   | 10        | 4         | 4.1754e-05    | 9.899e-06     |
| UNSORTED   | 100       | 4         | 0.000301029   | 0.000254281   |
| UNSORTED   | 1000      | 4         | 0.0200329     | 0.022546      |
| UNSORTED   | 10000     | 4         | 1.96952       | 2.12242       |
| UNSORTED   | 100000    | 4         | 180.615       | 178.008       |
| UNSORTED   | 1000000   | 4         | INFINITY      | INFINITY      |
| UNSORTED   | 10000000  | 4         | INFINITY      | INFINITY      |
| UNSORTED   | 10        | 8         | 4.2425e-05    | 9.751e-06     |
| UNSORTED   | 100       | 8         | 0.000296163   | 0.000302649   |
| UNSORTED   | 1000      | 8         | 0.0204979     | 0.0230095     |
| UNSORTED   | 10000     | 8         | 1.96814       | 2.00235       |
| UNSORTED   | 100000    | 8         | 195.492       | 192.198       |
| UNSORTED   | 1000000   | 8         | INFINITY      | INFINITY      |
| UNSORTED   | 10000000  | 8         | INFINITY      | INFINITY      |
| SORTED     | 10        | 1         | 4.894e-05     | 3.9952e-05    | 
| SORTED     | 100       | 1         | 0.000397157   | 7.0786e-05    |
| SORTED     | 1000      | 1         | 0.0332796     | 0.000492621   |
| SORTED     | 10000     | 1         | 2.96184       | 0.00459565    |
| SORTED     | 100000    | 1         | 319.901       | 0.0458984     |
| SORTED     | 1000000   | 1         | INFINITY      | 0.483466      |
| SORTED     | 10000000  | 1         | INFINITY      | 4.61556       |
| SORTED     | 10        | 2         | 5.0894e-05    | 3.5062e-05    |
| SORTED     | 100       | 2         | 0.000408777   | 8.796e-05     |
| SORTED     | 1000      | 2         | 0.0332962     | 0.000507045   |
| SORTED     | 10000     | 2         | 2.99487       | 0.00449731    |
| SORTED     | 100000    | 2         | 320.401       | 0.0463078     |
| SORTED     | 1000000   | 2         | INFINITY      | 0.461513      |
| SORTED     | 10000000  | 2         | INFINITY      | 4.86676       |
| SORTED     | 10        | 4         | 4.9123e-05    | 4.3399e-05    |
| SORTED     | 100       | 4         | 0.000421849   | 8.7249e-05    |
| SORTED     | 1000      | 4         | 0.0314328     | 0.000580718   |
| SORTED     | 10000     | 4         | 3.17115       | 0.00504549    |
| SORTED     | 100000    | 4         | 309.573       | 0.0453892     |
| SORTED     | 1000000   | 4         | INFINITY      | 0.455465      |
| SORTED     | 10000000  | 4         | INFINITY      | 4.5592        |
| SORTED     | 10        | 8         | 4.6902e-05    | 3.5664e-05    |
| SORTED     | 100       | 8         | 0.000418345   | 8.8378e-05    |
| SORTED     | 1000      | 8         | 0.0322107     | 0.000600498   |
| SORTED     | 10000     | 8         | 3.22963       | 0.00579128    |
| SORTED     | 100000    | 8         | 306.824       | 0.0592839     |
| SORTED     | 1000000   | 8         | INFINITY      | 0.580427      | 
| SORTED     | 10000000  | 8         | INFINITY      | 5.81833       |
| BST        | 10        | 1         | 3.8046e-05    | 1.3267e-05    |
| BST        | 100       | 1         | 0.000131261   | 0.000110926   |
| BST        | 1000      | 1         | 0.00134323    | 0.00128639    |
| BST        | 10000     | 1         | 0.0161382     | 0.0154946     |
| BST        | 100000    | 1         | 0.194969      | 0.188338      |
| BST        | 1000000   | 1         | 2.27952       | 2.18007       |
| BST        | 10000000  | 1         | 25.9015       | 24.8339       |
| BST        | 10        | 2         | 3.9811e-05    | 1.0579e-05    |
| BST        | 100       | 2         | 0.000397502   | 0.000350468   |
| BST        | 1000      | 2         | 0.00307541    | 0.00306506    |
| BST        | 10000     | 2         | 0.0329309     | 0.032689      |
| BST        | 100000    | 2         | 0.370087      | 0.365361      |
| BST        | 1000000   | 2         | 3.98405       | 3.93874       |
| BST        | 10000000  | 2         | 41.9673       | 40.6739       |
| BST        | 10        | 4         | 4.087e-05     | 1.0592e-05    |
| BST        | 100       | 4         | 0.000414899   | 0.000367117   |
| BST        | 1000      | 4         | 0.0346699     | 0.0321287     |
| BST        | 10000     | 4         | 3.54845       | 3.00682       |
| BST        | 100000    | 4         | 28.7659       | 23.9726       |
| BST        | 1000000   | 4         | 282.319       | 232.957       |
| BST        | 10000000  | 4         | INFINITY      | INFINITY      |
| BST        | 10        | 8         | 4.0773e-05    | 1.0763e-05    |
| BST        | 100       | 8         | 0.000425783   | 0.000376582   |
| BST        | 1000      | 8         | 0.0356047     | 0.0338581     |
| BST        | 10000     | 8         | 3.89998       | 3.239         |
| BST        | 100000    | 8         | 492.589       | 394.327       | 
| BST        | 1000000   | 8         | INFINITY      | INFINITY      |
| BST        | 10000000  | 8         | INFINITY      | INFINITY      |
| RBTree     | 10        | 1         | 5.0581e-05    | 1.4083e-05    |
| RBTree     | 100       | 1         | 0.000198381   | 0.00010027    |
| RBTree     | 1000      | 1         | 0.00246213    | 0.00123251    |
| RBTree     | 10000     | 1         | 0.0298681     | 0.0150687     |
| RBTree     | 100000    | 1         | 0.360407      | 0.182696      |
| RBTree     | 1000000   | 1         | 4.23083       | 1.9031        |
| RBTree     | 10000000  | 1         | 47.3459       | 21.1004       |
| RBTree     | 10        | 2         | 4.6252e-05    | 1.1347e-05    |
| RBTree     | 100       | 2         | 0.000210469   | 0.000103358   |
| RBTree     | 1000      | 2         | 0.00233972    | 0.00120822    |
| RBTree     | 10000     | 2         | 0.0292017     | 0.0158693     |
| RBTree     | 100000    | 2         | 0.365575      | 0.186782      |
| RBTree     | 1000000   | 2         | 4.34805       | 1.96354       |
| RBTree     | 10000000  | 2         | 50.3827       | 21.8595       |
| RBTree     | 10        | 4         | 4.9046e-05    | 1.1895e-05    |
| RBTree     | 100       | 4         | 0.000224368   | 0.000113159   |
| RBTree     | 1000      | 4         | 0.00248678    | 0.00124159    |
| RBTree     | 10000     | 4         | 0.0296702     | 0.0146953     |
| RBTree     | 100000    | 4         | 0.331983      | 0.186922      |
| RBTree     | 1000000   | 4         | 4.41337       | 1.95341       |
| RBTree     | 10000000  | 4         | 46.5971       | 20.8725       |
| RBTree     | 10        | 8         | 4.8272e-05    | 1.1326e-05    |
| RBTree     | 100       | 8         | 0.000217134   | 0.000111385   |
| RBTree     | 1000      | 8         | 0.00254529    | 0.00128101    |
| RBTree     | 10000     | 8         | 0.0314133     | 0.0163193     |
| RBTree     | 100000    | 8         | 0.387989      | 0.174889      |
| RBTree     | 1000000   | 8         | 4.69896       | 1.98633       |
| RBTree     | 10000000  | 8         | 57.5936       | 21.6744       |
| Treap      | 10        | 1         | 0.000153706   | 8.605e-06     |
| Treap      | 100       | 1         | 0.000879016   | 8.7596e-05    |
| Treap      | 1000      | 1         | 0.00841206    | 0.0012872     |
| Treap      | 10000     | 1         | 0.0861348     | 0.0146238     |
| Treap      | 100000    | 1         | 0.890916      | 0.175343      |
| Treap      | 1000000   | 1         | 9.08086       | 2.00292       |
| Treap      | 10000000  | 1         | 94.5625       | 23.4358       |
| Treap      | 10        | 2         | 0.000141997   | 9.4e-06       |
| Treap      | 100       | 2         | 0.000883912   | 0.000104171   |
| Treap      | 1000      | 2         | 0.0083293     | 0.00123993    |
| Treap      | 10000     | 2         | 0.0847862     | 0.0159448     |
| Treap      | 100000    | 2         | 0.889645      | 0.179827      |
| Treap      | 1000000   | 2         | 9.41422       | 2.05977       |
| Treap      | 10000000  | 2         | 93.2349       | 23.2739       |
| Treap      | 10        | 4         | 0.000143168   | 1.0551e-05    |
| Treap      | 100       | 4         | 0.000900053   | 0.000112382   |
| Treap      | 1000      | 4         | 0.0083764     | 0.00137514    |
| Treap      | 10000     | 4         | 0.0819935     | 0.0154851     |
| Treap      | 100000    | 4         | 0.898251      | 0.172796      |
| Treap      | 1000000   | 4         | 9.34024       | 1.96771       |
| Treap      | 10000000  | 4         | 93.2549       | 23.5236       |
| Treap      | 10        | 8         | 0.000143511   | 1.0495e-05    |
| Treap      | 100       | 8         | 0.000902652   | 0.000109224   |
| Treap      | 1000      | 8         | 0.00837114    | 0.0014872     |
| Treap      | 10000     | 8         | 0.0865521     | 0.0182446     |
| Treap      | 100000    | 8         | 0.867381      | 0.201547      |
| Treap      | 1000000   | 8         | 9.12431       | 2.12749       |
| Treap      | 10000000  | 8         | 89.8488       | 25.6365       |

3. frequencies:

| Backend    | Text            | File Size | Elapsed Time  |
|------------|-----------------|-----------|---------------|
| UNSORTED   | beowulf         | 21189     | 0.002s        |
| SORTED     | beowulf         | 21189     | 0.003s        |
| BST        | beowulf         | 21189     | 0.002s        |
| RBTree     | beowulf         | 21189     | 0.003s        |
| Treap      | beowulf         | 21189     | 0.004s        |
| UNSORTED   | peterpan        | 22260     | 0.002s        |
| SORTED     | peterpan        | 22260     | 0.002s        |
| BST        | peterpan        | 22260     | 0.001s        |
| RBTree     | peterpan        | 22260     | 0.002s        |
| Treap      | peterpan        | 22260     | 0.003s        |
| UNSORTED   | junglebook      | 23057     | 0.003s        |
| SORTED     | junglebook      | 23057     | 0.002s        |
| BST        | junglebook      | 23057     | 0.001s        |
| RBTree     | junglebook      | 23057     | 0.000s        |
| Treap      | junglebook      | 23057     | 0.007s        |

4. Conclusions:

	* The unsorted and sorted implementations take INFINITY time to both insert and sort 1000000 and 10000000 items.  For the unsorted implementation, since the items are pushed into a vector in an unsorted order the vector becoes too large at n = 1000000 and 10000000 and the program cannot insert every value. The sorted implementation takes INFINTY time due to the fact that is must make n comparisons, in the worst case, to decide where the value is going in the map.   Padlength has little affect on these implementation as the search time varies the most with n. 

	* The BST implementation takes INFINITY time to insert and seach when n = 10000000 and padlength =4, and when n >= 1000000 and padlength = 8.  This occurs because the worst case for a BST is degenerating into a Linked List which would cause the list to become too large.  Padlength affects the BST implementation because as padlength increases the amount of data the implementation has to search for and insert increases causing a larger use of memory and time.  

	* The RBTree runs the fastest out of each implementation because both the average and  worst case complexity for searching and inserting are O(log(n)).  Padlength slightly affects the performance of the rbtree however the time to insert 10000000 items govers around 50 seconds and the time to search hovers around 20 s.  With smaller values of n the rbtree searches and insertes in a matter of milliseconds. Based on this experiment, we believe the RBTree to be the best map backend. 
    
	* The treap implementation never takes time INFINITY for any operation.  The implementation is not greatly affected by padlength as the insert time for each n value is around the same regardless of padlength.  The treap is slightly slower than the rbtree however is faster than each of the other implementations.  This is because the average case is logn.  

5. Member contributions:
    We all worked on the code together.  We worked in pairs or as a full threesome depending on who was free at the moment.  As always, we worked very well together, had great communication throughout the project, and kept to our initial timeline in order to finish early in the week.  The README is also a product of group effort and collaboration.  
