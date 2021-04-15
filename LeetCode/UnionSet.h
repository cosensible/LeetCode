#ifndef UNION_SET
#define UNION_SET

#include <vector>
#include <numeric>

class UnionSet {
	std::vector<int> parent;
	std::vector<int> size;
	int cnt;

public:
	UnionSet(int n) :parent(n), size(n, 1), cnt(n) {
		std::iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) {
		while (parent[x] != x) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	void merge(int x, int y) {
		int xp = find(x), yp = find(y);
		if (xp == yp) { return; }
		if (size[xp] > size[yp]) {
			parent[yp] = xp;
			size[xp] += size[yp];
		}
		else {
			parent[xp] = yp;
			size[yp] += size[xp];
		}
		--cnt;
	}

	bool connected(int x, int y) {
		int xp = find(x), yp = find(y);
		return xp == yp;
	}

	int getCnt() {
		return cnt;
	}
};


#endif // !UNION_SET