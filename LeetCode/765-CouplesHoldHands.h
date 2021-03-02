#include "common.h"
using namespace std;

class UnionSet {
	vector<int> parent; // 记录每个节点的父节点
	vector<int> size;   // 记录每个子树包含的节点数量
	int cnt; // 记录连通分量的个数

public:
	UnionSet(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0); // 每个节点的父节点为自己
		size.assign(n, 1); // 每棵树初始情况只包含 1 个节点
		cnt = n; // 初始情况有 n 棵树
	}

	int find(int x) {
		while (parent[x] != x) {
			parent[x] = parent[parent[x]]; // 路径压缩
			x = parent[x];
		}
		return x;
	}

	void merge(int x, int y) {
		int xp = find(x), yp = find(y);
		if (xp == yp) { return; } // 已经连通
		// 小树接到大树下面, 更加平衡
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

class Solution_765_Greedy {
public:
	int minSwapsCouples(vector<int>& row) {
		vector<int> pos(row.size());
		for (int i = 0; i < row.size(); ++i) {
			pos[row[i]] = i; // 记录每个人所在的位置
		}
		int ans = 0;
		for (int i = 0; i < row.size(); i += 2) {
			int cpos = pos[row[i] ^ 1]; // 另一半编号为 row[i] ^ 1, 获取其所在位置
			if (cpos == i + 1) { continue; } // 如果另一半在旁边, 不用再找另一半
			pos[row[i + 1]] = cpos; // 将旁边的人交换到另一半所在位置
			row[cpos] = row[i + 1];
			++ans;
		}
		return ans;
	}
};

class Solution_765_UnionFind {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		UnionSet us(n); // n 对情侣, 正常情况下分为 n 堆
		for (int i = 0; i < 2 * n; i += 2) {
			// 个体 row[i] 所在情侣对的编号为 row[i]/2
			us.merge(row[i] / 2, row[i + 1] / 2); // 如果两对情侣有联系（有坐在一起）, 合并为一堆
		}
		return n - us.getCnt();
	}
};

void test_765() {
	vector<int> row = { 0,2,1,3 };
	cout << (Solution_765_Greedy().minSwapsCouples(row) == 1) << endl;
}