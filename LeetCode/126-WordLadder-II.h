#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_126 {
	vector<int> level;    // 每个单词在转换序列中最早出现的层次
	vector<bool> visited; // 在 DFS 中判断单词是否被访问过，防止出现回路
	vector<vector<bool>> isconnected; // 各单词之间是否能相互转换
	int minNum = INT_MAX; // 最短转换序列的长度，通过 BFS 计算
	vector<string> sequence;    // 当前转换序列
	vector<vector<string>> res; // 所有最短转换序列
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		wordList.insert(wordList.begin(), beginWord);
		int n = wordList.size();
		level.assign(n, 0); // 0 代表单词未被访问或无法到达
		isconnected.assign(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) { // 单词无法转换为自己
				if (connected(wordList[i], wordList[j]))
					isconnected[i][j] = isconnected[j][i] = true;
			}
		}
		// BFS，计算最短转换序列的长度，并标记每个单词最早出现的层次
		// 若单词最早出现在第 i 层，则该单词出现在第 j>i 层得到的转换序列一定更长，可以剪枝
		bfs(0, endWord, wordList);

		// DFS，起点为 beginWord
		sequence.push_back(beginWord);
		visited.assign(n, false);
		visited[0] = true;
		backtrack(0, endWord, wordList);
		return res;
	}

private:
	void bfs(int cid, string endWord, vector<string>& wordList) {
		queue<pair<int, int>> Q;
		Q.push({ cid,1 });
		level[cid] = 1;
		while (!Q.empty()) {
			auto p = Q.front();
			Q.pop();
			if (wordList[p.first] == endWord) minNum = min(minNum, p.second);
			// 找到最短长度并不返回，继续标记剩余单词最早出现的层次
			for (int i = 0; i < wordList.size(); ++i) {
				if (level[i] == 0 && isconnected[p.first][i]) {
					Q.push({ i,p.second + 1 });
					level[i] = p.second + 1;
				}
			}
		}
	}

	void backtrack(int cid, string &endWord, vector<string>& wordList) {
		// 单词当前所在层次为 sequence.size()，若其大于 level[cid]，剪枝
		if (sequence.size() > level[cid]) { return; }
		if (sequence.size() == minNum) { // 转换序列的长度不会超过 minNum
			if (wordList[cid] == endWord)
				res.push_back(sequence);
			return;
		}
		// 挑选下一层单词
		for (int i = 0; i < wordList.size(); ++i) {
			if (!visited[i] && isconnected[cid][i]) {
				sequence.push_back(wordList[i]);
				visited[i] = true;
				backtrack(i, endWord, wordList);
				visited[i] = false;
				sequence.pop_back();
			}
		}
	}
	// 判断单词能否相互转换
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


void test_126() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
	auto res = Solution_126().findLadders(beginWord, endWord, wordList);
	for (auto &vs : res) {
		for (string &s : vs) {
			cout << s << " ";
		}
		cout << endl;
	}
}