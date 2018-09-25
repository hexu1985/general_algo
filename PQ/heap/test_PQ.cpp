#include <iostream>
#include "PQ.hpp"

using namespace std;
using namespace general_algo::heap;

int main(int argc, char *argv[]) 
{
	const int maxN = 100;

	PQ<int> pq(maxN);
	int n;
	int count = 0;
	while (cin >> n) {
		count++;
		if (count > maxN)
			break;
		pq.insert(n);
	}

	cout << "pop all item from PQ:\n";
	while (!pq.empty()) {
		cout << pq.getmax() << "\n";
	}

	cout << endl;
	return 0;
}
