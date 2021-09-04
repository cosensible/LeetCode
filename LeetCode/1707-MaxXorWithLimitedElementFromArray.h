#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1707 {
public:
	struct TrieNode_1707 {
		int val; // 以节点为根的子树所记录元素的最小值，若 val>m，则该子树所有元素不满足条件
		vector<TrieNode_1707*> children; // 用 C 风格的数组更快

		TrieNode_1707(int v) :val(v), children(2, nullptr) {}
		~TrieNode_1707() {
			for (TrieNode_1707 *ptn : children) {
				delete ptn;
				ptn = nullptr;
			}
		}
	};

	struct Trie_1707 {
		const int BIT = 30; // 1e9 最多使用 30 个二进制位
		TrieNode_1707 *root;

		Trie_1707() :root(new TrieNode_1707(INT_MAX)) {}
		~Trie_1707() { delete root; root = nullptr; }

		void add(int num) {
			TrieNode_1707 *p = root;
			for (int k = BIT - 1; k >= 0; --k) {
				bool bit = (1 << k)&num;
				if (p->children[bit] == nullptr) {
					p->children[bit] = new TrieNode_1707(num);
				}
				// 更新经过的每个子树存储的最小元素
				p->val = min(p->val, num);
				p = p->children[bit];
			}
		}

		int getMaxXorNum(int x, int m) {
			TrieNode_1707 *p = root;
			if (p->val > m) return -1; // 字典树中不包含 <=m 的数
			for (int k = BIT - 1; k >= 0; --k) {
				bool bit = (1 << k)&x;
				// 字典树中包含 <=m 的数，并且在被优先选择的子树中
				if (p->children[!bit] && p->children[!bit]->val <= m) {
					p = p->children[!bit];
				}
				else { // 若 <=m 的数不在被优先选择的子树中，则一定在另一子树中
					p = p->children[bit];
				}
			}
			return p->val;
		}
	};

	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
		Trie_1707 trie;
		for (int num : nums) { trie.add(num); }

		vector<int> ans(queries.size(), -1);
		for (int k = 0; k < queries.size(); ++k) {
			int oppo = trie.getMaxXorNum(queries[k][0], queries[k][1]);
			if (oppo != -1) ans[k] = queries[k][0] ^ oppo;
		}
		return ans;
	}
};


void test_1707() {
	vector<int> nums = { 0,1,2,3,4 };
	vector<vector<int>> queries = { {3, 1},{1, 3},{5, 6} };
	auto ans = Solution_1707().maximizeXor(nums, queries);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}