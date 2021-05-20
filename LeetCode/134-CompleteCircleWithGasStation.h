#include <vector>
#include <iostream>
using namespace std;

class Solution_134 {
public:
	// ����Ӽ���վ x �������ܵ�������һ������վΪ y���� sum_gas[x,y]<sum_cost[x,y], sum_gas[x,j]>=sum_cost[x,j] j in [x,y)
	// �������� z in [x,y]���ж� z �Ƿ��ܵ��� y ����һ������վ�������� sum_gas[z,y]>=sum_cost[z,y]
	// Ȼ����sum_gas[z,y]=sum_gas[x,y]-sum_gas[x,z-1]<sum_cost[x,y]-sum_gas[x,z-1]<sum_cost[x,y]-sum_cost[x,z-1]=sum_cost[z,y]
	// ��ˣ����� z in [x,y]�������ܵ��� y ����һ������վ���������� [x,y]��ֱ�Ӵ� y+1 ��ʼ�ж�
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.size() != cost.size()) return -1;
		if (gas.size() == 0) return -1;
		int n = gas.size();
		for (int s = 0; s < n;) { // ������ֻ�� 0~n-1 �� n ��ѡ��
			int cur = 0;  // ��ǰ������
			int step = 0; // �� step ��·�Σ�����һ�ܻص������Ҫ�� n ��·��
			for (; step < n; ++step) {
				int i = (s + step) % n; // �� s Ϊ���ĵ� step ��·�ε�����վ�ı��
				cur += gas[i];
				if (cur < cost[i]) break; // �Ͳ������޷�������һ������վ
				cur -= cost[i];
			}
			if (step == n) return s; // ���� n ��·�Σ�˵���ص����
			s = s + step + 1; // û�ص���㣬���жϺ����һ������վ��ʼ
		}
		return -1;
	}
};


void test_134() {
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << (Solution_134().canCompleteCircuit(gas, cost) == 3) << endl;
}