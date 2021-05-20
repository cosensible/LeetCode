#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution_127 {
public:
	// 若两个单词只有一个字符不同，则可以相互转换
	// 将每个单词看作一个节点，单词能相互转换代表节点之间有边相连
	// 求转换序列中的最少单词数，等价于求解无向图中的最短路的长度
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		vector<bool> visited(wordList.size(), false);
		queue<pair<int, int>> Q;
		for (int i = 0; i < wordList.size(); ++i) {
			if (connected(beginWord, wordList[i])) {
				Q.push({ i,2 });
				visited[i] = true;
			}
		}
		while (!Q.empty()) {
			auto p = Q.front();
			Q.pop();
			if (wordList[p.first] == endWord) return p.second;
			for (int i = 0; i < wordList.size(); ++i) {
				if (!visited[i] && connected(wordList[p.first], wordList[i])) {
					Q.push({ i,p.second + 1 });
					visited[i] = true;
				}
			}
		}
		return 0;
	}

private:
	bool connected(string &s1, string &s2) {
		int cnt = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) {
				if (++cnt > 1) { return false; }
			}
		}
		return cnt == 1;
	}
};


void test_127() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
	cout << (Solution_127().ladderLength(beginWord, endWord, wordList) == 5) << endl;
}