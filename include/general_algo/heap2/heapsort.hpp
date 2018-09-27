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
	Item *pq = a+l;
	for (k = (N-2)/2; k >= 0; k--) 
		fixDown(pq, k, N);
	while (N > 0) { 
		exch(pq[0], pq[N-1]); 
		fixDown(pq, 0, --N); 
	}
}

}	// heap

}	// general_algo

#endif

