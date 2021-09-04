#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
using namespace std;

struct TrieNode {
	bool end;
	vector<TrieNode*> table;
	TrieNode() :end(false), table(256, nullptr) {}
};

class Trie {
	TrieNode *root;
public:
	/** Initialize your data structure here. */
	Trie() :root(new TrieNode()) {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (char c : word) {
			if (p->table[c] == nullptr) {
				p->table[c] = new TrieNode();
			}
			p = p->table[c];
		}
		p->end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = root;
		for (char c : word) {
			if (p->table[c] == nullptr)
				return false;
			p = p->table[c];
		}
		return p->end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (char c : prefix) {
			if (p->table[c] == nullptr)
				return false;
			p = p->table[c];
		}
		return true;
	}
};

#endif // !TRIE_H
