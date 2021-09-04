#include <vector>
#include <iostream>
using namespace std;

#include "Trie.h"


vector<string> diff(vector<string> &A, vector<string> &B) {
	Trie trie;
	vector<string> ans;
	for (auto &w : A) {
		trie.insert(w);
	}
	for (auto &w : B) {
		if (!trie.search(w)) {
			ans.push_back(w);
		}
	}
	return ans;
}

void test_diff() {
	vector<string> A = { "this is the world!","hello word", "phone size" };
	vector<string> B = { "this is the world","hello word","hello world", "phone" };
	auto ans = diff(A, B);
	for (string &s : ans) {
		cout << s << endl;
	}
}