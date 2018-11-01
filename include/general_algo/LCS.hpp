#ifndef GENERAL_ALGO_LCS_HPP
#define GENERAL_ALGO_LCS_HPP

#include <vector>
#include <stdexcept>

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
	static void make_matrix(std::vector<std::vector<T>> &v, int m, int n)
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
		make_matrix(b, m, n);
		make_matrix(c, m, n);

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

public:
	LCS(const Item *x, int x_length, const Item *y, int y_length):
		X(x), Y(y), X_length(x_length), Y_length(y_length)
	{
		calculate();
	}

	int length() const {
		return c[X_length][Y_length];
	}

	std::vector<Item> get_LCS() const {
		std::vector<Item> lcs;
		int i = X_length, j = Y_length;
		while (i > 0 && j > 0) {
			switch (b[i][j]) {
			case '\\':
				lcs.push_back(X[i-1]);
				--i; --j;
				break;
			case '|':
				--i;
				break;
			case '-':
				--j;
				break;
			default:
				std::runtime_error("logic error!");
				break;
			}
		}
		return std::move(lcs);
	}
};

}	// general_algo

#endif

