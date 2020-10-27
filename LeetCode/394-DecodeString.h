#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution_394 {
	unordered_map<int, int> mp; // 记录括号对起止索引
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
			if (s[i] >= '0' && s[i] <= '9') {  // 碰到数字
				int num = s[i++] - '0';
				while (s[i] != '[') {  // 多位数
					num = num * 10 + (s[i++] - '0');
				}
				// 递归求解子串
				string tmp = helper(s, i + 1, mp[i] - 1);
				// 根据子串结果扩展 res
				for (int k = 0; k < num; ++k) { res += tmp; }
				i = mp[i]; // 更新索引至子串后, 继续扩展 res
			}
			else { res.push_back(s[i]); } // 碰到常规字母, 直接扩展
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
			if (s[i] >= '0' && s[i] <= '9') {  // 碰到数字
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