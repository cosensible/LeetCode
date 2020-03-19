#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_4 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n) { //�ƶ�������,�����ƶ�����
			swap(nums1, nums2);
			swap(m, n);
		}
		int l = m + n;						//�ܹ��ж��ٸ�Ԫ��
		int lmxi = m / 2 - 1, rmxi = m / 2;	//nums1�� ������/�ұ���С Ԫ������
		int lmyi, rmyi;						//nums2�� ������/�ұ���С Ԫ������
		int lmx, lmy, rmx, rmy;				//nums1��nums2�� ������/�ұ���С Ԫ��

		//��nums1ȫ��Ԫ��λ��ͬһ��,һ���ܵõ���λ��,����Ҫ����nums2�ķָ��
		while (lmxi >= -1 && rmxi <= m) {
			//nums1��nums2�е����Ԫ������֮��Ӧ��Ϊ��������һ��: l/2
			//nums1�����Ԫ�ظ���Ϊrmxi,nums2�����Ԫ�ظ���Ӧ��Ϊl/2-rmxi,���Ԫ�ص���������������һ
			lmyi = l / 2 - rmxi - 1;
			rmyi = lmyi + 1;

			lmx = lmxi < 0 ? INT_MIN : nums1[lmxi];
			rmx = rmxi >= m ? INT_MAX : nums1[rmxi];
			lmy = lmyi < 0 ? INT_MIN : nums2[lmyi];
			rmy = rmyi >= n ? INT_MAX : nums2[rmyi];

			//nums1��nums2�е��������Ԫ�ض��������ұ�Ԫ��,�����÷ֳ�����,��λ���ɷֽ紦���ĸ�Ԫ�ز���
			if (lmx <= rmy && lmy <= rmx) {
				if (l % 2)return min(rmx, rmy);
				return (max(lmx, lmy) + min(rmx, rmy)) / 2.0;
			}
			else if (lmx > rmy) {
				lmxi--; //nums1��������Ԫ�ش���nums2���ұ���СԪ��,Ӧ��ʹ�併��,�������ƶ�
			}
			else if (lmy > rmx) {
				lmxi++; //nums1���ұ���СԪ��С��nums2��������Ԫ��,Ӧ��ʹ������,�������ƶ�
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