#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_126 {
	vector<int> level;    // ÿ��������ת��������������ֵĲ��
	vector<bool> visited; // �� DFS ���жϵ����Ƿ񱻷��ʹ�����ֹ���ֻ�·
	vector<vector<bool>> isconnected; // ������֮���Ƿ����໥ת��
	int minNum = INT_MAX; // ���ת�����еĳ��ȣ�ͨ�� BFS ����
	vector<string> sequence;    // ��ǰת������
	vector<vector<string>> res; // �������ת������
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		wordList.insert(wordList.begin(), beginWord);
		int n = wordList.size();
		level.assign(n, 0); // 0 ������δ�����ʻ��޷�����
		isconnected.assign(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) { // �����޷�ת��Ϊ�Լ�
				if (connected(wordList[i], wordList[j]))
					isconnected[i][j] = isconnected[j][i] = true;
			}
		}
		// BFS���������ת�����еĳ��ȣ������ÿ������������ֵĲ��
		// ��������������ڵ� i �㣬��õ��ʳ����ڵ� j>i ��õ���ת������һ�����������Լ�֦
		bfs(0, endWord, wordList);

		// DFS�����Ϊ beginWord
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
			// �ҵ���̳��Ȳ������أ��������ʣ�൥��������ֵĲ��
			for (int i = 0; i < wordList.size(); ++i) {
				if (level[i] == 0 && isconnected[p.first][i]) {
					Q.push({ i,p.second + 1 });
					level[i] = p.second + 1;
				}
			}
		}
	}

	void backtrack(int cid, string &endWord, vector<string>& wordList) {
		// ���ʵ�ǰ���ڲ��Ϊ sequence.size()��������� level[cid]����֦
		if (sequence.size() > level[cid]) { return; }
		if (sequence.size() == minNum) { // ת�����еĳ��Ȳ��ᳬ�� minNum
			if (wordList[cid] == endWord)
				res.push_back(sequence);
			return;
		}
		// ��ѡ��һ�㵥��
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
	// �жϵ����ܷ��໥ת��
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