#!/bin/bash

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	./map_bench -b unsorted $i; 
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	./map_bench -b sorted $i; 
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	./map_bench -b bst $i; 
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	./map_bench -b rbtree $i; 
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	./map_bench -b treap $i; 
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
        ./map_bench -b unordered $i;    
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
        ./map_bench -b unordered $i;
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 0.5, 0.75, 1.0, 5.0, 10.0, 100.0; do
        	./map_bench -b chained-$j $i;
	done
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 0.5, 0.6, 0.7, 0.8, 0.9, 1.0; do
        	./map_bench -b open-$j $i;
	done
done
