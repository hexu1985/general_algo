#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "PQsort.hpp"

using namespace std;
using namespace general_algo::heap;

int main(int argc, char *argv[]) 
{
	vector<int> vec;
	int n;
	while (cin >> n) {
		vec.push_back(n);
	}

	if (vec.empty()) return 1;

	cout << "initial vector:\n";
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	PQsort(vec.data(), 0, vec.size()-1);

	cout << "after PQsort:\n";
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	return 0;
}

