#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1872 {
public:
	// ��ҵ�ÿһ�����������ǽ����� x öʯ�Ӻϲ�������ȡ�ȼ۵ķ�����ÿһ�ֵķ�������ĳ��ǰ׺��
	// �� f(i) ��ʾ��ҿ�ѡ����±� u �ڷ�Χ [i,n-1] ʱ���ܻ�õ����ֲ�
	// �� Alice ѡ�� i������� prefix[i] �֣�Bob ֻ���� [i+1,n-1] ��ѡ��
	// ���� Bob Ҫ��С���÷ֲ������ [i+1,n-1] ��Χ��ѡ������ֵ f(i+1)����˵÷ֲ�Ϊ pre[i]-f(i+1)
	// �� Alice ��ѡ�� i��˵����Ҫ�ڷ�Χ [i+1,n-1] ����ѡ�����ֲ�Ϊ f(i+1)
	// ��� f(i) Ϊ�������ֵ
	int stoneGameVIII(vector<int>& stones) {
		int n = stones.size();
		if (n < 2) return 0;
		for (int i = 1; i < n; ++i) stones[i] += stones[i - 1];
		int ans = stones[n - 1];
		for (int i = n - 2; i >= 1; --i) {
			ans = max(ans, stones[i] - ans);
		}
		return ans;
	}
};

void test_1872() {
	vector<int> stones = { -1,2,-3,4,-5 };
	cout << (Solution_1872().stoneGameVIII(stones) == 5) << endl;
}