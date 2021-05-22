#include <vector>
#include <iostream>
using namespace std;


// ����ʼ���ֵ S==0��Alice ��ʤ
// S!=0���� nums ����Ϊż����һ������һ���� nums[i]������ȥ����ʹ���ֵ��Ϊ 0
// ��֤����S=nums[0]^...^nums[n-1]����ȥ�������� nums[i] ������� Si=S^nums[i] ��Ϊ��
// ��S0^...^Sn-1=0 => (S^nums[0])^...^(S^nums[n-1])=(S^...^S)^(nums[0]^...^nums[n-1])=0^S=S=0���� S!=0 ì��
// ��ˣ��� nums ����Ϊż�����������ֵ�Ƿ�Ϊ�㣬Alice ���ܻ�ʤ
// ��Ϊ���������ֵΪ���� Alice ʤ�����ֵ��Ϊ�㣬Bob ÿ�β�����Ϊż����Alice �ذ�

class Solution_810 {
public:
	bool xorGame(vector<int>& nums) {
		int n = nums.size();
		if ((n & 1) == 0) return true;
		int sxor = 0;
		for (int x : nums) sxor ^= x;
		return sxor == 0;
	}
};

void test_810() {
	vector<int> nums = { 1,1,2 };
	cout << (Solution_810().xorGame(nums) == false) << endl;
}