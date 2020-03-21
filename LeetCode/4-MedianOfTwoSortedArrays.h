#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_4 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n) { //选择短数组,降低二分次数
			return findMedianSortedArrays(nums2, nums1);
		}
		int l = m + n;			//总共有多少个元素
		int lmx, rmx, lmy, rmy;	//nums1(nums2)中`左边最大和右边最小`元素
		int px, py;				//nums1和nums2的分割点, >=px(py) 划为右边

		int low = 0, high = m;	//用于二分搜索 [low,high)
		while (low <= high) {
			px = (low + high) / 2;
			py = l / 2 - px;

			lmx = px == 0 ? INT_MIN : nums1[px - 1];
			rmx = px == m ? INT_MAX : nums1[px];
			lmy = py == 0 ? INT_MIN : nums2[py - 1];
			rmy = py == n ? INT_MAX : nums2[py];

			//所有元素等分两半,且左边元素都不大于右边元素,则中位数由分界点的四个元素产生
			if (lmx <= rmy && lmy <= rmx) {
				if (l % 2) return min(rmx, rmy);
				return (max(lmx, lmy) + min(rmx, rmy)) / 2.0;
			}
			//为何不是 high=px-2 ? 因为high端是开区间,若=px-2,则会漏掉最后一个元素
			else if (lmx > rmy) {
				high = px - 1; //nums1中左边最大元素大于nums2中右边最小元素,应该使其减小,选择左边
			}
			else if (lmy > rmx) {
				low = px + 1; //nums1中右边最小元素小于nums2中左边最大元素,应该使其增大,选择右边
			}
		}
	}
};

void test_4()
{
	vector<int> a = { 1,1,3,3 }, b = { 1,1,3,3 };
	std::cout << (Solution_4().findMedianSortedArrays(a, b) == 2) << endl;
}