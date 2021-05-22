#include <vector>
#include <iostream>
using namespace std;


// 若初始异或值 S==0，Alice 获胜
// S!=0，若 nums 长度为偶数，一定存在一个数 nums[i]，将其去掉可使异或值不为 0
// 反证法：S=nums[0]^...^nums[n-1]，若去掉任意数 nums[i] 的异或结果 Si=S^nums[i] 都为零
// 则：S0^...^Sn-1=0 => (S^nums[0])^...^(S^nums[n-1])=(S^...^S)^(nums[0]^...^nums[n-1])=0^S=S=0，与 S!=0 矛盾
// 因此，若 nums 长度为偶数，无论异或值是否为零，Alice 都能获胜
// 若为奇数，异或值为零则 Alice 胜；异或值不为零，Bob 每次操作都为偶数，Alice 必败

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