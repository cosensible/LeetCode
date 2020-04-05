#include "List.h"

class Solution_206 {
public:
	ListNode* reverseList(ListNode* head) {
		//// 迭代版本
		//if (head == nullptr || head->next == nullptr) { return head; }
		//ListNode *p = head, *q = head->next;
		//while (q != nullptr) {
		//	p->next = q->next;
		//	q->next = head;
		//	head = q;
		//	q = p->next;
		//}
		//return head;

		// 递归版本
		if (head == nullptr || head->next == nullptr) { return head; }
		ListNode *p = reverseList(head->next);
		// 此时，head->next 指向最后一个节点
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
};

void test_206() {
	std::vector<int> nv1 = { 1,2,3 };
	std::vector<int> nv2 = { 3,2,1 };
	ListNode *l1 = arr2list(nv1), *l2 = arr2list(nv2);
	//printList(l1);
	//printList(l2);
	ListNode *rList = Solution_206().reverseList(l1);
	//printList(rList);
	std::cout << "test_206 : " << isListSame(l2, rList) << std::endl;
}