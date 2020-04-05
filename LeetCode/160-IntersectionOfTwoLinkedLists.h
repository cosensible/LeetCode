#include "List.h"

using namespace std;

class Solution_160 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p = headA, *q = headB;
		while (p != q) {
			p = p ? p->next : headB;
			q = q ? q->next : headA;
		}
		return p;
	}
};