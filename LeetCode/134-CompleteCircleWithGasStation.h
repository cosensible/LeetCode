#include <vector>
#include <iostream>
using namespace std;

class Solution_134 {
public:
	// 假设从加油站 x 出发，能到达的最后一个加油站为 y，则 sum_gas[x,y]<sum_cost[x,y], sum_gas[x,j]>=sum_cost[x,j] j in [x,y)
	// 对于任意 z in [x,y]，判断 z 是否能到达 y 的下一个加油站，需满足 sum_gas[z,y]>=sum_cost[z,y]
	// 然而，sum_gas[z,y]=sum_gas[x,y]-sum_gas[x,z-1]<sum_cost[x,y]-sum_gas[x,z-1]<sum_cost[x,y]-sum_cost[x,z-1]=sum_cost[z,y]
	// 因此，任意 z in [x,y]，都不能到达 y 的下一个加油站，可以跳过 [x,y]，直接从 y+1 开始判断
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.size() != cost.size()) return -1;
		if (gas.size() == 0) return -1;
		int n = gas.size();
		for (int s = 0; s < n;) { // 起点最多只有 0~n-1 这 n 种选择
			int cur = 0;  // 当前汽油量
			int step = 0; // 第 step 个路段，环行一周回到起点需要走 n 个路段
			for (; step < n; ++step) {
				int i = (s + step) % n; // 以 s 为起点的第 step 个路段的汽油站的编号
				cur += gas[i];
				if (cur < cost[i]) break; // 油不够，无法到达下一个汽油站
				cur -= cost[i];
			}
			if (step == n) return s; // 走完 n 个路段，说明回到起点
			s = s + step + 1; // 没回到起点，从中断后的下一个汽油站开始
		}
		return -1;
	}
};


void test_134() {
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << (Solution_134().canCompleteCircuit(gas, cost) == 3) << endl;
}