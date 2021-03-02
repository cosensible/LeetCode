#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// 评测题目: 随机生成小学生口算题，3个数字加减，如“19-8+11=”，要求中间和最终结果都在0~20的范围内

string getProblem() {
	const int N = 21; // 每个数和结果的范围为 [0,N)
	unsigned seed = time(nullptr);
	cout << seed << endl;
	srand(seed);

	int a = 0, b = 0, c = 0; // 三个数字
	int cur = 0; // 当前计算得到的数
	int flag1 = 1, flag2 = 1; // 两个符号位

	c = rand() % N; // 先随机生成最后一个数
	flag1 = (rand() % 2) == 0 ? -1 : 1; // 随机生成倒数第一个符号
	cur = flag1 * c; // 计算当前得到的数

	// 0<=(b+cur)<=20, 若cur>=0, b in [0,20-cur]; 否则, b in [-cur,20]
	if (cur >= 0) {
		b = rand() % (N - cur);
	}
	else {
		b = rand() % (N + cur) - cur;
	}

	cur += b;
	flag2 = (rand() % 2) == 0 ? -1 : 1; // flag2为b的符号, 同时也是cur的符号
	cur *= flag2;
	flag1 *= flag2; // c的符号flag1需要随之改变

	// 在合法范围内随机返回a
	if (cur >= 0) {
		a = rand() % (N - cur);
	}
	else {
		a = rand() % (N + cur) - cur;
	}

	string s1 = flag1 > 0 ? "+" : "-";
	string s2 = flag2 > 0 ? "+" : "-";

	return to_string(a) + s2 + to_string(b) + s1 + to_string(c);
}

void test_ali_1() {
	cout << getProblem() << endl;
}