#ifndef GENERAL_ALGO_HEAP_FIXDOWN_HPP
#define GENERAL_ALGO_HEAP_FIXDOWN_HPP

#include "exch.hpp"

namespace general_algo {

namespace heap {

template <class Item>
void fixDown(Item a[], int k, int N)
{
	while (2*k+1 < N) { 
		int j = 2*k+1;
		if (j < N-1 && a[j] < a[j+1]) j++;
		if (!(a[k] < a[j])) break;
		exch(a[k], a[j]); k = j;
	}
}

}	// heap

}	// general_algo

#endif
