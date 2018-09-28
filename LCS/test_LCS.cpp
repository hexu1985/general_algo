#include <iostream>
#include <string>
#include "LCS.hpp"

using namespace std;
using namespace general_algo;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cout << "usage: lcs str1 str2" << endl;
		return 1;
	}

	string x = argv[1];
	string y = argv[2];

	LCS<char> lcs(x.data(), x.length(), y.data(), y.length());
	cout << "the lcs of [" << x << "] and [" << y << "]:\n";
	cout << "length = " << lcs.length() << "\n";
	cout << "common subsequence: ";
	lcs.print();
	cout << endl;

	return 0;
}
