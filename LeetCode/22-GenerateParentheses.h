#include <vector>

using namespace std;

class Solution_22 {
	vector<string> res;
public:
	vector<string> generateParenthesis(int n) {
		string s(2 * n, '.');
		backtrace(s, 0, 0);
		return res;
	}

	void backtrace(string &s, int l, int r) {
		if (r > l) return; //��ǰ�����ű������Ŷ�,�ᵼ�������ַ����Ƿ�
		int n = s.size() / 2;
		if (l + r == 2 * n) { //���������ҵõ��Ϸ������ַ���,��������
			res.push_back(s);
			return;
		}
		//������û����,��ѡ��������
		if (l < n) {
			s[l + r] = '(';
			backtrace(s, l + 1, r);
		}
		//������û����,��ѡ��������
		if (r < n) {
			s[l + r] = ')';
			backtrace(s, l, r + 1);
		}
	}
};