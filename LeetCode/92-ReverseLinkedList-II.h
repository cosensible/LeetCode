#include "common.h"
using namespace std;

class Solution_92 {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (head == nullptr || head->next == nullptr || left == right) return head;
		ListNode *dummy = new ListNode(0, head);
		ListNode *pre = dummy; // pre 指向待反转部分的前一个节点
		int i = 1;
		for (; i < left; ++i) { // 找到待反转部分的第一个节点
			pre = pre->next;
		}
		ListNode *cur = pre->next, *p = nullptr;
		for (; i < right; ++i) { // 执行链表反转，pre->next 指向反转链表的头部
			p = cur->next;
			cur->next = p->next;
			p->next = pre->next;
			pre->next = p;
		}
		return dummy->next;
	}
};


void test_92() {
	vector<int> vals = { 3,5 };
	ListNode *list = arr2list(vals);
	ListNode *ans = Solution_92().reverseBetween(list, 1, 2);
	printList(ans);
}