#include <array>
#include <string>
#include <iostream>
using namespace std;

class Solution_12 {
public:
	string intToRoman(int num) {
		if (num < 1 || num>3999) return "";

		string ans;
		array<int, 13> x = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		array<string, 13> y = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		// 贪心转换, 转换面额由高到低
		for (int i = 0; i < x.size() && num>0; ++i) {
			while (num >= x[i]) {
				ans += y[i];
				num -= x[i];
			}
		}
		return ans;
	}
};

void test_12() {
	cout << (Solution_12().intToRoman(58) == "LVIII") << endl;
}