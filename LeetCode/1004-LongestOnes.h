#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1004 {
public:
	int longestOnes(vector<int>& A, int K) {
		int i = 0, j = 0, res = 0;
		while (j < A.size()) {
			if (A[j] == 0) {
				--K;
				if (K < 0) { // 碰到0, 且K不够, 将i移动至当前窗口中的第一个0之后
					while (A[i]) ++i;
					++i;
					++K;
				}
			}
			++j;
			res = max(res, j - i);
		}
		return res;
	}
};

void test_1004() {
	vector<int> vi = { 1,1,1,0,0,0,1,1,1,1,0 };
	cout << (Solution_1004().longestOnes(vi, 2) == 6) << endl;
}