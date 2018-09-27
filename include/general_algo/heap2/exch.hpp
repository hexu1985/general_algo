#ifndef GENERAL_ALGO_HEAP_EXCH_HPP
#define GENERAL_ALGO_HEAP_EXCH_HPP

namespace general_algo {

namespace heap {

template <class Item> 
void exch(Item &A, Item &B) 
{ 
	Item t = A; A = B; B = t; 
}

}	// heap

}	// general_algo

#endif
