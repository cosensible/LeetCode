#include "common.h"
using namespace std;

class UnionSet {
	vector<int> parent; // ��¼ÿ���ڵ�ĸ��ڵ�
	vector<int> size;   // ��¼ÿ�����������Ľڵ�����
	int cnt; // ��¼��ͨ�����ĸ���

public:
	UnionSet(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0); // ÿ���ڵ�ĸ��ڵ�Ϊ�Լ�
		size.assign(n, 1); // ÿ������ʼ���ֻ���� 1 ���ڵ�
		cnt = n; // ��ʼ����� n ����
	}

	int find(int x) {
		while (parent[x] != x) {
			parent[x] = parent[parent[x]]; // ·��ѹ��
			x = parent[x];
		}
		return x;
	}

	void merge(int x, int y) {
		int xp = find(x), yp = find(y);
		if (xp == yp) { return; } // �Ѿ���ͨ
		// С���ӵ���������, ����ƽ��
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
			pos[row[i]] = i; // ��¼ÿ�������ڵ�λ��
		}
		int ans = 0;
		for (int i = 0; i < row.size(); i += 2) {
			int cpos = pos[row[i] ^ 1]; // ��һ����Ϊ row[i] ^ 1, ��ȡ������λ��
			if (cpos == i + 1) { continue; } // �����һ�����Ա�, ����������һ��
			pos[row[i + 1]] = cpos; // ���Աߵ��˽�������һ������λ��
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
		UnionSet us(n); // n ������, ��������·�Ϊ n ��
		for (int i = 0; i < 2 * n; i += 2) {
			// ���� row[i] �������¶Եı��Ϊ row[i]/2
			us.merge(row[i] / 2, row[i + 1] / 2); // ���������������ϵ��������һ��, �ϲ�Ϊһ��
		}
		return n - us.getCnt();
	}
};

void test_765() {
	vector<int> row = { 0,2,1,3 };
	cout << (Solution_765_Greedy().minSwapsCouples(row) == 1) << endl;
}