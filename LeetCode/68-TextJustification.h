#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution_68 {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int curWidth = 0, wordsWidth = 0; // ���ʼӿո�ĳ��ȣ����е��ʵĳ���
		int i = 0, j = 0; // j Ϊÿһ�е���ʼ����
		while (i < words.size()) {
			curWidth += words[i].size();
			if (i > j) ++curWidth;     // ����������һ�����Ͽո�
			wordsWidth += words[i].size();
			if (curWidth > maxWidth) { // ����һ��
				string s;         // ����ÿ�еĽ��
				if (i - j == 1) { // ����ֻ��һ������
					s += words[j++];
					string space(maxWidth - s.size(), ' ');
					s += space;
					res.push_back(s);
					curWidth = wordsWidth = 0;
					continue;
				}
				// �����ж�����ʣ���Ҫ����ÿ������֮��Ŀո���
				wordsWidth -= words[i].size();
				int spaceSum = maxWidth - wordsWidth;  // �ܿո���
				int spaceCnt = spaceSum / (i - j - 1); // ÿ���հ��������ٿո���
				int leftSpace = spaceSum - spaceCnt * (i - j - 1); // ����Ŀո�
				string space(spaceCnt, ' ');
				while (j < i) {
					s += words[j];
					if (j < i - 1) s += space;
					// ʣ��ո�������ҷ���
					if (leftSpace > 0) {
						s.push_back(' ');
						--leftSpace;
					}
					++j;
				}
				--i; // ��ǰ i ����Ϊ��һ�е���㣬������� ++i ����
				res.push_back(s);
				curWidth = wordsWidth = 0;
			}
			++i;
		}
		string s; // ���һ��
		for (; j < i; ++j) {
			s += words[j];
			if (j < i - 1) s.push_back(' ');
		}
		// ĩβ����ո�
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