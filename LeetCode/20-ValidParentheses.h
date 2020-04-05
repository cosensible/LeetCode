#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution_20 {
public:
	bool isValid(string s) {
		stack<char> cs;
		unordered_map<char, char> mp = { {')','('},{']','['},{'}','{'} };
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				cs.push(s[i]);
			}
			else {
				if (cs.empty()) return false;
				if (mp[s[i]] != cs.top()) return false;
				cs.pop();
			}
		}
		return cs.empty();
	}
};

void test_20() {
	string s = "()";
	cout << Solution_20().isValid(s) << endl;
}