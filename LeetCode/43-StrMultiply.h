#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution_43 {
public:
	string multiply(string num1, string num2) {
		// if(num1=="0"||num2=="0") return "0";
		int m = num1.size(), n = num2.size();
		vector<int> table(m + n, 0);
		for (int i = m - 1; i >= 0; --i) {
			int a = num1[i] - '0';
			for (int j = n - 1; j >= 0; --j) {
				int b = num2[j] - '0';
				int num = a * b + table[i + j + 1];
				table[i + j + 1] = num % 10;
				table[i + j] += num / 10; // ½øÎ»
			}
		}
		string res;
		int i = 0;
		while (i < m + n && table[i] == 0) ++i;
		while (i < m + n) res.push_back(table[i++] + '0');
		if (res.empty()) res = "0";
		return res;
	}
};

void test_43() {
	string num1 = "123", num2 = "456";
	string res = Solution_43().multiply(num1, num2);
	cout << (res == "56088") << endl;
}