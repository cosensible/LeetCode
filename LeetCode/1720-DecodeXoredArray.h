#include <iostream>
#include <vector>
using namespace std;

class Solution_1720 {
public:
	// a^b=c => b=a^c
	vector<int> decode(vector<int>& encoded, int first) {
		int n = encoded.size();
		vector<int> ans(n + 1);
		ans[0] = first;
		for (int i = 1; i <= n; ++i) {
			ans[i] = ans[i - 1] ^ encoded[i - 1];
		}
		return ans;
	}
};

void test_1720() {
	vector<int> encoded = { 6,2,7,3 };
	auto res = Solution_1720().decode(encoded, 4);
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}