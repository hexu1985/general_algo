#ifndef GENERAL_ALGO_HEAP_FIXUP_HPP
#define GENERAL_ALGO_HEAP_FIXUP_HPP

#include "exch.hpp"

namespace general_algo {

namespace heap {

template <class Item>
void fixUp(Item a[], int k)
{
	while (k > 0 && a[(k-1)/2] < a[k]) { 
		exch(a[k], a[(k-1)/2]); 
		k = (k-1)/2; 
	}
}

}	// heap

}	// general_algo

#endif
