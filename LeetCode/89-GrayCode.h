#include <vector>
#include <iostream>
using namespace std;

// ����� i �����ױ���Ĺ�ʽ��i ^ (i >> 1)
class Solution_89 {
public:
	vector<int> grayCode(int n) {
		n = 1 << n;
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = i ^ (i >> 1);
		}
		return ans;
	}
};

// �� Gn �� Gn+1��Gn+1=Gn+Rn
// Rn �� Gn ÿ�����ĵ� n+1 λ�� 1������ת
// ����G2={ 00, 01, 11, 10 }��R2={ 110, 111, 101, 100 }�� G3=G2+R2={ 000, 001, 011, 010, 110, 111, 101, 100 }
class Solution_89_FromPreG {
public:
	vector<int> grayCode(int n) {
		if (n == 0) return { 0 };
		vector<int> ans(1 << n);
		ans[1] = 1;
		for (int k = 2; k <= n; ++k) {
			int sz = 1 << (k - 1);
			int i = sz;
			for (int j = sz - 1; j >= 0; --j) {
				ans[i++] = ans[j] + sz;
			}
		}
		return ans;
	}
};


void test_89() {
	vector<int> ans = Solution_89().grayCode(3);
	for (int i : ans)cout << i << " ";
	cout << endl;
}