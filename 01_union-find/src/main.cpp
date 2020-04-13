#include <iostream>
#include <fstream>
#include "UnionFind.h"
#include "Timer.h"

int main()
{
	unsigned int N;		// number of points
	unsigned int p, q;	// pair of points

	std::ifstream infile("input.txt");

	if (infile.is_open()) {

		infile >> N;

		std::cout << '\n' << N << " points in total.\n";
		
        // QuickFind uf(N);
        // QuickUnion uf(N);
		WeightedQuickUnion uf(N);
        // PathCompressionWeightedQuickUnion uf(N);

		{
			Timer timer;

			while (infile >> p >> q) {
				if (!uf.connected(p, q)) {
					uf.join(p, q);
					//std::cout << p << " " << q << '\n'; // comment if timing
				}
			}
		}
	}

	return 0;
}