#include <vector>
#include <iostream>

using namespace std;

/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ */

class Solution_123 {
public:
	int maxProfit(vector<int>& prices) {
		//������Ǯ�����󽵵ͣ��������֣���������
		//ͨ��������Ѻ�������������Ӧ������������������
		int buy1 = INT_MIN; //ĿǰΪֹ������1����Ѻ������������Ӧ������
		int buy2 = INT_MIN; //ĿǰΪֹ������2����Ѻ������������Ӧ������
		int sell1 = 0; //ĿǰΪֹ������1����Ѻ�������������Ӧ������
		int sell2 = 0; //ĿǰΪֹ������2���������������Ӧ�����󣬼�������

		for (int p : prices) {
			if (buy1 < -p)buy1 = -p;
			if (sell1 < buy1 + p)sell1 = buy1 + p;
			if (buy2 < sell1 - p)buy2 = sell1 - p; //�ڽ���1�Ļ��������Ͻ��н���2
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