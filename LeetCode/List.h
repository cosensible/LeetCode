#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
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


#endif