#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_4 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n) { //移动短数组,降低移动次数
			swap(nums1, nums2);
			swap(m, n);
		}
		int l = m + n;						//总共有多少个元素
		int lmxi = m / 2 - 1, rmxi = m / 2;	//nums1中 左边最大/右边最小 元素索引
		int lmyi, rmyi;						//nums2中 左边最大/右边最小 元素索引
		int lmx, lmy, rmx, rmy;				//nums1和nums2中 左边最大/右边最小 元素

		//当nums1全部元素位于同一边,一定能得到中位数,但需要更新nums2的分割点
		while (lmxi >= -1 && rmxi <= m) {
			//nums1和nums2中的左边元素数量之和应该为总数量的一半: l/2
			//nums1中左边元素个数为rmxi,nums2中左边元素个数应该为l/2-rmxi,最后元素的索引等于数量减一
			lmyi = l / 2 - rmxi - 1;
			rmyi = lmyi + 1;

			lmx = lmxi < 0 ? INT_MIN : nums1[lmxi];
			rmx = rmxi >= m ? INT_MAX : nums1[rmxi];
			lmy = lmyi < 0 ? INT_MIN : nums2[lmyi];
			rmy = rmyi >= n ? INT_MAX : nums2[rmyi];

			//nums1和nums2中的所有左边元素都不大于右边元素,且正好分成两半,中位数由分界处的四个元素产生
			if (lmx <= rmy && lmy <= rmx) {
				if (l % 2)return min(rmx, rmy);
				return (max(lmx, lmy) + min(rmx, rmy)) / 2.0;
			}
			else if (lmx > rmy) {
				lmxi--; //nums1中左边最大元素大于nums2中右边最小元素,应该使其降低,即向左移动
			}
			else if (lmy > rmx) {
				lmxi++; //nums1中右边最小元素小于nums2中左边最大元素,应该使其增加,即向右移动
			}
			rmxi = lmxi + 1;
		}
	}
};

void test_4()
{
	vector<int> a = { 1 }, b = { 2,3 };
	std::cout << (Solution_4().findMedianSortedArrays(a, b) == 2) << endl;
}