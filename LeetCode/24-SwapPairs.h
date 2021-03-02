#include "common.h"
using namespace std;

class Solution_24 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *dummy = new ListNode(0, head);
		ListNode *p = head, *q = head->next, *cur = dummy;
		while (p != nullptr&&p->next != nullptr) {
			q = p->next;
			p->next = q->next;
			q->next = p;
			cur->next = q;
			cur = p;
			p = p->next;
		}
		return dummy->next;
	}
};

void test_24() {
	vector<int> vi = { 1,2,3,4,5 };
	ListNode *lst = arr2list(vi);
	ListNode *res = Solution_24().swapPairs(lst);
	printList(res);
}