#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cassert>
#include "binSearch.hpp"

using namespace general_algo;
using namespace std;

vector<int> read_ivec_from_file(const std::string &file_name)
{
    ifstream file(file_name);
    if (!file) {
        cout << "open file " << file_name << " fail!" << endl;
        exit(1);
    }
    
	int n;
	vector<int> vec;
    while (file >> n) {
        vec.push_back(n);
    }

    return std::move(vec);
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        cout << "usage: " << argv[0] << " datafile val_to_search" << endl;
        exit(1);
    }

	vector<int> vec = read_ivec_from_file(argv[1]);
	if (vec.empty()) return 1;

    sort(vec.begin(), vec.end());

	cout << "initial vector:\n";
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

    int val = stoi(argv[2]);
    cout << "look for value: " << val << endl;
	bool found = (binSearch(vec.data(), 0, vec.size(), val) != vec.size());
    cout << (found ? "Found it!" : "Not found!") << endl;

	assert(found == binary_search(vec.begin(), vec.end(), val));

	return 0;
}

