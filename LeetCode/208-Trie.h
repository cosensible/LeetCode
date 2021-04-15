#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

struct TrieNode {
	bool isWord;
	std::vector<TrieNode*> children;

	TrieNode() :isWord(false), children(26, nullptr) {}

	~TrieNode() {
		for (auto &p : children) {
			delete p;
			p = nullptr;
		}
	}
};

class Trie {
	TrieNode *root;
public:
	/** Initialize your data structure here. */
	Trie() :root(new TrieNode()) {}

	~Trie() {
		delete root;
		root = nullptr;
	}

	/** Inserts a word into the trie. */
	void insert(std::string word) {
		TrieNode *p = root;
		for (char c : word) {
			if (p->children[c - 'a'] == nullptr) {
				p->children[c - 'a'] = new TrieNode();
			}
			p = p->children[c - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(std::string word) {
		TrieNode *p = root;
		for (char c : word) {
			if (p->children[c - 'a'] == nullptr)
				return false;
			p = p->children[c - 'a'];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(std::string prefix) {
		TrieNode *p = root;
		for (char c : prefix) {
			if (p->children[c - 'a'] == nullptr)
				return false;
			p = p->children[c - 'a'];
		}
		return true;
	}
};


#endif // !TRIE_H