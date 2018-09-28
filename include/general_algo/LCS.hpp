#ifndef GENERAL_ALGO_LCS_HPP
#define GENERAL_ALGO_LCS_HPP

#include <vector>
#include <iostream>
#include <string>

namespace general_algo {

template <class Item>
class LCS {
private:
	std::vector<std::vector<int>> c;
	std::vector<std::vector<char>> b;
	const Item *X;
	const Item *Y;
	int X_length;
	int Y_length;

	template <typename T>
	static void init(std::vector<std::vector<T>> &v, int m, int n)
	{
		v.resize(m+1);
		for (int i = 0; i <= m; i++) {
			v[i].resize(n+1);
		}	
	}

	void calculate()
	{
		int m = X_length;
		int n = Y_length;
		init(b, m, n);
		init(c, m, n);

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (X[i-1] == Y[j-1]) {
					c[i][j] = c[i-1][j-1]+1;
					b[i][j] = '\\';
				} else if (c[i-1][j] >= c[i][j-1]) {
					c[i][j] = c[i-1][j];
					b[i][j] = '|';
				} else {
					c[i][j] = c[i][j-1];
					b[i][j] = '-';
				}
			}
		}
	}

	void print(int i, int j, const std::string &sep)
	{
		if (i == 0 || j == 0)
			return;
		if (b[i][j] == '\\') {
			print(i-1, j-1, sep);
			std::cout << X[i-1] << sep;
		} else if (b[i][j] == '|') {
			print(i-1, j, sep);
		} else {
			print(i, j-1, sep);
		}
	}

public:
	LCS(const Item *x, int x_length, const Item *y, int y_length):
		X(x), Y(y), X_length(x_length), Y_length(y_length)
	{
		calculate();
	}

	int length() const {
		return c[X_length][Y_length];
	}

	void print(const std::string &sep=", ")
	{
		print(X_length, Y_length, sep);
	}
};

}	// general_algo

#endif

