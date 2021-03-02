#include "common.h"
using namespace std;


class Solution_25 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy = new ListNode(0, head);
		ListNode *cur = dummy;
		ListNode *beg = head, *end = head;
		while (beg != nullptr) {
			int i = 0;
			for (; i < k - 1 && end->next != nullptr; ++i) {
				end = end->next;
			}
			if (i == k - 1) {
				auto ptrs = reverse(beg, end);
				cur->next = ptrs.first;
				cur = ptrs.second;
				beg = cur->next;
				end = beg;
			}
			else {
				break;
			}
		}
		return dummy->next;
	}

	pair<ListNode*, ListNode*> reverse(ListNode *beg, ListNode *end) {
		if (beg == nullptr || beg == end) return { beg,end };
		ListNode *p = beg, *q = p->next, *tail = end->next;
		while (q != tail) {
			p->next = q->next;
			q->next = beg;
			beg = q;
			q = p->next;
		}
		return { beg,p };
	}
};

void test_25() {
	vector<int> vi = { 1,2,3,4,5 };
	ListNode *lst = arr2list(vi);
	ListNode *res = Solution_25().reverseKGroup(lst, 3);
	printList(res);
}