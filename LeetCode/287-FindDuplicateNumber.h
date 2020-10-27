#include <vector>
#include <iostream>

using namespace std;


// �������СΪ n, �����ظ�Ԫ��, �����ĳԪ�� x, С�ڵ��� x ��Ԫ������Ϊ x
// ������ >x, ˵�� [1,x] ���ظ�Ԫ��, ���� [x+1,n] ���ظ�Ԫ��
// ���, �����ö������������ظ�Ԫ��
class Solution_287_1 {
public:
	int findDuplicate(vector<int>& nums) {
		int l = 1, r = nums.size() - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			int count = 0;
			for (int n : nums) {
				if (n <= m) { count++; }
			}
			if (count > m) { r = m; }
			else { l = m + 1; }
		}
		return l;
	}
};

// �����СΪ n+1, ����Ϊ 0~n, ����Ԫ��Ϊ 1~n
// ����Ԫ�ؿ��Կ�����һ����������, �Ӷ��γ�һ������
// �������ظ�Ԫ�ر��������������ڵ�ָ���Ԫ��, ��˸�Ԫ��Ϊ���������
class Solution_287 {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		fast = 0;
		while (fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}
		return fast;
	}
};

void test_287() {
	vector<int> vi = { 1,3,4,2,2 };
	vector<int> vi1 = { 3,1,3,4,2 };
	cout << ((Solution_287().findDuplicate(vi) == 2) &&
		(Solution_287().findDuplicate(vi1) == 3)) << endl;
}