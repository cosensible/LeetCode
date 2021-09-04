#include <unordered_set>
#include <iostream>
using namespace std;

// 判断快乐数的过程中要么碰到 1 结束，要么进入循环
// 碰到 1 是快乐数，碰到循环不是快乐数
// 判断是否进入循环与判断链表是否有环相似，可以用哈希表记录出现过的数，也可用快慢指针

class Solution_202_HashTable {
public:
	bool isHappy(int n) {
		unordered_set<int> us;
		while (n != 1 && us.count(n) == 0) {
			us.insert(n);
			n = getNext(n);
		}
		return n == 1;
	}

private:
	int getNext(int n) {
		int a = 0;
		while (n) {
			int x = n % 10;
			a += x * x;
			n /= 10;
		}
		return a;
	}
};

class Solution_202_FastSlowPtr {
public:
	bool isHappy(int n) {
		int slow = n, fast = getNext(n);
		while (fast != 1 && slow != fast) {
			slow = getNext(slow);
			fast = getNext(getNext(fast));
		}
		return fast == 1;
	}

private:
	int getNext(int n) {
		int a = 0;
		while (n) {
			int x = n % 10;
			a += x * x;
			n /= 10;
		}
		return a;
	}
};

void test_202() {
	cout << (Solution_202_FastSlowPtr().isHappy(19) == true
		&& Solution_202_HashTable().isHappy(2) == false) << endl;
}