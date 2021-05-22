#include <string>
#include <iostream>
using namespace std;

class Solution_151 {
public:
	string reverseWords(string s) {
		int n = s.size(), i = 0, j = 0;
		while (j < n) {
			while (j < n&&s[j] == ' ') ++j; // ��������ǰ��Ŀո�
			while (j < n&&s[j] != ' ') s[i++] = s[j++]; // д�뵥��
			if (j < n) s[i++] = ' '; // ���ʺ���д��һ���ո�
		}
		s.resize(i); // ���ĩβ�пո�ɾ��
		if (s[i - 1] == ' ') s.pop_back();
		// �����ַ���ת��
		n = s.size();
		for (i = 0, j = n - 1; i < j; ++i, --j) {
			swap(s[i], s[j]);
		}
		// �ҵ�ÿ�����ʣ���ÿ������ת��
		i = 0, j = 0;
		while (j < n) {
			while (j < n&&s[j] != ' ') ++j;
			for (int k = j - 1; i < k; ++i, --k) {
				swap(s[i], s[k]);
			}
			i = ++j; // i j ��Ϊ��һ�����ʵ���ʼλ��
		}
		return s;
	}
};

void test_151() {
	string s = "  hello world!  ";
	string ans = "world! hello";
	cout << (Solution_151().reverseWords(s) == ans) << endl;
}