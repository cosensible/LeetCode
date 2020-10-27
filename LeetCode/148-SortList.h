/* https://leetcode.com/problems/sort-list/ */

#include "List.h"
#include <iostream>

using namespace std;

class Solution_148 {
public:
	ListNode* sortList(ListNode* head) {
		// �鲢����, �Ե�����, ��ֹ������Ҫ֪������ĳ���
		int length = 0;
		for (auto p = head; p; p = p->next) length++;

		ListNode *dummy = new ListNode(0, head);  // �ƽڵ�, ��Ҫ���ںϲ�����
		for (int size = 1; size <= length; size <<= 1) { // 1--2--4--...--length
			// tail: �Ѻϲ����ֵ�β�ڵ�
			// cur: ���и��Ĳ��ֵ�ͷ�ڵ�
			ListNode *tail = dummy, *cur = dummy->next;
			while (cur) {
				ListNode *left = cur;
				ListNode *right = cut(left, size);
				cur = cut(right, size);

				// ����tail��Ϊ�ϲ����ֵ�ǰ���ڵ�, �����Ѻϲ����ֵ�β�ڵ�
				tail = merge(tail, left, right);
				tail->next = cur;
			}
		}
		return dummy->next;
	}

private:
	// �е�ǰn���ڵ�, ��������ĺ�벿��
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
	// cur: ���ϲ����ֵ�ǰ���ڵ�(��ֵ)
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
		return cur; // �����Ѻϲ����ֵ�β�ڵ�
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