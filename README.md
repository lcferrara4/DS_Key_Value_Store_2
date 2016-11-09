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
|             unsorted |         10 | 1.2525e-05 |  1.363e-06 |
|               sorted |         10 | 1.3422e-05 |  2.919e-06 |
|                  bst |         10 | 1.4422e-05 |   3.09e-06 |
|               rbtree |         10 | 1.7245e-05 | 0.00039367 |
|                treap |         10 | 0.00055868 |  7.447e-06 |
|             unsorted |        100 | 1.3615e-05 |  1.196e-06 |
|               sorted |        100 | 1.7452e-05 |  4.103e-06 |
|                  bst |        100 |  9.333e-06 |   2.69e-06 |
|               rbtree |        100 | 2.1931e-05 |  8.318e-06 |
|                treap |        100 | 3.0054e-05 |  4.208e-06 |
|            unordered |        100 |     0.0001 |     0.0000 |
|             unsorted |       1000 | 1.2178e-05 |  1.041e-06 |
|               sorted |       1000 | 1.2653e-05 |  2.648e-06 |
|                  bst |       1000 |  8.576e-06 |  2.588e-06 |
|               rbtree |       1000 | 1.3627e-05 |  6.498e-06 |
|                treap |       1000 |  3.568e-05 |   4.27e-06 |
|            unordered |       1000 |     0.0005 |     0.0003 |
|             unsorted |      10000 | 1.2191e-05 |   9.14e-07 |
|               sorted |      10000 | 1.1487e-05 |  2.767e-06 |
|                  bst |      10000 |  8.274e-06 |  3.469e-06 |
|               rbtree |      10000 | 1.2963e-05 | 1.3167e-05 |
|                treap |      10000 |  3.065e-05 |  3.962e-06 |
|            unordered |      10000 |     0.0045 |     0.0030 |
|             unsorted |     100000 | 1.1757e-05 |   9.87e-07 |
|               sorted |     100000 | 1.2182e-05 |  2.649e-06 |
|                  bst |     100000 |  9.061e-06 |  2.528e-06 |
|               rbtree |     100000 | 1.3291e-05 |  5.829e-06 |
|                treap |     100000 | 3.2195e-05 |  4.844e-06 |
|             unsorted |    1000000 | 1.7941e-05 |   2.18e-06 |
|               sorted |    1000000 | 1.3523e-05 |   4.14e-06 |
|                  bst |    1000000 |  8.937e-06 |  3.152e-06 |
|               rbtree |    1000000 | 1.3977e-05 |  6.304e-06 |
|                treap |    1000000 | 3.3359e-05 | 1.4903e-05 |
|             unsorted |   10000000 | 1.2232e-05 |   9.55e-07 |
|               sorted |   10000000 | 1.2011e-05 |  2.806e-06 |
|                  bst |   10000000 |  8.596e-06 |  3.594e-06 |
|               rbtree |   10000000 | 1.3614e-05 |  7.994e-06 |
|                treap |   10000000 | 3.1325e-05 |  4.162e-06 |
project04

| BACKEND				| NITEMS	| INSERT		| SEARCH		|
| 				  treap |		 10 |  6.2122e-05 s |   4.326e-06 s |
|			  unordered |		 10 |  3.2209e-05 s |   7.109e-06 s |
| 				  treap |		100 |  5.1801e-05 s |   3.704e-06 s |
|			  unordered |		100 |  2.4836e-05 s |   5.964e-06 s |
| 				  treap |	   1000 |  5.2142e-05 s |   3.788e-06 s |
|			  unordered |	   1000 |  2.4739e-05 s |   5.831e-06 s |
| 				  treap |     10000 |  5.2168e-05 s |     3.8e-06 s |
|			  unordered |	  10000 |  2.4766e-05 s |    5.85e-06 s |
| 				  treap |	 100000 |  5.1817e-05 s |   3.757e-06 s |
|			  unordered |	 100000 |  2.5172e-05 s |   5.856e-06 s |
| 				  treap | 	1000000 |  5.1908e-05 s |   3.784e-06 s |
|			  unordered |	1000000 |  2.4788e-05 s |   5.951e-06 s |
| 				  treap |  10000000 |  5.2088e-05 s |   3.779e-06 s |
|			  unordered |  10000000 |  2.5014e-05 s |   5.942e-06 s |


| BACKEND				| NITEMS	|	LOAD FACTOR | INSERT		| SEARCH		|
|				chained |		 10 |            .5 |  2.3788e-05 s |   3.595e-06 s |
|				chained |        10 |           .75 |  1.8114e-05 s |    3.23e-06 s |
|				chained |  		 10 |             1 |  2.8052e-05 s |   3.319e-06 s |
|				chained |		 10 |             5 |  1.8873e-05 s |   3.132e-06 s |
|				chained |		 10 |            10 |   1.865e-05 s |   3.234e-06 s |
|				chained |		 10 |           100 |  1.8994e-05 s |   3.191e-06 s |
|				chained |		100 |			 .5 |  1.8297e-05 s |   3.262e-06 s |
|				chained |		100 |			.75 |  1.8144e-05 s |    3.31e-06 s |
|				chained |		100 |			  1 |  1.8719e-05 s |   3.173e-06 s |
|				chained |		100 |			  5 |  1.8762e-05 s |   3.169e-06 s |
|				chained |		100 |			 10 |  1.8756e-05 s |   3.203e-06 s |
|				chained |		100 |			100 |  3.7179e-05 s |   3.441e-06 s |
|				chained |	   1000 |			 .5 |  1.8114e-05 s |   3.141e-06 s |
|				chained |	   1000 |			.75 |  1.8047e-05 s |   3.243e-06 s |
|				chained |	   1000 |			  1 |  1.8696e-05 s |   3.133e-06 s |
|				chained |	   1000 |			  5 |  1.8745e-05 s |   3.227e-06 s |
|				chained |	   1000 |			 10 |  1.8647e-05 s |   3.125e-06 s |
|				chained |	   1000 |			100 |  1.9141e-05 s |   3.192e-06 s |
|				chained |     10000 |			 .5 |  1.8202e-05 s |    3.14e-06 s |
|				chained |     10000 |			.75 |  1.8286e-05 s |   3.578e-06 s |
|				chained |     10000 |			  1 |  1.8947e-05 s |   3.247e-06 s |
|				chained |     10000 |			  5 |  1.8946e-05 s |   3.213e-06 s |
|				chained |     10000 |			 10 |  1.8644e-05 s |   3.157e-06 s |
|				chained |     10000 |			100 |  1.8856e-05 s |   3.263e-06 s |
|				chained |    100000 |			 .5 |  1.8154e-05 s |   3.193e-06 s |
|				chained |    100000 |			.75 |  1.7986e-05 s |   3.244e-06 s |
|				chained |    100000 |			  1 |  1.8954e-05 s |    3.17e-06 s |
|				chained |    100000 |			  5 |  1.8812e-05 s |   3.232e-06 s |
|				chained |    100000 |			 10 |  1.8732e-05 s |   3.395e-06 s |
|				chained |    100000 |			100 |  1.8985e-05 s |   3.093e-06 s |
|				chained |   1000000 |			 .5 |  1.8435e-05 s |   3.143e-06 s |
|				chained |   1000000 |			.75 |  1.8083e-05 s |   3.234e-06 s |
|				chained |   1000000 |			  1 |  1.89755-05 s |   3.118e-06 s |
|				chained |   1000000 |			  5 |  1.8735e-05 s |   3.229e-06 s |
|				chained |   1000000 |			 10 |  1.8809e-05 s |   3.192e-06 s |
|				chained |   1000000 |			100 |  1.8817e-05 s |   3.194e-06 s |
|				chained |  10000000 |			 .5 |  1.8368e-05 s |   3.121e-06 s |
|				chained |  10000000 |			.75 |  1.8396e-05 s |   3.166e-06 s |
|				chained |  10000000 |			  1 |  1.8906e-05 s |   3.161e-06 s |
|				chained |  10000000 |			  5 |  1.8812e-05 s |   3.096e-06 s |
|				chained |  10000000 |			 10 |  1.8771e-05 s |   3.274e-06 s |
|				chained |  10000000 |			100 |  1.8843e-05 s |   3.217e-06 s |

| BACKEND				| NITEMS	|	LOAD FACTOR | INSERT		| SEARCH		|
|				   open |		 10 |            .5 |  2.0788e-05 s |   6.294e-06 s |
|				   open |        10 |            .6 |  1.6478e-05 s |   6.091e-06 s |
|				   open |  		 10 |            .7 |  1.6176e-05 s |   6.035e-06 s |
|				   open |		 10 |            .8 |  1.6169e-05 s |   6.023e-06 s |
|				   open |		 10 |            .9 |  1.6283e-05 s |   6.009e-06 s |
|				   open |		 10 |             1 |  1.7193e-05 s |   6.069e-06 s |
|				   open |		100 |			 .5 |  1.7699e-05 s |   6.186e-06 s |
|				   open |		100 |			 .6 |  2.1873e-05 s |   6.765e-06 s |
|				   open |		100 |			 .7 |  1.6016e-05 s |   6.089e-06 s |
|				   open |		100 |			 .8 |   1.616e-05 s |   5.963e-06 s |
|				   open |		100 |			 .9 |  1.6387e-05 s |   6.626e-06 s |
|				   open |		100 |			  1 |  1.6512e-05 s |   5.887e-06 s |
|				   open |	   1000 |			 .5 |   1.611e-05 s |   6.246e-06 s |
|				   open |	   1000 |			 .6 |  1.6191e-05 s |   5.948e-06 s |
|				   open |	   1000 |			 .7 |  1.6362e-05 s |   5.984e-06 s |
|				   open |	   1000 |			 .8 |  1.6273e-05 s |    5.89e-06 s |
|				   open |	   1000 |			 .9 |  1.6044e-05 s |   5.977e-06 s |
|				   open |	   1000 |			  1 |  1.6995e-05 s |   5.971e-06 s |
|				   open |     10000 |			 .5 |  1.5854e-05 s |   6.164e-06 s |
|				   open |     10000 |			 .6 |  1.6055e-05 s |   5.923e-06 s |
|				   open |     10000 |			 .7 |  1.6186e-05 s |   5.849e-06 s |
|				   open |     10000 |			 .8 |   1.622e-05 s |   6.033e-06 s |
|				   open |     10000 |			 .9 |  1.6108e-05 s |    6.04e-06 s |
|				   open |     10000 |			  1 |  1.6675e-05 s |   5.964e-06 s |
|				   open |    100000 |			 .5 |  1.5811e-05 s |   6.074e-06 s |
|				   open |    100000 |			 .6 |  1.6153e-05 s |    6.05e-06 s |
|				   open |    100000 |			 .7 |  1.5841e-05 s |   5.946e-06 s |
|				   open |    100000 |			 .8 |  1.6008e-05 s |   6.042e-06 s |
|				   open |    100000 |			 .9 |  3.2023e-05 s |   6.025e-06 s |
|				   open |    100000 |			  1 |  1.7561e-05 s |   6.086e-06 s |
|				   open |   1000000 |			 .5 |  1.6139e-05 s |   6.618e-06 s |
|				   open |   1000000 |			 .6 |  1.6334e-05 s |     6.5e-06 s |
|				   open |   1000000 |			 .7 |    1.625-05 s |   6.034e-06 s |
|				   open |   1000000 |			 .8 |  1.7086e-05 s |   6.101e-06 s |
|				   open |   1000000 |			 .9 |  1.6694e-05 s |   5.985e-06 s |
|				   open |   1000000 |			  1 |  1.6777e-05 s |   6.055e-06 s |
|				   open |  10000000 |			 .5 |  1.6093e-05 s |   6.026e-06 s |
|				   open |  10000000 |			 .6 |  1.6451e-05 s |   6.021e-06 s |
|				   open |  10000000 |			 .7 |  1.6317e-05 s |    6.01e-06 s |
|				   open |  10000000 |			 .8 |  1.6106e-05 s |   6.455e-06 s |
|				   open |  10000000 |			 .9 |  1.6314e-05 s |   7.311e-06 s |
|				   open |  10000000 |			  1 |  2.2403e-05 s |   6.286e-06 s |

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
