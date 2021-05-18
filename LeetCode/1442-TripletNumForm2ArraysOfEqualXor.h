#include <vector>
#include <iostream>
using namespace std;

class Solution_1442 {
public:
	int countTriplets(vector<int>& arr) {
		// 0<=i<k, 0<k<n, i<j<=k
		// a==b -> a^b==0 -> arr[i]^...^arr[k]==0 -> arr[0]^...^arr[i-1]==arr[0]^...^arr[k]
		// 此时，j 可以取 (i,k] 中的任意值，有 k-i 种情况
		int n = arr.size();
		if (n < 2) return 0;
		int ans = 0;
		// k 从 1 开始，对数组累计异或，并查找之前是否存在相同的累计异或值
		for (int k = 1; k < n; ++k) {
			arr[k] ^= arr[k - 1];
			for (int i = k - 1; i >= 0; --i) {
				int pre = i == 0 ? 0 : arr[i - 1];
				// 存在相等的累计异或值，累加 j 的取值数量
				if (pre == arr[k]) {
					ans += (k - i);
				}
			}
		}
		return ans;
	}
};


void test_1442() {
	vector<int> arr = { 2,3,1,6,7 };
	cout << (Solution_1442().countTriplets(arr) == 4) << endl;
}