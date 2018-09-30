#ifndef GENERAL_ALGO_BINSEARCH_HPP
#define GENERAL_ALGO_BINSEARCH_HPP

namespace general_algo {

// perform a binary search of an array for a target
// in the index range [first, last). return the index of a
// match or last if the target is not in arr
template <typename T>
int binSearch(const T arr[], int first, int last, const T &target);
{
	int mid;					// index of the midpoint
	T midValue;					// object that is assigned arr[mid]
	int origLast = last;		// save original value of last
	
	while (first < last)		// test for nonempty sublist
	{
		mid = (first+last)/2;
		midValue = arr[mid];
		if (target == midValue)
			return mid;			// have a match
		// determine which sublist to search
		else if (target < midValue)
			last = mid;			// search lower sublist. reset last
		else
			first = mid+1;		// search upper sublist. reset first
	}

	return origLast;			// target not found
}

}	// general_algo

#endif

