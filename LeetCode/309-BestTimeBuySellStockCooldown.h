#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_309
{
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2)return 0;

		//i买入，i-1必须无票
		//i-1无票由卖出造成，不可取，需考虑i-2
		//i-1无票由不操作造成，其值与i-2相等
		//综上，买入需参考i-2

		int pre_s_i_0 = 0, s_i_0 = 0, s_i_1 = INT_MIN;
		for (int i = 0; i < n; ++i) {
			int tmp = s_i_0;
			s_i_0 = max(s_i_0, s_i_1 + prices[i]);
			s_i_1 = max(s_i_1, pre_s_i_0 - prices[i]);
			pre_s_i_0 = tmp;
		}
		return s_i_0;
	}
};

void test_309() {
	vector<int> profits = { 1,2,4 };
	int res = Solution_309().maxProfit(profits);
	std::cout << "test_309 : " << (res == 3) << std::endl;
}