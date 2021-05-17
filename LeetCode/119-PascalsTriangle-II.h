#include <vector>
#include <iostream>
using namespace std;

class Solution_119 {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 0) return {};
		vector<int> res(rowIndex + 1);

		// ��̬�滮��c(i,j) = c(i-1,j) + c(i-1,j-1)
		res[0] = 1;
		for (int i = 1; i <= rowIndex; ++i) {
			for (int j = i; j > 0; --j) {
				res[j] += res[j - 1];
			}
		}

		// ��ѧ��ʽ��c(i,j) = c(i,j-1) * (i-j+1) / j
		res[0] = res[rowIndex] = 1;
		for (int i = 1; i < rowIndex; ++i) {
			// ��ֹ�˷�Խ��
			res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
		}
		return res;
	}
};

void test_119() {
	auto res = Solution_119().getRow(4);
	for (int i : res) { cout << i << " "; } // 1 4 6 4 1
	cout << endl;
}