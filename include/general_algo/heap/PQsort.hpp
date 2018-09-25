#ifndef GENERAL_ALGO_HEAP_PQSORT_HPP
#define GENERAL_ALGO_HEAP_PQSORT_HPP

#include "PQ.hpp"

namespace general_algo {

namespace heap {

template <class Item>
void PQsort(Item a[], int l, int r)
{ 
	int k;
	PQ<Item> pq(r-l+1);
	for (k = l; k <= r; k++) pq.insert(a[k]);
	for (k = r; k >= l; k--) a[k] = pq.getmax();
}

}	// heap

}	// general_algo

#endif

