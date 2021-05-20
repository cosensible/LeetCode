#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution_127 {
public:
	// ����������ֻ��һ���ַ���ͬ��������໥ת��
	// ��ÿ�����ʿ���һ���ڵ㣬�������໥ת������ڵ�֮���б�����
	// ��ת�������е����ٵ��������ȼ����������ͼ�е����·�ĳ���
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