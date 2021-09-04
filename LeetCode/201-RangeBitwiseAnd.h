#include <iostream>
using namespace std;

// 对区间所有数字按位与的结果是所有数字的公共前缀，进一步而言，是首尾两个数字的公共前缀
// 假设前 i 位均相同，第 i+1 位开始不同，由于数字连续，所以第 i+1 位先 0 后 1
// 存在两个连续的数，分别为 0111... 和 1000... 完成第 i+1 位从 0 到 1 的跳变
// 因此，对区间所有数按位与的结果是首尾两个数的公共前缀，求公共前缀可以移位，也可以消去末尾 1，直至 m>=n

class Solution_201_Shift {
public:
	int rangeBitwiseAnd(int left, int right) {
		int shift = 0;
		while (left < right) {
			left >>= 1;
			right >>= 1;
			++shift;
		}
		return left << shift;
	}
};

class Solution_201_BrianKernighan {
public:
	int rangeBitwiseAnd(int left, int right) {
		while (left < right) {
			right &= (right - 1);
		}
		return right;
	}
};

void test_201() {
	cout << (Solution_201_BrianKernighan().rangeBitwiseAnd(2, 7) == 0) << endl;
}