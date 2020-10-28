#include <vector>
#include <iostream>

using namespace std;

/*
Say you have an array for which the i'th element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
design an algorithm to find the maximum profit. Note that you cannot sell a stock before you buy one.
*/

class Solution_121 {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MAX, maxProfit = 0;
		for (int p : prices) {
			if (p < minPrice) {
				minPrice = p;
			}
			else if (p - minPrice > maxProfit) {
				maxProfit = p - minPrice;
			}
		}
		return maxProfit;
	}
};

void test_121() {
	vector<int> nums = { 7,1,5,3,6,4 };
	cout << "test_121 : " << (Solution_121().maxProfit(nums) == 5) << endl;
}