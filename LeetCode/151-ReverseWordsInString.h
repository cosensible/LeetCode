#include <string>
#include <iostream>
using namespace std;

class Solution_151 {
public:
	string reverseWords(string s) {
		int n = s.size(), i = 0, j = 0;
		while (j < n) {
			while (j < n&&s[j] == ' ') ++j; // 跳过单词前面的空格
			while (j < n&&s[j] != ' ') s[i++] = s[j++]; // 写入单词
			if (j < n) s[i++] = ' '; // 单词后面写入一个空格
		}
		s.resize(i); // 如果末尾有空格，删除
		if (s[i - 1] == ' ') s.pop_back();
		// 整个字符串转置
		n = s.size();
		for (i = 0, j = n - 1; i < j; ++i, --j) {
			swap(s[i], s[j]);
		}
		// 找到每个单词，将每个单词转置
		i = 0, j = 0;
		while (j < n) {
			while (j < n&&s[j] != ' ') ++j;
			for (int k = j - 1; i < k; ++i, --k) {
				swap(s[i], s[k]);
			}
			i = ++j; // i j 置为下一个单词的起始位置
		}
		return s;
	}
};

void test_151() {
	string s = "  hello world!  ";
	string ans = "world! hello";
	cout << (Solution_151().reverseWords(s) == ans) << endl;
}