#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution_394 {
	unordered_map<int, int> mp; // ��¼���Ŷ���ֹ����
public:
	string decodeString(string s) {
		stack<int> is;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '[') is.push(i);
			else if (s[i] == ']') {
				mp[is.top()] = i;
				is.pop();
			}
		}
		return helper(s, 0, s.size() - 1);
	}

private:
	string helper(const string &s, int l, int r) {
		string res;
		if (l > r) return res;
		for (int i = l; i <= r; ++i) {
			if (s[i] >= '0' && s[i] <= '9') {  // ��������
				int num = s[i++] - '0';
				while (s[i] != '[') {  // ��λ��
					num = num * 10 + (s[i++] - '0');
				}
				// �ݹ�����Ӵ�
				string tmp = helper(s, i + 1, mp[i] - 1);
				// �����Ӵ������չ res
				for (int k = 0; k < num; ++k) { res += tmp; }
				i = mp[i]; // �����������Ӵ���, ������չ res
			}
			else { res.push_back(s[i]); } // ����������ĸ, ֱ����չ
		}
		return res;
	}
};

class Solution_394_1 {
public:
	string decodeString(string s) {
		stack<int> is;
		stack<string> ss;
		string res;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {  // ��������
				int num = s[i++] - '0';
				while (s[i] != '[') {
					num = num * 10 + (s[i++] - '0');
				}
				is.push(num);
				ss.push(res);
				res = "";
			}
			else if (s[i] == ']') {
				for (int k = 0; k < is.top(); ++k) { ss.top() += res; }
				is.pop();
				res = ss.top();
				ss.pop();
			}
			else { res += s[i]; }
		}
		return res;
	}
};

void test_394() {
	string s = "2[10[a]2[bc]]";
	cout << Solution_394_1().decodeString(s) << endl;
}