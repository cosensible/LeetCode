#include <vector>
#include <iostream>
using namespace std;

class Solution_1734 {
public:
	// ǰ n �������������У��� n Ϊ������encoded �����СΪż��
	// a0^a1=b0, a1^a2=b1, a2^a3=b2, a3^a4=b3, ..., an-2^an-1=bn-2
	// a1^a2^a3^a4^...^an-1=b1^b3^...^bn-2
	// ��ǰ n ����������������� a1-an-1 ���������򣬵õ� a0
	// �ٸ��� a0 ���ԭ����
	vector<int> decode(vector<int>& encoded) {
		int n = encoded.size() + 1;
		int allXor = 0;
		for (int i = 1; i <= n; ++i) allXor ^= i;
		int xorTail = 0;
		for (int i = 1; i < encoded.size(); i += 2) {
			xorTail ^= encoded[i];
		}
		vector<int> res(n);
		res[0] = allXor ^ xorTail;
		for (int i = 1; i < n; ++i) {
			res[i] = res[i - 1] ^ encoded[i - 1];
		}
		return res;
	}
};


void test_1734() {
	vector<int> encoded = { 6,5,4,6 };
	auto res = Solution_1734().decode(encoded);
	for (int i : res) { cout << i << " "; } // 2,4,1,5,3
	cout << endl;
}