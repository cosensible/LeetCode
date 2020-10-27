#include <vector>
#include <iostream>
#include "List.h"

using namespace std;

/* https://leetcode.com/problems/product-of-array-except-self/ */

class Solution_238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> prefix(n, 1), suffix(n, 1), res(n, 1);
		for (int i = 1; i < n; ++i) {
			prefix[i] = prefix[i - 1] * nums[i - 1];
		}
		for (int i = n - 2; i >= 0; --i) {
			suffix[i] = suffix[i + 1] * nums[i + 1];
		}
		for (int i = 0; i < n; ++i) {
			res[i] = prefix[i] * suffix[i];
		}
		return res;
	}
};

class Solution_238_CSpace {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size(), prefix = 1;
		vector<int> res(n, 1);
		for (int i = n - 2; i >= 0; --i) {
			res[i] = res[i + 1] * nums[i + 1];
		}
		for (int i = 1; i < n; ++i) {
			prefix *= nums[i - 1];
			res[i] *= prefix;
		}
		return res;
	}
};

void test_238() {
	vector<int> vi = { 1,2,3,4 }, except = { 24,12,8,6 };
	vector<int> res = Solution_238().productExceptSelf(vi);
	cout << (isVecSame(res, except) == true) << endl;
}