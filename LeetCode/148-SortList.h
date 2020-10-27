/* https://leetcode.com/problems/sort-list/ */

#include "List.h"
#include <iostream>

using namespace std;

class Solution_148 {
public:
	ListNode* sortList(ListNode* head) {
		// 归并排序, 自底向上, 终止条件需要知道链表的长度
		int length = 0;
		for (auto p = head; p; p = p->next) length++;

		ListNode *dummy = new ListNode(0, head);  // 哑节点, 主要用于合并操作
		for (int size = 1; size <= length; size <<= 1) { // 1--2--4--...--length
			// tail: 已合并部分的尾节点
			// cur: 待切割处理的部分的头节点
			ListNode *tail = dummy, *cur = dummy->next;
			while (cur) {
				ListNode *left = cur;
				ListNode *right = cut(left, size);
				cur = cut(right, size);

				// 传入tail作为合并部分的前驱节点, 返回已合并部分的尾节点
				tail = merge(tail, left, right);
				tail->next = cur;
			}
		}
		return dummy->next;
	}

private:
	// 切掉前n个节点, 返回链表的后半部分
	ListNode* cut(ListNode* head, int n) {
		ListNode *p = head;
		while (--n && p) {
			p = p->next;
		}
		if (!p) return nullptr;
		ListNode *next = p->next;
		p->next = nullptr;
		return next;
	}
	// cur: 待合并部分的前驱节点(传值)
	ListNode* merge(ListNode *cur, ListNode *l1, ListNode *l2) {
		while (l1&&l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		while (cur->next) cur = cur->next;
		return cur; // 返回已合并部分的尾节点
	}
};

void test_148() {
	vector<int> vi = { -1,5,3,4,0 };
	vector<int> res = { -1,0,3,4,5 };
	ListNode *list = arr2list(vi);
	ListNode *except = arr2list(res);

	ListNode *output = Solution_148().sortList(list);
	cout << isListSame(except, output) << endl;
}