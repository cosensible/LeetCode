#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


// ���ⳤ��Ϊ k �����������Ϊ 0���� xor{ nums[i,i+k-1] }=0��xor{ nums[i+1,i+k] }=0���Ƴ� nums[i]^nums[i+k]=0���� nums[i]==nums[i+k]
// ��ˣ�nums ���޸ĺ���һ���� k Ϊ���ڵ����飬�� nums �е�Ԫ�ذ� i%k ��Ϊ k �飬�޸ĺ�ÿ��Ԫ�ر�����ȣ��� nums[0]^...^nums[k-1]==0
// �� f(i,x) Ϊ������ [0,i] ���������Ϊ x �������޸Ĵ����������ս��Ϊ f(k-1,0)
// �� x' Ϊǰ i-1 ������������ǰ i �������� x=x'^num�����̶� num���� x' ����Ϊ x^num�������̶� num���� x' ����Ϊ����ֵ
// �ù�ϣ��ͳ�Ƶ� i ���Ԫ�ؼ����������ʹ�ù�ϣ��Ԫ�� num����ֻ�ܴ� f(i-1,x^num) ת�ƣ����޸�����Ԫ�أ�f(i,x)=min{ f(i-1,x^num) }+cnt-cnt_num
// ����ʹ�ù�ϣ���е�Ԫ�أ���Ҫ�޸ĸ���ȫ��Ԫ�أ����ǿ��Դ����� x' ת�ƣ�f(i,x)=min{ f(i-1,x) }+cnt
// �������� f(i,x) ʱ������Сֵ���浽 g[i] �У������ڳ���ʱ��õ� min{ f(i,x) }=g[i]


class Solution_1787 {
	const int N = 1 << 10; // ������Ԫ�ص����ޣ�0<=nums[i]<=2^10-1������� x Ҳ�ڸ÷�Χ��
public:
	int minChanges(vector<int>& nums, int k) {
		vector<vector<int>> f(k, vector<int>(N, INT_MAX)); // f(i,x) ������ [0,i] ���������Ϊ x �������޸Ĵ���
		vector<int> g(k, INT_MAX); // �������� x ȡֵ�� f(i,x) ����Сֵ

		for (int i = 0; i < k; ++i) { // ���δ���ÿһ��
			int cnt = 0; // ��¼���������Ԫ�ظ���
			unordered_map<int, int> mp; // ��¼����Ԫ�ص����༰����ִ���
			for (int j = i; j < nums.size(); j += k) {
				cnt++;
				mp[nums[j]]++;
			}
			if (i == 0) { // ����� 0 ��
				for (int x = 0; x < N; ++x) {
					f[0][x] = cnt - mp[x];
					g[0] = min(g[0], f[0][x]);
				}
			}
			else {
				for (int x = 0; x < N; ++x) {
					f[i][x] = g[i - 1] + cnt; // ��ѡ���ϣ���е���
					for (auto &p : mp) { // ѡ���ϣ���е���
						f[i][x] = min(f[i][x], f[i - 1][x^p.first] + cnt - p.second);
					}
					g[i] = min(g[i], f[i][x]); // �洢 f(i,x) ����Сֵ������һ��ļ�����ʹ��
				}
			}
		}
		return f[k - 1][0];
	}
};

void test_1787() {
	vector<int> nums = { 3,4,5,2,1,7,3,4,7 };
	cout << (Solution_1787().minChanges(nums, 3) == 3) << endl;
}