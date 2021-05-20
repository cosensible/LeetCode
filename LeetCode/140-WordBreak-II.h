#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution_140 {
	vector<string> res;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		string sentence;
		backtrack(s, wordDict, 0, sentence);
		return res;
	}

private:
	void backtrack(string &s, vector<string> &wordDict, int i, string &sentence) {
		if (i == s.size()) {
			sentence.pop_back();
			res.push_back(sentence);
			sentence.push_back(' ');
			return;
		}
		for (string &word : wordDict) {
			if (s.substr(i, word.size()) == word) {
				sentence += word;
				sentence.push_back(' ');
				backtrack(s, wordDict, i + word.size(), sentence);
				sentence.resize(sentence.size() - word.size() - 1);
			}
		}
	}
};


void test_140() {
	string s = "catsanddog";
	vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
	auto res = Solution_140().wordBreak(s, wordDict);
	for (string &sentence : res) {
		cout << sentence << endl;
	}
}