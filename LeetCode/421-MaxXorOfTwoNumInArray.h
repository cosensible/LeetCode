#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 每个数的范围是 [0, 2^31)，其二进制表示可以看成是长度为 31 的二进制串
// 将数组中每个数的二进制串按高位优先加入字典树中，在求一个数与其它数的最大异或结果时，查找字典树，使每一位尽可能与参照数相反
// 遍历数组，取每个数作为参照数，在字典树中查找异或结果最大的数，最后返回所有结果的最大值

struct TrieNode_421 {
	int val; // 只在叶子节点存储，代表该二进制串表示的数
	vector<TrieNode_421*> children; // 每个节点两个儿子，分别代表 0 和 1

	TrieNode_421() :val(0), children(2, nullptr) {}

	~TrieNode_421() {
		for (TrieNode_421 *p : children) {
			delete p;
		}
	}
};

struct Trie_421 {
	TrieNode_421 *root;

	Trie_421() :root(new TrieNode_421()) {}

	~Trie_421() { delete root; }

	// 将一个数 x 按其二进制形式加入字典树中
	void add(int x) {
		TrieNode_421 *p = root;
		for (int k = 30; k >= 0; --k) {
			bool bit = (1 << k)&x;
			if (p->children[bit] == nullptr) {
				p->children[bit] = new TrieNode_421();
			}
			p = p->children[bit];
		}
		p->val = x;
	}

	// 以 num 为参照数，求与 num 异或后能获得最大结果的数
	int getReverse(int num) {
		TrieNode_421 *p = root;
		for (int k = 30; k >= 0; --k) {
			bool bit = (1 << k)&num;
			// 要使异或结果最大，需要优先考虑相反的位
			if (p->children[!bit]) {
				p = p->children[!bit];
			}
			else {
				p = p->children[bit];
			}
		}
		return p->val;
	}
};

class Solution_421 {
	Trie_421 trie;
public:
	int findMaximumXOR(vector<int>& nums) {
		for (int x : nums) { trie.add(x); }
		int ans = 0;
		for (int x : nums) { ans = max(ans, x^trie.getReverse(x)); }
		return ans;
	}
};


void test_421() {
	vector<int> nums = { 3,10,5,25,2,8 };
	cout << (Solution_421().findMaximumXOR(nums) == 28) << endl;
}