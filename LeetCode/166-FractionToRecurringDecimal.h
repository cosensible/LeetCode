#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_166 {
public:
	string fractionToDecimal(int numerator_, int denominator_) {
		long long numerator = numerator_, denominator = denominator_;
		string ans;
		bool sign = (numerator^denominator) < 0;   // 是否为负数
		long long a = 1LL * numerator / denominator;
		long long b = 1LL * numerator%denominator;
		if (a == 0 && b != 0 && sign) ans.push_back('-'); // 商为 0 但余数不为 0，需要补上符号
		ans += to_string(a);
		denominator = abs(denominator); // 符号已定，后续计算不需要符号
		b = abs(b);
		if (b != 0) ans.push_back('.');

		unordered_map<long long, int> mp;
		while (b != 0) {
			if (mp.count(b) != 0) {
				ans.insert(ans.begin() + mp[b], '(');
				ans.push_back(')');
				break;
			}
			mp[b] = ans.size();
			numerator = b * 10;
			a = numerator / denominator;
			ans.push_back('0' + a);
			b = numerator % denominator;
		}
		return ans;
	}
};

void test_166() {
	cout << (Solution_166().fractionToDecimal(-7, 24) == "-0.291(6)") << endl;
}