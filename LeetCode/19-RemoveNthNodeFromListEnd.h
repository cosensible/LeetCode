#include "List.h"

class Solution_19 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = new ListNode(0), *q = p;
		p->next = head;
		head = p;
		while (q->next) {
			if (n-- <= 0)
				p = p->next;
			q = q->next;
		}
		p->next = p->next->next;
		return head->next;
	}
};

void test_19() {
	std::vector<int> nv1 = { 1,2,3,4,5 };
	std::vector<int> nv2 = { 2,3,4,5 };
	ListNode *l1 = arr2list(nv1), *l2 = arr2list(nv2);

	ListNode *res = Solution_19().removeNthFromEnd(l1, 5);
	std::cout << isListSame(l2, res) << std::endl;
}