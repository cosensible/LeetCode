#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_4 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n) { //ѡ�������,���Ͷ��ִ���
			return findMedianSortedArrays(nums2, nums1);
		}
		int l = m + n;			//�ܹ��ж��ٸ�Ԫ��
		int lmx, rmx, lmy, rmy;	//nums1(nums2)��`��������ұ���С`Ԫ��
		int px, py;				//nums1��nums2�ķָ��, >=px(py) ��Ϊ�ұ�

		int low = 0, high = m;	//���ڶ������� [low,high)
		while (low <= high) {
			px = (low + high) / 2;
			py = l / 2 - px;

			lmx = px == 0 ? INT_MIN : nums1[px - 1];
			rmx = px == m ? INT_MAX : nums1[px];
			lmy = py == 0 ? INT_MIN : nums2[py - 1];
			rmy = py == n ? INT_MAX : nums2[py];

			//����Ԫ�صȷ�����,�����Ԫ�ض��������ұ�Ԫ��,����λ���ɷֽ����ĸ�Ԫ�ز���
			if (lmx <= rmy && lmy <= rmx) {
				if (l % 2) return min(rmx, rmy);
				return (max(lmx, lmy) + min(rmx, rmy)) / 2.0;
			}
			//Ϊ�β��� high=px-2 ? ��Ϊhigh���ǿ�����,��=px-2,���©�����һ��Ԫ��
			else if (lmx > rmy) {
				high = px - 1; //nums1��������Ԫ�ش���nums2���ұ���СԪ��,Ӧ��ʹ���С,ѡ�����
			}
			else if (lmy > rmx) {
				low = px + 1; //nums1���ұ���СԪ��С��nums2��������Ԫ��,Ӧ��ʹ������,ѡ���ұ�
			}
		}
	}
};

void test_4()
{
	vector<int> a = { 1,1,3,3 }, b = { 1,1,3,3 };
	std::cout << (Solution_4().findMedianSortedArrays(a, b) == 2) << endl;
}