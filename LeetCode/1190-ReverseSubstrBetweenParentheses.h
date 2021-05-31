#include <string>
#include <iostream>
using namespace std;

class Solution_1190 {
public:
	string reverseParentheses(string s) {
		string ans;
		for (char c : s) {
			if (c != ')') {
				ans.push_back(c);
			}
			else {
				string tmp;
				while (!ans.empty() && ans.back() != '(') {
					tmp.push_back(ans.back());
					ans.pop_back();
				}
				ans.pop_back(); // pop '('
				ans += tmp;
			}
		}
		return ans;
	}
};


// Ԥ��������
class Solution_1190_Preprocess {
public:
	// ��ת�����ڵ��Ӵ��ȼ���������������ڵ��Ӵ�
	// ������ĳ��������ַ�������������ʱ����Ҫ��ת����һ�����ŵ�λ�ã�Ȼ��ı��������
	string reverseParentheses(string s) {
		int n = s.size();
		stack<int> stk;
		vector<int> pair(n); // ����ÿ�����ŵ���һ���λ��
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') stk.push(i);
			else if (s[i] == ')') {
				pair[i] = stk.top();
				pair[stk.top()] = i;
				stk.pop();
			}
		}

		string ans;
		int index = 0, step = 1; // ��ǰ����λ�ã���������
		while (index < n) {
			if (s[index] == '(' || s[index] == ')') { // ��ת����һ�����ţ����ı䷽��
				index = pair[index];
				step = -step;
			}
			else {
				ans.push_back(s[index]);
			}
			index += step;
		}
		return ans;
	}
};


void test_1190() {
	string s = "(u(love)i)";
	cout << (Solution_1190_Preprocess().reverseParentheses(s) == "iloveu") << endl;
}