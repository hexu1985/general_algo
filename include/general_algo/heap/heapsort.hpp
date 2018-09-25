#ifndef GENERAL_ALGO_HEAP_HEAPSORT_HPP
#define GENERAL_ALGO_HEAP_HEAPSORT_HPP

#include "exch.hpp"
#include "fixDown.hpp"

namespace general_algo {

namespace heap {

template <class Item>
void heapsort(Item a[], int l, int r)
{ 
	int k, N = r-l+1;
	Item *pq = a+l-1;
	for (k = N/2; k >= 1; k--) 
		fixDown(pq, k, N);
	while (N > 1) { 
		exch(pq[1], pq[N]); 
		fixDown(pq, 1, --N); 
	}
}

}	// heap

}	// general_algo

#endif

