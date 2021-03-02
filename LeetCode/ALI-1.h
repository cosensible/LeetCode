#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// ������Ŀ: �������Сѧ�������⣬3�����ּӼ����硰19-8+11=����Ҫ���м�����ս������0~20�ķ�Χ��

string getProblem() {
	const int N = 21; // ÿ�����ͽ���ķ�ΧΪ [0,N)
	unsigned seed = time(nullptr);
	cout << seed << endl;
	srand(seed);

	int a = 0, b = 0, c = 0; // ��������
	int cur = 0; // ��ǰ����õ�����
	int flag1 = 1, flag2 = 1; // ��������λ

	c = rand() % N; // ������������һ����
	flag1 = (rand() % 2) == 0 ? -1 : 1; // ������ɵ�����һ������
	cur = flag1 * c; // ���㵱ǰ�õ�����

	// 0<=(b+cur)<=20, ��cur>=0, b in [0,20-cur]; ����, b in [-cur,20]
	if (cur >= 0) {
		b = rand() % (N - cur);
	}
	else {
		b = rand() % (N + cur) - cur;
	}

	cur += b;
	flag2 = (rand() % 2) == 0 ? -1 : 1; // flag2Ϊb�ķ���, ͬʱҲ��cur�ķ���
	cur *= flag2;
	flag1 *= flag2; // c�ķ���flag1��Ҫ��֮�ı�

	// �ںϷ���Χ���������a
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