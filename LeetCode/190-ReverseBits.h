#include <iostream>
using namespace std;

class Solution_190_Recurrent {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		for (int i = 0; i < 32; ++i) {
			ans <<= 1;
			ans |= (n & 1);
			n >>= 1;
		}
		return ans;
	}
};

// 先交换相邻 1 位，再交换相邻 2 位，再交换相邻 4 位，...，最后交换相邻 16 位
class Solution_190_DivideConquer {
private:
	const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
	const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
	const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
	const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
	uint32_t reverseBits(uint32_t n) {
		n = n >> 1 & M1 | (n & M1) << 1;
		n = n >> 2 & M2 | (n & M2) << 2;
		n = n >> 4 & M4 | (n & M4) << 4;
		n = n >> 8 & M8 | (n & M8) << 8;
		return n >> 16 | n << 16;
	}
};

void test_190() {
	uint32_t n1 = 43261596, n2 = 4294967293;
	uint32_t ans1 = 964176192, ans2 = 3221225471;
	cout << (Solution_190_DivideConquer().reverseBits(n1) == ans1
		&& Solution_190_Recurrent().reverseBits(n2) == ans2) << endl;
}