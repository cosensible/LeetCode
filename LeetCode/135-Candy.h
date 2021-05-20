#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_135 {
public:
	// ���ָߵĺ��ӱ����������ĺ��ӻ�ø����ǹ�
	// ������� ratings[i]>ratings[i-1]���� candy[i]=candy[i-1]+1
	// �ҹ����� ratings[i]>ratings[i+1]���� candy[i]=candy[i+1]+1
	// ���� i ���յõ����ǹ�����Ϊ���������������ҹ�������ֵ
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> cnt(n, 1); // ÿ����������һ���ǹ�
		// �����ұ������飬����ÿ�����������������ʱ��õ��ǹ���
		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i - 1])
				cnt[i] = cnt[i - 1] + 1;
		}
		// ���ҵ���������飬����ÿ�������������ҹ���ʱ��õ��ǹ�������ȡ�������ֵ
		for (int i = n - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1])
				cnt[i] = max(cnt[i], cnt[i + 1] + 1);
		}
		int ans = 0; // �ۼ�ÿ�����ӵ��ǹ���
		for (int i = 0; i < n; ++i) {
			ans += cnt[i];
		}
		return ans;
	}
};


void test_135() {
	vector<int> ratings = { 1,0,2 };
	cout << (Solution_135().candy(ratings) == 5) << endl;
}