#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution_60 {
public:
	string getPermutation(int n, int k) {
		vector<int> nums(n + 1, 1); // [1,n] �� i ������Ӧ��������
		for (int i = 1; i <= n; ++i) {
			nums[i] = nums[i - 1] * i;
		}
		string s; // ������
		vector<bool> used(n + 1, false);   // ��¼�����Ƿ�ʹ�ù�
		while (k > 0) { // ͨ������ȷ������Ŀ�ͷ������С k ֵ����ʣ�������е�������
			for (int i = 1; i <= n; ++i) {      // n Ϊ����ֵĸ���
				if (nums[i] < k) continue; // ������������Ѱ�Ҹ����������
				// ʹ�� i �����־͹��ˣ��� n ��������ѡ n-i ����С�����̶ֹ���ǰ��
				for (int j = 1; n > i && j < used.size(); ++j) {
					if (!used[j]) { // ʹ�ù������ֲ����ٴα�ʹ��
						used[j] = true;
						s.push_back(j + '0');
						--n;
					}
				}
				// i ������ǡ���γ� k �����У������ִ�С���������
				if (nums[i] == k) {
					for (int j = used.size() - 1; j >= 1; --j) {
						if (!used[j]) s.push_back(j + '0');
					}
					return s;
				}
				// �ҳ��� k ���������ĸ����ֿ�ͷ����Ҫ�ж� k �Ƿ����� nums[i-1]
				// ����������ͷΪ�� cnt+1 ��������������ͷΪ�� cnt ����
				if (nums[i] > k) {
					int cnt = k / nums[i - 1];
					if (cnt*nums[i - 1] < k) ++cnt;
					int j = 1; // �̶���ͷΪ�� cnt �������
					for (int c = 0; j < used.size(); ++j) {
						if (!used[j]) ++c;
						if (c == cnt) break;
					}
					s.push_back(j + '0');
					used[j] = true;
					--n;
					k -= (cnt - 1)*nums[i - 1];
				}
			}
		}
		return s;
	}
};


class Solution_60_Better {
public:
	string getPermutation(int n, int k) {
		vector<int> factor(n, 1); // �׳ˣ�������
		for (int i = 1; i < n; ++i) {
			factor[i] = factor[i - 1] * i;
		}
		--k; // ʹ���б�Ŵ��㿪ʼ�����ڼ���ÿ��λ���ϵ����ֱ��
		string ans; // ������
		vector<int> used(n + 1, 1); // ��¼�����Ƿ����

		for (int i = 1; i <= n; ++i) {   // ��ǰ����ȷ��ÿһ��λ���ϵ�����
			// ǰ�����б�ȷ����λ�� i ��ÿ��ȡֵ��Ӧ n-i ������
			int cnt = k / factor[n - i] + 1;
			for (int j = 1; j <= n; ++j) { // ��С�����ҳ��� cnt ����������
				cnt -= used[j];      // ֻ�п������ֲŻ�ʹ cnt ��һ
				if (cnt == 0) {
					used[j] = 0;
					ans.push_back(j + '0');
					break;
				}
			}
			k %= factor[n - i]; // ���� k Ϊ����ʣ�����ֵ����м����еı��
		}
		return ans;
	}
};


void test_60() {
	cout << (Solution_60_Better().getPermutation(4, 9) == "2314") << endl;
}