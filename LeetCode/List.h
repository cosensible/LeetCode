#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
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

bool isVecSame(const std::vector<int> &v1, const std::vector<int> &v2) {
	if (v1.size() != v2.size()) { return false; }
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) { return false; }
	}
	return true;
}

#endif