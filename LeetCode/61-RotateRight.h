#include "common.h"
using namespace std;

class Solution_61 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		// ����Ϊ�ջ�������ֻ��һ��Ԫ��, ֱ�ӷ���
		if (head == nullptr || head->next == nullptr) return head;
		int len = 1;
		ListNode *tail = head;
		// ����������, ���ҵ�����ĩβ�ڵ�
		for (; tail->next != nullptr; tail = tail->next, ++len);
		k %= len; // k ����������, ������
		if (k == 0) return head;

		k = (k + len) % len; // �� k Ϊ����, ��ģ����ɽ���ת��Ϊ����
		k = len - k - 1; // ������ͷ���µ�����β����Ҫǰ���Ĳ���
		ListNode *newTail = head;
		for (int i = 0; i < k; newTail = newTail->next, ++i);
		ListNode *newHead = newTail->next;
		newTail->next = nullptr;
		tail->next = head;
		return newHead;
	}
};

void test_61() {
	vector<int> vi = { 1,2,3,4,5 };
	ListNode *lst = arr2list(vi);
	ListNode *res = Solution_61().rotateRight(lst, -2);
	printList(res);
}