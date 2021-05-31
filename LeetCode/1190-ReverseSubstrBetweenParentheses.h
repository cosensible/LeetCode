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


// 预处理括号
class Solution_1190_Preprocess {
public:
	// 反转括号内的子串等价于逆序遍历括号内的子串
	// 当沿着某方向遍历字符串，遇到括号时，需要跳转到另一半括号的位置，然后改变遍历方向
	string reverseParentheses(string s) {
		int n = s.size();
		stack<int> stk;
		vector<int> pair(n); // 保存每个括号的另一半的位置
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') stk.push(i);
			else if (s[i] == ')') {
				pair[i] = stk.top();
				pair[stk.top()] = i;
				stk.pop();
			}
		}

		string ans;
		int index = 0, step = 1; // 当前遍历位置，遍历方向
		while (index < n) {
			if (s[index] == '(' || s[index] == ')') { // 跳转到另一半括号，并改变方向
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