#include "common.h"
using namespace std;

class Solution_27 {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (i < n && nums[i] == val) {
				// swap(nums[i],nums[--n]);
				nums[i] = nums[--n];
			}
		}
		return n;
	}
};

void test_27() {
	vector<int> vi = { 0,1,2,2,3,0,4,2 };
	cout << (Solution_27().removeElement(vi, 2) == 5) << endl;
}