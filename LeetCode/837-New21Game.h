#include <vector>
#include <iostream>
using namespace std;

class Solution_837 {
public:
	double new21Game(int N, int K, int W) {
		// �õ������ķ�Χ�� 0~K+W-1 (����Ϊ K-1 ʱ�鵽 W), dp[i] ��ʾ����Ϊ i ʱ��ʤ�ĸ���
		vector<double> dp(K + W, 0.0);
		double sum = 0.0;
		// ���ڷ��� K~K+W-1, ��Ϸ����, ʤ��ȡ���� ?(i>N)
		for (int i = K + W - 1; i >= K; --i) {
			dp[i] = i > N ? 0.0 : 1.0;
			sum += dp[i];
		}
		// ���ڷ��� x in [K-1~0], ��ʤ���� dp[x]=sum(dp[x+1]...dp[x+W])*1/W
		for (int i = K - 1; i >= 0; --i) {
			dp[i] = 1.0 / W * sum;
			sum = sum - dp[i + W] + dp[i];
		}
		return dp[0];
	}
};

void test_837() {
	//cout << fixed << setprecision(6) << 1e-5 << endl;
	cout << (Solution_837().new21Game(21, 17, 10) - 0.73278 < 1e-5) << endl;
}