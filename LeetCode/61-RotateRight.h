#include "common.h"
using namespace std;

class Solution_61 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		// 链表为空或者链表只有一个元素, 直接返回
		if (head == nullptr || head->next == nullptr) return head;
		int len = 1;
		ListNode *tail = head;
		// 计算链表长度, 并找到链表末尾节点
		for (; tail->next != nullptr; tail = tail->next, ++len);
		k %= len; // k 大于链表长度, 求余数
		if (k == 0) return head;

		k = (k + len) % len; // 若 k 为负数, 求模运算可将其转换为正数
		k = len - k - 1; // 从链表头到新的链表尾部需要前进的步数
		ListNode *newTail = head;
		for (int i = 0; i < k; newTail = newTail->next, ++i);
		ListNode *newHead = newTail->next;
		newTail->next = nullptr;
		tail->next = head;
		return newHead;
	}
};

void test_61() {
	vector<int> vi = { 1,2,3,4,5 };
	ListNode *lst = arr2list(vi);
	ListNode *res = Solution_61().rotateRight(lst, -2);
	printList(res);
}