#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution_68 {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int curWidth = 0, wordsWidth = 0; // 单词加空格的长度，所有单词的长度
		int i = 0, j = 0; // j 为每一行的起始单词
		while (i < words.size()) {
			curWidth += words[i].size();
			if (i > j) ++curWidth;     // 单词数大于一，加上空格
			wordsWidth += words[i].size();
			if (curWidth > maxWidth) { // 超出一行
				string s;         // 保存每行的结果
				if (i - j == 1) { // 该行只有一个单词
					s += words[j++];
					string space(maxWidth - s.size(), ' ');
					s += space;
					res.push_back(s);
					curWidth = wordsWidth = 0;
					continue;
				}
				// 该行有多个单词，需要计算每个单词之间的空格数
				wordsWidth -= words[i].size();
				int spaceSum = maxWidth - wordsWidth;  // 总空格数
				int spaceCnt = spaceSum / (i - j - 1); // 每个空包含的最少空格数
				int leftSpace = spaceSum - spaceCnt * (i - j - 1); // 多余的空格
				string space(spaceCnt, ' ');
				while (j < i) {
					s += words[j];
					if (j < i - 1) s += space;
					// 剩余空格从左往右分配
					if (leftSpace > 0) {
						s.push_back(' ');
						--leftSpace;
					}
					++j;
				}
				--i; // 当前 i 将作为新一行的起点，与下面的 ++i 抵消
				res.push_back(s);
				curWidth = wordsWidth = 0;
			}
			++i;
		}
		string s; // 最后一行
		for (; j < i; ++j) {
			s += words[j];
			if (j < i - 1) s.push_back(' ');
		}
		// 末尾补齐空格
		if (s.size() < maxWidth) {
			string space(maxWidth - s.size(), ' ');
			s += space;
		}
		res.push_back(s);
		return res;
	}
};


void test_68() {
	vector<string> words = { "Science","is","what","we","understand","well","enough",
		"to","explain","to","a","computer.","Art","is","everything","else","we","do" };
	auto res = Solution_68().fullJustify(words, 20);
	for (string &s : res) {
		cout << s << endl;
	}
}