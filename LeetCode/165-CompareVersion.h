#include <string>
#include <iostream>
using namespace std;

class Solution_165 {
public:
	int compareVersion(string version1, string version2) {
		int num1 = 0, num2 = 0; // 保存每个修订号的值
		int p1 = 0, p2 = 0; // 保存下一个修订号的起始位置
		int len1 = version1.size(), len2 = version2.size();
		while (p1 < len1 || p2 < len2) {
			if (p1 < len1)
				p1 = getNext(version1, p1, num1);
			else num1 = 0; // p1到达末尾, 修订号置为0
			if (p2 < len2)
				p2 = getNext(version2, p2, num2);
			else num2 = 0; // p2到达末尾, 修订号置为0
			if (num1 < num2) return -1;
			if (num1 > num2) return 1;
		}
		return 0;
	}

private:
	// s为版本号字符串, beg为下一个修订号的起始位置, 修订号的值保存到num
	int getNext(string &s, int beg, int &num) {
		int i = beg;
		for (; i < s.size() && s[i] != '.'; ++i) {}
		num = stoi(s.substr(beg, i - beg));
		return i < s.size() ? i + 1 : i;
	}
};


void test_165() {
	string v1 = "1.2.01";
	string v2 = "1.10.0";
	cout << (Solution_165().compareVersion(v1, v2) == -1) << endl;
}