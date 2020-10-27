#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution_406 {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end()); //����ߴ�С��������
		vector<vector<int>> res(people.size());

		for (auto &p : people) {
			int i = 0, j = 0;
			while (j <= p[1]) { //Ѱ�ҵ� p[1] ������λ��
				//λ��i���л���һ��ͬ����ߵ���,�ڵ�ǰ��һ����Чλ��
				if (res[i].size() != 2 || res[i][0] == p[0]) ++j;
				++i;
			}
			swap(res[i - 1], p);
		}
		return res;
	}
};

void test_406() {
	vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,2},{6,1},{5,0} };
	vector<vector<int>> res = Solution_406().reconstructQueue(people);

	for (int i = 0; i < res.size(); ++i) {
		cout << "[" << res[i][0] << "," << res[i][1] << "]" << "��";
	}
	cout << endl;
}