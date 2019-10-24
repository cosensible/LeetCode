#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

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

bool isListSame(ListNode *l1, ListNode *l2) {
	while (l1 && l2 && l1->val == l2->val) {
		l1 = l1->next;
		l2 = l2->next;
	}
	if (!l1 && !l2) { return true; }
	return false;
}

ListNode* arr2list(const std::vector<int> &vals) {
	if (vals.size() == 0) { return nullptr; }
	ListNode *list = new ListNode(vals[0]), *p = list;
	for (int i = 1; i < vals.size(); ++i) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	return list;
}

void printList(ListNode *list) {
	while (list != nullptr) {
		std::cout << list->val << " ";
		list = list->next;
	}
	std::cout << std::endl;
}

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