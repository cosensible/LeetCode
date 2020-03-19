#include <vector>
#include <iostream>

using namespace std;

/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ */

class Solution_123 {
public:
	int maxProfit(vector<int>& prices) {
		//买入掏钱，利润降低；卖出变现，利润增加
		//通过三个最佳后续操作点所对应的利润来计算总利润
		int buy1 = INT_MIN; //目前为止，交易1的最佳后续买入点所对应的利润
		int buy2 = INT_MIN; //目前为止，交易2的最佳后续买入点所对应的利润
		int sell1 = 0; //目前为止，交易1的最佳后续卖出点所对应的利润
		int sell2 = 0; //目前为止，交易2的最佳卖出点所对应的利润，即总利润

		for (int p : prices) {
			if (buy1 < -p)buy1 = -p;
			if (sell1 < buy1 + p)sell1 = buy1 + p;
			if (buy2 < sell1 - p)buy2 = sell1 - p; //在交易1的获利基础上进行交易2
			if (sell2 < buy2 + p)sell2 = buy2 + p;
		}
		return sell2;
	}
};

void test_123() {
	vector<int> profits = { 3,3,5,0,0,3,1,4 };
	int res = Solution_123().maxProfit(profits);
	std::cout << "test_123 : " << (res == 6) << std::endl;
}