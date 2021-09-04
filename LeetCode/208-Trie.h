#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

/**
 * Your Trie_208 object will be instantiated and called as such:
 * Trie_208* obj = new Trie_208();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

struct TrieNode_208 {
	bool isWord;
	std::vector<TrieNode_208*> children;

	TrieNode_208() :isWord(false), children(26, nullptr) {}

	~TrieNode_208() {
		for (auto &p : children) {
			delete p;
			p = nullptr;
		}
	}
};

class Trie_208 {
	TrieNode_208 *root;
public:
	/** Initialize your data structure here. */
	Trie_208() :root(new TrieNode_208()) {}

	~Trie_208() {
		delete root;
		root = nullptr;
	}

	/** Inserts a word into the trie. */
	void insert(std::string word) {
		TrieNode_208 *p = root;
		for (char c : word) {
			if (p->children[c - 'a'] == nullptr) {
				p->children[c - 'a'] = new TrieNode_208();
			}
			p = p->children[c - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(std::string word) {
		TrieNode_208 *p = root;
		for (char c : word) {
			if (p->children[c - 'a'] == nullptr)
				return false;
			p = p->children[c - 'a'];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(std::string prefix) {
		TrieNode_208 *p = root;
		for (char c : prefix) {
			if (p->children[c - 'a'] == nullptr)
				return false;
			p = p->children[c - 'a'];
		}
		return true;
	}
};


#endif // !TRIE_H