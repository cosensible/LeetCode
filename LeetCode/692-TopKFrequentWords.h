#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_692 {
	using WordCnt = pair<string, int>;
	struct Comp {
		bool operator()(WordCnt &a, WordCnt &b) {
			// 次数一样按字典序
			if (a.second == b.second) return a.first < b.first;
			return a.second > b.second;
		}
	};
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> cnt; // 统计词频
		for (auto &word : words) { cnt[word]++; }
		// 保留前 K 个高频词
		priority_queue<WordCnt, vector<WordCnt>, Comp> pq;
		for (auto &p : cnt) {
			pq.push(p);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		// 降序排列
		vector<string> res(k);
		for (int i = k - 1; i >= 0; --i) {
			res[i] = pq.top().first;
			pq.pop();
		}
		return res;
	}
};

void test_692() {
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	auto res = Solution_692().topKFrequent(words, 2);
	for (string &s : res) {
		cout << s << " ";
	}
	cout << endl;
}