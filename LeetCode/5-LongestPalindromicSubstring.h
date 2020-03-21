#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution_5 {
public:
	////��̬�滮
	//string longestPalindrome(string s) {
	//	int n = s.size();
	//	if (n < 2) return s;
	//	int p = 0, len = 1;
	//	vector<vector<bool>> mp = vector<vector<bool>>(n, vector<bool>(n, false));
	//	for (int k = 0; k < n; ++k) {
	//		for (int i = 0; i < n - k; ++i) {
	//			if (k == 0) {
	//				mp[i][i] = true;
	//			}
	//			else if (k == 1) {
	//				mp[i][i + 1] = (s[i] == s[i + 1]);
	//			}
	//			else {
	//				mp[i][i + k] = mp[i + 1][i + k - 1] && (s[i] == s[i + k]);
	//			}
	//			if (k + 1 > len&&mp[i][i + k]) {
	//				p = i;
	//				len = k + 1;
	//			}
	//		}
	//	}
	//	return s.substr(p, len);
	//}

	////������չ
	//string longestPalindrome(string s) {
	//	int n = s.size();
	//	if (n < 2) return s;
	//	int p = 0, res = 1;
	//	for (int i = 0; i < n; ++i) {
	//		int len1 = expandCenter(s, i, i); //�ӵ����ַ���ʼ��չ
	//		int len2 = expandCenter(s, i, i + 1); //���ַ���϶��ʼ��չ
	//		int len = max(len1, len2);
	//		if (len > res) {
	//			res = len;
	//			p = i - (len - 1) / 2;
	//		}
	//	}
	//	return s.substr(p, res);
	//}

	//Manacher
	string longestPalindrome(string s) {
		int n = s.size(), en = 2 * n + 1; //���n+1��#�ַ�,ʹ�ַ�����Ϊ����
		if (n < 2) return s;
		string es(en, '#');
		for (int i = 0; i < n; ++i) {
			es[2 * i + 1] = s[i]; //ԭ�����ַ�����#���
		}

		int mx = 1, id = 0;     //��ǰ���ʵ���es���ұ߽缰���Ӧ���ĵ�����λ��
		int len = 1, start = 0; //s��������Ӵ��ĳ��ȼ��俪ʼλ��
		vector<int> p(en, 1);   //���es�и����Ĵ�������Ӵ��İ뾶,��������
		for (int i = 0; i < en; ++i) {
			//������˵��
			p[i] = i < mx ? min(p[2 * id - i], mx - i) : 1;
			//�������Ż����Ӵ�
			while (i - p[i] >= 0 && i + p[i] < en
				&& es[i - p[i]] == es[i + p[i]]) ++p[i];
			if (mx < i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			if (p[i] - 1 > len) {
				len = p[i] - 1;
				start = (id - len) / 2;
			}
		}
		return s.substr(start, len);
	}

private:
	int expandCenter(const string &s, int l, int r) {
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			--l;
			++r;
		}
		return r - l - 1;
	}
};

void test_5() {
	string s = "cbbd";
	string res = Solution_5().longestPalindrome(s);
	cout << (res == "bb") << endl;
}