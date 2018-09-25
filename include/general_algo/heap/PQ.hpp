#ifndef GENERAL_ALGO_HEAP_PQ_HPP
#define GENERAL_ALGO_HEAP_PQ_HPP

#include "exch.hpp"
#include "fixUp.hpp"
#include "fixDown.hpp"

namespace general_algo {

namespace heap {

template <class Item>
class PQ {
private:
	Item *pq; 
	int N;

public:
	PQ(int maxN) 
	{ pq = new Item[maxN+1]; N = 0; }

	int empty() const 
	{ return N == 0; }

	void insert(Item item)
	{ pq[++N] = item;  fixUp(pq, N); }

	Item getmax()
	{ 
		exch(pq[1], pq[N]); 
		fixDown(pq, 1, N-1); 
		return pq[N--]; 
	}
};

}	// heap

}	// general_algo

#endif

