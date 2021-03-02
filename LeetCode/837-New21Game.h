#include <vector>
#include <iostream>
using namespace std;

class Solution_837 {
public:
	double new21Game(int N, int K, int W) {
		// 得到分数的范围是 0~K+W-1 (分数为 K-1 时抽到 W), dp[i] 表示分数为 i 时获胜的概率
		vector<double> dp(K + W, 0.0);
		double sum = 0.0;
		// 对于分数 K~K+W-1, 游戏结束, 胜负取决于 ?(i>N)
		for (int i = K + W - 1; i >= K; --i) {
			dp[i] = i > N ? 0.0 : 1.0;
			sum += dp[i];
		}
		// 对于分数 x in [K-1~0], 获胜概率 dp[x]=sum(dp[x+1]...dp[x+W])*1/W
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