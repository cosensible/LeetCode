#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ÿ�����ķ�Χ�� [0, 2^31)��������Ʊ�ʾ���Կ����ǳ���Ϊ 31 �Ķ����ƴ�
// ��������ÿ�����Ķ����ƴ�����λ���ȼ����ֵ����У�����һ����������������������ʱ�������ֵ�����ʹÿһλ��������������෴
// �������飬ȡÿ������Ϊ�����������ֵ����в������������������󷵻����н�������ֵ

struct TrieNode {
	int val; // ֻ��Ҷ�ӽڵ�洢������ö����ƴ���ʾ����
	vector<TrieNode*> children; // ÿ���ڵ��������ӣ��ֱ���� 0 �� 1

	TrieNode() :val(0), children(2, nullptr) {}

	~TrieNode() {
		for (TrieNode *p : children) {
			delete p;
		}
	}
};

struct Trie {
	TrieNode *root;

	Trie() :root(new TrieNode()) {}

	~Trie() { delete root; }

	// ��һ���� x �����������ʽ�����ֵ�����
	void add(int x) {
		TrieNode *p = root;
		for (int k = 30; k >= 0; --k) {
			bool bit = (1 << k)&x;
			if (p->children[bit] == nullptr) {
				p->children[bit] = new TrieNode();
			}
			p = p->children[bit];
		}
		p->val = x;
	}

	// �� num Ϊ������������ num �����ܻ�����������
	int getReverse(int num) {
		TrieNode *p = root;
		for (int k = 30; k >= 0; --k) {
			bool bit = (1 << k)&num;
			// Ҫʹ����������Ҫ���ȿ����෴��λ
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
	Trie trie;
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